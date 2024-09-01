#!/bin/bash

SOURCE_FILES="../src/misc.cpp ../src/binaryTree.cpp ../src/graph.cpp ../src/linkedList.cpp ../src/parser.cpp"
OBJECT_FILES="misc.o   binaryTree.o   graph.o   linkedList.o   parser.o"
LIBRARY_NAME="libmylib.a"

# Compile into object files
COMPILE_CMD="g++ -g -c $SOURCE_FILES -std=c++17 -fsanitize=address"
$COMPILE_CMD
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Make the library file
ARCHIVE_CMD="ar rcs $LIBRARY_NAME $OBJECT_FILES"
$ARCHIVE_CMD
if [ $? -ne 0 ]; then
    echo "Archival failed"
    exit 1
fi

# Delete object files
rm misc.o binaryTree.o graph.o linkedList.o parser.o 

if [ $? -eq 0 ]; then
    echo "Library successfully made"
fi