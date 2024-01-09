message(STATUS "Including ${CMAKE_CURRENT_LIST_FILE}") 

option(CPPCHECK "Build cppheck" OFF)
if(CPPCHECK)
	find_program(CPPCHECK_EXECUTABLE NAMES cppcheck)
	if(CPPCHECK_EXECUTABLE-NOTFOUND)
		message(FATAL_ERROR
			"expected CPPCHECK_EXECUTABLE=<ANY> got ''. Try CPPCHECK=OFF or install cppcheck")
	endif()
	add_custom_target(cppcheck-posix
		COMMAND ${CPPCHECK_EXECUTABLE} 
		--enable=all
		--check-level=exhaustive
		--force
		--inconclusive
		--library=posix
		--check-library
		--project=compile_commands.json
		# sane default suppressions 
		--suppress=checkLibraryFunction
		--suppress=missingIncludeSystem
		--suppress='*:test/include/test/acutest.h'
		# example suppressions
		--suppress='unmatchedSuppression:examples/pe/*.c'
		--suppress='checkLibraryNoReturn:examples/pe/*.c'
		--suppress='nullPointer:examples/pe/*.c'
	)
endif()