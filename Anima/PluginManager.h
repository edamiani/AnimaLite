#ifndef __AE_PLUGIN_MANAGER__
#define __AE_PLUGIN_MANAGER__

#include "Anima/Types.h"
#include "Anima/Plugin.h"
#include "Anima/PluginGroup.h"

#include <cassert>
#include <map>
#include <string>

namespace AE
{
	class PluginManager
	{
	public:
		~PluginManager();

		static AE::PluginManager*		getInstance() { assert(mInstance != nullptr); return mInstance; }
		static AE::PluginManager*		initialize();
		static void						shutdown();

		AE::Plugin*						find(const std::string &pluginName);
		AE::Plugin*						getInstalledPluginByType(AE::PluginType pluginType);
		AE::Plugin*						getPluginByName(const std::string &pluginName);
		AE::PluginGroup*				getRoot() { return mRoot; }

		template<class T>
		T* registerPlugin(const std::string &pluginName)
		{
			if(mRegisteredPlugins.find(pluginName) != mRegisteredPlugins.end())
				return 0;

			mRegisteredPlugins[pluginName] = new T();

			return static_cast<T*>(mRegisteredPlugins[pluginName]);
		}

		template<class T>
		void unregisterPlugin(const std::string &pluginName)
		{
			std::map<std::string, AE::Plugin *>::iterator i = mRegisteredPlugins.find(pluginName);

			assert(i != mRegisteredPlugins.end());

			/*if(i == mRegisteredPlugins.end())
			{
				throw AE::Exception(AE::ET_NOT_FOUND, "AE::PluginManager::unregisterPlugin(): there is no plugin registered with this name.");
			}*/

			if((*i).second->isInstalled())
			{
				(*i).second->uninstall();
			}

			delete (*i).second;

			mRegisteredPlugins.erase(i);
		}

	protected:
		PluginManager();

		static AE::PluginManager		*mInstance;

		std::map<std::string, AE::Plugin *> 
										mRegisteredPlugins;
		AE::PluginGroup					*mRoot;
	};
}

#endif
