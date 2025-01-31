# Proj-1
# StringUtils Library

## Overview
This library provides useful string functions for common text operations. It includes methods for formatting, trimming, modifying case, and measuring differences between strings.

## Features
- **Slice**: Extracts part of a string.
- **Capitalize**: Makes the first letter uppercase, the rest lowercase.
- **Upper/Lower**: Converts the entire string to uppercase or lowercase.
- **LStrip/RStrip/Strip**: Removes spaces from the left, right, or both sides.
- **Center/LJust/RJust**: Aligns text with padding.
- **Replace**: Replaces parts of a string.
- **Split/Join**: Splits a string into parts or joins parts into a string.
- **ExpandTabs**: Replaces tab characters with spaces.
- **EditDistance**: Measures the difference between two strings.

## Usage
Include `StringUtils.h` in your project and link the corresponding implementation file. Example:

```cpp
#include "StringUtils.h"
#include <iostream>

int main() {
    std::string text = " hello world ";
    std::cout << StringUtils::Strip(text) << std::endl; // "hello world"
    return 0;
}
```

## Requirements
- C++11 or newer



