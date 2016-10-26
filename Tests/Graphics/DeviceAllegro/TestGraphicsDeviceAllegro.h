#ifndef __TEST_EVENT_SDL__
#define __TEST_EVENT_SDL__

#include "Anima/PluginManager.h"

#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"

#include "Plugins/Graphics/Device/Sfml/ManagerSfml.h"

#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"

class TestListener : public AE::OS::KeyListener, public AE::OS::MouseListener
{
	void onKeyDown(const AE::OS::EventKeyboard &event);
	void onKeyUp(const AE::OS::EventKeyboard &event);

	void onButtonDown(const AE::OS::EventMouse &event);
	void onButtonUp(const AE::OS::EventMouse &event);
	void onMouseMove(const AE::OS::EventMouse &event);
};

#endif

