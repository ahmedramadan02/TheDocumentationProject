# CMAKE generated file: DO NOT EDIT!
# Generated by "MSYS Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /C/ProgramFiles/cmake/x64/bin/cmake.exe

# The command to remove a file.
RM = /C/ProgramFiles/cmake/x64/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /C/Users/aramadan/Desktop/cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /C/Users/aramadan/Desktop/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/cmake-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cmake-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cmake-test.dir/flags.make

CMakeFiles/cmake-test.dir/main.cpp.obj: CMakeFiles/cmake-test.dir/flags.make
CMakeFiles/cmake-test.dir/main.cpp.obj: CMakeFiles/cmake-test.dir/includes_CXX.rsp
CMakeFiles/cmake-test.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/aramadan/Desktop/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cmake-test.dir/main.cpp.obj"
	/C/msys64/mingw64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cmake-test.dir/main.cpp.obj -c /C/Users/aramadan/Desktop/cmake/main.cpp

CMakeFiles/cmake-test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cmake-test.dir/main.cpp.i"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/aramadan/Desktop/cmake/main.cpp > CMakeFiles/cmake-test.dir/main.cpp.i

CMakeFiles/cmake-test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cmake-test.dir/main.cpp.s"
	/C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/aramadan/Desktop/cmake/main.cpp -o CMakeFiles/cmake-test.dir/main.cpp.s

# Object files for target cmake-test
cmake__test_OBJECTS = \
"CMakeFiles/cmake-test.dir/main.cpp.obj"

# External object files for target cmake-test
cmake__test_EXTERNAL_OBJECTS =

cmake-test.exe: CMakeFiles/cmake-test.dir/main.cpp.obj
cmake-test.exe: CMakeFiles/cmake-test.dir/build.make
cmake-test.exe: foo/libfoo.a
cmake-test.exe: CMakeFiles/cmake-test.dir/linklibs.rsp
cmake-test.exe: CMakeFiles/cmake-test.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/C/Users/aramadan/Desktop/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cmake-test.exe"
	/C/ProgramFiles/cmake/x64/bin/cmake.exe -E remove -f CMakeFiles/cmake-test.dir/objects.a
	/C/msys64/mingw64/bin/ar.exe cr CMakeFiles/cmake-test.dir/objects.a @CMakeFiles/cmake-test.dir/objects1.rsp
	/C/msys64/mingw64/bin/g++.exe    -Wl,--whole-archive CMakeFiles/cmake-test.dir/objects.a -Wl,--no-whole-archive  -o cmake-test.exe -Wl,--out-implib,libcmake-test.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/cmake-test.dir/linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles/cmake-test.dir/build: cmake-test.exe

.PHONY : CMakeFiles/cmake-test.dir/build

CMakeFiles/cmake-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cmake-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cmake-test.dir/clean

CMakeFiles/cmake-test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/aramadan/Desktop/cmake /C/Users/aramadan/Desktop/cmake /C/Users/aramadan/Desktop/cmake/build /C/Users/aramadan/Desktop/cmake/build /C/Users/aramadan/Desktop/cmake/build/CMakeFiles/cmake-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cmake-test.dir/depend

