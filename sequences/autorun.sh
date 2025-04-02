#!/bin/bash
BIN_DIR=bin

# build project
make

# run each executable
echo -e "10\n" | ./$BIN_DIR/cw_tree
echo -e "10\n" | ./$BIN_DIR/sb_tree
echo -e "10\n" | ./$BIN_DIR/fs_tree
read -p "Press Enter to continue"
