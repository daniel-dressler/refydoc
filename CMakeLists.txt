cmake_minimum_required (VERSION 2.7)

if ( WIN32 )
    message( FATAL_ERROR "Windows not supported!" )
endif()

################################################################################
#                            Toolchain config
################################################################################
# Adds a ton of warnings to the build. 
# NOTE: ALL CODE SHOULD COMPILE CLEANLY WITH THIS ON!
option(CONFIG_ALL_WARNINGS "Add warnings for GCC/Clang" ON)

# Unit tests require the boost test library.
# And a version that also uses the configured standard library
option(CONFIG_UNIT_TESTS "build unit tests" ON)

# Source files in header only source directories are uneeded.
# When this option is on those files are removed from the build.
# The disadvantage of this is it does not perform any include tests
# on the build but the build is MUCH faster.
option(CONFIG_HEADER_TESTS
        " Build source files that simple include the matching header.
          This is used in  header only librarys to check for errors" ON)


################################################################################
#                            PROJECT Refydoc
################################################################################
# need C to get the pthreads library 
project(Refydoc CXX C)

################################################################################
#                       Toolchain config (Post-project)
################################################################################

if (DEFINED ENV{REFYDOC_CMAKE_OPTIONS})
    message(STATUS "Configuring with REFYDOC_CMAKE_OPTIONS: $ENV{REFYDOC_CMAKE_OPTIONS}")
endif()

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE DEBUG CACHE STRING
       "Choose the type of build"
       FORCE )
endif()
set( CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG" )
set( CMAKE_C_FLAGS_RELEASE "-O2 -DNDEBUG" )
set( CMAKE_C_FLAGS_DEBUG " -g -fno-omit-frame-pointer  " )
set( CMAKE_CXX_FLAGS_DEBUG " -g -fno-omit-frame-pointer " )
set( CMAKE_C_FLAGS_TEST " -g -fno-omit-frame-pointer  -fno-elide-constructors -fprofile-arcs -ftest-coverage")
set( CMAKE_CXX_FLAGS_TEST " -g -fno-omit-frame-pointer -fno-elide-constructors -fprofile-arcs -ftest-coverage")


message( STATUS "Configuring for Build Type: ${CMAKE_BUILD_TYPE}")

set(CXX_WARNING_FLAGS " -Wall -Wextra -pedantic ")
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} ${CXX_VERSION_FLAGS} ${CXX_WARNING_FLAGS}")

if (DEFINED ENV{CXXFLAGS})
    message(STATUS "Configuring with extra CXX flags: $ENV{CXXFLAGS}")
endif()
if (DEFINED ENV{LDFLAGS})
    message(STATUS "Configuring with extra LD flags: $ENV{LDFLAGS}")
