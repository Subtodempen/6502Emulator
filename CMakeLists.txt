cmake_minimum_required(VERSION 3.10)
project(Emu)
set(CMAKE_CXX_STANDARD 23)

# Add source files
set(SOURCES 
  src/CPU/AddressingModes.cpp
  src/CPU/Instructions.cpp
  src/CPU/CPU.cpp
  src/CPU/InstructionsImpl.cpp
  src/Memory/memory.cpp
  )

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)
add_compile_options(-g)

# Create executable
add_executable(Emu src/main.cpp ${SOURCES})

# Link libraries
target_link_libraries(Emu ${CMAKE_DL_LIBS})

# google Test
enable_testing()

add_executable(
  cpuTest
  test/test.cpp
  ${SOURCES}
)
target_link_libraries(
  cpuTest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cpuTest)

