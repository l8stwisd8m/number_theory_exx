#!/bin/bash

# build project
make

# run each executable
cd visual/
python farey_visual.py
cd ..
