include(FetchContent)

FetchContent_Declare(llhttp
  URL "https://github.com/nodejs/llhttp/archive/refs/tags/release/v8.1.0.tar.gz")

  set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
  set(BUILD_STATIC_LIBS ON CACHE INTERNAL "")
  
FetchContent_MakeAvailable(llhttp)

file(GLOB LLHTTP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_library(QHttp STATIC)
add_library(QExpress::QHttp ALIAS QHttp)

set_target_properties(QHttp
  PROPERTIES
  LINKER_LANGUAGE CXX
)

target_link_libraries(QHttp Qt5::Core llhttp_static)
target_include_directories(QHttp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_BINARY_DIR}/_deps/llhttp-src/include)