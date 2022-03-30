add_library(rational rational.h rational.cpp)
set(CMAKE_CXX_STANDARD 14)
add_executable(tests test.cpp)
target_link_libraries(tests rational)
