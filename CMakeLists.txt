cmake_minimum_required (VERSION 3.0)
project (AnimaLite)

set(wxWidgets_CONFIGURATION mswu)
set(wxWidgets_ROOT_DIR ${PROJECT_SOURCE_DIR}/Dependencies/wxWidgets)
set(wxWidgets_LIB_DIR ${PROJECT_SOURCE_DIR}/Dependencies/wxWidgets/lib/vc140_x64_dll)
find_package(wxWidgets COMPONENTS core base REQUIRED)
#include(${wxWidgets_USE_FILE})

option(Anima_BuildSharedLibs "Build DLLs?")
option(Anima_Temp "Build DLLs?")

option(AnimaMath_Mathfu "Uses mathfu as the math library" ON)
option(AnimaMath_Eigen "Uses Eigen as the math library" OFF)

#add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/allegro")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/anax")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/bullet3")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/Box2D/Box2D")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/Choreograph")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/SDL2-2.0.4")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/SFML")
add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/mathfu")
#add_subdirectory ("${PROJECT_SOURCE_DIR}/Dependencies/DevIL/DevIL")

include_directories("${PROJECT_SOURCE_DIR}")

#include_directories("${PROJECT_SOURCE_DIR}/Dependencies/allegro/include")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/anax/include")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/bullet3/src")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/Box2D/Box2D")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/Choreograph/src")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/SFML/include")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/mathfu/include")
include_directories("${PROJECT_SOURCE_DIR}/Dependencies/mathfu/dependencies/vectorial/include")
#include_directories("${PROJECT_SOURCE_DIR}/Dependencies/DevIL/DevIL/include")

if(Anima_BuildSharedLibs)
	set(SDL_LIB SDL2)
	#set(ALLEGRO_LIB allegro-static)
else()
	set(SDL_LIB SDL2-static)
	#set(ALLEGRO_LIB allegro)
endif()

if(AnimaMath_Mathfu)
	file(WRITE Anima/Math/Matrix3.h "#ifndef __AE_MATH_MATRIX3__\n#define __AE_MATH_MATRIX3__\n\n#include \"Plugins/Math/MathMathfu/Matrix3.h\"\n\n#endif")
	file(WRITE Anima/Math/Transform2.h "#ifndef __AE_MATH_TRANSFORM2__\n#define __AE_MATH_TRANSFORM2__\n\n#include \"Plugins/Math/MathMathfu/Transform2.h\"\n\n#endif")
	file(WRITE Anima/Math/Vector2.h "#ifndef __AE_MATH_VECTOR2__\n#define __AE_MATH_VECTOR2__\n\n#include \"Plugins/Math/MathMathfu/Vector2.h\"\n\n#endif")
	file(WRITE Anima/Math/Vector3.h "#ifndef __AE_MATH_VECTOR3__\n#define __AE_MATH_VECTOR3__\n\n#include \"Plugins/Math/MathMathfu/Vector3.h\"\n\n#endif")
endif()

add_library(AeCore STATIC
	Anima/Plugin.h
	Anima/Plugin.cpp
	Anima/PluginGroup.h
	Anima/PluginGroup.cpp
	Anima/PluginManager.h
	Anima/PluginManager.cpp
	Anima/PluginOptions.h
	Anima/PluginRoot.h
	Anima/PluginRoot.cpp)
	
add_library(AeInputCore STATIC
	Anima/Input/Device.h
	Anima/Input/Joystick.h
	Anima/Input/Keyboard.h
	Anima/Input/KeyInfo.h
	Anima/Input/Manager.h
	Anima/Input/Mouse.h)
target_link_libraries(AeInputCore AeCore)

add_library(AeMathMathfu STATIC
	Plugins/Math/MathMathfu/Matrix3.h
	Plugins/Math/MathMathfu/Transform2.h
	Plugins/Math/MathMathfu/Vector2.h
	Plugins/Math/MathMathfu/Vector3.h)
target_link_libraries(AeMathMathfu AeCore)

add_library(AeInputSdl STATIC
	Plugins/Input/Sdl/InputManagerSdlDesc.h
	Plugins/Input/Sdl/JoystickSdl.h
	Plugins/Input/Sdl/KeyboardSdl.h
	Plugins/Input/Sdl/KeyInfoSdl.h
	Plugins/Input/Sdl/KeyInfoSdl.cpp
	Plugins/Input/Sdl/ManagerSdl.h
	Plugins/Input/Sdl/MouseSdl.h)
#target_link_libraries(AeInputSdl AeInputCore)

add_library(AeOsTimerCore STATIC
	Anima/OS/Timer.h)
target_link_libraries(AeOsTimerCore AeCore)

add_library(AeOsTimerSdl STATIC
	Plugins/OS/TimerSdl/TimerSdl.h)
target_link_libraries(AeOsTimerSdl AeOsTimerCore)

