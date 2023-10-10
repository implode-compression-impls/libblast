libblast (modified for better packaging)
========
**We have moved to https://codeberg.org/implode-compression-impls/libblast, grab new versions there.**

Under the disguise of "better security" Micro$oft-owned GitHub has [discriminated users of 1FA passwords](https://github.blog/2023-03-09-raising-the-bar-for-software-security-github-2fa-begins-march-13/) while having commercial interest in success of [FIDO 1FA specifications](https://fidoalliance.org/specifications/download/) and [Windows Hello implementation](https://support.microsoft.com/en-us/windows/passkeys-in-windows-301c8944-5ea2-452b-9886-97e4d2ef4422) which [it promotes as a replacement for passwords](https://github.blog/2023-07-12-introducing-passwordless-authentication-on-github-com/). It will result in dire consequencies and is competely inacceptable, [read why](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

If you don't want to participate in harming yourself, it is recommended to follow the lead and migrate somewhere away of GitHub and Micro$oft. Here is [the list of alternatives and rationales to do it](https://github.com/orgs/community/discussions/49869). If they delete the discussion, there are certain well-known places where you can get a copy of it. [Read why you should also leave GitHub](https://codeberg.org/KOLANICH/Fuck-GuanTEEnomo).

---

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
