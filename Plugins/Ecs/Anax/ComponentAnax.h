#ifndef __AE_ECS_COMPONENT_ANAX__
#define __AE_ECS_COMPONENT_ANAX__

#include "Anima/Ecs/Component.h"

#include "anax/anax.hpp"

namespace AE
{
	namespace Ecs
	{
		class ComponentAnax : public AE::Ecs::Component, public anax::Component
		{
		public:
						ComponentAnax() {  }
			virtual		~ComponentAnax() {  }
		};
	}
}

#endif