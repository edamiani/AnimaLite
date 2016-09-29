#include "Anima/PluginGroup.h"
#include "Anima/PluginManager.h"

#include "Anima/Exception.h"

#include <cassert>

namespace AE
{
	PluginGroup::PluginGroup() : Plugin(AE::PT_GROUP)
	{
	}

	PluginGroup::PluginGroup(AE::PluginType pluginType) : Plugin(pluginType)
	{
	}

	PluginGroup::~PluginGroup()
	{
		Uninstall();
	}

	AE::Plugin* PluginGroup::attach(AE::Plugin *pluginToAttach)
	{
		pluginToAttach->SetParent(this);

		mChildren.push_back(pluginToAttach);

		return pluginToAttach;
	}

	AE::Plugin* PluginGroup::attachAndInstall(AE::Plugin *pluginToAttach, AE::uint installOptions)
	{
		pluginToAttach->SetParent(this);

		mChildren.push_back(pluginToAttach);

		bool result = pluginToAttach->install(installOptions);
		assert(result);

		return pluginToAttach;
	}

	void PluginGroup::detach(const std::string &pluginName)
	{
		AE::Plugin *plugin = AE::PluginManager::getInstance()->find(pluginName);

		if(!plugin)
			throw AE::Exception(AE::ET_NOT_FOUND, "AE::PluginGroup::detach(): there is no plugin with such name.");

		if(plugin->GetParent() != this)
			throw AE::Exception(AE::ET_NOT_RELATED, "AE::PluginGroup::detach(): this plugin is not attached as a child.");

		mChildren.remove(plugin);
	}

	void PluginGroup::detach(AE::Plugin *child)
	{
		if(child->GetParent() != this)
			throw AE::Exception(AE::ET_NOT_RELATED, "AE::PluginGroup::detach(): this plugin is not attached as a child.");

		mChildren.remove(child);
	}

	void PluginGroup::detachAndUninstall(const std::string &pluginName)
	{
		AE::Plugin *plugin = AE::PluginManager::getInstance()->find(pluginName);

		if(!plugin)
			throw AE::Exception(AE::ET_NOT_FOUND, "AE::PluginGroup::detachAndUninstall(): there is no plugin with such name.");

		if(plugin->GetParent() != this)
			throw AE::Exception(AE::ET_NOT_RELATED, "AE::PluginGroup::detachAndUninstall(): this plugin is not attached as a child.");
		
		if(plugin->IsInstalled())
			plugin->uninstall();

		mChildren.remove(plugin);
	}

	void PluginGroup::detachAndUninstall(AE::Plugin *child)
	{
		if(child->GetParent() != this)
			throw AE::Exception(AE::ET_NOT_RELATED, "AE::PluginGroup::detachAndUninstall(): this plugin is not attached as a child.");
		
		if(child->IsInstalled())
			child->uninstall();

		mChildren.remove(child);
	}

	AE::Plugin* PluginGroup::getChildByType(AE::PluginType pluginType)
	{
		assert(pluginType != AE::PT_ALL && pluginType != AE::PT_GROUP && pluginType != AE::PT_IRRELEVANT && pluginType != AE::PT_ROOT);

		std::list<AE::Plugin *>::iterator i;

		for(i = mChildren.begin(); i != mChildren.end(); i++)
		{
			if((*i)->GetType() == pluginType)
				return (*i);
		}

		return 0;
	}

	bool PluginGroup::Install(AE::uint options)
	{
		std::list<AE::Plugin *>::iterator i;

		for(i = mChildren.begin(); i != mChildren.end(); i++)
		{
			if(!(*i)->IsInstalled())
				(*i)->install(options);
		}

		mIsInstalled = true;

		return true;
	}

	bool PluginGroup::Uninstall()
	{
		std::list<AE::Plugin *>::iterator i;

		for(i = mChildren.begin(); i != mChildren.end(); i++)
		{
			if((*i)->IsInstalled())
				(*i)->uninstall();

			delete (*i);
		}

		mChildren.clear();

		return true;
	}
}
