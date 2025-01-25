#!/bin/bash

BASE_DIR="./"

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
    ["/notification"]="/Notification"
    ["/request"]="/Request"
    ["/response"]="/Response"
)

find "$BASE_DIR" -type f \( -name "*.cpp" -o -name "*.h" \) | while read -r file; do
    for old_dir in "${!DIR_MAP[@]}"; do
        new_dir=${DIR_MAP[$old_dir]}

        sed -i "s|$old_dir/|$new_dir/|g" "$file"
    done
done

echo "All #include statements updated."
