# CMake Functions

function(add_portable_executable EXECUTABLE SRC)
	add_executable(${EXECUTABLE} ${SRC} ${NOMAIN_SOURCES})
	target_include_directories(${EXECUTABLE} PUBLIC ${NOMAIN_INCLUDES})
	target_compile_options(${EXECUTABLE} PUBLIC 
		${FLAGS}
	)
endfunction()

function(add_dll LIBRARY SRC)
	add_library(${LIBRARY} SHARED ${SRC} ${NOMAIN_SOURCES})
	target_include_directories(${LIBRARY} PUBLIC ${NOMAIN_INCLUDES})
	target_compile_options(${LIBRARY} PUBLIC
		${FLAGS}
	)
endfunction()

# Portable Executables (PE)

add_portable_executable(${PE}Ex0 pe/ex0.c)
add_portable_executable(${PE}Ex1 pe/ex1.c)
add_portable_executable(${PE}Ex2 pe/ex2.c)
add_portable_executable(${PE}Ex3 pe/ex3.c)
add_portable_executable(${PE}Ex4 pe/ex4.c)
add_portable_executable(${PE}Ex5 pe/ex5.c)
add_portable_executable(${PE}Ex6 pe/ex6.c)

# Dynamic Linked Library (DLL)

add_dll(${DLL}Ex0 dll/ex0.c)
add_dll(${DLL}Ex1 dll/ex1.c)

# Resource files

add_portable_executable(${PE}RsrcEx0 rsrc/ex0.c)
target_sources(${PE}RsrcEx0 PUBLIC rsrc/resources.rc)
