set(core_SRCS neurons/Neuron.cpp neurons/Neuron.h)
add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)
