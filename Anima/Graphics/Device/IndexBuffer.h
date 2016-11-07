#ifndef __ANIMA_GRAPHICS_DEVICE_INDEX_BUFFER__
#define __ANIMA_GRAPHICS_DEVICE_INDEX_BUFFER__

#include "Anima/Types.h"
#include "Anima/Graphics/Enums.h"

#include <cassert>

namespace AE
{
	namespace Graphics
	{
		namespace Device
		{
			class IndexBuffer
			{
			public:
				IndexBuffer() { }
				virtual ~IndexBuffer() { }

				virtual void	AddIndex(AE::ushort) = 0;
				virtual size_t	GetSize() = 0;
				virtual void	Lock() = 0;
				virtual void	Unlock() = 0;
			};
		}
	}
}

#endif