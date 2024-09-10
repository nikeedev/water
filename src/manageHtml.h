#ifndef MANAGEHTML_H
#define MANAGEHTML_H

#include <filesystem>
#include <fstream>
#include <string>
#include <fmt/core.h>
#include <format> 
#include "httpp.h"

std::string getOsName();

using namespace httpp;

namespace Water {
    extern std::string html_code;

    void manageUrl(const std::string &url);

    void manageFile(const std::string &path);
}

#endif // MANAGEHTML_H