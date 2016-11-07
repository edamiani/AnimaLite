#include "Anima/PluginRoot.h"
#include "Anima/PluginManager.h"

#include "Anima/Exception.h"

namespace AE
{
	PluginRoot::PluginRoot()
		: PluginGroup(AE::PT_ROOT)
	{
	}

	PluginRoot::~PluginRoot()
	{
		/*std::list<AE::Plugin *>::iterator i;
		for(i = mChildren.begin(); i != mChildren.end(); i++)
		{
			if((*i)->isInstalled())
				(*i)->uninstall();

			delete (*i);
		}*/
	}

	AE::Plugin* PluginRoot::Attach(AE::Plugin *pluginToAttach)
	{
		pluginToAttach->SetParent(this);

		mChildren.push_back(pluginToAttach);

		return pluginToAttach;
	}

	AE::Plugin* PluginRoot::AttachAndInstall(AE::Plugin *pluginToAttach, AE::uint installOptions)
	{
		pluginToAttach->SetParent(this);

		mChildren.push_back(pluginToAttach);

		pluginToAttach->Install(installOptions);

		return pluginToAttach;
	}

	void PluginRoot::Detach(const std::string &pluginName)
	{
		AE::Plugin *plugin = AE::PluginManager::GetInstance()->Find(pluginName);

		if(!plugin)
			throw AE::Exception(AE::ET_NOT_FOUND, "AE::PluginRoot::detach(): there is no plugin with this name attached as a root's child.");

		if(plugin->IsInstalled())
		{
			plugin->Uninstall();
		}

		mChildren.remove(plugin);
	}
}
