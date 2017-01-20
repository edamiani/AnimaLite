#ifndef __TEST_EVENT_SDL__
#define __TEST_EVENT_SDL__

#include "Anima/PluginManager.h"

#include "Anima/OS/KeyListener.h"
#include "Anima/OS/MouseListener.h"

#include "Plugins/Graphics/Device/Sfml/ManagerSfml.h"
#include "Plugins/Graphics/Image/Sfml/ImageManagerSfml.h"

#include "Plugins/OS/EventSdl/EventManagerSdl.h"
#include "Plugins/OS/WindowSdl/WindowSdl.h"
#include "Plugins/OS/WindowSdl/WindowManagerSdl.h"

#include "Box2D/Box2D.h"

class TestListener : public AE::OS::KeyListener, public AE::OS::MouseListener, public AE::OS::WindowListener, public b2ContactListener
{
	void OnKeyDown(const AE::OS::EventKeyboard &event);
	void OnKeyUp(const AE::OS::EventKeyboard &event);

	void OnButtonDown(const AE::OS::EventMouse &event);
	void OnButtonUp(const AE::OS::EventMouse &event);
	void OnMouseMove(const AE::OS::EventMouse &event);

	void onClose(AE::OS::WindowPtr window) { window->Close(); }

	// Callbacks for derived classes.
	virtual void BeginContact(b2Contact* contact);
	virtual void EndContact(b2Contact* contact) { B2_NOT_USED(contact); }
	virtual void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(oldManifold);
	}
	virtual void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
	{
		B2_NOT_USED(contact);
		B2_NOT_USED(impulse);
	}
};

#endif

