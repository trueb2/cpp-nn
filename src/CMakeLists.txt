set(core_SRCS neural/Neuron.cpp neural/Neuron.h neural/NeuralLayer.cpp neural/NeuralLayer.h functions/ActivationFunction.h functions/SigmoidFunction.cpp functions/SigmoidFunction.h io/Input.cpp io/Input.h neural/NeuralNetwork.cpp neural/NeuralNetwork.h io/OutputAdapter.h io/OneHotAdapter.cpp io/OneHotAdapter.h)
add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)
