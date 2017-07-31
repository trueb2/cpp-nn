set(core_SRCS foo/Bar.cpp foo/Bar.h)
add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)
