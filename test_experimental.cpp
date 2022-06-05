#include "RPCommon/RPInterface.h"
#include "RPCommon/terminalcolor.h"

bool PerformTestInterface()
{
    std::cout << "Testing RPInterface" << std::endl;
    WindowOptions* opt = new WindowOptions(0,0,500,500,"Hello There!");
    try
    {
        XID w = CreateWindow(*opt,Xlib);
            
        std::cout << TERMINAL_COLOR_GREEN << "Window Creation Sucess" << TERMINAL_COLOR_RESET << std::endl;
    
        std::cout << TERMINAL_COLOR_YELLOW << "Attempting Mapping..." << TERMINAL_COLOR_RESET << std::endl;

        ShowWindow(*opt);
        
        std::cout << TERMINAL_COLOR_YELLOW << "Attempting Doubble Creation..." << TERMINAL_COLOR_RESET << std::endl;
        
        CreateWindow(*opt, Xlib);
        
        __DefaultTestHandle(*opt);
    
        DestroyWindow(*opt);
    
        delete(opt);
    }
    catch(RPInterfaceException e)
    {
        std::cout << TERMINAL_COLOR_RED << "Failed to create Window - Failed with error: " << TERMINAL_COLOR_BLUE << e.what() << TERMINAL_COLOR_RESET << std::endl;
        return 0;
    }

    
    std::cout << TERMINAL_COLOR_GREEN << "RPInterface test succeeded" << TERMINAL_COLOR_RESET << std::endl;
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
