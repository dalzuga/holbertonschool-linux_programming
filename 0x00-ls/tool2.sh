#!/bin/bash
mkdir test
cd test
cd .. && make gdb && cp hls test && cd test
touch abc abC aBc aBC
echo "ls:" && ls | fmt && echo "hls:" && ./hls
