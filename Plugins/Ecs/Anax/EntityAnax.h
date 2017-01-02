#ifndef __AE_ECS_ENTITY_ANAX__
#define __AE_ECS_ENTITY_ANAX__

#include "Anima/Ecs/Entity.h"

#include "anax/anax.hpp"

namespace AE
{
	namespace Ecs
	{
		class EntityAnax : public AE::Ecs::Entity
		{
		public:
			EntityAnax(anax::Entity &entity) : mEntity(entity) { mEntity.activate(); }
			virtual	~EntityAnax() { mEntity.kill(); }

		private:
			anax::Entity &mEntity;
		};
	}
}

#endif