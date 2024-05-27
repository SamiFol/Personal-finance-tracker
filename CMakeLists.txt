cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(FinanceTracker VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory to the search path for include files
include_directories(include)

# Add the executable
add_executable(finance_tracker src/main.cpp)

# Link pthread library
target_link_libraries(finance_tracker pthread)

