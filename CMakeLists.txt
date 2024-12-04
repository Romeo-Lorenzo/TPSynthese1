cmake_minimum_required(VERSION 3.30)
project(TPSynthese1 C)

set(CMAKE_C_STANDARD 11)

add_executable(TPSynthese1 main.c
        CustomWrite.c
        CustomWrite.h
        Prompt.c
        Prompt.h
        GetTime.c
        GetTime.h
        Redirect.c
        Redirect.h
)
