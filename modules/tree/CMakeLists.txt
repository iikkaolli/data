project(tree)

file(GLOB TreeSources "src/*.cpp")

add_library(tree ${TreeSources})

target_include_directories(tree
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)

