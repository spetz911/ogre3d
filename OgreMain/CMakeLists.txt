cmake_minimum_required(VERSION 3.1)
project(OgreMain)

###################################################################
# configure global build settings based on selected build options
###################################################################

# FIXME config doesn't work
#configure_file(${CMAKE_CURRENT_SOURCE_DIR}/OgreBuildSettings.h.in ${CMAKE_CURRENT_SOURCE_DIR}/OgreBuildSettings.h )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCE_FILES

    src/OSX/OgreConfigDialog.mm
    src/OSX/OgreFileSystemLayer.cpp
    src/OSX/OgreErrorDialog.mm
    src/OSX/OgreTimer.cpp

    src/Threading/OgreDefaultWorkQueueStandard.cpp

    src/OgreAlignedAllocator.cpp
    src/OgreAnimable.cpp
    src/OgreAnimation.cpp
    src/OgreAnimationState.cpp
    src/OgreAnimationTrack.cpp
    src/OgreArchive.cpp
    src/OgreArchiveManager.cpp
    src/OgreAtomicScalar.cpp
    src/OgreAutoParamDataSource.cpp
    src/OgreAxisAlignedBox.cpp
    src/OgreBillboard.cpp
    src/OgreBillboardChain.cpp
    src/OgreBillboardParticleRenderer.cpp
    src/OgreBillboardSet.cpp
    src/OgreBone.cpp
    src/OgreCamera.cpp
    src/OgreCodec.cpp
    src/OgreColourValue.cpp
    src/OgreCommon.cpp
    src/OgreCompositionPass.cpp
    src/OgreCompositionTargetPass.cpp
    src/OgreCompositionTechnique.cpp
    src/OgreCompositor.cpp
    src/OgreCompositorChain.cpp
    src/OgreCompositorInstance.cpp
    src/OgreCompositorManager.cpp
    src/OgreConfigFile.cpp
    src/OgreController.cpp
    src/OgreControllerManager.cpp
    src/OgreConvexBody.cpp
    src/OgreDataStream.cpp
    src/OgreDDSCodec.cpp
    src/OgreDefaultHardwareBufferManager.cpp
    src/OgreDefaultSceneQueries.cpp
    src/OgreDeflate.cpp
    src/OgreDepthBuffer.cpp
    src/OgreDistanceLodStrategy.cpp
    src/OgreDualQuaternion.cpp
    src/OgreDynLib.cpp
    src/OgreDynLibManager.cpp
    src/OgreEdgeListBuilder.cpp
    src/OgreEntity.cpp
    src/OgreETCCodec.cpp
    src/OgreException.cpp
    src/OgreExternalTextureSource.cpp
    src/OgreExternalTextureSourceManager.cpp
    src/OgreFileSystem.cpp
    src/OgreFrustum.cpp
    src/OgreGpuProgram.cpp
    src/OgreGpuProgramManager.cpp
    src/OgreGpuProgramParams.cpp
    src/OgreGpuProgramUsage.cpp
    src/OgreHardwareBufferManager.cpp
    src/OgreHardwareCounterBuffer.cpp
    src/OgreHardwareIndexBuffer.cpp
    src/OgreHardwareOcclusionQuery.cpp
    src/OgreHardwarePixelBuffer.cpp
    src/OgreHardwareUniformBuffer.cpp
    src/OgreHardwareVertexBuffer.cpp
    src/OgreHighLevelGpuProgram.cpp
    src/OgreHighLevelGpuProgramManager.cpp
    src/OgreImage.cpp
    src/OgreImageResampler.h
    src/OgreInstanceBatch.cpp
    src/OgreInstanceBatchHW.cpp
    src/OgreInstanceBatchHW_VTF.cpp
    src/OgreInstanceBatchShader.cpp
    src/OgreInstanceBatchVTF.cpp
    src/OgreInstancedEntity.cpp
    src/OgreInstancedGeometry.cpp
    src/OgreInstanceManager.cpp
    src/OgreKeyFrame.cpp
    src/OgreLight.cpp
    src/OgreLodStrategy.cpp
    src/OgreLodStrategyManager.cpp
    src/OgreLog.cpp
    src/OgreLogManager.cpp
    src/OgreManualObject.cpp
    src/OgreMaterial.cpp
    src/OgreMaterialManager.cpp
    src/OgreMaterialSerializer.cpp
    src/OgreMath.cpp
    src/OgreMatrix3.cpp
    src/OgreMatrix4.cpp
    src/OgreMemoryAllocatedObject.cpp
    src/OgreMemoryNedAlloc.cpp
    src/OgreMemoryTracker.cpp
    src/OgreMesh.cpp
    src/OgreMeshManager.cpp
    src/OgreMeshSerializer.cpp
    src/OgreMeshSerializerImpl.cpp
    src/OgreMovableObject.cpp
    src/OgreMovablePlane.cpp
    src/OgreNode.cpp
    src/OgreNumerics.cpp
    src/OgreOptimisedUtil.cpp
    src/OgreOptimisedUtilGeneral.cpp
    src/OgreOptimisedUtilSSE.cpp
    src/OgreParticle.cpp
    src/OgreParticleEmitter.cpp
    src/OgreParticleEmitterCommands.cpp
    src/OgreParticleIterator.cpp
    src/OgreParticleSystem.cpp
    src/OgreParticleSystemManager.cpp
    src/OgrePass.cpp
    src/OgrePatchMesh.cpp
    src/OgrePatchSurface.cpp
    src/OgrePixelConversions.h
    src/OgrePixelCountLodStrategy.cpp
    src/OgrePixelFormat.cpp
    src/OgrePlane.cpp
    src/OgrePlatformInformation.cpp
    src/OgrePolygon.cpp
    src/OgrePose.cpp
    src/OgrePrecompiledHeaders.cpp
    src/OgrePredefinedControllers.cpp
    src/OgrePrefabFactory.cpp
    src/OgreProfiler.cpp
    src/OgreProgressiveMeshGenerator.cpp
    src/OgrePVRTCCodec.cpp
    src/OgreQuaternion.cpp
    src/OgreQueuedProgressiveMeshGenerator.cpp
    src/OgreRectangle2D.cpp
    src/OgreRenderQueue.cpp
    src/OgreRenderQueueInvocation.cpp
    src/OgreRenderQueueSortingGrouping.cpp
    src/OgreRenderSystem.cpp
    src/OgreRenderSystemCapabilities.cpp
    src/OgreRenderSystemCapabilitiesManager.cpp
    src/OgreRenderSystemCapabilitiesSerializer.cpp
    src/OgreRenderTarget.cpp
    src/OgreRenderTexture.cpp
    src/OgreRenderToVertexBuffer.cpp
    src/OgreRenderWindow.cpp
    src/OgreResource.cpp
    src/OgreResourceBackgroundQueue.cpp
    src/OgreResourceGroupManager.cpp
    src/OgreResourceManager.cpp
    src/OgreRibbonTrail.cpp
    src/OgreRoot.cpp
    src/OgreRotationSpline.cpp
    src/OgreSceneManager.cpp
    src/OgreSceneManagerEnumerator.cpp
    src/OgreSceneNode.cpp
    src/OgreSceneQuery.cpp
    src/OgreScriptCompiler.cpp
    src/OgreScriptLexer.cpp
    src/OgreScriptParser.cpp
    src/OgreScriptTranslator.cpp
    src/OgreSearchOps.cpp
    src/OgreSerializer.cpp
    src/OgreShadowCameraSetup.cpp
    src/OgreShadowCameraSetupFocused.cpp
    src/OgreShadowCameraSetupLiSPSM.cpp
    src/OgreShadowCameraSetupPlaneOptimal.cpp
    src/OgreShadowCameraSetupPSSM.cpp
    src/OgreShadowCaster.cpp
    src/OgreShadowTextureManager.cpp
    src/OgreShadowVolumeExtrudeProgram.cpp
    src/OgreSIMDHelper.h
    src/OgreSimpleRenderable.cpp
    src/OgreSimpleSpline.cpp
    src/OgreSkeleton.cpp
    src/OgreSkeletonInstance.cpp
    src/OgreSkeletonManager.cpp
    src/OgreSkeletonSerializer.cpp
    src/OgreSmallVector.cpp
    src/OgreStaticGeometry.cpp
    src/OgreStreamSerialiser.cpp
    src/OgreString.cpp
    src/OgreStringConverter.cpp
    src/OgreStringInterface.cpp
    src/OgreSubEntity.cpp
    src/OgreSubMesh.cpp
    src/OgreTagPoint.cpp
    src/OgreTangentSpaceCalc.cpp
    src/OgreTechnique.cpp
    src/OgreTexture.cpp
    src/OgreTextureManager.cpp
    src/OgreTextureUnitState.cpp
    src/OgreUnifiedHighLevelGpuProgram.cpp
    src/OgreUserObjectBindings.cpp
    src/OgreUTFString.cpp
    src/OgreVector2.cpp
    src/OgreVector3.cpp
    src/OgreVector4.cpp
    src/OgreVertexIndexData.cpp
    src/OgreViewport.cpp
    src/OgreWindowEventUtilities.cpp
    src/OgreWireBoundingBox.cpp
    src/OgreWorkQueue.cpp)


#set_target_properties(OgreMain PROPERTIES
#    LINK_FLAGS "-framework IOKit -framework Cocoa -framework Carbon -framework OpenGL")


add_library(OgreMain OBJECT ${SOURCE_FILES})

#add_executable(OgreMain2
#               main.cpp
#               BaseApplication.cpp
#               ${SOURCE_FILES})
#
#add_executable(OgreMain
#               BareOgre.cpp
#               ExampleApplication.cpp
#               ${SOURCE_FILES})

#target_link_libraries(OgreMain ${CARBON_LIBRARY} ${COCOA_LIBRARY} ${IOKIT_LIBRARY})
