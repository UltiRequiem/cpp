cmake_minimum_required(VERSION 3.14)

project(cpp-exercises LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

enable_testing()

# add_exercise(<name>)
#   exercises/<name>/ holds <name>.cpp (the solution), main.cpp (the program) and test.cpp (the tests).
#   This builds the program `<name>` and the test `test_<name>`, and registers the test with CTest.
function(add_exercise name)
  set(dir ${CMAKE_CURRENT_SOURCE_DIR}/exercises/${name})

  add_library(${name}_lib STATIC ${dir}/${name}.cpp)
  target_include_directories(${name}_lib PUBLIC ${dir})

  add_executable(${name} ${dir}/main.cpp)
  target_link_libraries(${name} PRIVATE ${name}_lib)

  add_executable(test_${name} ${dir}/test.cpp)
  target_link_libraries(test_${name} PRIVATE ${name}_lib)
  add_test(NAME ${name} COMMAND test_${name})
endfunction()

add_exercise(fibonacci)
add_exercise(triangulos)
