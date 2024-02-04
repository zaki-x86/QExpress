cmake_minimum_required(VERSION 3.20)

##################################################################################
# Project details

# TODO: Add project documentation website in HOMEPAGE_URL
# TODO : Add project description
# TODO: Configure automated version adjustment from a version.txt file
##################################################################################

project(
  QExpress
  VERSION 0.1.0
  DESCRIPTION ""
  LANGUAGES CXX
)

################## Qt CMake ##################

# Set the directory containing Qt5 to CMAKE_MODULE_PATH
if(MSVC AND WIN32)
    set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.12\\5.12.12\\msvc2017_64" ${CMAKE_PREFIX_PATH})
    set(CMAKE_PROJECT_INCLUDE_BEFORE "C:\\Qt\\Qt5.12.12\\Tools\\QtCreator\\share\\qtcreator\\package-manager\\auto-setup.cmake")
    set(QT5Core_DIR "C:/Qt/Qt5.12.12/5.12.12/msvc2017_64/lib/cmake/Qt5Core")
    set(QT5Network_DIR "C:/Qt/Qt5.12.12/5.12.12/msvc2017_64/lib/cmake/Qt5Network")
    set(QT5_DIR "C:/Qt/Qt5.12.12/5.12.12/msvc2017_64/lib/cmake/Qt5")  
endif(MSVC AND WIN32)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Network REQUIRED)

###############################################

##################################################################################
# MAIN_PROJECT CHECK

# determine if project is built as a subproject (using add_subdirectory) or if it is the main project
##################################################################################

set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
    message(STATUS "${PROJECT_NAME} is being built as a main project")
endif()

##################################################################################
# Setup the include path
##################################################################################

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/scripts/cmake ${CMAKE_MODULE_PATH})
message(STATUS "Module path is set to: ${CMAKE_MODULE_PATH}")
#include(Utils)
#include(CompilerWarnings)

##################################################################################
# Set general project options
##################################################################################
option(${PROJECT_NAME}UseAltNames "Use alternative names for the project, such as naming the include directory all lowercase." ON)

option(EnableTesting "Enable unit tests for the projects (from the test subfolder)." ON)
option(${PROJECT_NAME}EnableCi "Enable CI build targets." OFF)
option(${PROJECT_NAME}EnableDoxygen "Enable Doxygen documentation builds of source." OFF)
option(${PROJECT_NAME}WarningsAsErrors "Treat compiler warnings as errors"  OFF)

# Generate compile_commands.json for clang based tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(${PROJECT_NAME}VerboseOutput "Enable verbose output, allowing for a better understanding of each step taken." ON)
option(${PROJECT_NAME}GenerateExportHeader "Create a `project_export.h` file containing all exported symbols." OFF)
option(${PROJECT_NAME}EnableLTO "Enable Interprocedural Optimization, aka Link Time Optimization (LTO)." OFF)
option(${PROJECT_NAME}EnableCCache "Enable the usage of Ccache, in order to speed up rebuild times." OFF)

# Export all symbols when building a shared library
if(BUILD_SHARED_LIBS)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF)
  set(CMAKE_CXX_VISIBILITY_PRESET hidden)
  set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
endif()

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
else()
    message(STATUS "ccache not found .. skipping")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  if (MINGW OR CMAKE_COMPILER_IS_GNUCXX )    
    add_compile_options("$<$<CONFIG:DEBUG>:-D_DEBUG>")    #this will allow to use same _DEBUG macro available in both Linux as well as Windows - MSCV environment. Easy to put Debug specific code.
  endif ()  
  message(STATUS "_DEBUG macro is added for debugging specific code\n")
endif()

#
# Setup alternative names
#

if(${PROJECT_NAME}UseAltNames)
    message(STATUS "Setting up alt names")
    string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
    string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)
else()
  set(PROJECT_NAME_LOWERCASE ${PROJECT_NAME})
  set(PROJECT_NAME_UPPERCASE ${PROJECT_NAME})
endif()

#
# Prevent building in the source directory
#

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

#
# QExpress specific options
#

option(QExpressServerOnly "build server executable only, rest are built as libraries" OFF)
option(QExpressTemplateEngineOnly "build template engine executable only, rest are built as libraries" OFF)
option(QExpressLibrary "build all QExpress components as libraries" ON)

