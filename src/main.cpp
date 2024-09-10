#include <fmt/core.h>
#include <filesystem>
#include "manageHtml.h"

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        fmt::print("water browser - v0.1.1\nusage: water <file path or url to a website or a HTML page> ");
        return -1;
    }
    else
    {
        bool file = false;
        std::string html_file = argv[1];

        file = !html_file.starts_with("http") || html_file.ends_with(".html");

        if (file)
        {
            fmt::print("water browser - v0.1.0\nloading file: {}\n", html_file);

            Water::manageFile(html_file);
        }
        else
        {
            fmt::print("water browser - v0.1.0\nloading url: {}\n", html_file);
            
            Water::manageUrl(html_file);
        }
    }

    fmt::println("{}", Water::html_code);
    
    return 0;
}