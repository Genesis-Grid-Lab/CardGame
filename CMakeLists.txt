cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# build output directories

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(CMAKE_PDB_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH $<0:>${CMAKE_BINARY_DIR}/bin)

# cpp standard options

set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)

project(CardGame)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/inlucde/*.h)


if(UNIX)
add_executable(${PROJECT_NAME} ${sources} ${headers})
endif(UNIX)

if(WIN32)
add_executable(${PROJECT_NAME} WIN32 ${sources} ${headers})
endif(WIN32)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL_image)


#include directories
target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2/include
  ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL_image/include
  #${CONAN_INCLUDE_DIRS}
)

# link directories
target_link_directories(${PROJECT_NAME} PUBLIC
  ${CONAN_LIB_DIRS}
)

#link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
  SDL2
  SDL2main
  SDL2_image
  #${CONAN_LIBS}
)

# copy resources
if(EXISTS ${CMAKE_SOURCE_DIR}/Assets)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND 
        ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/Assets
        ${EXECUTABLE_OUTPUT_PATH}/Assets
    )
else()
    message(WARNING "[WARNING] no Assets directory!")
endif()
