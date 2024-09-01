#!/bin/bash

SOURCE_FILES="testinglib.cpp"
OBJECT_FILES="testinglib.o"
LIBRARY_NAME="libmylib.a"


# Compile into object file
COMPILE_CMD="g++ -g -c $SOURCE_FILES -o $OBJECT_FILES -std=c++17 -fsanitize=address"
$COMPILE_CMD
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Make a library
ARCHIVE_CMD="ar rcs $LIBRARY_NAME $OBJECT_FILES"
$ARCHIVE_CMD
if [ $? -ne 0 ]; then
    echo "Archival failed"
    exit 1
fi

# Delete object file
rm testinglib.o

if [ $? -eq 0 ]; then
    echo "Library successfully made"
fi