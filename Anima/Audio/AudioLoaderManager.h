#ifndef __AE_AUDIO_LOADER_MANAGER__
#define __AE_AUDIO_LOADER_MANAGER__

#include "Anima/Plugin.h"

namespace AE
{
	namespace Audio
	{
		class AudioLoaderManager : public AE::Plugin
		{
		public:
								AudioLoaderManager() : Plugin(AE::PT_AUDIO_LOADER_MANAGER) {}
			virtual				~AudioLoaderManager() {}

			virtual bool		Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
			virtual bool		Uninstall() = 0;



		protected:
			
		};
	}
}

#endif