cmake_minimum_required(VERSION 2.6)
set(TARGET_NAME decode_sample)

project(${TARGET_NAME})

####################################
## to use C++11
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
####################################

find_package(OpenCV REQUIRED)

set( MFX_API_HOME $ENV{MFX_HOME} )

include_directories(
	${MFX_API_HOME}/include/
	${CMAKE_CURRENT_SOURCE_DIR}
	${OpenCV_INCLUDE_DIRS}
)

message( status "${MFX_API_HOME}/include/")

link_directories(${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${MFX_API_HOME}/lib/lin_x64)

# Create executable programe
add_executable(${TARGET_NAME} main.cpp decode.hpp decode.cpp)

# Link 3rd library
target_link_libraries(${TARGET_NAME} ${OpenCV_LIBS} libmfx.a)

