#ifndef __TEST_EVENT_SDL__
#define __TEST_EVENT_SDL__

#include "Anima/PluginManager.h"

#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"

#include "Plugins/Animation/Choreograph/AnimationManagerChoreograph.h"
#include "Plugins/Graphics/Device/Sfml/ManagerSfml.h"
#include "Plugins/Graphics/Image/Sfml/ImageManagerSfml.h"
#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/TimerSdl/TimerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"

class TestListener : public AE::OS::KeyListener, public AE::OS::MouseListener, public AE::OS::WindowListener
{
	void OnKeyDown(const AE::OS::EventKeyboard &event);
	void OnKeyUp(const AE::OS::EventKeyboard &event);

	void OnButtonDown(const AE::OS::EventMouse &event);
	void OnButtonUp(const AE::OS::EventMouse &event);
	void OnMouseMove(const AE::OS::EventMouse &event);

	void onClose(AE::OS::WindowPtr window) { window->Close(); }
};

#endif

