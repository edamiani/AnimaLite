#ifndef __ANIMA__
#define __ANIMA__

#ifdef AE_EXPORT_DLL
#	define AE_DECLSPEC __declspec(dllexport) 
#else
#	define AE_DECLSPEC
#endif

#endif