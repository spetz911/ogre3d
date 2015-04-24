cmake_minimum_required(VERSION 3.1)
project(untitled)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_subdirectory(GL3Plus)
add_subdirectory(OgreMain)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/OgreMain/include)


set(SOURCE_FILES BareOgre.cpp ExampleApplication.cpp)


#set_target_properties(OgreMain PROPERTIES
#    LINK_FLAGS "-framework IOKit -framework Cocoa -framework Carbon -framework OpenGL")

FIND_LIBRARY(CARBON_LIBRARY Carbon)
FIND_LIBRARY(COCOA_LIBRARY Cocoa )
FIND_LIBRARY(IOKIT_LIBRARY IOKit )
FIND_LIBRARY(OPENGL_LIBRARY OpenGL)



set(CMAKE_BUILD_TYPE Release)

#add_library(OgreMain SHARED ${SOURCE_FILES})


add_executable(untitled
               ${SOURCE_FILES}
               $<TARGET_OBJECTS:OgreMain>
               $<TARGET_OBJECTS:GL3Plus>
               )

target_link_libraries(untitled ${CARBON_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY}
                                ${OPENGL_LIBRARY})


include_directories(/opt/local/include)

FIND_LIBRARY(GLFW_LIBRARY GLFW)

add_executable(main main.cpp tutorial08/common/shader.cpp)

target_link_libraries(main ${OPENGL_LIBRARY} ${GLFW_LIBRARY})


