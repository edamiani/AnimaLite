#ifndef __TEST_WINDOW_SDL__
#define __TEST_WINDOW_SDL__

#include "Anima/PluginManager.h"

#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"


class TestListener : public AE::OS::WindowListener
{
	void onClose(AE::OS::WindowPtr window) { window->Close(); }
};

#endif