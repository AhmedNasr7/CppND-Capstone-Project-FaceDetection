cmake_minimum_required(VERSION 3.11.3)

# set(CMAKE_CXX_STANDARD 17)
project(face-detector)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 ")

find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})

add_executable(face-detector 
				src/main.cpp
                src/img.cpp)
target_link_libraries(face-detector ${OpenCV_LIBRARIES})

# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h


set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/build
    )
target_include_directories(
   	${PROJECT_NAME} PUBLIC
    src
 )
 
target_link_libraries(
    face-detector
    ${OpenCV_LIBRARIES}
    )

