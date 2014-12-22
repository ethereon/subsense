SET(PROJECT_NAME Subsense)
PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.3)

set(EXTRA_INC_DIRS
  /usr/local/include
)

LIST(APPEND LINK_LIBS
    opencv_core
    opencv_video
    opencv_features2d
    opencv_imgproc
)

set(SS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Ofast")

 if(APPLE)
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
    set(CMAKE_INSTALL_NAME_DIR ${CMAKE_INSTALL_PREFIX}/lib)
    set(CMAKE_MACOSX_RPATH ON)
    set(CMAKE_SKIP_BUILD_RPATH FALSE)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
    set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
    set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

file(GLOB LIB_SRC_FILES ${SS_DIR}/Subsense/*.cpp)
include_directories(${SS_DIR} ${EXTRA_INC_DIRS})

add_library(Subsense SHARED ${LIB_SRC_FILES})
target_link_libraries(Subsense ${LINK_LIBS})
