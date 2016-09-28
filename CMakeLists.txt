cmake_minimum_required (VERSION 2.6)
project (AnimaLite)

option(BUILD_SHARED_LIBS "Build DLLs?")

add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/SDL2-2.0.4")

include_directories("${PROJECT_SOURCE_DIR}")

add_library(AnimaCore STATIC
	Anima/Plugin.h
	Anima/Plugin.cpp
	Anima/PluginGroup.h
	Anima/PluginGroup.cpp
	Anima/PluginManager.h
	Anima/PluginManager.cpp
	Anima/PluginRoot.h
	Anima/PluginRoot.cpp)
	
add_library(EventCore STATIC
	Anima/OS/Event.h
	Anima/OS/EventListener.h
	Anima/OS/EventManager.h
	Anima/OS/EventQueue.h
	Anima/OS/EventQueue.cpp)
target_link_libraries(EventCore AnimaCore)

add_library(WindowCore STATIC
	Anima/OS/EventQueue.h
	Anima/OS/EventQueue.cpp
	Anima/OS/Window.h
	Anima/OS/Window.cpp
	Anima/OS/WindowDesc.h
	Anima/OS/WindowManager.h
	Anima/OS/WindowManager.cpp)
target_link_libraries(WindowCore AnimaCore)

add_library(EventSdl STATIC
	Plugins/OS/EventSdl/EventManagerSdl.h
	Plugins/OS/EventSdl/EventManagerSdl.cpp
	Plugins/OS/EventSdl/EventQueueSdl.h
	Plugins/OS/EventSdl/EventQueueSdl.cpp)
target_link_libraries(EventSdl EventCore)
	
add_library(WindowSdl
	Plugins/OS/WindowSdl/EventQueueSdl.h
	Plugins/OS/WindowSdl/EventQueueSdl.cpp
	Plugins/OS/WindowSdl/WindowSdl.h 
	Plugins/OS/WindowSdl/WindowSdl.cpp
	Plugins/OS/WindowSdl/WindowManagerSdl.h
	Plugins/OS/WindowSdl/WindowManagerSdl.cpp)
target_link_libraries(WindowSdl WindowCore SDL2 SDL2main)

if(BUILD_SHARED_LIBS)
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
target_link_libraries(TestWindowSdl WindowSdl)

#install(TARGETS SDL2 RUNTIME DESTINATION bin)