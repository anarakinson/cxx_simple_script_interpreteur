cmake_minimum_required(VERSION 3.5)


project(interpreteur)


add_executable(
    main
    run_test.cpp 
    tests/lexer_test.cpp 
    tests/parser_test.cpp 
    lexer/lexer.cpp
)

target_include_directories(
    main
    PUBLIC  
    lexer 
    parser 
    tests
    ${CMAKE_CURRENT_SOURCE_DIR}
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