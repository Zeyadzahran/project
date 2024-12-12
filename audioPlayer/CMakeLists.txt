cmake_minimum_required(VERSION 3.30)
project(Quran_project)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable static linking for GCC/MinGW libraries if using MinGW
if(MINGW)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()

# Add the executable with all source files
add_executable(Quran_project
        main.cpp
        Shurah.h
        Shurah.cpp
        Playlist.h
        Playlist.cpp
        DoublyLinkedList.h
        MediaPlayer.h
        MediaPlayer.cpp
)

# Link against the winmm library for PlaySound functionality
target_link_libraries(Quran_project PRIVATE winmm)
