cmake_minimum_required( VERSION 2.8.12 )

project(libarchive_cpp_wrapper)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
file(GLOB template_implementations "${CMAKE_CURRENT_SOURCE_DIR}/*.tpp")

add_library( ${PROJECT_NAME} SHARED

  archive_reader.cpp
  archive_reader_entry.cpp
  archive_reader_iterator.cpp
  archive_reader_file_container.cpp
  archive_reader_memory_container.cpp
  archive_reader_entry_buffer.cpp

  archive_exception.cpp

  ${headers}
  ${template_implementations}
)

target_link_libraries( ${PROJECT_NAME} /usr/lib/x86_64-linux-gnu/libarchive.so.13 )
