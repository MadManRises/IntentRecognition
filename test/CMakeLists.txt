project(IntentRecognitionTest)

#Include gtest. Make sure to link against the same runtime library
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(googletest-1.11.0)

add_executable(IntentRecognizerTest recognizertest.cpp)

target_link_libraries(IntentRecognizerTest PRIVATE gtest_main IntentRecognizerImpl)

add_test(NAME IntentRecognizerTest
		 COMMAND $<TARGET_FILE:IntentRecognizerTest>
		 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})