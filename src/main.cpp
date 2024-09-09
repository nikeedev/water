#include <fmt/core.h>
#include <filesystem>
#include "manageUrl.h"

int main(int argc, char **argv)
{
    if (!std::filesystem::exists(".cache"))
    {
        std::filesystem::create_directory(".cache");
    }

    if (argc < 1)
    {
        fmt::print("water browser - v0.1.0\nusage: water <file/url to a website or a HTML page> ");
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

            std::ifstream file(html_file);
            if (!file.is_open())
            {
                std::cerr << "Unable to open the file!" << std::endl;
                return 1;
            }

            std::ostringstream buffer;
            buffer << file.rdbuf();
            std::string cached_file = buffer.str();

            file.close();
        }
        else
        {
            fmt::print("water browser - v0.1.0\nloading url: {}\n", html_file);
            std::string short_html_name = html_file.substr(html_file.find("/") + 2, html_file.length());

            httpOptions ops;
            ops.url = html_file;
            ops.method = GET;
            ops.redirect = follow;

            ops.headers.insert({"User-Agent", std::format("Water/0.1.0 {} OS: {}", html_file, getOsName())});
            ops.headers.insert({"Host", short_html_name});

            httpRequest req(ops);

            httpResponse resp = req.send();

            std::ofstream cached_file;
            fmt::println("saving to file: {}", std::format(".cache/{}.html", short_html_name));
            cached_file.open(std::format(".cache/{}.html", short_html_name));
            if (cached_file.is_open())
            {
                cached_file << resp.body;
                fmt::println("{}", resp.body);
            }
            else
            {
                std::cerr << "Unable to open the file!" << std::endl;
            }
            cached_file.close();

            fmt::println("loaded the url. status code {}", resp.status_code);
        }
    }
    return 0;
}