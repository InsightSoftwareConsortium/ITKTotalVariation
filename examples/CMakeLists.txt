cmake_minimum_required(VERSION 3.10.2)
project(ProxTVExamples)

find_package(ITK REQUIRED COMPONENTS
  ITKCommon
  ITKIOImageBase
  ITKImageIntensity
  ITKImageIO
  TotalVariation
  CONFIG)
include(${ITK_USE_FILE})
# TODO(PHC) Why find_package(proxTV) is required? error message if missing:
#Target "ProxTV" links to target "proxTV::proxTV" but the target was not
#found.  Perhaps a find_package() call is missing for an IMPORTED target, or
#an ALIAS target is missing?
# find_package(proxTV REQUIRED CONFIG)

message(STATUS "ITK_LIBRARIES: ${ITK_LIBRARIES}")
add_executable(ProxTV ProxTV.cxx)
target_link_libraries(ProxTV ${ITK_LIBRARIES})
# target_link_libraries(ProxTV proxTV::proxTV)
target_include_directories(ProxTV SYSTEM PUBLIC ${ITK_INCLUDE_DIRS})
