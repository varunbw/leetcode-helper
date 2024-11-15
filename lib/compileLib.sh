#!/bin/bash

rm -f misc.o binaryTree.o graph.o linkedList.o parser.o perf.o

SOURCE_FILES="../src/misc.cpp ../src/binaryTree.cpp ../src/graph.cpp ../src/linkedList.cpp ../src/parser.cpp ../src/perf.cpp"
OBJECT_FILES="misc.o   binaryTree.o   graph.o   linkedList.o   parser.o   perf.o"
LIBRARY_NAME="liblch.a"

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
rm -f misc.o binaryTree.o graph.o linkedList.o parser.o perf.o

if [ $? -eq 0 ]; then
    echo "Library successfully made"
fi