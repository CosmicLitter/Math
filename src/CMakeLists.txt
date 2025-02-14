add_library(Math particle.cpp)

target_include_directories(Math PUBLIC 
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
  $<INSTALL_INTERFACE:include>
)

install (TARGETS Math EXPORT MathConfig 
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(DIRECTORY ../include/ DESTINATION include)

install(EXPORT MathConfig 
  FILE MathConfig.cmake
  DESTINATION lib/cmake/Math
)
