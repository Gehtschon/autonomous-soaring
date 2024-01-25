#!/bin/bash

# Specify the input folder containing .h files
input_folder="SupportFunctions"

# Create output folder if it doesn't exist
output_folder="UML_Diagrams"
mkdir -p "$output_folder"

# Loop through each .h file in the input folder
for header_file in "$input_folder"/*.h; do
    # Extract the filename without extension
    filename=$(basename -- "$header_file")
    filename_no_ext="${filename%.*}"

    # Run hpp2plantuml for the current header file
    hpp2plantuml -i "$header_file" -o "$output_folder/$filename_no_ext.puml" -d
done

