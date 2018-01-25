#!/bin/bash
make clean
betty-doc *
betty-style *
make gdb
valgrind ./hls
