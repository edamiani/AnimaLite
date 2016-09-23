cmake_minimum_required (VERSION 2.6)
project (AnimaLite)

option(BUILD_SHARED_LIBS "Build DLLs?")

add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/SDL2-2.0.4")

include_directories("${PROJECT_SOURCE_DIR}")

add_library(WindowCore STATIC
	Engine/OS/EventQueue.h
	Engine/OS/EventQueue.cpp
	Engine/OS/Window.h
	Engine/OS/Window.cpp
	Engine/OS/WindowDesc.h
	Engine/OS/WindowManager.h
	Engine/OS/WindowManager.cpp)
	
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