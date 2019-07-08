
### Building a Ruby C Extension with oniguruma

I'm having a problem when I try to include oniguruma in my ruby C extension. The regexp `foo([a-z]+)` will not match `foobar` when running in _Debian GNU/Linux 9_.

I know ruby uses a modified version of oniguruma since 2.0 but if there is a collision/mismatch, why does it work when running in OSX?

Maybe someone with more knowledge in ruby c extensions/onigmo/onig can point me in the right direction?

### Tests

I kept the tests simple and the line to look for is in

#### Running on macOS Mojave 10.14.5

Run using (in osx):
```shell
git clone https://github.com/voke/ruby-onig-issue
cd ruby-onig-issue
bash run_all_tests.sh
```

```
Ruby version:
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-darwin15]
-----------------------------------
Test C program:
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (3-6)
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
```

#### Running on Debian GNU/Linux 9 (stretch)

Run using:
```shell
git clone https://github.com/voke/ruby-onig-issue
cd ruby-onig-issue
docker build -t ruby-onig .
docker run -it ruby-onig
```

```
Ruby version:
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-linux]
-----------------------------------
Test C program:
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (3-6)
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
```

**NOTE:** `1: (0-0)` (empty match).
