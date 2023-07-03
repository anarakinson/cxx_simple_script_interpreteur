cmake_minimum_required(VERSION 3.5)


project(interpreteur)


add_executable(
    main
    run_test.cpp 
)

include_directories(
    lexer 
    parser 
    PUBLIC  
    ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(
    main PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)



if(
    CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU"
)
    target_compile_options(
        main 
        PRIVATE
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(
        main
        PRIVATE 
        /EHsc
        /W4
        /WX
    )
endif()