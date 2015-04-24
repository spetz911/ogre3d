cmake_minimum_required(VERSION 3.1)
project(GL3Plus)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/OSX)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/GLSL)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../OgreMain/include)

set(SOURCE_FILES

    src/OSX/OgreOSXCocoaView.mm
    src/OSX/OgreOSXCocoaWindowDelegate.mm
    src/OSX/OgreOSXCocoaContext.mm
    src/OSX/OgreOSXCocoaWindow.mm
    src/OSX/OgreOSXGL3PlusSupport.mm

    src/GLSL/src/OgreGLSLExtSupport.cpp
    src/GLSL/src/OgreGLSLGpuProgram.cpp
    src/GLSL/src/OgreGLSLLinkProgram.cpp
    src/GLSL/src/OgreGLSLLinkProgramManager.cpp
    src/GLSL/src/OgreGLSLPreprocessor.cpp
    src/GLSL/src/OgreGLSLProgram.cpp
    src/GLSL/src/OgreGLSLProgramCommon.cpp
    src/GLSL/src/OgreGLSLProgramFactory.cpp
    src/GLSL/src/OgreGLSLProgramManagerCommon.cpp
    src/GLSL/src/OgreGLSLProgramPipeline.cpp
    src/GLSL/src/OgreGLSLProgramPipelineManager.cpp
    src/OgreGL3PlusContext.cpp
    src/OgreGL3PlusDefaultHardwareBufferManager.cpp
    src/OgreGL3PlusDepthBuffer.cpp
    src/OgreGL3PlusEngineDll.cpp
    src/OgreGL3PlusFBOMultiRenderTarget.cpp
    src/OgreGL3PlusFBORenderTexture.cpp
    src/OgreGL3PlusFrameBufferObject.cpp
    src/OgreGL3PlusGpuProgram.cpp
    src/OgreGL3PlusGpuProgramManager.cpp
    src/OgreGL3PlusHardwareBufferManager.cpp
    src/OgreGL3PlusHardwareCounterBuffer.cpp
    src/OgreGL3PlusHardwareIndexBuffer.cpp
    src/OgreGL3PlusHardwareOcclusionQuery.cpp
    src/OgreGL3PlusHardwarePixelBuffer.cpp
    src/OgreGL3PlusHardwareUniformBuffer.cpp
    src/OgreGL3PlusHardwareVertexBuffer.cpp
    src/OgreGL3PlusPixelFormat.cpp
    src/OgreGL3PlusPlugin.cpp
    src/OgreGL3PlusRenderSystem.cpp
    src/OgreGL3PlusRenderTexture.cpp
    src/OgreGL3PlusRenderToVertexBuffer.cpp
    src/OgreGL3PlusSupport.cpp
    src/OgreGL3PlusTexture.cpp
    src/OgreGL3PlusTextureManager.cpp
    src/OgreGL3PlusVertexArrayObject.cpp)


#FIND_LIBRARY(COCOA_LIBRARY Cocoa )
#FIND_LIBRARY(CARBON_LIBRARY Carbon)

set(CMAKE_BUILD_TYPE Release)

#add_executable(GL3Plus ${SOURCE_FILES})

add_library(GL3Plus OBJECT ${SOURCE_FILES})

#add_library(GL3Plus SHARED ${SOURCE_FILES} $<TARGET_OBJECTS:OgreMain>)

#target_link_libraries(GL3Plus ${CARBON_LIBRARY} ${COCOA_LIBRARY} ${OPENGL_LIBRARY})
