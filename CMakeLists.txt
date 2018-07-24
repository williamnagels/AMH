cmake_minimum_required (VERSION 3.9.1)

project (AsioMessageHandler)
include( CTest )
include(ExternalProject)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_GENERATOR_PLATFORM x86-64)
set(CMAKE_BUILD_TYPE Debug)
set (CMAKE_CXX_STANDARD 17)

if (WIN32)
	set (CMAKE_CXX_FLAGS "/std:c++latest /EHsc")
endif()

set(Boost_DEBUG ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65.0 REQUIRED thread) 


add_executable(examples examples/example1.cpp) 

target_include_directories(examples 
	PRIVATE
		${Boost_INCLUDE_DIRS}
	PUBLIC
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
target_link_libraries(examples ${Boost_LIBRARIES})