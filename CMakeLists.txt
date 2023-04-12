cmake_minimum_required(VERSION 3.17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(motorGUI)
set(CMAKE_CXX_STANDARD 20)

# Use the package PkgConfig to detect GTK+ headers/library files
set(ENV{PKG_CONFIG_PATH} "./libs/libs/lib/pkgconfig")
FIND_PACKAGE(PkgConfig REQUIRED)
# PKG_CHECK_MODULES(GTK4 REQUIRED gtk+-4.0)

# Setup CMake to use GTK+, tell the compiler where to look for headers
# and to the linker where to look for libraries
# INCLUDE_DIRECTORIES(${GTK4_INCLUDE_DIRS})
# LINK_DIRECTORIES(${GTK4_LIBRARY_DIRS})
pkg_check_modules(gtkmm REQUIRED IMPORTED_TARGET gtkmm-4.0 )

# Add other flags to the compiler
# ADD_DEFINITIONS(${GTK4_CFLAGS_OTHER})

# PKG_CHECK_MODULES(GTKMM4 REQUIRED gtkmm-4.0)
# INCLUDE_DIRECTORIES(${GTKMM4_INCLUDE_DIRS})
# LINK_DIRECTORIES(${GTKMM4_LIBRARY_DIRS})

# ADD_DEFINITIONS(${GTKMM4_CFLAGS_OTHER})

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
add_executable(motorGUI ${SOURCES})

# Link the target to the GTK+ libraries
# TARGET_LINK_LIBRARIES(motorGUI ${GTK4_LIBRARIES})
# TARGET_LINK_LIBRARIES(motorGUI ${GTKMM4_LIBRARIES})
TARGET_LINK_LIBRARIES(motorGUI PkgConfig::gtkmm)
