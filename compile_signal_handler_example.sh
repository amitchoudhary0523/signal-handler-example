#!/bin/bash

set -x

rm -f signal_handler_example.out

gcc -Wall -Werror -Wextra -Wundef -Wunreachable-code -Winit-self -Wparentheses -Wconversion -Wsign-conversion -Wsign-compare -Werror-implicit-function-declaration -Wmissing-prototypes -Wmissing-declarations -Wformat-security signal_handler_example.c -o signal_handler_example.out

