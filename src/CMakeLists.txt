set(core_SRCS neural/Neuron.cpp neural/Neuron.h neural/layers/NeuralLayer.cpp neural/layers/NeuralLayer.h functions/ActivationFunction.h functions/SigmoidFunction.cpp functions/SigmoidFunction.h io/Input.cpp io/Input.h neural/NeuralNetwork.cpp neural/NeuralNetwork.h io/OutputAdapter.h io/OneHotAdapter.cpp io/OneHotAdapter.h neural/layers/OutputLayer.cpp neural/layers/OutputLayer.h io/Dataset.cpp io/Dataset.h enums/Separability.h enums/Separability.cpp)
add_library(core ${core_SRCS})
add_executable(exe main.cpp)
target_link_libraries(exe core)
