#!/bin/bash
BIN_DIR=bin

# build project
make

# run each executable
echo -e "225/157\n" | ./$BIN_DIR/expansion
echo -e "225/157\n" | ./$BIN_DIR/convergents
echo -e "[1; 2, 3, 4, 5]\n" | ./$BIN_DIR/generalization
read -p "Press Enter to continue"
