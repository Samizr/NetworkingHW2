# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Sami\Documents\GitHub\NetworkingHW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Sami\Documents\GitHub\NetworkingHW2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NetworkingHW2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NetworkingHW2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NetworkingHW2.dir/flags.make

CMakeFiles/NetworkingHW2.dir/main.cpp.obj: CMakeFiles/NetworkingHW2.dir/flags.make
CMakeFiles/NetworkingHW2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Sami\Documents\GitHub\NetworkingHW2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NetworkingHW2.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NetworkingHW2.dir\main.cpp.obj -c C:\Users\Sami\Documents\GitHub\NetworkingHW2\main.cpp

CMakeFiles/NetworkingHW2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NetworkingHW2.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Sami\Documents\GitHub\NetworkingHW2\main.cpp > CMakeFiles\NetworkingHW2.dir\main.cpp.i

CMakeFiles/NetworkingHW2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NetworkingHW2.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Sami\Documents\GitHub\NetworkingHW2\main.cpp -o CMakeFiles\NetworkingHW2.dir\main.cpp.s

CMakeFiles/NetworkingHW2.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/NetworkingHW2.dir/main.cpp.obj.requires

CMakeFiles/NetworkingHW2.dir/main.cpp.obj.provides: CMakeFiles/NetworkingHW2.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\NetworkingHW2.dir\build.make CMakeFiles/NetworkingHW2.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/NetworkingHW2.dir/main.cpp.obj.provides

CMakeFiles/NetworkingHW2.dir/main.cpp.obj.provides.build: CMakeFiles/NetworkingHW2.dir/main.cpp.obj


# Object files for target NetworkingHW2
NetworkingHW2_OBJECTS = \
"CMakeFiles/NetworkingHW2.dir/main.cpp.obj"

# External object files for target NetworkingHW2
NetworkingHW2_EXTERNAL_OBJECTS =

NetworkingHW2.exe: CMakeFiles/NetworkingHW2.dir/main.cpp.obj
NetworkingHW2.exe: CMakeFiles/NetworkingHW2.dir/build.make
NetworkingHW2.exe: CMakeFiles/NetworkingHW2.dir/linklibs.rsp
NetworkingHW2.exe: CMakeFiles/NetworkingHW2.dir/objects1.rsp
NetworkingHW2.exe: CMakeFiles/NetworkingHW2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Sami\Documents\GitHub\NetworkingHW2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NetworkingHW2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NetworkingHW2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NetworkingHW2.dir/build: NetworkingHW2.exe

.PHONY : CMakeFiles/NetworkingHW2.dir/build

CMakeFiles/NetworkingHW2.dir/requires: CMakeFiles/NetworkingHW2.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/NetworkingHW2.dir/requires

CMakeFiles/NetworkingHW2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NetworkingHW2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NetworkingHW2.dir/clean

CMakeFiles/NetworkingHW2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Sami\Documents\GitHub\NetworkingHW2 C:\Users\Sami\Documents\GitHub\NetworkingHW2 C:\Users\Sami\Documents\GitHub\NetworkingHW2\cmake-build-debug C:\Users\Sami\Documents\GitHub\NetworkingHW2\cmake-build-debug C:\Users\Sami\Documents\GitHub\NetworkingHW2\cmake-build-debug\CMakeFiles\NetworkingHW2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NetworkingHW2.dir/depend
