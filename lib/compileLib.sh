#!/bin/bash

SOURCE_FILE="mylib.cpp"
OBJECT_FILE="mylib.o"
LIBRARY_NAME="../lib/libmylib.a"

# Compile into object file
COMPILE_CMD="g++ -g -c $SOURCE_FILE -o $OBJECT_FILE"
$COMPILE_CMD
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Make a library
ARCHIVE_CMD="ar rcs $LIBRARY_NAME $OBJECT_FILE"
$ARCHIVE_CMD
if [ $? -ne 0 ]; then
    echo "Archival failed"
    exit 1
fi

# Delete object file
rm mylib.o

if [ $? -eq 0 ]; then
    echo "Library successfully made"
fi