#!/bin/bash
BIN_DIR=bin

# build project
make

# run each executable
echo -e "21\n12\n" | ./$BIN_DIR/bezout
read -p "Press Enter to continue"
