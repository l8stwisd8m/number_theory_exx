#!/bin/bash

# build project
make

# run each executable
echo -e "225/157\n" | ./expansion
echo -e "225/157\n" | ./convergents
echo -e "[1; 2, 3, 4, 5]\n" | ./generalization
read -p "Press Enter to continue"
