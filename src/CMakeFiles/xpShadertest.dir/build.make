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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/peter/Programming/xplane/xpshader

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peter/Programming/xplane/xpshader

# Include any dependencies generated for this target.
include src/CMakeFiles/xpShadertest.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/xpShadertest.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/xpShadertest.dir/flags.make

src/CMakeFiles/xpShadertest.dir/xps.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/xps.c.o: src/xps.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/xps.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/xps.c.o   -c /home/peter/Programming/xplane/xpshader/src/xps.c

src/CMakeFiles/xpShadertest.dir/xps.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/xps.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/xps.c > CMakeFiles/xpShadertest.dir/xps.c.i

src/CMakeFiles/xpShadertest.dir/xps.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/xps.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/xps.c -o CMakeFiles/xpShadertest.dir/xps.c.s

src/CMakeFiles/xpShadertest.dir/xps.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/xps.c.o.requires

src/CMakeFiles/xpShadertest.dir/xps.c.o.provides: src/CMakeFiles/xpShadertest.dir/xps.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/xps.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/xps.c.o.provides

src/CMakeFiles/xpShadertest.dir/xps.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/xps.c.o

src/CMakeFiles/xpShadertest.dir/xputil.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/xputil.c.o: src/xputil.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/xputil.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/xputil.c.o   -c /home/peter/Programming/xplane/xpshader/src/xputil.c

src/CMakeFiles/xpShadertest.dir/xputil.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/xputil.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/xputil.c > CMakeFiles/xpShadertest.dir/xputil.c.i

src/CMakeFiles/xpShadertest.dir/xputil.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/xputil.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/xputil.c -o CMakeFiles/xpShadertest.dir/xputil.c.s

src/CMakeFiles/xpShadertest.dir/xputil.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/xputil.c.o.requires

src/CMakeFiles/xpShadertest.dir/xputil.c.o.provides: src/CMakeFiles/xpShadertest.dir/xputil.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/xputil.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/xputil.c.o.provides

src/CMakeFiles/xpShadertest.dir/xputil.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/xputil.c.o

src/CMakeFiles/xpShadertest.dir/xpdraw.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/xpdraw.c.o: src/xpdraw.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/xpdraw.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/xpdraw.c.o   -c /home/peter/Programming/xplane/xpshader/src/xpdraw.c

src/CMakeFiles/xpShadertest.dir/xpdraw.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/xpdraw.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/xpdraw.c > CMakeFiles/xpShadertest.dir/xpdraw.c.i

src/CMakeFiles/xpShadertest.dir/xpdraw.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/xpdraw.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/xpdraw.c -o CMakeFiles/xpShadertest.dir/xpdraw.c.s

src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.requires

src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.provides: src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.provides

src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/xpdraw.c.o

src/CMakeFiles/xpShadertest.dir/xpopengl.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/xpopengl.c.o: src/xpopengl.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/xpopengl.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/xpopengl.c.o   -c /home/peter/Programming/xplane/xpshader/src/xpopengl.c

src/CMakeFiles/xpShadertest.dir/xpopengl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/xpopengl.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/xpopengl.c > CMakeFiles/xpShadertest.dir/xpopengl.c.i

src/CMakeFiles/xpShadertest.dir/xpopengl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/xpopengl.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/xpopengl.c -o CMakeFiles/xpShadertest.dir/xpopengl.c.s

src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.requires

src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.provides: src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.provides

src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/xpopengl.c.o

src/CMakeFiles/xpShadertest.dir/xpscene.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/xpscene.c.o: src/xpscene.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/xpscene.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/xpscene.c.o   -c /home/peter/Programming/xplane/xpshader/src/xpscene.c

src/CMakeFiles/xpShadertest.dir/xpscene.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/xpscene.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/xpscene.c > CMakeFiles/xpShadertest.dir/xpscene.c.i

src/CMakeFiles/xpShadertest.dir/xpscene.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/xpscene.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/xpscene.c -o CMakeFiles/xpShadertest.dir/xpscene.c.s

src/CMakeFiles/xpShadertest.dir/xpscene.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/xpscene.c.o.requires

src/CMakeFiles/xpShadertest.dir/xpscene.c.o.provides: src/CMakeFiles/xpShadertest.dir/xpscene.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/xpscene.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/xpscene.c.o.provides

src/CMakeFiles/xpShadertest.dir/xpscene.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/xpscene.c.o

src/CMakeFiles/xpShadertest.dir/xppixel.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/xppixel.c.o: src/xppixel.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/xppixel.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/xppixel.c.o   -c /home/peter/Programming/xplane/xpshader/src/xppixel.c

src/CMakeFiles/xpShadertest.dir/xppixel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/xppixel.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/xppixel.c > CMakeFiles/xpShadertest.dir/xppixel.c.i

src/CMakeFiles/xpShadertest.dir/xppixel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/xppixel.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/xppixel.c -o CMakeFiles/xpShadertest.dir/xppixel.c.s

src/CMakeFiles/xpShadertest.dir/xppixel.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/xppixel.c.o.requires

