#ifndef __AE_PLUGIN_GROUP__
#define __AE_PLUGIN_GROUP__

#include "Anima/Plugin.h"

#include <list>

namespace AE
{	
	class PluginGroup : public AE::Plugin
	{
	public:
		PluginGroup();
		PluginGroup(AE::PluginType pluginType);
		virtual ~PluginGroup();

		AE::Plugin*			Attach(AE::Plugin *pluginToAttach);
		AE::Plugin*			AttachAndInstall(AE::Plugin *pluginToAttach, AE::uint installOptions);
		void				Detach(std::string const &pluginName);
		void				Detach(AE::Plugin *child);
		void				DetachAndUninstall(std::string const &pluginName);
		void				DetachAndUninstall(AE::Plugin *child);
		AE::Plugin*			GetChildByType(AE::PluginType pluginType);
		virtual bool		Install(AE::uint options);
		virtual bool		Uninstall();

	protected:
		std::list<AE::Plugin *> mChildren;
	};
}

#endif