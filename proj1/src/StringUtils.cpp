#include "StringUtils.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

namespace StringUtils {

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {
    if (end == 0) end = str.length(); // default end to string length if zero
    if (start < 0) start += str.length(); // handle negative start index
    if (end < 0) end += str.length(); // handle negative end index
    return str.substr(start, end - start);
}

std::string Capitalize(const std::string &str) noexcept {
    if (str.empty()) return str; // return empty string if input is empty
    std::string result = str;
    result[0] = std::toupper(result[0]); // capitalize first character
    std::transform(result.begin() + 1, result.end(), result.begin() + 1, ::tolower); // make the rest lowercase
    return result;
}

std::string Upper(const std::string &str) noexcept {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper); // convert all to uppercase
    return result;
}

std::string Lower(const std::string &str) noexcept {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower); // convert all to lowercase
    return result;
}

std::string LStrip(const std::string &str) noexcept {
    size_t start = str.find_first_not_of(" \t\n\r"); // find first non-whitespace char
    return (start == std::string::npos) ? "" : str.substr(start); // return trimmed string
}

std::string RStrip(const std::string &str) noexcept {
    size_t end = str.find_last_not_of(" \t\n\r"); // find last non-whitespace char
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string Strip(const std::string &str) noexcept {
    return LStrip(RStrip(str)); // trim both sides
}

std::string Center(const std::string &str, int width, char fill) noexcept {
    int padding = width - str.length(); // calculate needed padding
    if (padding <= 0) return str; // return original if width is too small
    int left_pad = padding / 2;
    int right_pad = padding - left_pad;
    return std::string(left_pad, fill) + str + std::string(right_pad, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept {
    return str + std::string(std::max(0, width - static_cast<int>(str.size())), fill); // pad right side
}

std::string RJust(const std::string &str, int width, char fill) noexcept {
    return std::string(std::max(0, width - static_cast<int>(str.size())), fill) + str; // pad left side
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept {
    if (old.empty()) return str; // nothing to replace if old is empty
    std::string result = str;
    size_t pos = 0;
    while ((pos = result.find(old, pos)) != std::string::npos) {
        result.replace(pos, old.length(), rep); // replace occurrences
        pos += rep.length();
    }
    return result;
}

std::vector<std::string> Split(const std::string &str, const std::string &splt) noexcept {
    std::vector<std::string> result;
    if (str.empty()) return result; // return empty vector if input is empty
    
    if (splt.empty()) { // if no delimiter, split by whitespace
        std::istringstream iss(str);
        std::string token;
        while (iss >> token) {
            result.push_back(token);
        }
        return result;
    }

    size_t start = 0;
    size_t end = str.find(splt);
    while (end != std::string::npos) {
        result.push_back(str.substr(start, end - start)); // push each token
        start = end + splt.length();
        end = str.find(splt, start);
    }
    result.push_back(str.substr(start)); // push last segment
    return result;
}

std::string Join(const std::string &str, const std::vector<std::string> &vect) noexcept {
    if (vect.empty()) return ""; // return empty string if vector is empty
    std::string result = vect[0];
    for (size_t i = 1; i < vect.size(); ++i) {
        result += str + vect[i]; // concatenate with delimiter
    }
    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept {
    std::string result;
    size_t column = 0;
    
    for (char c : str) {
        if (c == '\t') {
            size_t spaces = tabsize - (column % tabsize); // figure out how many spaces needed
            result.append(spaces, ' ');
            column += spaces;
        } else {
            result += c;
            column++;
            if (c == '\n') column = 0; // reset column on newline
        }
    }
    return result;
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept {
    std::string l = ignorecase ? Lower(left) : left;
    std::string r = ignorecase ? Lower(right) : right;
    
    std::vector<std::vector<int>> dp(l.length() + 1, std::vector<int>(r.length() + 1));
    
    for (size_t i = 0; i <= l.length(); i++) dp[i][0] = i; // init first column
    for (size_t j = 0; j <= r.length(); j++) dp[0][j] = j; // init first row
    
    for (size_t i = 1; i <= l.length(); i++) {
        for (size_t j = 1; j <= r.length(); j++) {
            dp[i][j] = std::min({
                dp[i-1][j] + 1, // deletion
                dp[i][j-1] + 1, // insertion
                dp[i-1][j-1] + (l[i-1] != r[j-1]) // substitution
            });
        }
    }
    
    return dp[l.length()][r.length()]; // return final edit distance
}

}
