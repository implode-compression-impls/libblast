Tests
=====

These tests are executed using fileTestSuite.

To execute tests you basically need:

* `fileTestSuite`
* `

Then run something like (the example assummes Ubuntu, but the software involved is cross-platform)

```bash
testabs-runner /usr/lib/x86_64-linux-gnu/libTestAbsBackend_GTest.so /usr/lib/x86_64-linux-gnu/libFileTestSuite_runner.so ./libtests.so ../../tests/testDataset
```

* `testabs-runner` is the TestAbs CLI frontend.
* `/usr/lib/x86_64-linux-gnu/libTestAbsBackend_GTest.so` is a `TestAbs` backend
* `/usr/lib/x86_64-linux-gnu/libFileTestSuite_runner.so` is a `fileTestSuite` testing module for `TestAbs`
* `./libtests.so` is the library built here.
* `../../tests/testDataset` is the repo with tests, conforming with `fileTestSuite` spec. Since we are in `build/tests` dir, and our suite is submoduled into `tests/testDataset`, the path is such.
