# InterpreterCC

A simple REPL for adding and subtracting two numbers written in C++. Uses the [Bazel](https://bazel.build) build system. Follows the [Google Style Guide](https://google.github.io/styleguide/cppguide.html), well almost.

## Building
1. Clone the repo
2. Make sure you have bazel installed
3. Build the repl
```sh
$ bazel build repl
```
4. Run it
```sh
$ ./bazel-bin/repl
```