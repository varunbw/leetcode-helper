#!/bin/bash

# Check if at least two parameters are passed
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <mode>"
    echo "Mode:"
    echo "  0 - Compile with -g"
    echo "  1 - Compile with -g and execute"
    echo ""
    exit 1
fi  

SOURCE_FILE="lc.cpp"
OUTPUT_FILE="lc"
MODE=$1

# Base compile command
COMPILE_CMD="g++ -g $SOURCE_FILE -o $OUTPUT_FILE -Llib -lmylib -fsanitize=address"

# Compile the source file
echo "Compiling with command: $COMPILE_CMD"
$COMPILE_CMD

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

if [ $? -eq 0 ]; then
    echo "Compilation successfull"
    echo ""
fi

# Execute the file if mode is 1
if [ "$MODE" -eq 1 ]; then
    echo "Executing $OUTPUT_FILE"
    echo ""
    ./$OUTPUT_FILE
fi