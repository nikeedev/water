cmake_minimum_required(VERSION 3.10)

project(water)

set(CMAKE_CXX_STANDARD 20)

set(water_src
  src/main.cpp
  src/manageHtml.cpp
)

message("water src: ${water_src}")

add_executable(water 
  ${water_src}
)

file(COPY test DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")


find_package(fmt CONFIG REQUIRED)
find_package(pugixml CONFIG REQUIRED)
find_package(ftxui CONFIG REQUIRED)
find_package(curl)

add_subdirectory(httpp)

target_link_libraries(water PUBLIC 
  fmt::fmt
  pugixml::shared pugixml::pugixml
  ftxui::dom ftxui::screen ftxui::component
  CURL::libcurl
  httpp
)

