# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Tarea_2___CLION.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Tarea_2___CLION.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Tarea_2___CLION.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tarea_2___CLION.dir/flags.make

CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj: CMakeFiles/Tarea_2___CLION.dir/flags.make
CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj: C:/Users/csricar/Documents/GitHub/Tarea2UNED/Tarea\ 2\ -\ CLION/tarea2.cpp
CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj: CMakeFiles/Tarea_2___CLION.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj -MF CMakeFiles\Tarea_2___CLION.dir\tarea2.cpp.obj.d -o CMakeFiles\Tarea_2___CLION.dir\tarea2.cpp.obj -c "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\tarea2.cpp"

CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\tarea2.cpp" > CMakeFiles\Tarea_2___CLION.dir\tarea2.cpp.i

CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\tarea2.cpp" -o CMakeFiles\Tarea_2___CLION.dir\tarea2.cpp.s

# Object files for target Tarea_2___CLION
Tarea_2___CLION_OBJECTS = \
"CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj"

# External object files for target Tarea_2___CLION
Tarea_2___CLION_EXTERNAL_OBJECTS =

Tarea_2___CLION.exe: CMakeFiles/Tarea_2___CLION.dir/tarea2.cpp.obj
Tarea_2___CLION.exe: CMakeFiles/Tarea_2___CLION.dir/build.make
Tarea_2___CLION.exe: CMakeFiles/Tarea_2___CLION.dir/linkLibs.rsp
Tarea_2___CLION.exe: CMakeFiles/Tarea_2___CLION.dir/objects1
Tarea_2___CLION.exe: CMakeFiles/Tarea_2___CLION.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tarea_2___CLION.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Tarea_2___CLION.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tarea_2___CLION.dir/build: Tarea_2___CLION.exe
.PHONY : CMakeFiles/Tarea_2___CLION.dir/build

CMakeFiles/Tarea_2___CLION.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Tarea_2___CLION.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Tarea_2___CLION.dir/clean

CMakeFiles/Tarea_2___CLION.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION" "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION" "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\cmake-build-debug" "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\cmake-build-debug" "C:\Users\csricar\Documents\GitHub\Tarea2UNED\Tarea 2 - CLION\cmake-build-debug\CMakeFiles\Tarea_2___CLION.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tarea_2___CLION.dir/depend
