add_library(simpsonLib STATIC simpson.cpp)

target_include_directories(simpsonLib PUBLIC ./)

install(FILES simpson.hpp DESTINATION include)