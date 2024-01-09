message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}") 

option(CLANG_FORMAT "Build clang format" OFF)
if(CLANG_FORMAT)
	find_program(CLANG_FORMAT_EXECUTABLE NAMES clang-format)
	if(CLANG_FORMAT_EXECUTABLE-NOTFOUND)
		message(FATAL_ERROR
			"expected CLANG_FORMAT_EXECUTABLE=<ANY> got ''. Try CLANG_FORMAT=OFF or install clang-format")
	endif()
	add_custom_target(clang-format
		COMMAND ${CLANG_FORMAT_EXECUTABLE} -i -verbose
			src/*.c mock/stub/*.h mock/stub/*.c examples/{pe,dll}/*.c include/dropper/*.h
		)
endif()