src/CMakeFiles/xpShadertest.dir/xppixel.c.o.provides: src/CMakeFiles/xpShadertest.dir/xppixel.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/xppixel.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/xppixel.c.o.provides

src/CMakeFiles/xpShadertest.dir/xppixel.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/xppixel.c.o

src/CMakeFiles/xpShadertest.dir/lodepng.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/lodepng.c.o: src/lodepng.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/lodepng.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/lodepng.c.o   -c /home/peter/Programming/xplane/xpshader/src/lodepng.c

src/CMakeFiles/xpShadertest.dir/lodepng.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/lodepng.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/lodepng.c > CMakeFiles/xpShadertest.dir/lodepng.c.i

src/CMakeFiles/xpShadertest.dir/lodepng.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/lodepng.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/lodepng.c -o CMakeFiles/xpShadertest.dir/lodepng.c.s

src/CMakeFiles/xpShadertest.dir/lodepng.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/lodepng.c.o.requires

src/CMakeFiles/xpShadertest.dir/lodepng.c.o.provides: src/CMakeFiles/xpShadertest.dir/lodepng.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/lodepng.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/lodepng.c.o.provides

src/CMakeFiles/xpShadertest.dir/lodepng.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/lodepng.c.o

src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o: src/CMakeFiles/xpShadertest.dir/flags.make
src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o: src/tb_triangle.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/peter/Programming/xplane/xpshader/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/xpShadertest.dir/tb_triangle.c.o   -c /home/peter/Programming/xplane/xpshader/src/tb_triangle.c

src/CMakeFiles/xpShadertest.dir/tb_triangle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/xpShadertest.dir/tb_triangle.c.i"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/peter/Programming/xplane/xpshader/src/tb_triangle.c > CMakeFiles/xpShadertest.dir/tb_triangle.c.i

src/CMakeFiles/xpShadertest.dir/tb_triangle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/xpShadertest.dir/tb_triangle.c.s"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/peter/Programming/xplane/xpshader/src/tb_triangle.c -o CMakeFiles/xpShadertest.dir/tb_triangle.c.s

src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.requires:
.PHONY : src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.requires

src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.provides: src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.requires
	$(MAKE) -f src/CMakeFiles/xpShadertest.dir/build.make src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.provides.build
.PHONY : src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.provides

src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.provides.build: src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o

# Object files for target xpShadertest
xpShadertest_OBJECTS = \
"CMakeFiles/xpShadertest.dir/xps.c.o" \
"CMakeFiles/xpShadertest.dir/xputil.c.o" \
"CMakeFiles/xpShadertest.dir/xpdraw.c.o" \
"CMakeFiles/xpShadertest.dir/xpopengl.c.o" \
"CMakeFiles/xpShadertest.dir/xpscene.c.o" \
"CMakeFiles/xpShadertest.dir/xppixel.c.o" \
"CMakeFiles/xpShadertest.dir/lodepng.c.o" \
"CMakeFiles/xpShadertest.dir/tb_triangle.c.o"

# External object files for target xpShadertest
xpShadertest_EXTERNAL_OBJECTS =

build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/xps.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/xputil.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/xpdraw.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/xpopengl.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/xpscene.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/xppixel.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/lodepng.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/build.make
build/libxpShadertest.so: src/CMakeFiles/xpShadertest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C shared library ../build/libxpShadertest.so"
	cd /home/peter/Programming/xplane/xpshader/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/xpShadertest.dir/link.txt --verbose=$(VERBOSE)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Copying 'xpShadertest' library to '/home/peter/xp10/Resources/plugins/xpShadertest.xpl'"
	cd /home/peter/Programming/xplane/xpshader/src && /usr/bin/cmake -E copy /home/peter/Programming/xplane/xpshader/build/libxpShadertest.so /home/peter/xp10/Resources/plugins/xpShadertest.xpl

# Rule to build all files generated by this target.
src/CMakeFiles/xpShadertest.dir/build: build/libxpShadertest.so
.PHONY : src/CMakeFiles/xpShadertest.dir/build

src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/xps.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/xputil.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/xpdraw.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/xpopengl.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/xpscene.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/xppixel.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/lodepng.c.o.requires
src/CMakeFiles/xpShadertest.dir/requires: src/CMakeFiles/xpShadertest.dir/tb_triangle.c.o.requires
.PHONY : src/CMakeFiles/xpShadertest.dir/requires

src/CMakeFiles/xpShadertest.dir/clean:
	cd /home/peter/Programming/xplane/xpshader/src && $(CMAKE_COMMAND) -P CMakeFiles/xpShadertest.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/xpShadertest.dir/clean

src/CMakeFiles/xpShadertest.dir/depend:
	cd /home/peter/Programming/xplane/xpshader && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peter/Programming/xplane/xpshader /home/peter/Programming/xplane/xpshader/src /home/peter/Programming/xplane/xpshader /home/peter/Programming/xplane/xpshader/src /home/peter/Programming/xplane/xpshader/src/CMakeFiles/xpShadertest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/xpShadertest.dir/depend

