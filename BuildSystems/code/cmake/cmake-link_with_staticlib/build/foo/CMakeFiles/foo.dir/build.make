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
include foo/CMakeFiles/foo.dir/depend.make

# Include the progress variables for this target.
include foo/CMakeFiles/foo.dir/progress.make

# Include the compile flags for this target's objects.
include foo/CMakeFiles/foo.dir/flags.make

foo/CMakeFiles/foo.dir/libfoo.cpp.obj: foo/CMakeFiles/foo.dir/flags.make
foo/CMakeFiles/foo.dir/libfoo.cpp.obj: foo/CMakeFiles/foo.dir/includes_CXX.rsp
foo/CMakeFiles/foo.dir/libfoo.cpp.obj: ../foo/libfoo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/C/Users/aramadan/Desktop/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object foo/CMakeFiles/foo.dir/libfoo.cpp.obj"
	cd /C/Users/aramadan/Desktop/cmake/build/foo && /C/msys64/mingw64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/foo.dir/libfoo.cpp.obj -c /C/Users/aramadan/Desktop/cmake/foo/libfoo.cpp

foo/CMakeFiles/foo.dir/libfoo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/foo.dir/libfoo.cpp.i"
	cd /C/Users/aramadan/Desktop/cmake/build/foo && /C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /C/Users/aramadan/Desktop/cmake/foo/libfoo.cpp > CMakeFiles/foo.dir/libfoo.cpp.i

foo/CMakeFiles/foo.dir/libfoo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/foo.dir/libfoo.cpp.s"
	cd /C/Users/aramadan/Desktop/cmake/build/foo && /C/msys64/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /C/Users/aramadan/Desktop/cmake/foo/libfoo.cpp -o CMakeFiles/foo.dir/libfoo.cpp.s

# Object files for target foo
foo_OBJECTS = \
"CMakeFiles/foo.dir/libfoo.cpp.obj"

# External object files for target foo
foo_EXTERNAL_OBJECTS =

foo/libfoo.a: foo/CMakeFiles/foo.dir/libfoo.cpp.obj
foo/libfoo.a: foo/CMakeFiles/foo.dir/build.make
foo/libfoo.a: foo/CMakeFiles/foo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/C/Users/aramadan/Desktop/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libfoo.a"
	cd /C/Users/aramadan/Desktop/cmake/build/foo && $(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean_target.cmake
	cd /C/Users/aramadan/Desktop/cmake/build/foo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/foo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
foo/CMakeFiles/foo.dir/build: foo/libfoo.a

.PHONY : foo/CMakeFiles/foo.dir/build

foo/CMakeFiles/foo.dir/clean:
	cd /C/Users/aramadan/Desktop/cmake/build/foo && $(CMAKE_COMMAND) -P CMakeFiles/foo.dir/cmake_clean.cmake
.PHONY : foo/CMakeFiles/foo.dir/clean

foo/CMakeFiles/foo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MSYS Makefiles" /C/Users/aramadan/Desktop/cmake /C/Users/aramadan/Desktop/cmake/foo /C/Users/aramadan/Desktop/cmake/build /C/Users/aramadan/Desktop/cmake/build/foo /C/Users/aramadan/Desktop/cmake/build/foo/CMakeFiles/foo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : foo/CMakeFiles/foo.dir/depend
