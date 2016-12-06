#include "FsmMachine.h"

namespace AE
{
	namespace AI
	{
		//---------------------------------------------------------
		FsmMachine::FsmMachine(int type)
			: FsmMachine(type)
		{
		}

		//---------------------------------------------------------
		void FsmMachine::UpdateMachine(float dt)
		{
			//don't do anything if you have no states
			if(mStates.size() == 0)
			{
				return;
			}

			//don't do anything if there's no current 
			//state, and no default state
			if(!mDefaultState)
			{
				return;
			}

			if(!mCurrentState)
			{
				mCurrentState = mDefaultState;
			}

			//check for transitions, and then update
			int currentStateId = mCurrentState->GetType();
			mNextStateId = mCurrentState->CheckTransitions();
			
			//switch if there was a transition
			if(mNextStateId != currentStateId)
			{
				if(TransitionState(mNextStateId))
				{
					mCurrentState->OnExit();
					mCurrentState = mNextState;
					mCurrentState->OnEnter();
				}
			}
			mCurrentState->OnUpdate(dt);	
			
		}

		//---------------------------------------------------------
		void FsmMachine::AddState(AE::AI::FsmState* state)
		{
			mStates.push_back(state);
		}

		//---------------------------------------------------------
		bool FsmMachine::TransitionState(int nextStateId)
		{
			// If there are no states, do nothing
			if(mStates.size() == 0)
			{
				return false;
			}
			
			// Determine if we have state of type 'nextStateId'
			// in the list, and switch to it; otherwise, quit
			for(unsigned int i = 0; i < mStates.size(); i++)
			{
				if(mStates[i]->GetType() == nextStateId)
				{
					mNextState = mStates[i];
					return true;
				}
			}

			return false;
		}

		//---------------------------------------------------------
		void FsmMachine::Reset()
		{
			OnExit();

			if(mCurrentState)
			{
				mCurrentState->OnExit();
			}

			mCurrentState = mDefaultState;

			// Init all states
			for(unsigned int i = 0; i < mStates.size(); i++)
			{
				mStates[i]->OnInitialize();
			}

			// And now enter the mDefaultState, if any
			if(mCurrentState)
			{
				mCurrentState->OnEnter();
			}
		}
	}
}