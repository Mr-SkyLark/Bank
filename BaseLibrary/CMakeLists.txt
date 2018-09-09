#-------------------------------------------------------------------------------
set(BASE_LINK_TYPE "SHARED")
if(LINK_STATIC_BASE_LIBRARY)
  set(BASE_LINK_TYPE "STATIC")
endif()
message(STATUS "Base libraries has ${BASE_LINK_TYPE} link type")
#-------------------------------------------------------------------------------
add_subdirectory(BString)
add_subdirectory(BDate)
#-------------------------------------------------------------------------------
