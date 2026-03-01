cmake_minimum_required(VERSION 4.1)
project(dev_c C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(DM)

add_executable(dev_c
        DM/dm01/DM1-anthime.c
        DM/dm01/dm1-IV.c
        DM/dm01/DM1.c
        exercice-a2.c
        exercice-a3-c5-c10.c
        exercice-b2.c
        exercice-c1-2-3.c
        exercice-c15.c
        tri-fusion.c)
