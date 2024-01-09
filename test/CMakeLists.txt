option(BUILD_PTHREADS "Build pthreads" OFF)
if (BUILD_PTRHEADS)
        target_link_libraries(TestDropperEnc PUBLIC ${CMAKE_PROJECT_NAME} Threads::Threads)
endif()

list (APPEND NOTEST_SOURCES
)

list (APPEND TEST_SOURCES
	src/TestDropperEnc.c 
)

add_executable(TestDropperEnc ${TEST_SOURCES}  ${NOTEST_SOURCES})
target_include_directories(TestDropperEnc PUBLIC ../include include)
add_test(NAME TestDropperEnc COMMAND TestDropperEnc)
