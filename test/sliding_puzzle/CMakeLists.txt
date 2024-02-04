add_executable(sliding_puzzle_test sliding_puzzle_test.cpp)
target_link_libraries(sliding_puzzle_test PRIVATE sliding_puzzle_static)

target_link_libraries(sliding_puzzle_test PRIVATE precompiled)

target_link_libraries(sliding_puzzle_test
	PRIVATE ftxui::screen
	PRIVATE ftxui::dom
	PRIVATE ftxui::component
)

include(Format)
Format(sliding_puzzle_test .)
AddTests(sliding_puzzle_test)
EnableCoverage(sliding_puzzle_obj)
