# hexxer

[![build status](https://secure.travis-ci.org/dcousens/hexxer.png)](http://travis-ci.org/dcousens/hexxer)
[![Version](https://img.shields.io/npm/v/hexxer.svg)](https://www.npmjs.org/package/hexxer)

A streaming hex encoding/decoding tool,  pipes `stdin` to `stdout`.
Throws via `assert` on invalid characters (platform dependent, could be a SEGV).


## Examples

Decoding
``` bash
> echo "6a" | hexxer -d
j
```

Encoding
``` bash
> echo "j" | hexxer
6a0a

> echo -n "j" | hexxer
6a
```
