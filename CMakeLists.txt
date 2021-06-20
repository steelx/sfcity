cmake_minimum_required(VERSION 3.19)
set(PROJECT_NAME sfml_01)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} src/main.cpp headers/game_state.hpp src/game.cpp headers/game.hpp src/game_state_start.cpp headers/game_state_start.hpp src/game_state_editor.cpp headers/game_state_editor.hpp src/texture_manager.cpp headers/texture_manager.hpp src/animation_handler.cpp headers/animation_handler.hpp src/tile.cpp headers/tile.hpp)

include_directories(headers /usr/include C:/SFML/include)

set(SFML_ROOT c:/SFML)
set(SFML_DIR "${SFML_ROOT}/lib/cmake/SFML")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)

## If you want to link SFML statically
#set(SFML_STATIC_LIBRARIES TRUE)

if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# copy images, sound etc ready to be bundled
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# copy DLL's
if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_ROOT}/bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
