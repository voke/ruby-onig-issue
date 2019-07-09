
## Building a Ruby C Extension with oniguruma

I'm having a problem when I try to include oniguruma (v6.9.2) in my ruby C extension. The regexp `foo([a-z]+)` with input `foobar` will not capture `bar` when running in _Debian GNU/Linux 9_.

I know ruby uses a modified version of oniguruma since 2.0 but if there is a collision/mismatch, why does it work when running in _Darwin_?

Maybe someone with more knowledge in ruby c extensions/onigmo/onig/compiling can point me in the right direction?

## Tests

I used the sample code taken from https://github.com/kkos/oniguruma/blob/master/sample/simple.c to write the tests.

There is two tests. A simple C program using oniguruma to see expected output and another one written as a Ruby c extension.

I compiled oniguruma v6.9.2 with _DEBUG_ flags to see if the function is actually called. I skipped the `extconf.rb` file
and just compiled using gcc since there were no difference in the output.

**A successful test should output:**
```
0: (0-6)
1: (3-6)
```
to indicate a correct match.

### Running on macOS Mojave 10.14.5

- Dependency: [oniguruma 6.9.2](https://github.com/kkos/oniguruma)

Run using (in osx):
```shell
git clone https://github.com/voke/ruby-onig-issue
cd ruby-onig-issue
bash run_all_tests.sh
```
**Output:**
```
Ruby version:
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-darwin15]
-----------------------------------
Test C program:
oniguruma version: 6.9.2

PATTERN: /foo([a-z]+)/
onig_search (entry point): str: 0x10b853f5a, end: 6, start: 0, range: 6
onig_search(apply anchor): end: 6, start: 0, range: 6
forward_search_range: str: 0x10b853f5a, end: 0x10b853f60, s: 0x10b853f5a, range: 0x10b853f60
forward_search_range success: low: 0, high: 0, dmin: 0, dmax: 0
match at 0
0: (0-6)
1: (3-6)
-----------------------------------
Test Ruby C extension:
Run test with ruby v2.5.1:
oniguruma version: 6.9.2

PATTERN: /foo([a-z]+)/
onig_search (entry point): str: 0x11035bf5e, end: 6, start: 0, range: 6
onig_search(apply anchor): end: 6, start: 0, range: 6
forward_search_range: str: 0x11035bf5e, end: 0x11035bf64, s: 0x11035bf5e, range: 0x11035bf64
forward_search_range success: low: 0, high: 0, dmin: 0, dmax: 0
match at 0
0: (0-6)
1: (3-6)
```

Successful! Everything works as expected.

### Running on Debian GNU/Linux 9

Run using:
```shell
git clone https://github.com/voke/ruby-onig-issue
cd ruby-onig-issue
docker build -t ruby-onig .
docker run -it ruby-onig
```
**Output:**
```
Ruby version:
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-linux]
-----------------------------------
Test C program:
oniguruma version: 6.9.2

PATTERN: /foo([a-z]+)/
onig_search (entry point): str: 0x55cc4adadebf, end: 6, start: 0, range: 6
onig_search(apply anchor): end: 6, start: 0, range: 6
forward_search_range: str: 0x55cc4adadebf, end: 0x55cc4adadec5, s: 0x55cc4adadebf, range: 0x55cc4adadec5
forward_search_range success: low: 0, high: 0, dmin: 0, dmax: 0
match at 0
0: (0-6)
1: (3-6)
-----------------------------------
Test Ruby C extension:
Run test with ruby v2.5.1:
oniguruma version: 6.9.2
match at 0
0: (0-6)
1: (0-0)
```

Failure! `1: (0-0)` indicates no match. And no debugging output is present.
