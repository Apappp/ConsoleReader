cmake_minimum_required(VERSION 3.14)
project(ConsoleReader)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================
#  Pobieranie restclient-cpp z GitHuba
# ============================================
include(FetchContent)

FetchContent_Declare(
    restclient
    GIT_REPOSITORY https://github.com/mrtazz/restclient-cpp.git
    GIT_TAG main
)

FetchContent_MakeAvailable(restclient)

# ============================================
#  Twoje źródła
# ============================================
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(ConsoleReader ${SRC_FILES})

# Linkowanie biblioteki restclient + curl
target_link_libraries(ConsoleReader
    restclient-cpp
    curl
)
