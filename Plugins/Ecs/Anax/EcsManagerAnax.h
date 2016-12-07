#ifndef __ANIMA_ECS_MANAGER_ANAX__
#define __ANIMA_ECS_MANAGER_ANAX__

#include "Anima/Ecs/EcsManager.h"

#include "anax/anax.hpp"

namespace AE
{
	namespace Ecs
	{
		class EcsManagerAnax : public AE::Ecs::EcsManager
		{
		public:
			EcsManagerAnax() {}
			virtual ~EcsManagerAnax() {}

		private:
			anax::World world;
		};
	}
}

#endif