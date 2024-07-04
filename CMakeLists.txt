cmake_minimum_required(VERSION 3.10)
project(ImageEditor)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# List your project's source files
set(SOURCES
    main.cpp
    utilities.cpp
    image_processing.cpp
    # Add more .cpp files as needed
)

# Add executable
add_executable(ImageEditor ${SOURCES})

# Link OpenCV libraries
target_link_libraries(ImageEditor PRIVATE ${OpenCV_LIBS})

# Specify include directories
target_include_directories(ImageEditor PRIVATE
    ${OpenCV_INCLUDE_DIRS}
    include  # Add your project's include directory if any
)

# Optional: Install target
install(TARGETS ImageEditor DESTINATION bin)

