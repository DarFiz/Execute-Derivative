# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0

# Include any dependencies generated for this target.
include CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/gmock_main.dir/flags.make

CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o: CMakeFiles/gmock_main.dir/flags.make
CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o: gtest/src/gtest-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o -c /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/gtest/src/gtest-all.cc

CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/gtest/src/gtest-all.cc > CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.i

CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/gtest/src/gtest-all.cc -o CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.s

CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires:
.PHONY : CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires

CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides: CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock_main.dir/build.make CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides.build
.PHONY : CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides

CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides.build: CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: CMakeFiles/gmock_main.dir/flags.make
CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: src/gmock-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmock_main.dir/src/gmock-all.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.o -c /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/src/gmock-all.cc

CMakeFiles/gmock_main.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock-all.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/src/gmock-all.cc > CMakeFiles/gmock_main.dir/src/gmock-all.cc.i

CMakeFiles/gmock_main.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock-all.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/src/gmock-all.cc -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.s

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires:
.PHONY : CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock_main.dir/build.make CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build
.PHONY : CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides

CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: CMakeFiles/gmock_main.dir/flags.make
CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: src/gmock_main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/src/gmock_main.cc

CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires:
.PHONY : CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires
	$(MAKE) -f CMakeFiles/gmock_main.dir/build.make CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build
.PHONY : CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides

CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

libgmock_main.a: CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o
libgmock_main.a: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o
libgmock_main.a: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
libgmock_main.a: CMakeFiles/gmock_main.dir/build.make
libgmock_main.a: CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgmock_main.a"
	$(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/gmock_main.dir/build: libgmock_main.a
.PHONY : CMakeFiles/gmock_main.dir/build

CMakeFiles/gmock_main.dir/requires: CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires
CMakeFiles/gmock_main.dir/requires: CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
CMakeFiles/gmock_main.dir/requires: CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires
.PHONY : CMakeFiles/gmock_main.dir/requires

CMakeFiles/gmock_main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/gmock_main.dir/clean

CMakeFiles/gmock_main.dir/depend:
	cd /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0 /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0 /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0 /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0 /home/zbynek/Programowanie/RiemannTensor/lib/gmock-1.7.0/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/gmock_main.dir/depend
