workspace(name = "libtins_bazel")

load("//:versions.bzl", "LIBPCAP_VERSION", "LIBTINS_VERSION")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Rule repository, note that it's recommended to use a pinned commit to a released version of the rules
http_archive(
   name = "rules_foreign_cc",
    sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
    strip_prefix = "rules_foreign_cc-0.9.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/refs/tags/0.9.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

# This sets up some common toolchains for building targets. For more details, please see
# https://github.com/bazelbuild/rules_foreign_cc/tree/main/docs#rules_foreign_cc_dependencies
rules_foreign_cc_dependencies()

#############
#   gtest   #
#############
http_archive(
  name = "com_google_googletest",
  sha256 = "755f9a39bc7205f5a0c428e920ddad092c33c8a1b46997def3f1d4a82aded6e1",
  urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
  strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
)

#############
#  libpcap  #
#############
http_archive(
    name = "com_github_the_tcpdump_group_libpcap",
    build_file = "//:libpcap/BUILD.libpcap.bzl",
    # Here you can use e.g. sha256sum cli utility to compute the sha sum.
    sha256 = "1783ff39f2a6eb99a7625c7ea471782614c94965ea934b6b22ac6eb38db266bc",
    strip_prefix = "libpcap-libpcap-{}".format(LIBPCAP_VERSION),
    url = "https://github.com/the-tcpdump-group/libpcap/archive/refs/tags/libpcap-{}.tar.gz".format(LIBPCAP_VERSION),
)


#############
#  libtins  #
#############
http_archive(
    name = "com_github_mfontanini_libtins",
    build_file = "//:libtins/BUILD.libtins.bzl",
    # Here you can use e.g. sha256sum cli utility to compute the sha sum.
    sha256 = "ff0121b4ec070407e29720c801b7e1a972042300d37560a62c57abadc9635634",
    strip_prefix = "libtins-{}".format(LIBTINS_VERSION),
    url = "https://github.com/mfontanini/libtins/archive/refs/tags/v{}.tar.gz".format(LIBTINS_VERSION),
)
