project(TestAudioPlayback)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


find_package(Qt5Widgets)
find_package(Qt5Multimedia)

FIND_PACKAGE( Boost 1.55 COMPONENTS random REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

aux_source_directory(. SRC_LIST)

set(UI_SOURCES
    mainwindow.ui
)

set (CMAKE_CXX_STANDARD 11)

if(MSVC)
  # Force to always compile with W4
  if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
    string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
  endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  # Update if necessary
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

add_executable(${PROJECT_NAME} ${SRC_LIST} ${UI_SOURCES})

qt5_wrap_ui(UI_GENERATED_HEADERS ${UI_SOURCES})


target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Multimedia)

