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

# TODO(phcerdan): This shouldn't be required:
find_package(Eigen3 REQUIRED CONFIG)

if(NOT TARGET TotalVariation)
  message(WARNING "No TotalVariation Target")
endif()
message(STATUS "ITK_LIBRARIES: ${ITK_LIBRARIES}")
add_executable(Example ProxTV.cxx)
target_link_libraries(Example PUBLIC ${ITK_LIBRARIES})
