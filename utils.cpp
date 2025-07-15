#include "utils.hpp"
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n");
    return str.substr(first, last - first + 1);
}