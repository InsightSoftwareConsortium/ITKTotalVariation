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

add_executable(runProxTV ProxTV.cxx)
target_link_libraries(runProxTV PUBLIC ${ITK_LIBRARIES})
