# set the package root dir
set( MENGE_PACKAGE_ROOT ${CMAKE_MODULE_PATH}/..)

# I need to find libmengeCore.so and libmengVis.so for MENGE_LIBRARIES
# HINTS direct the right path
find_library(MENGE_LIBRARIES 
  NAMES mengeCore mengeVis
  HINTS "${MENGE_PACKAGE_ROOT}/projects/g++/build/lib")

if(NOT MENGE_LIBRARIES)
  set(MENGE_LIBRARIES_FOUND FALSE)
endif()

# I need to include all the header files, so I manually set this var for all header dirs.
# if you only want to find one header file like xxx.h, you can use
# find_path(xxx_INCLUDE_DIRS xxx.h)
set( MENGE_INCLUDE_DIRS "${MENGE_PACKAGE_ROOT}/src/Menge" "${MENGE_PACKAGE_ROOT}/src/include" "${MENGE_PACKAGE_ROOT}/src")