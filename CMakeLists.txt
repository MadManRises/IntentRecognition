set(CMAKE_CXX_STANDARD 20)

project(IntentRecognition)

add_library(IntentRecognizerImpl STATIC recognizer.cpp recognizer.h)

add_executable(IntentRecognizer main.cpp)

target_link_libraries(IntentRecognizer PRIVATE IntentRecognizerImpl)


add_subdirectory(test)