endif()
################################################################################
##                         Compiler Detection
################################################################################
if ( ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" )
    message(STATUS "Configuring for Compiler: GCC")
    set( CXX_COMPILER_GCC TRUE )
    set( CXX_COMPILER_CLANG FALSE )
elseif( ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang" )
    message(STATUS "Configuring for Compiler: Clang")
    set( CXX_COMPILER_GCC FALSE )
    set( CXX_COMPILER_CLANG TRUE )
else()
    message( FATAL_ERROR "Compiler not supported! (${CMAKE_CXX_COMPILER_ID})" )
endif()

################################################################################
##                        Compiler Configuration
################################################################################
if ( CXX_COMPILER_GCC )
   
    # check min version
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.8.0")
        message(FATAL_ERROR "Insufficient GCC Version")
    elseif(CMAKE_CXX_COMPILER_VERSION VERSION_EQUAL "4.9.0"
        OR CMAKE_CXX_COMPILER_VERSION VERSION_GREATER "4.9.0")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -fdiagnostics-color=auto ")
    endif()

    # Check C++1y config
    if (CONFIG_CXX1Y AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "4.9.0")
        message(FATAL_ERROR "Insufficient GCC Version for C++1y")
    endif()

    set(CXX_GCC_FLAGS " -fmax-errors=5 " )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_GCC_FLAGS}")

elseif( CXX_COMPILER_CLANG ) ###################################################

    if (CMAKE_CXX_COMPILER_VERSION STREQUAL "")
        message(WARNING "Failed to detect clang version")
    elseif (CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.3")
        message(FATAL_ERROR "Insufficient Clang Version: ${CMAKE_CXX_COMPILER_VERSION} (Requires >= 3.3)")
    endif()

    if (CONFIG_CXX1Y AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS "3.4")
        message(FATAL_ERROR "Insufficient Clang Version for C++1y")
    endif()

    set(CXX_CLANG_FLAGS " -ferror-limit=3 " )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_CLANG_FLAGS}")

endif()


#################################################################################
if (CONFIG_ELIB_ASSERT_CONFIG)
    add_definitions( -DELIB_ASSERT_CONFIG )
endif()

if (CONFIG_ELIB_COVERITY_SCAN)
    message( STATUS "Configuring for Coverity Scan")
    add_definitions( -DELIB_CONFIG_COVERITY_SCAN )
   add_definitions( -include config/gcc_4_8_2_coverity_scan_missing_builtins.hpp)
endif()

################################################################################
#                          Build & Installation Config
################################################################################

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "/usr" 
        CACHE PATH "library install prefix" FORCE)
    MESSAGE(STATUS "Configuring for Install Prefix: ${CMAKE_INSTALL_PREFIX}")
endif()

set(headerDir ${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/elib)
set(ELIB_LIBRARIES_DIR "${CMAKE_CURRENT_LIST_DIR}/elib/bin")
set(ELIB_LIBRARIES "-L${ELIB_LIBRARIES_DIR} -Wl,-rpath -Wl,${ELIB_LIBRARIES_DIR} -lelib")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

################################################################################
#                           Macros & Functions
################################################################################

macro(set_dot_dir)
    set(dotDir ${CMAKE_CURRENT_LIST_DIR})
endmacro(set_dot_dir)

# Use the library configuration option to selectivly 
# build build a library. 
macro(include_library_if Pred CFile)
    if (${Pred})
        include(${CFile})
        add_definitions( -D${Pred} )
    endif()
endmacro(include_library_if)

macro(include_build_dir BuildDir)
    set_dot_dir()
    include(${dotDir}/${BuildDir}/build.cmake)
endmacro(include_build_dir)

macro(include_unit_tests)
    set_dot_dir()
    include(${dotDir}/unit_tests/build.cmake)
endmacro(include_unit_tests)

macro(include_header_tests)
    set_dot_dir()
    include(${dotDir}/header_tests/build.cmake)
endmacro(include_header_tests)


# adds all c++ file in the CWD
macro(add_library_src)
    set_dot_dir()
    aux_source_directory(${dotDir} _library_src)
    list(APPEND LIBRARY_SRC ${_library_src})
endmacro(add_library_src)

macro(add_header_test_src)
    set_dot_dir()
    aux_source_directory(${dotDir} _header_src)
    list(APPEND HEADER_TEST_SRC ${_header_src})
endmacro(add_header_test_src)

macro(add_unit_test_src)
    set_dot_dir()
    aux_source_directory(${dotDir} _unit_test_src)
    list(APPEND UNIT_TEST_SRC ${_unit_test_src})
endmacro(add_unit_test_src)

# Always add source and unit tests
macro(add_src)
    add_library_src()
    include_header_tests()
    include_unit_tests()
endmacro(add_src)

macro(stringify_list m_list dest)
    string(REPLACE ";" " " ${dest} "${m_list}")
endmacro(stringify_list)

macro(add_flags to)
    stringify_list("${ARGN}" _TMP)
    set(${to} "${${to}} ${_TMP}")
endmacro(add_flags)


################################################################################
add_subdirectory(src)
