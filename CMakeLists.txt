project(SEM3_OOP_CPP CXX)
set(CMAKE_CXX_STANDARD 23)
cmake_minimum_required(VERSION 3.23)


# Add libraries
file(GLOB LIB_SOURCES lib/*.cpp)
file(GLOB LIB_HEADERS lib/*.h)
add_library(LIB ${LIB_SOURCES} ${LIB_HEADERS})
target_include_directories(LIB PUBLIC ${PROJECT_SOURCE_DIR}/lib)


# Add executables
add_executable(main main.cpp)
file(GLOB SOURCE_FILES RELATIVE ${PROJECT_SOURCE_DIR}/examples examples/*.cpp)
foreach (SOURCE ${SOURCE_FILES})
    string(REPLACE ".cpp" "" BIN ${SOURCE})
    add_executable(${BIN} examples/${SOURCE})
    target_link_libraries(${BIN} LIB)
endforeach ()


# Add tests
file(GLOB TEST_FILES RELATIVE ${PROJECT_SOURCE_DIR}/lib lib/*.test.cpp)
foreach (TEST_SOURCE ${TEST_FILES})
    string(REPLACE ".test.cpp" "" TEST ${TEST_SOURCE})
    add_executable(test_${TEST} lib/${TEST_SOURCE})
    target_link_libraries(test_${TEST} LIB)
    add_test(${TEST} test_${TEST})
endforeach ()
enable_testing()
