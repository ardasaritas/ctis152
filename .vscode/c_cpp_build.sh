#!/bin/bash

# Get filename
filename="$1"

# Check if filename provided
if [[ -z "$filename" ]]; then
    echo "Error: No source file provided."
    echo "Usage: ./c_cpp_build.sh <sourcefile.c/.cpp>"
    exit 1
fi

# Get basename and extension
basename="${filename%.*}"
ext="${filename##*.}"

# Clean previous executable if exists
if [[ -f "$basename.out" ]]; then
    rm "$basename.out"
fi

# Compile based on extension
if [[ "$ext" == "c" ]]; then
    clang -g "$filename" -o "$basename.out"
elif [[ "$ext" == "cpp" ]]; then
    clang++ -g "$filename" -o "$basename.out"
else
    echo "Error: Unsupported file extension '$ext'. Only .c and .cpp are supported."
    exit 2
fi

# Check compilation success
if [[ $? -eq 0 ]]; then
    echo "✅ Build successful. Executable created: $basename.out"
else
    echo "❌ Build failed."
    exit 3
fi
