load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake")
load("@libtins_bazel//:versions.bzl", "LIBTINS_VERSION")

filegroup(
    name = "all_srcs",
    srcs = glob(["**"]),
)

cmake(
    name = "libtins",
    cache_entries = {
        "PCAP_LIBRARY": "$EXT_BUILD_DEPS/libpcap/lib",
        "PCAP_INCLUDE_DIR": "$EXT_BUILD_DEPS/libpcap/include",
    },
    lib_source = ":all_srcs",
    out_shared_libs = ["libtins.so.{}".format(LIBTINS_VERSION)],
    deps = ["@com_github_the_tcpdump_group_libpcap//:libpcap"],
    visibility = ["//visibility:public"],
)