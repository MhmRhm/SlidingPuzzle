add_library(sliding_puzzle_obj OBJECT
	sliding_puzzle.cpp
)
target_compile_options(sliding_puzzle_obj
	PRIVATE ${DEFAULT_CXX_COMPILE_FLAGS}
	PRIVATE ${DEFAULT_CXX_OPTIMIZE_FLAG}
)
target_include_directories(sliding_puzzle_obj INTERFACE
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)
set_target_properties(sliding_puzzle_obj PROPERTIES
    PUBLIC_HEADER src/sliding_puzzle/include/sliding_puzzle/sliding_puzzle.h
    POSITION_INDEPENDENT_CODE 1
)
target_link_libraries(sliding_puzzle_obj PRIVATE precompiled)
BuildInfo(sliding_puzzle_obj)

add_library(sliding_puzzle_shared SHARED)
target_link_libraries(sliding_puzzle_shared sliding_puzzle_obj)
add_library(sliding_puzzle_static STATIC)
target_link_libraries(sliding_puzzle_static sliding_puzzle_obj)

add_executable(slidingpuzzle bootstrap.cpp main.cpp)
target_link_libraries(slidingpuzzle
	PRIVATE precompiled
	PRIVATE sliding_puzzle_shared
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)

include(Coverage)
CleanCoverage(sliding_puzzle_static)
include(Format)
Format(sliding_puzzle_static .)
include(CppCheck)
AddCppCheck(sliding_puzzle_obj)
include(Doxygen)
Doxygen(sliding_puzzle src/sliding_puzzle)
