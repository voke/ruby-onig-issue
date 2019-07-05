#!/bin/sh

# Compile & run
ruby extconf.rb && make && ruby test.rb

# Cleanup
make clean && rm Makefile
