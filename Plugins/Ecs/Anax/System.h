#ifndef __ANIMA_ECS_SYSTEM_ANAX__
#define __ANIMA_ECS_SYSTEM_ANAX__

#include "anax/anax.hpp"

namespace AE
{
	namespace Ecs
	{
		template<typename... Args>
		class System : public anax::System<anax::Requires<Args...>>
		{

		};
	}
}

#endif