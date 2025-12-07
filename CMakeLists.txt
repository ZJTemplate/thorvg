# ThorVG CMakeLists.txt
# Exports sources, includes, and compile definitions to parent scope for direct compilation

cmake_minimum_required(VERSION 3.5)

set(THORVG_NAME thorvg)
project(${THORVG_NAME} CXX)

# Set ThorVG root directory
set(THORVG_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(LOTTIE_EXPRESSIONS_SUPPORT 1)
# Check if LOTTIE_EXPRESSIONS_SUPPORT is defined in parent scope, default to 0 if not
if(NOT DEFINED LOTTIE_EXPRESSIONS_SUPPORT)
    set(LOTTIE_EXPRESSIONS_SUPPORT 0)
endif()

# Add jerryscript subdirectory only if LOTTIE_EXPRESSIONS_SUPPORT is enabled
set(JERRY_CORE_SOURCES "")
set(JERRY_CORE_INCLUDE_DIRS "")
set(JERRY_CORE_COMPILE_DEFINITIONS "")
if(LOTTIE_EXPRESSIONS_SUPPORT)
    set(JERRYSCRIPT_ROOT ${THORVG_ROOT}/src/loaders/lottie/jerryscript)
    set(JERRY_CORE_DIR ${JERRYSCRIPT_ROOT}/jerry-core)
    add_subdirectory(${JERRY_CORE_DIR} ${CMAKE_BINARY_DIR}/jerry-core EXCLUDE_FROM_ALL)
endif()

# ThorVG source files
set(THORVG_SOURCES
    ${THORVG_ROOT}/src/common/tvgColor.cpp
    ${THORVG_ROOT}/src/common/tvgCompressor.cpp
    ${THORVG_ROOT}/src/common/tvgMath.cpp
    ${THORVG_ROOT}/src/common/tvgStr.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieAnimation.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieBuilder.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieExpressions.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieInterpolator.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieLoader.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieModel.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieModifier.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieParser.cpp
    ${THORVG_ROOT}/src/loaders/lottie/tvgLottieParserHandler.cpp
    ${THORVG_ROOT}/src/loaders/raw/tvgRawLoader.cpp
    ${THORVG_ROOT}/src/loaders/external_png/tvgPngLoader.cpp
    ${THORVG_ROOT}/src/loaders/external_webp/tvgWebpLoader.cpp
    ${THORVG_ROOT}/src/loaders/external_jpg/tvgJpgLoader.cpp
    ${THORVG_ROOT}/src/loaders/external_ttf/tvgTtfLoader.cpp
    ${THORVG_ROOT}/src/loaders/external_ttf/tvgTtfReader.cpp
    ${THORVG_ROOT}/src/loaders/svg/tvgSvgCssStyle.cpp
    ${THORVG_ROOT}/src/loaders/svg/tvgSvgLoader.cpp
    ${THORVG_ROOT}/src/loaders/svg/tvgSvgPath.cpp
    ${THORVG_ROOT}/src/loaders/svg/tvgSvgSceneBuilder.cpp
    ${THORVG_ROOT}/src/loaders/svg/tvgSvgUtil.cpp
    ${THORVG_ROOT}/src/loaders/svg/tvgXmlParser.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGl.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlEffect.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlGeometry.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlGpuBuffer.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlProgram.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlRenderPass.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlRenderTarget.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlRenderTask.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlRenderer.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlShader.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlShaderSrc.cpp
    ${THORVG_ROOT}/src/renderer/gl_engine/tvgGlTessellator.cpp
    ${THORVG_ROOT}/src/renderer/tvgAccessor.cpp
    ${THORVG_ROOT}/src/renderer/tvgAnimation.cpp
    ${THORVG_ROOT}/src/renderer/tvgCanvas.cpp
    ${THORVG_ROOT}/src/renderer/tvgFill.cpp
    ${THORVG_ROOT}/src/renderer/tvgInitializer.cpp
    ${THORVG_ROOT}/src/renderer/tvgLoader.cpp
    ${THORVG_ROOT}/src/renderer/tvgPaint.cpp
    ${THORVG_ROOT}/src/renderer/tvgPicture.cpp
    ${THORVG_ROOT}/src/renderer/tvgRender.cpp
    ${THORVG_ROOT}/src/renderer/tvgSaver.cpp
    ${THORVG_ROOT}/src/renderer/tvgScene.cpp
    ${THORVG_ROOT}/src/renderer/tvgShape.cpp
    ${THORVG_ROOT}/src/renderer/tvgTaskScheduler.cpp
    ${THORVG_ROOT}/src/renderer/tvgText.cpp
)

# Combine ThorVG sources with JerryScript sources (if enabled) and export to parent scope
set(THORVG_ALL_SOURCES
    ${THORVG_SOURCES}
)
if(LOTTIE_EXPRESSIONS_SUPPORT)
    list(APPEND THORVG_ALL_SOURCES ${JERRY_CORE_SOURCES})
endif()
set(THORVG_SOURCES ${THORVG_ALL_SOURCES} PARENT_SCOPE)

# Include directories - separate PUBLIC and PRIVATE
set(THORVG_ALL_INCLUDE_DIRS
    ${THORVG_ROOT}/inc
    ${THORVG_ROOT}/src
    ${THORVG_ROOT}/src/common
    ${THORVG_ROOT}/src/renderer
    ${THORVG_ROOT}/src/loaders
    ${THORVG_ROOT}/src/loaders/lottie
    ${THORVG_ROOT}/src/loaders/svg
    ${THORVG_ROOT}/src/loaders/raw
    ${THORVG_ROOT}/src/loaders/ttf
    ${THORVG_ROOT}/src/loaders/external_png
    ${THORVG_ROOT}/src/loaders/external_webp
    ${THORVG_ROOT}/src/loaders/external_jpg
    ${THORVG_ROOT}/src/loaders/external_ttf
    ${THORVG_ROOT}/src/renderer/gl_engine
    ${THORVG_ROOT}
)
if(LOTTIE_EXPRESSIONS_SUPPORT)
    list(APPEND THORVG_ALL_INCLUDE_DIRS ${JERRY_CORE_INCLUDE_DIRS})
endif()

# Separate PUBLIC (inc/) and PRIVATE include directories
set(THORVG_PUBLIC_INCLUDE_DIRS "")
set(THORVG_PRIVATE_INCLUDE_DIRS "")
foreach(INCLUDE_DIR ${THORVG_ALL_INCLUDE_DIRS})
    # Check if this is the public inc directory (ends with /inc)
    get_filename_component(INCLUDE_DIR_BASE ${INCLUDE_DIR} NAME)
    if(INCLUDE_DIR_BASE STREQUAL "inc")
        list(APPEND THORVG_PUBLIC_INCLUDE_DIRS ${INCLUDE_DIR})
    else()
        list(APPEND THORVG_PRIVATE_INCLUDE_DIRS ${INCLUDE_DIR})
    endif()
endforeach()

set(THORVG_PUBLIC_INCLUDE_DIRS ${THORVG_PUBLIC_INCLUDE_DIRS} PARENT_SCOPE)
set(THORVG_PRIVATE_INCLUDE_DIRS ${THORVG_PRIVATE_INCLUDE_DIRS} PARENT_SCOPE)

# Compile definitions (PRIVATE only, PUBLIC definitions are set in parent)
set(THORVG_COMPILE_DEFINITIONS
    GL_GLEXT_PROTOTYPES
)

# Add Lottie expressions support if enabled
if(LOTTIE_EXPRESSIONS_SUPPORT)
    list(APPEND THORVG_COMPILE_DEFINITIONS THORVG_LOTTIE_EXPRESSIONS_SUPPORT)
    list(APPEND THORVG_COMPILE_DEFINITIONS ${JERRY_CORE_COMPILE_DEFINITIONS})
endif()

# Thread support (controlled by PTHREAD variable from parent scope)
# -pthread flag is already added to CMAKE_CXX_FLAGS globally, no need to add again
if(PTHREAD)
    list(APPEND THORVG_COMPILE_DEFINITIONS THORVG_THREAD_SUPPORT)
endif()

set(THORVG_COMPILE_DEFINITIONS ${THORVG_COMPILE_DEFINITIONS} PARENT_SCOPE)

