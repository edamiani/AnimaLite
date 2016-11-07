#ifndef __AE_OS_MOUSE_LISTENER__
#define __AE_OS_MOUSE_LISTENER__

namespace AE
{
	namespace OS
	{
		class MouseListener
		{
		public:
			MouseListener() {}
			virtual ~MouseListener() {}

			// Mouse events
			virtual void OnButtonDown(const AE::OS::EventMouse &event) { }
			virtual void OnButtonUp(const AE::OS::EventMouse &event) { }
			virtual void OnMouseMove(const AE::OS::EventMouse &event) { }
		};

		typedef std::unique_ptr<MouseListener> MouseListenerPtr;
	}
}

#endif