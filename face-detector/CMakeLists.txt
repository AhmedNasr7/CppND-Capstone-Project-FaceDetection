cmake_minimum_required(VERSION 3.11.3)

# set(CMAKE_CXX_STANDARD 17)
project(face-detector)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 ")

find_package(OpenCV 4.1 REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})


# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h


add_executable(${PROJECT_NAME} 
				${project_SRCS})

                
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES})


set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_HOME_DIRECTORY}/build
    )
target_include_directories(
   	${PROJECT_NAME} PUBLIC
    src
 )
 
target_link_libraries(
    ${PROJECT_NAME}
    ${OpenCV_LIBRARIES}
    )

