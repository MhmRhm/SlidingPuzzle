include(GNUInstallDirs)

install(TARGETS precompiled sliding_puzzle_obj sliding_puzzle_shared sliding_puzzle_static
    EXPORT SlidingPuzzleLibrary
    ARCHIVE COMPONENT sliding_puzzle_dev
    LIBRARY COMPONENT sliding_puzzle
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/sliding_puzzle
        COMPONENT sliding_puzzle
)

if(UNIX)
    install(CODE "execute_process(COMMAND ldconfig)"
        COMPONENT sliding_puzzle
    )
endif()

install(EXPORT SlidingPuzzleLibrary
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${MY_PROJECT_NAME}/cmake
    NAMESPACE ${MY_PACKAGE_NAME}::SlidingPuzzle::
    COMPONENT sliding_puzzle
)

install(FILES "ProjectConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${CMAKE_PROJECT_NAME}/cmake
    RENAME "${MY_PACKAGE_NAME}Config.cmake"
)

set(CPACK_PACKAGE_VENDOR "Mohammad Rahimi")
set(CPACK_PACKAGE_CONTACT "rahimi.mhmmd@yahoo.com")
set(CPACK_PACKAGE_DESCRIPTION "Sliding Puzzle Implemented by FTXUI")
include(CPack)
