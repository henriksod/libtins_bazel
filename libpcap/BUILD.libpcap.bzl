load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "libpcap",
    lib_source = ":all_srcs",
    out_shared_libs = ["libpcap.so.1"],
    visibility = ["//visibility:public"],
)