add_library(AeAiFsmCore STATIC
	Anima/AI/FsmMachine.h
	Anima/AI/FsmMachine.cpp
	Anima/AI/FsmState.h)
target_link_libraries(AeAiFsmCore AeCore)

add_library(AeAnimationCore STATIC
	Anima/Animation/Animation.h
	Anima/Animation/AnimationManager.h
	Anima/Animation/Easing.h
	Anima/Animation/Range.h)
target_link_libraries(AeAnimationCore AeCore)

add_library(AeAnimationChoreograph STATIC
	Plugins/Animation/Choreograph/AnimationChoreograph.h
	Plugins/Animation/Choreograph/AnimationManagerChoreograph.h
	Plugins/Animation/Choreograph/EasingChoreograph.h
	Plugins/Animation/Choreograph/RangeChoreograph.h)
target_link_libraries(AeAnimationChoreograph AeAnimationCore Choreograph)

add_library(AeEcsCore STATIC
	Anima/Ecs/Component.h
	Anima/Ecs/EcsManager.h
	Anima/Ecs/Entity.h)
target_link_libraries(AeEcsCore AeCore)

add_library(AeEcsAnax STATIC
	Plugins/Ecs/Anax/ComponentAnax.h
	Plugins/Ecs/Anax/EcsManagerAnax.h
	Plugins/Ecs/Anax/EcsManagerAnax.cpp
	Plugins/Ecs/Anax/EntityAnax.h)
target_link_libraries(AeEcsAnax AeEcsCore anax)
	
add_library(AeOsEventCore STATIC
	Anima/OS/Event.h
	Anima/OS/EventListener.h
	Anima/OS/EventManager.h
	Anima/OS/EventQueue.h
	Anima/OS/EventQueue.cpp
	Anima/OS/KeyListener.h
	Anima/OS/MouseListener.h
	Anima/OS/WindowListener.h)
target_link_libraries(AeOsEventCore AeCore)

add_library(AeOsWindowCore STATIC
	Anima/OS/Window.h
	Anima/OS/Window.cpp
	Anima/OS/WindowDesc.h
	Anima/OS/WindowManager.h
	Anima/OS/WindowManager.cpp)
target_link_libraries(AeOsWindowCore AeCore)

add_library(AeGraphicsImageSfml STATIC
	Plugins/Graphics/Image/Sfml/ImageManagerSfml.h
	Plugins/Graphics/Image/Sfml/ImageManagerSfml.cpp
	Plugins/Graphics/Image/Sfml/ImageSfml.h
	Plugins/Graphics/Image/Sfml/ImageSfml.cpp)
target_link_libraries(AeGraphicsImageSfml sfml-graphics)

add_library(AeGraphicsDeviceCore STATIC
	Anima/Graphics/Device/Context.h
	Anima/Graphics/Device/ContextDesc.h
	Anima/Graphics/Device/Driver.h
	Anima/Graphics/Device/Driver.cpp
	Anima/Graphics/Device/FragmentShader.h
	Anima/Graphics/Device/IndexBuffer.h
	Anima/Graphics/Device/Manager.cpp
	Anima/Graphics/Device/Manager.h
	Anima/Graphics/Device/Pipeline.cpp
	Anima/Graphics/Device/Pipeline.h
	Anima/Graphics/Device/Shader.h
	Anima/Graphics/Device/Texture.h
	Anima/Graphics/Device/VertexBuffer.h
	Anima/Graphics/Device/VertexShader.h)
target_link_libraries(AeGraphicsDeviceCore AeCore)

#[[
add_library(AeGraphicsDeviceAllegro STATIC
	Plugins/Graphics/Device/Allegro/ColorBufferAllegro.h
	Plugins/Graphics/Device/Allegro/ColorBufferAllegro.cpp
	Plugins/Graphics/Device/Allegro/ContextAllegro.h
	Plugins/Graphics/Device/Allegro/ContextAllegro.cpp
	Plugins/Graphics/Device/Allegro/DriverAllegro.h
	Plugins/Graphics/Device/Allegro/DriverAllegro.cpp
	Plugins/Graphics/Device/Allegro/ManagerAllegro.h
	Plugins/Graphics/Device/Allegro/ManagerAllegro.cpp)
target_link_libraries(AeGraphicsDeviceAllegro AeGraphicsDeviceCore "${ALLEGRO_LIB}")
]]

#[[
if(NOT Anima_BuildSharedLibs)
	target_compile_definitions(AeGraphicsDeviceAllegro PRIVATE ALLEGRO_STATICLINK)
endif()
]]

#[[
add_library(AeGraphicsDeviceSdl STATIC
	Plugins/Graphics/Device/Sdl/ContextSdl.h
	Plugins/Graphics/Device/Sdl/ContextSdl.cpp
	Plugins/Graphics/Device/Sdl/DriverSdl.h
	Plugins/Graphics/Device/Sdl/DriverSdl.cpp
	Plugins/Graphics/Device/Sdl/ManagerSdl.h
	Plugins/Graphics/Device/Sdl/ManagerSdl.cpp)
