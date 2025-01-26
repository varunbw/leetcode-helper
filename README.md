# Leetcode Helper

This basic C++ library provides utility functions for mainly solving Leetcode problems (amongst others) that simplify common tasks such as input/output handling and data structure construction. It is designed to help you focus on solving problems rather than spending time setting up the necessary input/output infrastructure.

The library *should* work on all platforms (Windows, Linux, Mac).

Checkout the functions the library has to offer at src/. Comments are included to help understand what each function does.

I also recommend going through the entirety of [FAQ.md](FAQ.md) first.

# Installation

1. Clone the repository

```bash
git clone https://github.com/varunbw/leetcode-helper.git
```

2. Include the library in your project by including the relevant header files.

```cpp
#include "lch.h"
```


# Usage

## Compiling library

The final compiled library is not included in the repo. You can compile it by running these commands when in the `lib/` directory in the console

#### Linux
```bash
./compile_lib.sh
```
#### Windows
```shell
.\compile_lib.bat
```

## Running the main solution file
You can directly use the `run.sh` script as follows
#### Linux
```bash
./run.sh
```
#### Windows
```shell
.\run.bat
```
#### Compile command
The base command for compiling with g++ and linking the library correctly is as follows:
```bash
g++ main.cpp -Llib -llch
```

The command used in the run files is:
```bash
g++ -g main.cpp -o main -Llib -llch -std=c++17 -fsanitize=address
```

## Refer [the FAQs](FAQ.md) for more help

# License
[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
