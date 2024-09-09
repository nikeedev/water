std::string getOsName()
{
    #ifdef _WIN32
    return "Windows 32bit";
    #elif _WIN64
    return "Windows 64bit";
    #elif __APPLE__ || __MACH__
    return "MacOS";
    #elif __linux__
    return "Linux";
    #elif __FreeBSD__
    return "FreeBSD";
    #elif __unix || __unix__
    return "Unix";
    #else
    return "Other";
    #endif
}
