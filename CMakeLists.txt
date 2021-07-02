#==============================
# Requirements
#==============================

cmake_minimum_required(VERSION 3.10)

#==============================
# Project Settings
#==============================

if (NOT PROJECT_DECLARED)
    project("Gaia Background" LANGUAGES CXX VERSION 1.0)
    set(PROJECT_DECLARED)
endif()

#==============================
# Project Modules
#==============================

add_subdirectory("GaiaBackground")

if (WITH_TEST)
    add_subdirectory("GaiaEventsTest")
endif()