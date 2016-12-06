#ifndef __ANIMA_ECS_MANAGER__
#define __ANIMA_ECS_MANAGER__

#include "Anima/Plugin.h"

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
		};
	}
}

#endif