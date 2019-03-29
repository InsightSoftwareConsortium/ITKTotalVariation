option(ITK_USE_SYSTEM_proxTV "Use external proxTV" OFF)
mark_as_advanced(ITK_USE_SYSTEM_proxTV)

option(ITK_USE_SYSTEM_EIGEN "Use External Eigen3" OFF)
mark_as_advanced(ITK_USE_SYSTEM_EIGEN)

# In case in the future we switch to use lapack instead of eigen for proxTV.
option(TotalVariation_proxTV_USE_EIGEN "proxTV in TotalVariation uses EIGEN" ON)
mark_as_advanced(TotalVariation_proxTV_USE_EIGEN)

if(ITK_USE_SYSTEM_proxTV)
  find_package(proxTV REQUIRED CONFIG)
endif()
