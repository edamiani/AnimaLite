#ifndef __AE_AI_FSM_MACHINE__
#define __AE_AI_FSM_MACHINE__

#include "FsmState.h"

#include "Anima/Types.h"

#include <vector>

namespace AE
{
	namespace AI
	{
		class FsmMachine: public AE::AI::FsmState
		{
		public:
			FsmMachine(int type = FSM_STATE_NONE);
			virtual ~FsmMachine() {  }

			virtual void	AddState(FsmState* state);
			FsmState*		GetCurrentState() { return mCurrentState; }
			virtual void	Reset();
			virtual void	SetDefaultState(FsmState* state) { mDefaultState = state; }
			virtual bool	TransitionState(int goal);
			virtual void	UpdateMachine(float dt);
		    
		protected:
			FsmState		*mCurrentState = nullptr;
			FsmState		*mDefaultState = nullptr;
			FsmState		*mNextState = nullptr;
			AE::int32		mNextStateId = -1;
			std::vector<AE::AI::FsmState *> 
							mStates;
		};
	}
}

#endif