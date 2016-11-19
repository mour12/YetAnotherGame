cmake_minimum_required(VERSION 2.8)

add_definitions(--std=c++11)

# Set up your project name.
project(YetAnotherGame)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5OpenGL REQUIRED)

# Set up the main source folder.
set(SOURCE_ROOT src)
# Scan source folder to find all sources and put the result to SRC_LIST.
aux_source_directory(${SOURCE_ROOT} SRC_LIST)

# JSON
add_subdirectory(3party/jsoncpp)
include_directories(3party/jsoncpp/include)
aux_source_directory(3party/jsoncpp/src/lib_json JSONCPP_SRC)

#XML
add_subdirectory(3party/pugixml)
include_directories(3party/pugixml/src)
aux_source_directory(3party/pugixml/src PUGIXML_SRC)

# Create executable by SRC_LIST.
file(GLOB HEADERS ${SOURCE_ROOT}/*.hpp)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEADERS} ${QT_WRAPPED_SRC} ${JSONCPP_SRC} ${PUGIXML_SRC})

# Qt modules
qt5_use_modules(${PROJECT_NAME} Widgets OpenGL)

# Add subdirectory with Google Test Library.
add_subdirectory(3party/googletest)

# Enable unit testing.
enable_testing()
# Set up testing project name.
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
# Add include directories for testing project.
include_directories(3party/googletest/googletest/include ${SOURCE_ROOT})
# Set up testing project.
set(TESTS_SOURCE_ROOT tests)
aux_source_directory(${TESTS_SOURCE_ROOT} TEST_SRC_FILES)
set(TEST_SRC_FILES ${SRC_LIST} ${TEST_SRC_FILES})
list(REMOVE_ITEM TEST_SRC_FILES src/main.cpp)
qt5_wrap_cpp(QT_WRAPPED_TEST_SRC ${TEST_SRC_FILES})
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${QT_WRAPPED_TEST_SRC})
# Link gtest and gtest_main libraries.
target_link_libraries(${PROJECT_TEST_NAME} gtest gtest_main)
qt5_use_modules(${PROJECT_TEST_NAME} Widgets OpenGL)
# Finish tests setting up.
add_test(test ${PROJECT_TEST_NAME})

# Copy files from data folder to current binary directory
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})