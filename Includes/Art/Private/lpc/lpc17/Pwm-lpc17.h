#ifndef ART_PWM_LPC17_H
#define ART_PWM_LPC17_H

#include <Art/lpc/lpc17/Timer-lpc17.h>

namespace Art
{
	class Pwm1 : public Pit
	{
	public:
		CompareChannel match4;
		CompareChannel match5;
		CompareChannel match6;

		Pwm1();
		void init(bool isPwm = true);
		void setPeriod(UInt value);
		void update();
		
		virtual void start();	
		virtual void powerUp();
		virtual void powerDown();
		virtual void enableIrq();
		virtual void disableIrq();
	protected:
		virtual LPC_TIM_TypeDef* getPort();
	};

	extern Pwm1 pwm1;
	
};

#endif
