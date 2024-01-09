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

# Dynamic Linked Library (DLL)

add_dll(${DLL}Ex0 dll/Ex0.c)
