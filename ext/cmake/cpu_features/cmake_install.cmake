# Install script for directory: /home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/lib/libcpu_features.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/cpu_features" TYPE FILE FILES
    "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/../../cpu_features/include/cpu_features_macros.h"
    "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/../../cpu_features/include/cpu_features_cache_info.h"
    "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/../../cpu_features/include/cpuinfo_x86.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures/CpuFeaturesTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures/CpuFeaturesTargets.cmake"
         "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/CMakeFiles/Export/lib/cmake/CpuFeatures/CpuFeaturesTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures/CpuFeaturesTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures/CpuFeaturesTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures" TYPE FILE FILES "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/CMakeFiles/Export/lib/cmake/CpuFeatures/CpuFeaturesTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures" TYPE FILE FILES "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/CMakeFiles/Export/lib/cmake/CpuFeatures/CpuFeaturesTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/CpuFeatures" TYPE FILE FILES
    "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/CpuFeaturesConfig.cmake"
    "/home/happy/Desktop/4.3-ng-joy/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/ppsspp-1/ext/cmake/cpu_features/CpuFeaturesConfigVersion.cmake"
    )
endif()

