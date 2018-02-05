#!/bin/bash
make clean
betty-doc *
betty-style *
# betty-style --ignore=FUNCTIONS *
# betty-style --show-types *
make gdb
valgrind ./hls
