# Project to build libtins with Bazel

1. Install bazel with e.g. bazelisk

2. Run the following command:

```
bazelisk test //libtins:test_libtins
```

You might have to run with `sudo` previliges to get around the error `socket: Operation not permitted`.