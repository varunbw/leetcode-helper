#!/bin/bash

SOURCE_FILE="main.cpp"
OUTPUT_FILE="main"
LIBRARY_FILE="lch"

# Base compile command
COMPILE_CMD="g++ -g $SOURCE_FILE -o $OUTPUT_FILE -Llib -l$LIBRARY_FILE -std=c++17 -fsanitize=address"

# Compile the source file
echo "Compiling with command: $COMPILE_CMD"
$COMPILE_CMD

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

echo "Compilation successful"
echo "-----------------------------------------------------------------------------------------"
./$OUTPUT_FILE "$@"