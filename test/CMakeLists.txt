cmake_minimum_required(VERSION 2.8)
enable_testing()

if (GCC)
	add_definitions(-std=c++0x)
endif ()

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/port/${BUILD_SYS})
include_directories(${CMAKE_SOURCE_DIR}/port/${THREAD_SYS})
include_directories(${CMAKE_SOURCE_DIR}/port/${OPERATING_SYS})
include_directories(${CMAKE_SOURCE_DIR}/port/${CPU_ARCH}/${BUILD_SYS})
include_directories(${CMAKE_SOURCE_DIR}/sub/gtest/include)

set(TEST_SRCS
	Anondle.cpp
	Barrier.cpp
	Condition.cpp
	Duration.cpp
	Event.cpp
	Handle.cpp
	Local.cpp
	Mutex.cpp
	Once.cpp
	Retex.cpp
	Semaphore.cpp
	Shorex.cpp
	Strand.cpp
	Thread.cpp
	Thrid.cpp
	Strid.cpp
	create.cpp
	exceptions.cpp
	prioqueue.cpp
	self.cpp
)
add_executable(runner runner.cpp ${TEST_SRCS})
target_link_libraries(runner gtest lisle)

add_test(lisle runner)