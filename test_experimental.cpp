#pragma once
#include "RPCommon/RPInterface.h"
#include "RPCommon/terminalcolor.h"

bool PerformTestInterface()
{
    WindowOptions opt = WindowOptions(0,0,100,100,"Hello There!");
    try
    {
        XID w = CreateWindow(opt,Xlib);
    }
    catch(RPInterfaceException e)
    {
        std::cout << TERMINAL_COLOR_RED << "Failed to create Window - Failed with error: " << TERMINAL_COLOR_BLUE << e.what() << TERMINAL_COLOR_RESET << std::endl;
        return 0;
    }
    return 1;
    
}

int main()
{
    std::cout << TERMINAL_COLOR_YELLOW << "Starting Experimental Test" << TERMINAL_COLOR_RESET << std::endl;
    
    if(!PerformTestInterface())
    {
        std::cout << TERMINAL_COLOR_RED << "RPInterface Failed it's tests..." << TERMINAL_COLOR_RESET << std::endl;
        exit(1);
    }
    return 0;
    
}
