# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yen/CLionProjects/proj4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yen/CLionProjects/proj4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj4.dir/flags.make

CMakeFiles/proj4.dir/main.cpp.o: CMakeFiles/proj4.dir/flags.make
CMakeFiles/proj4.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj4.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj4.dir/main.cpp.o -c /Users/yen/CLionProjects/proj4/main.cpp

CMakeFiles/proj4.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yen/CLionProjects/proj4/main.cpp > CMakeFiles/proj4.dir/main.cpp.i

CMakeFiles/proj4.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yen/CLionProjects/proj4/main.cpp -o CMakeFiles/proj4.dir/main.cpp.s

CMakeFiles/proj4.dir/Game.cpp.o: CMakeFiles/proj4.dir/flags.make
CMakeFiles/proj4.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/proj4.dir/Game.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj4.dir/Game.cpp.o -c /Users/yen/CLionProjects/proj4/Game.cpp

CMakeFiles/proj4.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4.dir/Game.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yen/CLionProjects/proj4/Game.cpp > CMakeFiles/proj4.dir/Game.cpp.i

CMakeFiles/proj4.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4.dir/Game.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yen/CLionProjects/proj4/Game.cpp -o CMakeFiles/proj4.dir/Game.cpp.s

CMakeFiles/proj4.dir/Entity.cpp.o: CMakeFiles/proj4.dir/flags.make
CMakeFiles/proj4.dir/Entity.cpp.o: ../Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/proj4.dir/Entity.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj4.dir/Entity.cpp.o -c /Users/yen/CLionProjects/proj4/Entity.cpp

CMakeFiles/proj4.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4.dir/Entity.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yen/CLionProjects/proj4/Entity.cpp > CMakeFiles/proj4.dir/Entity.cpp.i

CMakeFiles/proj4.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4.dir/Entity.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yen/CLionProjects/proj4/Entity.cpp -o CMakeFiles/proj4.dir/Entity.cpp.s

CMakeFiles/proj4.dir/Plants.cpp.o: CMakeFiles/proj4.dir/flags.make
CMakeFiles/proj4.dir/Plants.cpp.o: ../Plants.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/proj4.dir/Plants.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj4.dir/Plants.cpp.o -c /Users/yen/CLionProjects/proj4/Plants.cpp

CMakeFiles/proj4.dir/Plants.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4.dir/Plants.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yen/CLionProjects/proj4/Plants.cpp > CMakeFiles/proj4.dir/Plants.cpp.i

CMakeFiles/proj4.dir/Plants.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4.dir/Plants.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yen/CLionProjects/proj4/Plants.cpp -o CMakeFiles/proj4.dir/Plants.cpp.s

CMakeFiles/proj4.dir/Zombies.cpp.o: CMakeFiles/proj4.dir/flags.make
CMakeFiles/proj4.dir/Zombies.cpp.o: ../Zombies.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/proj4.dir/Zombies.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj4.dir/Zombies.cpp.o -c /Users/yen/CLionProjects/proj4/Zombies.cpp

CMakeFiles/proj4.dir/Zombies.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4.dir/Zombies.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yen/CLionProjects/proj4/Zombies.cpp > CMakeFiles/proj4.dir/Zombies.cpp.i

CMakeFiles/proj4.dir/Zombies.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4.dir/Zombies.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yen/CLionProjects/proj4/Zombies.cpp -o CMakeFiles/proj4.dir/Zombies.cpp.s

CMakeFiles/proj4.dir/Room.cpp.o: CMakeFiles/proj4.dir/flags.make
CMakeFiles/proj4.dir/Room.cpp.o: ../Room.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/proj4.dir/Room.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/proj4.dir/Room.cpp.o -c /Users/yen/CLionProjects/proj4/Room.cpp

CMakeFiles/proj4.dir/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj4.dir/Room.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yen/CLionProjects/proj4/Room.cpp > CMakeFiles/proj4.dir/Room.cpp.i

CMakeFiles/proj4.dir/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj4.dir/Room.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yen/CLionProjects/proj4/Room.cpp -o CMakeFiles/proj4.dir/Room.cpp.s

# Object files for target proj4
proj4_OBJECTS = \
"CMakeFiles/proj4.dir/main.cpp.o" \
"CMakeFiles/proj4.dir/Game.cpp.o" \
"CMakeFiles/proj4.dir/Entity.cpp.o" \
"CMakeFiles/proj4.dir/Plants.cpp.o" \
"CMakeFiles/proj4.dir/Zombies.cpp.o" \
"CMakeFiles/proj4.dir/Room.cpp.o"

# External object files for target proj4
proj4_EXTERNAL_OBJECTS =

proj4: CMakeFiles/proj4.dir/main.cpp.o
proj4: CMakeFiles/proj4.dir/Game.cpp.o
proj4: CMakeFiles/proj4.dir/Entity.cpp.o
proj4: CMakeFiles/proj4.dir/Plants.cpp.o
proj4: CMakeFiles/proj4.dir/Zombies.cpp.o
proj4: CMakeFiles/proj4.dir/Room.cpp.o
proj4: CMakeFiles/proj4.dir/build.make
proj4: CMakeFiles/proj4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable proj4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/proj4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj4.dir/build: proj4

.PHONY : CMakeFiles/proj4.dir/build

CMakeFiles/proj4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proj4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proj4.dir/clean

CMakeFiles/proj4.dir/depend:
	cd /Users/yen/CLionProjects/proj4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yen/CLionProjects/proj4 /Users/yen/CLionProjects/proj4 /Users/yen/CLionProjects/proj4/cmake-build-debug /Users/yen/CLionProjects/proj4/cmake-build-debug /Users/yen/CLionProjects/proj4/cmake-build-debug/CMakeFiles/proj4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj4.dir/depend
