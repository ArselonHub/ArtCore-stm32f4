#ifndef ART_CM3_GLOBALSECTION
#define ART_CM3_GLOBALSECTION

namespace Art
{
	class GlobalSection
	{
	private:
		UWord savedValue;
	public:
		GlobalSection()
		{
			savedValue =  __get_PRIMASK();
		}
		
		void enter()
		{
			__disable_irq();
		}
		
		void exit()
		{
			__set_PRIMASK(savedValue);
		}
	};
}

#endif
