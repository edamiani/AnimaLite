#ifndef __AE_ANIMATION_RANGE__
#define __AE_ANIMATION_RANGE__

namespace AE
{
	namespace Animation
	{
		template <typename T>
		class Range
		{
		public:
			Range(const T& from, const T& to) : mFrom(from), mTo(to) { }
			~Range() { }

			T& GetFrom() { return mFrom; }
			T& GetTo() { return mTo; }

		protected:
			T mFrom;
			T mTo;
		};
	}
}

#endif
