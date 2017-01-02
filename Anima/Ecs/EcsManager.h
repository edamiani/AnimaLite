#ifndef __ANIMA_ECS_MANAGER__
#define __ANIMA_ECS_MANAGER__

#include "Anima/Plugin.h"

#include "Anima/Ecs/Entity.h"

namespace AE
{
	namespace Ecs
	{
		class EcsManager
		{
		protected:

		public:
			EcsManager() : AE::Plugin(AE::PT_ECS_MANAGER) {}
			virtual ~EcsManager() {}

			virtual Entity CreateEntity() = 0;
			virtual void RegisterComponent() = 0;
		};
	}
}

#endif