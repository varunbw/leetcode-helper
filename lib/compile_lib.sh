#!/bin/bash

rm -f liblch.a

# Array of filenames without paths
FILES=(
    "misc"
    "binary_tree"
    "graph"
    "linked_list"
    "args_parser"
    "stream_parser"
    "perf"
)

LIBRARY_NAME="liblch.a"

# Construct a string of source file paths
SOURCE_FILES=""
for FILE in "${FILES[@]}"; do
    SOURCE_FILES+=" ../src/$FILE.cpp"
done

# Compile into object files in one g++ call
g++ -g -c -std=c++17 -fsanitize=address $SOURCE_FILES
if [ $? -ne 0 ]; then
    echo "Compilation failed"
    exit 1
fi

# Create a list of object files
OBJECT_FILES=$(printf "%s.o " "${FILES[@]}")

# Make the library file
ar rcs $LIBRARY_NAME $OBJECT_FILES
if [ $? -ne 0 ]; then
    echo "Archival failed"
    exit 1
fi

# Delete object files
rm -f $OBJECT_FILES

if [ $? -eq 0 ]; then
    echo "Library successfully made"
fi
