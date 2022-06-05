#pragma once

//Not that we support windows at this moment...
#if defined(_win32) || defined(_win64)
    typedef unsigned int uint;
#endif
#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
#include <map>
/*This header is causing the death my sanity :DDDDDD*/

typedef void* WindowPtr;

class RPInterfaceException : public std::exception
{
protected:
    std::string m_msg = "";
    uint error_code = -1;
public:
    enum Error {NOT_IMPLEMENTED, XERROR};
    RPInterfaceException(std::string_view e, Error eN)
    {
        error_code = static_cast<int>(eN);
        m_msg = std::string(e);
    }
    virtual char const * what() const noexcept override
    {
        return m_msg.c_str(); 
        
    }
    uint code()
    {
        return error_code;
    }
    

};

struct WindowOptions
{
    double default_x,default_y,currX,currY = 0.0;
    double default_h,default_w,currH,currW = 100.0;
    GC context = nullptr;
    Display* display = nullptr;
    int screen = -1;
    XID window = -1;
    std::string displayString = ""; //Set this to change what display will attempted to be opened
    std::map<std::string,unsigned long> colorMap = std::map<std::string, unsigned long>();
    std::string title, minimizedTitle = "Default Window";
    uint borderWidth = 5;
    
    
    
    WindowOptions(double x, double y, std::string_view _title)
    {
        currX = x;
        currY = y;
        title = _title;
    }
    
    WindowOptions(double x, double y, double w, double h, std::string_view _title)
    {
        currX = x;
        currY = y;
        currW = w;
        currH = h;
        title = _title;
    }
};

enum XHandler {Xlib, Wayland};

void DestroyWindow(WindowOptions& opt)
{
    //XFreeGC(opt.display, opt.context); //GC's created by XDefaultGC must never be freed
    XUnmapWindow(opt.display, opt.window);
    XFlush(opt.display);
    XDestroyWindow(opt.display,opt.window);
    XCloseDisplay(opt.display);
}

void __DefaultTestHandle(WindowOptions& opt)
{
    XEvent event;
    bool end = false;
    while(true)
    {
        XNextEvent(opt.display,&event);
        switch(event.type)
        {
            case MapNotify:
                std::cout << "Window Mapped" << std::endl;
                sleep(1);
                end = 1;
                break;
        }
        if(end)
        {
            break;
        }

    }
}

int __DefaultErrorHandler(Display* d, XErrorEvent * e)
{
    size_t errSize = 256;
    char* errT = new char[errSize];
    XGetErrorText(d, e->error_code,errT,errSize);
    std::string err = "XError: " + std::string(errT);
    throw new RPInterfaceException(err, RPInterfaceException::XERROR);
}

XID CreateWindow(WindowOptions& opt, XHandler handler, bool force=false)
{
    if(handler == Xlib)
    {
        //Check for missing settings...
        if(opt.window != -1)
        {
            std::cout << "Window Already on options struct" << std::endl;
            if(!force)
            {
                std::cout << "Returning old window" << std::endl;
                return opt.window;
            }
            std::cout << "Destroying old window..." << std::endl;
            DestroyWindow(opt);
            opt.window = -1;
            opt.display = nullptr;
            opt.screen = -1;
            return CreateWindow(opt, Xlib);
        }
        if(opt.display == nullptr)
        {
            if(opt.displayString == "")
            {
                opt.display = XOpenDisplay(NULL);
            }
            else
            {
                opt.display = XOpenDisplay(opt.displayString.c_str());
            }
            if(opt.display == NULL)
            {
                
                throw new RPInterfaceException(std::string("Failed To Open Display") + opt.displayString,RPInterfaceException::XERROR);
            }
        }
        if(opt.screen == -1)
        {
            opt.screen = DefaultScreen(opt.display);
        }
        //Init color map to B/W
        
        opt.colorMap["Black"] = BlackPixel(opt.display,opt.screen);
        opt.colorMap["White"] = WhitePixel(opt.display,opt.screen);
        
        XSetErrorHandler(*__DefaultErrorHandler);
        
        XID window = XCreateSimpleWindow(opt.display,DefaultRootWindow(opt.display),opt.currX,opt.currY,opt.currW,opt.currH,opt.borderWidth,opt.colorMap["White"],opt.colorMap["Black"]);
        opt.window = window;
        XSelectInput(opt.display, opt.window, ExposureMask | StructureNotifyMask | FocusChangeMask | KeyPressMask);
        XSetStandardProperties(opt.display,window,opt.title.c_str(),opt.minimizedTitle.c_str(),None,NULL,0,NULL);
        XFlush(opt.display);
        return window;
        

        
    }
    else
    {
        throw new RPInterfaceException("Wayland is not implemented yet...",RPInterfaceException::NOT_IMPLEMENTED);
    }
    return -1;
}

void ShowWindow(WindowOptions& opt)
{
    //XMapWindow(opt.display,opt.window);
    XMapRaised(opt.display,opt.window);
}

