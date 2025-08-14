#include "utils.hpp"
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n");
    return str.substr(first, last - first + 1);
}
