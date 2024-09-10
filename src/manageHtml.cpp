#include "manageHtml.h"

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

namespace Water
{
    std::string html_code; 

    void manageUrl(const std::string &url)
    {
        std::string short_html_name = url.starts_with("http") ? url.substr(url.find("/") + 2, url.length()) : url;

        httpOptions ops;
        ops.url = url;
        ops.method = GET;
        ops.redirect = follow;

        ops.headers.insert({"User-Agent", std::format("Water/0.1.0 {} OS: {}", url, getOsName())});
        ops.headers.insert({"Host", short_html_name});
        fmt::println("the host is: {}", short_html_name);

        httpRequest req(ops);

        httpResponse resp = req.send();

        fmt::println("loaded the url. status code {}", resp.status_code);

        html_code = resp.body;
    }

    void manageFile(const std::string &path)
    {
        std::ifstream file(path);
        if (!file.is_open())
        {
            std::cerr << "Unable to open the file!" << std::endl;
            std::exit(1);
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();
        std::string cached_file = buffer.str();

        file.close();

        html_code = cached_file;
    }
}