# Install script for directory: /home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada

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
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PPSSPPSDL" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PPSSPPSDL")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PPSSPPSDL"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/PPSSPPSDL")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PPSSPPSDL" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PPSSPPSDL")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/PPSSPPSDL")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ppsspp" TYPE DIRECTORY FILES "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/assets" REGEX "/\\.git[^/]*$" EXCLUDE REGEX "/mime$" EXCLUDE REGEX "/lang\\/README\\.md$" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/applications" TYPE FILE RENAME "PPSSPPSDL.desktop" FILES "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/ppsspp.desktop")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icons" TYPE DIRECTORY FILES "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/icons/hicolor")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/icons/hicolor/scalable/apps" TYPE FILE RENAME "ppsspp.svg" FILES "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/icons/icon-512.svg")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/mime/packages" TYPE FILE FILES "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/assets/mime/ppsspp.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/ext/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/happy/Desktop/EmuELEC-zhang/EmuELEC/sources/PPSSPPSDL/PPSSPPSDL-b11a5f6df45656003c80f31e5a1a957c94da2ada/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
