#ifndef __TEST_CH02_EVENT__
#define __TEST_CH02_EVENT__

#include "Anima/MainLoop.h"
#include "Anima/PluginManager.h"

#include "Anima/OS/JoystickListener.h"
#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"
#include "Anima/OS/WindowListener.h"
#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"

class TestListener : public AE::OS::JoystickListener, public AE::OS::KeyListener, public AE::OS::MouseListener, public AE::OS::WindowListener
{
	void OnAxisMove(const AE::OS::EventJoystick &event);
	void OnButtonDown(const AE::OS::EventJoystick &event);
	void OnButtonUp(const AE::OS::EventJoystick &event);
	void OnHatMove(const AE::OS::EventJoystick &event);


	void OnKeyDown(const AE::OS::EventKeyboard &event);
	void OnKeyUp(const AE::OS::EventKeyboard &event);

	void OnButtonDown(const AE::OS::EventMouse &event);
	void OnButtonUp(const AE::OS::EventMouse &event);
	void OnMouseMove(const AE::OS::EventMouse &event);

	void onClose(AE::OS::WindowPtr window) { window->Close(); }
};

#endif

