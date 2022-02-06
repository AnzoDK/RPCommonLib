#pragma once
#define RPCOMMON_VERSION __rpCommon_Get_Version()
#if defined(WIN32) || defined(WIN64)
#include <string>
#endif
#include "strreverse.h"
#include "strfindlast.h"
#include "strcomp.h"
#include "keymap.h"
#include "byteprint.h"
#include "strlen.h"
#include "terminalcolor.h"
#include "arrayprint.h"
#include "arraycpy.h"
#include "initconvert.h"
//This header is not useful at the current state and has been disabled
//#include "rpcommonerr.h"
#include "eat.h"
#include "unsignedfstream.h"
#include "arraytovector.h"
#include "arraypush.h"
#include "arrayappend.h"


static inline std::string __rpCommon_Get_Version()
{
    const char* cmd = "printf \"$MAJORVERSIONr%s.%s\" \"$(git rev-list --count HEAD)\" \"$(git rev-parse --short HEAD)\"";
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}
