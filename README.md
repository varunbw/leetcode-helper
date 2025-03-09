# Leetcode Helper

This basic C++ library provides utility functions for mainly solving Leetcode problems (amongst others) that simplify common tasks such as input/output handling and data structure construction. It is designed to help you focus on solving problems rather than spending time setting up the necessary input/output infrastructure.

The library *should* work on all platforms (Windows, Linux, Mac).

Checkout the functions the library has to offer at src/. Comments are included to help understand what each function does.

I also recommend going through the entirety of [FAQ.md](FAQ.md) first.

# Installation

1. Clone the repository.

```bash
git clone https://github.com/varunbw/leetcode-helper.git
```

2. Include the header file in your solution file.

```cpp
#include "lch.h"
```


# Usage

## Compiling library

The final compiled library is not included in the repo. You can compile it using the script/batch file provided in the `lib/` directory.
I will be adding a CMake solution soon.

## Running the main solution file
You can directly use the `run.sh` or `run.bat` script

#### Compile command
The base command for compiling with g++ and linking the library correctly is as follows:
```bash
g++ main.cpp -Llib -llch
```

The command used in the run files is:
```bash
g++ -g main.cpp -o main -Llib -llch -std=c++17 -fsanitize=address
```

It's the same for the `clang` compiler. For MSVC, or anything else, you can just ask a LLM to translate it for you

## Refer [the FAQs](FAQ.md) for more help

# License
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
