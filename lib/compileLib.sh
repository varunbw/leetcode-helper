#!/bin/bash

rm -f misc.o binary_tree.o graph.o linked_list.o args_parser.o stream_parser.o perf.o

SOURCE_FILES="../src/misc.cpp ../src/binary_tree.cpp ../src/graph.cpp ../src/linked_list.cpp ../src/args_parser.cpp ../src/stream_parser.cpp ../src/perf.cpp"
OBJECT_FILES="misc.o  binary_tree.o  graph.o  linked_list.o  args_parser.o stream_parser.o  perf.o"
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
rm -f misc.o binary_tree.o graph.o linked_list.o args_parser.o stream_parser.o perf.o

if [ $? -eq 0 ]; then
    echo "Library successfully made"
fi