#ifndef __ANIMA_ECS_MANAGER_ANAX__
#define __ANIMA_ECS_MANAGER_ANAX__

#include "Anima/Ecs/EcsManager.h"

#include "anax/anax.hpp"

#include <memory>

namespace AE
{
	namespace Ecs
	{
		class EcsManagerAnax : public AE::Ecs::EcsManager
		{
		public:
			EcsManagerAnax() { mWorld = new anax::World(); }
			virtual ~EcsManagerAnax() {}

			Entity CreateEntity();

		private:
			anax::World *mWorld;
		};
	}
}

#endif