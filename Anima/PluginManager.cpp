#include "Anima/PluginManager.h"

#include "Anima/Exception.h"
#include "Anima/PluginRoot.h"

AE::PluginManager* AE::PluginManager::mInstance = nullptr;

namespace AE
{
	PluginManager::PluginManager()
	{
		mRoot = new AE::PluginGroup(AE::PT_ROOT);
	}

	PluginManager::~PluginManager()
	{
		delete mRoot;
	}

	AE::PluginManager* PluginManager::initialize()
	{
		if(!mInstance)
		{
			mInstance = new AE::PluginManager();
		}

		return mInstance;
	}

	void PluginManager::shutdown()
	{
		if(mInstance)
		{
			delete mInstance;
			mInstance = nullptr;
		}
	}

	AE::Plugin* PluginManager::find(const std::string &pluginName) 
	{
		std::map<std::string, AE::Plugin *>::iterator i = mRegisteredPlugins.find(pluginName);

		if(i == mRegisteredPlugins.end())
			return 0;
		else
			return (*i).second;
	}

	AE::Plugin* PluginManager::getInstalledPluginByType(AE::PluginType pluginType)
	{
		assert(pluginType != AE::PT_ALL && pluginType != AE::PT_GROUP && pluginType != AE::PT_IRRELEVANT && pluginType != AE::PT_ROOT);

		std::map<std::string, AE::Plugin *>::iterator i;

		for(i = mRegisteredPlugins.begin(); i != mRegisteredPlugins.end(); i++)
		{
			if((*i).second->GetType() == pluginType && (*i).second->IsInstalled())
				return (*i).second;
		}

		return 0;
	}

	AE::Plugin* PluginManager::getPluginByName(const std::string &pluginName)
	{
		if(mRegisteredPlugins.find(pluginName) != mRegisteredPlugins.end())
			return 0;

		return mRegisteredPlugins[pluginName];
	}
}
