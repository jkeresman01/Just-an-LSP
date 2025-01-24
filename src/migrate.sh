#!/bin/bash

# Base directory for your source files
BASE_DIR="./"  # Adjust this if needed

# Mapping of old lowercase to new uppercase directory names
declare -A DIR_MAP=(
    ["../algo"]="../Algo"
    ["../capabilities"]="../Capabilities"
    ["../core"]="../Core"
    ["../enums"]="../Enums"
    ["../errors"]="../Errors"
    ["../factories"]="../Factories"
    ["../messages"]="../Messages"
    ["../params"]="../Params"
    ["../results"]="../Results"
    ["../rpc"]="../Rpc"
    ["../types"]="../Types"
    ["../utils"]="../Utils"
)

# Find all source code files (.cpp, .h)
find "$BASE_DIR" -type f \( -name "*.cpp" -o -name "*.h" \) | while read -r file; do
    for old_dir in "${!DIR_MAP[@]}"; do
        new_dir=${DIR_MAP[$old_dir]}

        sed -i "s|$old_dir/|$new_dir/|g" "$file"
    done
done

echo "All #include statements updated."

