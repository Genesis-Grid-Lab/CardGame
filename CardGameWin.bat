@echo off

rem output directory

set target="Targets\%1"

rem install conan dependencies

rem conan install . --install-folder %target% --build missing -s build_type=%1 -c tools.system.package_manager:mode=install

rem generate cmake build files

cmake -S . -B %target% -DCMAKE_BUILD_TYPE=%1 
rem -DCMAKE_TOOLCHAIN_FILE="conanbuildinfo.cmake"

rem compile cmake build files

cmake --build %target% --config %1