##################################################################################
# Build CI/CD targets
##################################################################################

if(${PROJECT_NAME}EnableCi)
#  include(ci)
endif()

##################################################################################
# Add configuration related header files
##################################################################################

set(VERSION_CONFIG_IN "${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/version.h.in")
set(VERSION_CONFIG_OUT "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/config/version.h")
set(VERSION_CONFIG_INSTALL_LOCATION "${PROJECT_NAME}/config")

set(${PROJECT_NAME}_CONFIG_IN "${CMAKE_CURRENT_LIST_DIR}/scripts/cmake/config.h.in")
set(${PROJECT_NAME}_CONFIG_OUT "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}/config/config.h")
set(${PROJECT_NAME}_CONFIG_INSTALL_LOCATION "${PROJECT_NAME}/config")

#
# Add version header
#

configure_file(
  ${VERSION_CONFIG_IN}
  ${VERSION_CONFIG_OUT}
  @ONLY
)

install(
  FILES
  ${VERSION_CONFIG_OUT}
  DESTINATION
  ${VERSION_CONFIG_INSTALL_LOCATION}
)

#
# Add config header
## Only if project is built as a main project
#

configure_file(
  ${${PROJECT_NAME}_CONFIG_IN}
  ${${PROJECT_NAME}_CONFIG_IN}
  @ONLY
)

install(
  FILES
  ${${PROJECT_NAME}_CONFIG_IN}
  DESTINATION
  ${${PROJECT_NAME}_CONFIG_INSTALL_LOCATION}
)

message(STATUS "Successfully generated configuration files for ${PROJECT_NAME}.")

##################################################################################
# Get dependencies
##################################################################################
include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    doctest
    PREFIX ${CMAKE_BINARY_DIR}/doctest
    GIT_REPOSITORY https://github.com/doctest/doctest.git
    TIMEOUT 10
    UPDATE_COMMAND ${GIT_EXECUTABLE} pull
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (DOCTEST_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(doctest source_dir)
set(DOCTEST_INCLUDE_DIR ${source_dir}/doctest CACHE INTERNAL "Path to include folder for doctest")
message(STATUS "Doctest path is set to ${DOCTEST_INCLUDE_DIR}")


##################################################################################
# Create targets, setup headers and source files
##################################################################################

#
# Find all headers and implementation files
#
add_subdirectory(QExpress/QHttp)
add_subdirectory(QExpress/HttpServer)
add_subdirectory(QExpress/TemplateEngine)

add_library(${PROJECT_NAME} STATIC)

#
# Link libraries
#
target_link_libraries(${PROJECT_NAME} PRIVATE
                      ${PROJECT_NAME}::QHttp
                      ${PROJECT_NAME}::Server
                      ${PROJECT_NAME}::TemplateEngine
                      Qt5::Core Qt5::Network)


##################################################################################
# Unit testing setup

## TODO Add feature to test each library individually
##################################################################################

if(EnableTesting)
    include(doctest/doctest)
    message(STATUS "Applied aggressive compiler warnings for testing.\n")
    enable_testing()
    message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
    add_subdirectory(test)
endif()

##################################################################################
# Enable Doxygen

## TODO : Export xml docs
##################################################################################

# include(Doxygen)


##################################################################################
# Qt configs
##################################################################################

# Specify source and destination directories
set(QT_BIN_DIR "C:/Qt/Qt5.12.12/5.12.12/msvc2017_64/bin")

# Get list of DLL files in Qt bin directory
file(GLOB QT_DLLS "${QT_BIN_DIR}/*.dll")

# Copy DLLs to app bin directory = temporarily disabled to speed up build
# add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
#     COMMAND ${CMAKE_COMMAND} -E copy ${QT_DLLS} ${CMAKE_CURRENT_BINARY_DIR}/Debug
#     COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Release
#     COMMAND ${CMAKE_COMMAND} -E copy ${QT_DLLS} ${CMAKE_CURRENT_BINARY_DIR}/Release
#     COMMENT "Copying DLL files to ${CMAKE_CURRENT_BINARY_DIR}"
# )
