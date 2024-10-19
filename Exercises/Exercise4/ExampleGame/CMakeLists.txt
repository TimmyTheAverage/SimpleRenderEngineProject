# Game Only

file(GLOB_RECURSE MyGame-src "*.h" "*.cpp")


add_executable(MyGame ${MyGame-src})

target_include_directories(MyGame PUBLIC ${MYENGINE_INCLUDE_DIR})

target_link_libraries(MyGame MyEngine ${SGE_LIBRARIES})

# Copy project data to output path
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


IF (WIN32)
	## Copy dll's to output path
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
	file(COPY ${SGE_LIBRARIES_SHARED} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
ENDIF(WIN32)