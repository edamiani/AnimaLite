cmake_minimum_required (VERSION 2.6)
project (AnimaLite)

option(Anima_BuildSharedLibs "Build DLLs?")
option(Anima_Temp "Build DLLs?")

option(AnimaMath_Mathfu "Uses mathfu as the math library" ON)
option(AnimaMath_Eigen "Uses Eigen as the math library" OFF)

add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/SDL2-2.0.4")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/mathfu")

include_directories("${PROJECT_SOURCE_DIR}")

include_directories("${PROJECT_SOURCE_DIR}/Dependencies/mathfu/include")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/mathfu/dependencies/vectorial/include")

if(Anima_BuildSharedLibs)
	set(SDL_LIB SDL2)
else()
	set(SDL_LIB SDL2-static)
endif()

if(AnimaMath_Mathfu)
	file(WRITE Anima/Math/Vector2.h "#ifndef __AE_MATH_VECTOR2__\n#define __AE_MATH_VECTOR2__\n\n#include \"Plugins/Math/MathMathfu/Vector2.h\"\n\n#endif")
endif()

add_library(AeCore STATIC
	Anima/Plugin.h
	Anima/Plugin.cpp
	Anima/PluginGroup.h
	Anima/PluginGroup.cpp
	Anima/PluginManager.h
	Anima/PluginManager.cpp
	Anima/PluginRoot.h
	Anima/PluginRoot.cpp)
	
add_library(AeEventCore STATIC
	Anima/OS/Event.h
	Anima/OS/EventListener.h
	Anima/OS/EventManager.h
	Anima/OS/EventQueue.h
	Anima/OS/EventQueue.cpp
	Anima/OS/KeyListener.h
	Anima/OS/MouseListener.h
	Anima/OS/WindowListener.h)
target_link_libraries(AeEventCore AeCore)

add_library(AeWindowCore STATIC
	Anima/OS/Window.h
	Anima/OS/Window.cpp
	Anima/OS/WindowDesc.h
	Anima/OS/WindowManager.h
	Anima/OS/WindowManager.cpp)
target_link_libraries(AeWindowCore AeCore)

add_library(AeEventSdl STATIC
	Plugins/OS/EventSdl/EventManagerSdl.h
	Plugins/OS/EventSdl/EventManagerSdl.cpp
	Plugins/OS/EventSdl/EventQueueSdl.h
	Plugins/OS/EventSdl/EventQueueSdl.cpp)
target_link_libraries(AeEventSdl AeEventCore "${SDL_LIB}")
	
add_library(AeWindowSdl STATIC
	Plugins/OS/WindowSdl/WindowSdl.h 
	Plugins/OS/WindowSdl/WindowSdl.cpp
	Plugins/OS/WindowSdl/WindowManagerSdl.h
	Plugins/OS/WindowSdl/WindowManagerSdl.cpp)
target_link_libraries(AeWindowSdl AeWindowCore "${SDL_LIB}")

if(Anima_BuildSharedLibs)
	target_compile_definitions(WindowCore PRIVATE AE_EXPORT_DLL)
	target_compile_definitions(WindowSdl PRIVATE AE_EXPORT_DLL)
endif()

#if(SDL_SHARED)
#	target_link_libraries (WindowSdl SDL2)
#endif()

#if(SDL_STATIC)
#	target_link_libraries (WindowSdl SDL2-static)
#endif()

add_executable(TestWindowSdl 
	Tests/OS/WindowSdl/TestWindowSdl.h
	Tests/OS/WindowSdl/TestWindowSdl.cpp)
target_link_libraries(TestWindowSdl AeEventSdl AeWindowSdl SDL2main)

#install(TARGETS SDL2 RUNTIME DESTINATION bin)