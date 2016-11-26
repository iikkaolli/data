project(TreeTests)

enable_testing()
include_directories("/d/Programming/googletest/build/stage/include")
link_directories("/d/Programming/googletest/build/stage/lib")

file(GLOB TreeTestSources "*.cpp")

add_executable(TreeTests ${TreeTestSources})
target_include_directories(TreeTests
	PUBLIC $<BUILD_INTERFACE:${TREE_PUBLIC_INCLUDE_PATH}>
	PRIVATE $<BUILD_INTERFACE:${TREE_PRIVATE_INCLUDE_PATH}>)

target_link_libraries(TreeTests PRIVATE libgtest)

add_test(NAME TreeTests
         COMMAND TreeTests)  
