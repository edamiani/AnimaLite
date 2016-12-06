#ifndef __AE_AI_FSM_STATE__
#define __AE_AI_FSM_STATE__

enum
{
	FSM_STATE_NONE = -1
};

namespace AE
{
	namespace AI
	{
		class FsmState
		{
		public:
			FsmState(int type = FSM_STATE_NONE) : mType(type) {  }
			virtual ~FsmState() {  }

			virtual int		CheckTransitions() { return FSM_STATE_NONE; }
			virtual void	OnEnter() {  }
			virtual void	OnExit() {  }
			int				GetType() { return mType; }
			virtual void	OnInitialize() {  }
			virtual void	OnUpdate(float dt) {  }

		protected:
			int mType;
		};
	}
}

#endif