target_link_libraries(AeGraphicsDeviceSdl AeGraphicsDeviceCore)
]]

add_library(AeGraphicsDeviceSfml STATIC
	Plugins/Graphics/Device/Sfml/ContextSfml.h
	Plugins/Graphics/Device/Sfml/ContextSfml.cpp
	Plugins/Graphics/Device/Sfml/DriverSfml.h
	Plugins/Graphics/Device/Sfml/DriverSfml.cpp
	Plugins/Graphics/Device/Sfml/ManagerSfml.h
	Plugins/Graphics/Device/Sfml/ManagerSfml.cpp
	Plugins/Graphics/Device/Sfml/PipelineSfml.h
	Plugins/Graphics/Device/Sfml/PipelineSfml.cpp
	Plugins/Graphics/Device/Sfml/ShaderSfml.h
	Plugins/Graphics/Device/Sfml/ShaderSfml.cpp
	Plugins/Graphics/Device/Sfml/TextureSfml.h
	Plugins/Graphics/Device/Sfml/TextureSfml.cpp)
target_link_libraries(AeGraphicsDeviceSfml AeGraphicsDeviceCore sfml-graphics)
target_compile_definitions(AeGraphicsDeviceSfml PRIVATE SFML_STATIC)

add_library(AeOsEventSdl STATIC
	Plugins/OS/EventSdl/EventManagerSdl.h
	Plugins/OS/EventSdl/EventManagerSdl.cpp
	Plugins/OS/EventSdl/EventQueueSdl.h
	Plugins/OS/EventSdl/EventQueueSdl.cpp)
target_link_libraries(AeOsEventSdl AeOsEventCore AeInputSdl "${SDL_LIB}")
	
add_library(AeOsWindowSdl STATIC
	Plugins/OS/WindowSdl/WindowSdl.h 
	Plugins/OS/WindowSdl/WindowSdl.cpp
	Plugins/OS/WindowSdl/WindowManagerSdl.h
	Plugins/OS/WindowSdl/WindowManagerSdl.cpp)
target_link_libraries(AeOsWindowSdl AeOsWindowCore "${SDL_LIB}")

add_library(AeAudioCore STATIC
	Anima/Audio/AudioManager.h
	Anima/Audio/Music.h
	Anima/Audio/Sound.h)
target_link_libraries(AeAudioCore AeCore)

add_library(AeAudioSfml STATIC
	Plugins/Audio/Sfml/AudioManagerSfml.h
	Plugins/Audio/Sfml/MusicSfml.h
	Plugins/Audio/Sfml/SoundSfml.h)
target_link_libraries(AeAudioSfml AeAudioCore)

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

add_executable(TestWindow 
	Tests/OS/WindowSdl/TestWindowSdl.h
	Tests/OS/WindowSdl/TestWindowSdl.cpp)
target_link_libraries(TestWindow AeOsEventSdl AeOsWindowSdl SDL2main)

add_executable(TestEvent 
	Tests/OS/EventSdl/TestEventSdl.h
	Tests/OS/EventSdl/TestEventSdl.cpp)
target_link_libraries(TestEvent AeOsEventSdl AeOsWindowSdl SDL2main)

add_executable(TestGraphicsDevice 
	Tests/Graphics/Deviceallegro/TestGraphicsDeviceAllegro.h
	Tests/Graphics/Deviceallegro/TestGraphicsDeviceAllegro.cpp)
target_link_libraries(TestGraphicsDevice AeGraphicsDeviceSfml AeGraphicsImageSfml AeOsEventSdl AeOsWindowSdl SDL2main)

add_executable(TestPhysicsBox2D 
	Tests/Physics/Box2D/TestPhysicsBox2D.h
	Tests/Physics/Box2D/TestPhysicsBox2D.cpp)
target_link_libraries(TestPhysicsBox2D AeGraphicsDeviceSfml AeGraphicsImageSfml AeOsEventSdl AeOsWindowSdl SDL2main Box2D)

add_executable(GamePongPrototype
	Games/PongPrototype/Game.h
	Games/PongPrototype/Game.cpp
	Games/PongPrototype/GameController.h
	Games/PongPrototype/GameController.cpp
	Games/PongPrototype/GameModel.h
	Games/PongPrototype/GameModel.cpp
	Games/PongPrototype/GameView.h
	Games/PongPrototype/GameView.cpp)
target_link_libraries(GamePongPrototype AeOsEventSdl AeOsWindowSdl AeGraphicsDeviceSfml AeGraphicsImageSfml SDL2main)

#install(TARGETS SDL2 RUNTIME DESTINATION bin)