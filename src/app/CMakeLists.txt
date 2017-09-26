set(app_included_dirs "${CMAKE_CURRENT_SOURCE_DIR}/main"
	"${CMAKE_CURRENT_SOURCE_DIR}/ui"
	"${CMAKE_CURRENT_SOURCE_DIR}/commands")
	
include_directories(${app_included_dirs})

file(GLOB_RECURSE main "${CMAKE_CURRENT_SOURCE_DIR}/main/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/main/*.cpp")
file(GLOB_RECURSE ui "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/ui/*.cpp")
file(GLOB_RECURSE commands "${CMAKE_CURRENT_SOURCE_DIR}/commands/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/commands/*.cpp")

add_executable(app ${main} ${ui} ${commands})

source_group("main" FILES ${main})
source_group("ui" FILES ${ui})
source_group("commands" FILES ${commands})

target_link_libraries(app util ${Qt5Widgets_LIBRARIES} domain)
