#ifndef __AE_INPUT_KEY_VALUE_SDL__
#define __AE_INPUT_KEY_VALUE_SDL__

#include "Dependencies/SDL2-2.0.4/include/SDL.h"

namespace AE
{
	namespace Input
	{
		enum KeyValue
		{
			KV_ESC = SDLK_ESCAPE,
			KV_ALT = SDLK_LALT,
			KV_0 = SDLK_0,
			KV_1 = SDLK_1,
			KV_2 = SDLK_2,
			KV_3 = SDLK_3,
			KV_4 = SDLK_4,
			KV_5 = SDLK_5,
			KV_6 = SDLK_6,
			KV_7 = SDLK_7,
			KV_8 = SDLK_8,
			KV_9 = SDLK_9,
			KV_A = SDLK_a,
			KV_B = SDLK_b,
			KV_C = SDLK_c,
			KV_D = SDLK_d,
			KV_E = SDLK_e,
			KV_F = SDLK_f,
			KV_G = SDLK_g,
			KV_H = SDLK_h,
			KV_I = SDLK_i,
			KV_J = SDLK_j,
			KV_K = SDLK_k,
			KV_L = SDLK_l,
			KV_M = SDLK_m,
			KV_N = SDLK_n,
			KV_O = SDLK_o,
			KV_P = SDLK_p,
			KV_Q = SDLK_q,
			KV_R = SDLK_r,
			KV_S = SDLK_s,
			KV_T = SDLK_t,
			KV_U = SDLK_u,
			KV_V = SDLK_v,
			KV_W = SDLK_w,
			KV_X = SDLK_x,
			KV_Y = SDLK_y,
			KV_Z = SDLK_z,
			KV_LSHIFT = SDLK_LSHIFT, //VK_LSHIFT
			KV_RSHIFT = SDLK_RSHIFT, //VK_RSHIFT
			KV_LCONTROL = SDLK_LCTRL, //VK_LCONTROL
			KV_RCONTROL = SDLK_RCTRL //VK_RCONTROL
		};
	}
}

#endif