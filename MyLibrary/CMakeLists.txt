#Create project
project (MyLibrary)

#Create library
add_library(MyLibrary STATIC)

#Set to C++20 standard
set_property(TARGET MyLibrary PROPERTY CXX_STANDARD 20)

#Source files and private headers
target_sources(MyLibrary PRIVATE
	"MyLibrary.cpp"
)

#Public headers
target_sources(MyLibrary PUBLIC 
	FILE_SET HEADERS TYPE HEADERS BASE_DIRS ${PROJECT_SOURCE_DIR} FILES
	"MyLibrary.h"
)

#Link SDL2 libraries
target_link_libraries(MyLibrary
	PRIVATE
	$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
	$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

set(CMAKE_INSTALL_PREFIX ".")

#Install project
install (TARGETS MyLibrary
	ARCHIVE DESTINATION "lib/${PROJECT_NAME}"
	LIBRARY DESTINATION "lib/${PROJECT_NAME}"
	RUNTIME DESTINATION "lib/${PROJECT_NAME}"
	FILE_SET HEADERS DESTINATION "include/${PROJECT_NAME}"
)
install (FILES LICENSE.txt DESTINATION "license/${PROJECT_NAME}")