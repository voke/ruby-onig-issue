#!/bin/bash

if [[ "$OSTYPE" == "darwin"* ]]; then
  gcc -Wall -o myextension.o -c myextension.c
  gcc -Wall -dynamic -bundle -o myextension.bundle myextension.o -lonig
else
  gcc -Wall -fPIC -o myextension.o -c myextension.c
  gcc -Wall -shared -o myextension.so myextension.o -lonig
fi

ruby test.rb

# Cleanup
rm -f myextension.o myextension.so myextension.bundle
