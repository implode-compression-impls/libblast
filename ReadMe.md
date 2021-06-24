libblast (modified for better packaging)
========

It is the modified version of [Mark @madler Adler](https://github.com/madler)'s [libblast](https://github.com/madler/zlib/tree/master/contrib/blast).

`libblast` is a free and open-source library implementing decompression of PKWare Data Compression Library (DCL) compressed format.

Modifications:

* splitted into a separate git repo for the convenience of ones who want to inline it as a submodule
* changed repo layout for convenience and clarity
* implemented building with CMake
* implemented packaging with CPack
* implemented hardening with [Hardening.cmake](https://codeberg.org/KOLANICH-libs/Hardening.cmake)


Bindings
--------
* https://codeberg.org/implode-compression-impls/pkblast.py - Python bindings of this lib


Other impls
-----------

* https://github.com/agrif/explode - a reimplementation of this lib in Rust.
* https://codeberg.org/implode-compression-impls/pklib - an impl extracted from [Ladislav Zezula](https://github.com/ladislav-zezula)'s [StormLib](https://github.com/ladislav-zezula/StormLib). Contains a compressor, [`libimplode](https://github.com/implode-compression-impls/pklib/tree/master/src/implode)
* https://github.com/Schallaven/pwexplode - a pure python lib for decompression, but it is under GPL-3.0-or-later
* https://github.com/ShieldBattery/implode-decoder - An impl in JS. Based on `libexplode`.
