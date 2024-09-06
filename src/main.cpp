#include <fmt/core.h>

int main(int argc, char** argv) {
    if (argc > 1) {
        fmt::print("water browser - v0.1.0\nusage: water <file/url to a website or a HTML page> ");
    }
    else {
        bool file = false;
        std::string html_file = argv[1];

        file = !html_file.starts_with("http") || html_file.ends_with(".html");

        if (file) {
            fmt::print("water browser - v0.1.0\nloading file: {}\n", html_file);
        }
        else {
            fmt::print("water browser - v0.1.0\nloading url: {}\n", html_file);
        }
    }
    return 0;
}