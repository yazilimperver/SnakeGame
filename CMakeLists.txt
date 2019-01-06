# Cmake min requirements
cmake_minimum_required(VERSION 3.9)

# Our project
project(SnakeGame)

# Include path
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Default C++ standard
set(CMAKE_CXX_STANDARD 17)

# Add source file groups
set(CONSOLE_CORE Color.h ConsoleCellData.h ConsoleCellItem.h ConsoleUtil.h ConsoleUtil.cpp ConsoleCellItem.cpp ConsoleLevel.h ConsoleLevel.cpp InformationWindow.h InformationWindow.cpp LogoDisplayer.h LogoDisplayer.cpp MidiPlayer.h MidiPlayer.cpp)
set(GAME_FILES ConsoleSnakeGame.cpp LoopManager.cpp main.cpp Menu.cpp MidiPlayer.cpp MusicRawData.cpp Player.cpp Snake.cpp SnakeModeItemGenerator.cpp ConsoleSnakeGame.h GameMode.h InformationWindow.h LogoDisplayer.h LoopManager.h Menu.h MenuContent.h MidiPlayer.h MusicRawData.h Player.h PlayerData.h Snake.h SnakeGameScreen.h SnakeModeItem.h SnakeModeItemGenerator.h)
set(SOURCES ${GAME_FILES} ${CONSOLE_CORE})

# not using precompiled header
set_source_files_properties(${SOURCES} PROPERTIES COMPILE_FLAGS /Y-)

# Will add filters for Visual Studio
source_group("ConsoleCore"            FILES ${CONSOLE_CORE})
source_group("SnakeGameFiles"        FILES ${GAME_FILES})

add_executable(SnakeGame ${SOURCES})

# To enable C++ latest option in Visual Studio
if (MSVC_VERSION GREATER_EQUAL "1900")
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
if (_cpp_latest_flag_supported)
add_compile_options("/std:c++latest")
endif()
endif()