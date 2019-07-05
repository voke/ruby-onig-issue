#!/bin/sh

echo "Ruby version:"
ruby --version

echo '-----------------------------------'

echo "Test C program:"
cd c-program/ && bash install_and_run.sh

cd ..

echo '-----------------------------------'

echo "Test Ruby C extension:"
cd ruby-c-ext/ && ./install_and_run.sh
