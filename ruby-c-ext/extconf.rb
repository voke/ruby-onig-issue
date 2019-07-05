#!/usr/bin/env ruby
require 'mkmf'

have_library('onig')

create_makefile 'myextension'
