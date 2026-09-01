cmake_minimum_required(VERSION 3.5)

project(simpson_cmake)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(lib)

add_executable(simpson main.cpp)
target_link_libraries(simpson simpsonLib)

set(RESULTS_DIR ${CMAKE_CURRENT_BINARY_DIR}/data)

add_custom_target(run_simpson
    COMMAND ${CMAKE_COMMAND} -E make_directory ${RESULTS_DIR}
    COMMAND simpson > ${RESULTS_DIR}/result.txt
    DEPENDS simpson
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Running simpson and writing output to data/result.txt"
    VERBATIM
)

add_custom_target(plot_simpson ALL
    COMMAND echo "set terminal png; set output 'data/result.png'; plot 'data/result.txt' with lines" | gnuplot
    DEPENDS run_simpson
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Plotting convergence in data/result.png"
    VERBATIM
)