#==============================
# Requirements
#==============================

cmake_minimum_required(VERSION 3.10)

#==============================
# Project Settings
#==============================

if (NOT PROJECT_DECLARED)
    project("Gaia Background" LANGUAGES CXX)
    set(PROJECT_DECLARED)
endif()

if (NOT PROJECT_SUIT)
    set(PROJECT_SUIT ON)
endif()

#==============================
# Project Modules
#==============================

add_subdirectory("GaiaBackground")

if (WITH_TEST)
    add_subdirectory("GaiaEventsTest")
endif()