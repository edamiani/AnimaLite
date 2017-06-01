#ifndef __AE_AUDIO_SPATIAL_MANAGER__
#define __AE_AUDIO_SPATIAL_MANAGER__

#include "Anima/Plugin.h"

namespace AE
{
	namespace Audio
	{
		class AudioSpatialManager : public AE::Plugin
		{
		public:
			AudioSpatialManager() : Plugin(AE::PT_AUDIO_SPATIAL_MANAGER) {}
			virtual				~AudioSpatialManager() {}

			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool		Uninstall() = 0;



		protected:

		};
	}
}

#endif