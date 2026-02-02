cmake_minimum_required(VERSION 3.10)
project(LinearAlgebra LANGUAGES CXX)

add_library(Vector
        src/Vector.cpp
)
target_include_directories(Vector
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_executable(LinearAlgebra
    main.cpp
)

target_link_libraries(LinearAlgebra
    PRIVATE
        Vector
)

target_compile_features(LinearAlgebra PRIVATE cxx_std_20)
target_compile_features(Vector PUBLIC cxx_std_20)
