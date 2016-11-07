#ifndef __AE_PLUGIN_ROOT__
#define __AE_PLUGIN_ROOT__

#include "Anima/PluginGroup.h"

#include <map>

namespace AE
{	
	class PluginManager;

	class PluginRoot : public AE::PluginGroup
	{
	public:
		~PluginRoot();

		AE::Plugin* Attach(AE::Plugin *pluginToAttach);
		AE::Plugin* AttachAndInstall(AE::Plugin *pluginToAttach, AE::uint installOptions);
		void Detach(const std::string &pluginName);

		friend class PluginManager;

	protected:
		PluginRoot();

		bool Install(AE::uint options) { return true; }
		bool Uninstall() { return true; }
	};
}

#endif