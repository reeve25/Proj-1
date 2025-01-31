#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <string>
#include <vector>

namespace StringUtils {
// slicing a string, handles negative indices too
std::string Slice(const std::string &str, ssize_t start, ssize_t end=0) noexcept;

// capitalizes the first letter, lowers the rest
std::string Capitalize(const std::string &str) noexcept;

// converts entire string to uppercase
std::string Upper(const std::string &str) noexcept;

// converts entire string to lowercase
std::string Lower(const std::string &str) noexcept;

// removes leading whitespace
std::string LStrip(const std::string &str) noexcept;

// removes trailing whitespace
std::string RStrip(const std::string &str) noexcept;

// removes whitespace from both sides
std::string Strip(const std::string &str) noexcept;

// centers the string with padding
std::string Center(const std::string &str, int width, char fill = ' ') noexcept;

// left justifies the string with padding
std::string LJust(const std::string &str, int width, char fill = ' ') noexcept;

// right justifies the string with padding
std::string RJust(const std::string &str, int width, char fill = ' ') noexcept;

// replaces occurrences of 'old' with 'rep'
std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept;

// splits the string by delimiter, defaults to whitespace
std::vector<std::string> Split(const std::string &str, const std::string &splt = "") noexcept;

// joins a vector of strings with a delimiter
std::string Join(const std::string &str, const std::vector<std::string> &vect) noexcept;

// replaces tabs with spaces, default tab size is 4
std::string ExpandTabs(const std::string &str, int tabsize = 4) noexcept;

// calculates the edit distance between two strings
int EditDistance(const std::string &left, const std::string &right, bool ignorecase=false) noexcept;

}

#endif
