project(tree)

file(GLOB TreeSources "src/*.cpp")

add_library(tree ${TreeSources})

set(TREE_PUBLIC_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(TREE_PRIVATE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(tree
	PUBLIC $<BUILD_INTERFACE:${TREE_PUBLIC_INCLUDE_PATH}>
	PRIVATE $<BUILD_INTERFACE:${TREE_PRIVATE_INCLUDE_PATH}>)

add_subdirectory(test)
