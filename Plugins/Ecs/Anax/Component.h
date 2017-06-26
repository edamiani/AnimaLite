#ifndef __AE_ECS_COMPONENT_ANAX__
#define __AE_ECS_COMPONENT_ANAX__

#include "Anima/Ecs/Component.h"

#include "Anima/Types.h"

#include "anax/anax.hpp"

namespace AE
{
	namespace Ecs
	{
		class Component : public anax::Component
		{
		public:
						Component() {  }
			virtual		~Component() {  }

			void Step(AE::Real deltaTime) {}
		};

		/*class ComponentWrapperAnax : public AE::Ecs::Component
		{
		public:
			ComponentWrapperAnax(ComponentAnax &component) : mComponentAnax(component) {}
			~ComponentWrapperAnax() {}

			void Step(AE::Real deltaTime) {}

		private:
			ComponentAnax mComponentAnax;
		};*/
	}
}

#endif