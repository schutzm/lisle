################################################################################
# CMake build script for Lisle.
#

# BUILD_SHARED_LIBS is a standard CMake variable, but we declare it here to
# make it prominent in the GUI.
option(BUILD_SHARED_LIBS "Build shared library (DLL)." OFF)

# When other libraries are using a shared version of runtime libraries,
# Lisle also has to use one.
option(lisle_force_shared_crt "Use shared (DLL) run-time lib even when Lisle is built as static lib." OFF)

option(lisle_build_tests "Build all of lisle's own tests." OFF)

################################################################################
#
# Project-wide settings

if (BUILD_SHARED_LIBS)
	project(Lisle-Shared)
else ()
	project(Lisle-Static)
endif ()
set(LISLE_VERSION_MAJOR 4)
set(LISLE_VERSION_MINOR 0)
set(LISLE_VERSION_MICRO 0)
cmake_minimum_required(VERSION 2.8)
enable_testing()

include(cmake/internal_utils.cmake)
config_compiler_and_linker()  # Defined in internal_utils.cmake.

include(cmake/internal_utils.cmake)

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE ${CMAKE_CURRENT_SOURCE_DIR}/COPYING)
set(CPACK_PACKAGE_VERSION_MAJOR ${LISLE_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${LISLE_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_MICRO ${LISLE_VERSION_MICRO})
include(CPack)

find_package(Threads REQUIRED)

set(BUILD_SYS gcc)
if (MSVC)
	set(BUILD_SYS msvc)
endif ()
if (BUILD_SYS MATCHES gcc)
	set(GCC 1)
endif ()

set(CPU_ARCH ${CMAKE_SYSTEM_PROCESSOR})
if (CPU_ARCH MATCHES "^x86*")
	set(CPU_ARCH x86)
endif ()
if (CPU_ARCH MATCHES "^AMD64*")
	set(CPU_ARCH x86)
endif ()

set(OPERATING_SYS ${THREAD_SYS})
if (APPLE)
	set(OPERATING_SYS darwin)
endif ()

set(THREAD_SYS)
if (CMAKE_USE_PTHREADS_INIT)
	set(THREAD_SYS posix)
elseif (CMAKE_USE_WIN32_THREADS_INIT)
	set(THREAD_SYS windows)
endif ()

add_subdirectory(sub/gtest)
add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(include/lisle)
add_subdirectory(port/${THREAD_SYS})