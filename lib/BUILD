cc_library(
    name = "greeter",
    srcs = ["greeter/greeter.cc"],
    hdrs = ["greeter/include/greeter.hpp"],
    visibility = ["//:__pkg__"],
)

cc_library(
    name = "token",
    srcs = ["token/token.cc"],
    hdrs = ["token/include/token.hpp"],
)

cc_library(
    name = "interpreter",
    srcs = ["interpreter/interpreter.cc"],
    hdrs = ["interpreter/include/interpreter.hpp"],
    visibility = ["//:__pkg__"],
    deps = ["//lib:token"]
)