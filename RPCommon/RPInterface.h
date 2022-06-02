#pragma once
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
public:
    RPInterfaceException(std::string_view e)
    {
        m_msg = std::string(e);
    }
    virtual char const * what() const noexcept override
    {
        return m_msg.c_str(); 
        
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
    std::map<std::string,unsigned long> colorMap = std::map<std::string, unsigned long>();
    std::string title, minimizedTitle = "Default Window";
    
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
    XFreeGC(opt.display, opt.context);
    XDestroyWindow(opt.display,opt.window);
    XCloseDisplay(opt.display);
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
            opt.display = XOpenDisplay((char*)0);
        }
        if(opt.screen == -1)
        {
            opt.screen = DefaultScreen(opt.display);
        }
        //Init color map to B/W
        
        opt.colorMap["Black"] = BlackPixel(opt.display,opt.screen);
        opt.colorMap["White"] = WhitePixel(opt.display,opt.screen);
        
        //No clue what "5" does here...
        
        XID window = XCreateSimpleWindow(opt.display,DefaultRootWindow(opt.display),opt.currX,opt.currY,opt.currW,opt.currH,5,opt.colorMap["White"],opt.colorMap["Black"]);
        
        XSetStandardProperties(opt.display,window,opt.title.c_str(),opt.minimizedTitle.c_str(),None,NULL,0,NULL);
        
        
        
        
        
    }
    else
    {
        throw new RPInterfaceException("Wayland is not implemented yet...");
    }
    return -1;
}

