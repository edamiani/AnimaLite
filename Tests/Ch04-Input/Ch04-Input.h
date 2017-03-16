#ifndef __TEST_CH04_INPUT__
#define __TEST_CH04_INPUT__

#include "Anima/PluginManager.h"

#include "Anima/Input/InputManagerDesc.h"
#include "Anima/Input/Joystick.h"
#include "Anima/Input/Keyboard.h"
#include "Anima/Input/Mouse.h"
#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"
#include "Anima/OS/WindowListener.h"
#include "Plugins/Input/Sdl/ManagerSdl.h"
#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"

class TestListener : public AE::OS::KeyListener, public AE::OS::MouseListener, public AE::OS::WindowListener
{
	void onClose(AE::OS::WindowPtr window) { window->Close(); }
};

#endif

