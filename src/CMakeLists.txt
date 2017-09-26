
file(GLOB_RECURSE domain "${CMAKE_CURRENT_SOURCE_DIR}/domain/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/domain/*.cpp")

source_group("domain" FILES ${domain})

include_directories("${PROJECT_SOURCE_DIR}/src/util")
include_directories("${PROJECT_SOURCE_DIR}/src/domain")

set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/5.0.2/msvc2010/lib/cmake/")
find_package(Qt5Widgets REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

include_directories(${Qt5Widgets_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS})

add_library(domain ${domain})
target_link_libraries(domain util  ${Qt5Widgets_LIBRARIES})

set_property(TARGET domain PROPERTY FOLDER "domain")

add_subdirectory(app)
add_subdirectory(util)






