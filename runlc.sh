#!/bin/bash

# Check if at least one parameter is passed
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <mode> [args...]"
    echo "Mode:"
    echo "  0 - Compile with debug info"
    echo "  1 - Compile with debug info and execute with parameters"
    # echo "  2 - Compile library and program, exec with params"
    echo ""
    exit 1
fi  

SOURCE_FILE="lc.cpp"
OUTPUT_FILE="lc"
MODE=$1

# Base compile command
COMPILE_CMD="g++ -g $SOURCE_FILE -o $OUTPUT_FILE -Llib -lmylib -std=c++17 -fsanitize=address"

# Compile the source file
echo "Compiling with command: $COMPILE_CMD"
$COMPILE_CMD

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

if [ $? -eq 0 ]; then
    echo "Compilation successful"
    echo ""
fi


# Shift the mode parameter to access additional parameters
shift

# Execute the file if mode is 1, passing all remaining arguments
if [ "$MODE" -eq 1 ]; then
    echo "Executing with parameters: $@"
    echo "---------------------------------------------------------------------------------------"
    ./$OUTPUT_FILE "$@"
fi