# Install script for directory: /home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext

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

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/armips/cmake_install.cmake")
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/glew/cmake_install.cmake")
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/cmake/cpu_features/cmake_install.cmake")
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/snappy/cmake_install.cmake")
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/udis86/cmake_install.cmake")
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/SPIRV-Cross-build/cmake_install.cmake")
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-9817567c85a7d4de55feeffe81d75e814b6c48cf/ext/discord-rpc-build/cmake_install.cmake")

endif()

