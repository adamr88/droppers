option(VALGRIND "Build valgrind" OFF)
if(VALGRIND)
	find_program(VALGRIND_EXECUTABLE NAMES valgrind)
	if(VALGRIND_EXECUTABLE-NOTFOUND)
		message(FATAL_ERROR
			"expected VALGRIND_EXECUTABLE=<ANY> got ''. Try VALGRIND=OFF or install valgrind")
	endif()
	# VALGRIND LEAKS
	add_custom_target(valgrind-leaks
		COMMAND ${VALGRIND_EXECUTABLE}
		--dsymutil=yes
		--leak-check=full
		--show-error-list=yes
		--show-leak-kinds=all
		--show-reachable=yes
		--track-origins=yes
		./${CMAKE_PROJECT_NAME}
	)
endif()