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

		static AE::PluginManager*		GetInstance() { assert(mInstance != nullptr); return mInstance; }
		static AE::PluginManager*		Initialize();
		static void						Shutdown();

		AE::Plugin*						Find(const std::string &pluginName);
		AE::Plugin*						GetInstalledPluginByType(AE::PluginType pluginType);
		AE::Plugin*						GetPluginByName(const std::string &pluginName);
		AE::PluginGroup*				GetRoot() { return mRoot; }

		template<class T>
		T* RegisterPlugin(const std::string &pluginName)
		{
			if(mRegisteredPlugins.find(pluginName) != mRegisteredPlugins.end())
				return 0;

			mRegisteredPlugins[pluginName] = new T();

			return static_cast<T*>(mRegisteredPlugins[pluginName]);
		}

		template<class T>
		void UnregisterPlugin(const std::string &pluginName)
		{
			std::map<std::string, AE::Plugin *>::iterator i = mRegisteredPlugins.find(pluginName);

			assert(i != mRegisteredPlugins.end());

			/*if(i == mRegisteredPlugins.end())
			{
				throw AE::Exception(AE::ET_NOT_FOUND, "AE::PluginManager::unregisterPlugin(): there is no plugin registered with this name.");
			}*/

			if((*i).second->IsInstalled())
			{
				(*i).second->Uninstall();
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
