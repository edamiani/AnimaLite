#ifndef __AE_PLUGIN__
#define __AE_PLUGIN__

#include "Anima/Types.h"

#include "Anima/PluginOptions.h"

#include <list>

namespace AE
{	
	enum PluginType
	{
		PT_ALL,

		PT_AI_MANAGER,
		PT_ANIMATION_MANAGER,
		PT_AUDIO_LOADER_MANAGER,
		PT_AUDIO_PLAYER_MANAGER,
		PT_AUDIO_SPATIAL_MANAGER,
		PT_DATABASE_MANAGER,
		PT_ECS_MANAGER,
		PT_FONT_MANAGER,
		PT_GRAPHICS_MANAGER,
		PT_GRAPHICS_DEVICE_MANAGER,
		PT_GUI_MANAGER,
		PT_IMAGE_MANAGER,
		PT_INPUT_MANAGER,
		PT_MATH_MANAGER,
		PT_MUSIC_MANAGER,
		PT_NATURE_MANAGER,
		PT_NETWORK_MANAGER,
		PT_OS_MANAGER,
		PT_OS_EVENT_MANAGER,
		PT_OS_TIMER_MANAGER,
		PT_OS_WINDOW_MANAGER,
		PT_PHYSICS_MANAGER,
		PT_SCENE_MANAGER,
		PT_SCRIPT_MANAGER,
		PT_XML_MANAGER,

		// Used internally
		PT_GROUP, 
		PT_IRRELEVANT,
		PT_ROOT
	};

	class Plugin
	{
	public:
		Plugin(AE::PluginType pluginType) 
			: mPluginType(pluginType), mIsAttached(false), mIsInstalled(false), mParent(0) {}

		virtual ~Plugin()
		{
			if(mParent)
			{
				mParent = 0;
			}
		}

		AE::Plugin*		GetParent() { return mParent; }
		AE::PluginType	GetType() { return mPluginType; }
		virtual bool	Install(AE::uint options, PluginOptions *pluginDesc = nullptr) = 0;
		bool			IsAttached() { return mIsAttached; }
		bool			IsInstalled() { return mIsInstalled; }
		void			SetParent(AE::Plugin *parent) { mParent = parent; }
		virtual bool	Uninstall() = 0;

	protected:
		bool			mIsAttached;
		bool			mIsInstalled;
		AE::Plugin		*mParent;
		AE::PluginType	mPluginType;
	};
}

#endif