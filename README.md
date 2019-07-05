
### Building a Ruby C Extension with oniguruma

#### Running on macOS Mojave 10.14.5
```
Ruby version:
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-darwin15]
-----------------------------------
Test C program:
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (3-6)
Hello C!
-----------------------------------
Test Ruby C extension:
checking for -lonig... yes
creating Makefile
compiling myextension.c
linking shared-object myextension.bundle
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (3-6)
Hello Ruby C Extension!
```

#### Running on Debian GNU/Linux 9 (stretch)
```
Ruby version:
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-linux]
-----------------------------------
Test C program:
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (3-6)
Hello C!
-----------------------------------
Test Ruby C extension:
checking for -lonig... yes
creating Makefile
compiling myextension.c
linking shared-object myextension.so
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (0-0)
Hello Ruby C Extension!
```

**NOTE:** `1: (0-0)` (empty match).
