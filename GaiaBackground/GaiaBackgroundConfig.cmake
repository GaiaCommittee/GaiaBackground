cmake_minimum_required(3.10)

find_path(GaiaBackground_INCLUDE_DIRS "GaiaBackground")
find_library(GaiaBackground_LIBS "GaiaBackground")

if (GaiaBackground_INCLUDE_DIRS AND GaiaBackground_LIBS)
    set(GaiaBackground_FOUND TRUE)
endif()