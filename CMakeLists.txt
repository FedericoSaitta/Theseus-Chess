cmake_minimum_required(VERSION 3.20)
project(Theseus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Theseus
	"main.cpp"
    "chess/bitboard.h" "chess/position.h" "chess/types.h")

if(MSVC)
    # Debug: all warnings, full debug info
    target_compile_options(Theseus PRIVATE
        $<$<CONFIG:Debug>:/W4 /Zi /Od /DEBUG>
    )
    # Release: max speed, no debug overhead
    target_compile_options(Theseus PRIVATE
        $<$<CONFIG:Release>:/O2 /DNDEBUG /W3>
    )
endif()