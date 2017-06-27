#include "EcsManagerAnax.h"

#include "EntityAnax.h"

namespace AE
{
	namespace Ecs
	{
		Entity EcsManagerAnax::CreateEntity()
		{
			anax::Entity entity = mWorld->createEntity();

			return EntityAnax(entity);
		}

		void EcsManagerAnax::RegisterComponent()
		{

		}
	}
}