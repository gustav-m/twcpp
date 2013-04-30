cmake_minimum_required(VERSION 2.8)

project(tw)
set (tw_VERSION_MAJOR 1)
set (tw_VERSION_MINOR 0)

#oauth
FIND_PATH(OAuth_INCLUDE_DIR oauth.h
  /usr/include
  /usr/local/include
  /opt/local/include
  PATH_SUFFIXES oauth
)
 
FIND_LIBRARY(OAuth_LIBRARY
  NAMES ${OAuth_NAMES} liboauth.so liboauth.dylib
  PATHS /usr/lib /usr/local/lib /opt/local/lib
)
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OAuth DEFAULT_MSG OAuth_LIBRARY
OAuth_INCLUDE_DIR)
 
IF(OAuth_FOUND)
  SET(OAuth_LIBRARIES ${OAuth_LIBRARY})
  SET(OAuth_INCLUDE_DIRS ${OAuth_INCLUDE_DIR})
ENDIF(OAuth_FOUND)




#Add include and generate binary
include_directories(${OAuth_INCLUDE_DIR})
add_library(${OAuth_INCLUDE_DIR} "./include" "./include/rapidjson")
TARGET_LINK_LIBRARIES(${OAuth_LIBRARY})
add_executable(tw maintest.cpp tweet.cpp twitter.cpp)

