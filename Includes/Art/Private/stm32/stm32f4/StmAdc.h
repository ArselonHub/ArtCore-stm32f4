/*
 * StmAdc.h
 *
 *  Created on: Jun 29, 2017
 *      Author: denizcan
 */

#ifndef ART_PRIVATE_STM32_STM32F4_STMADC_H_
#define ART_PRIVATE_STM32_STM32F4_STMADC_H_

#include <Art/Adc.h>
#include <Art/AdcChannel.h>
#include <Art/Mcu.h>
#include <Art/Task.h>

namespace Art
{
	enum StmAdcResolution
	{
		StmAdcResolution12Bit,
		StmAdcResolution10Bits,
		StmAdcResolution8Bit,
		StmAdcResolution6Bit
	};

	enum StmAdcConvertTrigger
	{
		StmAdcConvertTriggerNone = 0,

		StmAdcConvertTriggerTim1Channel4RisingEdge = 0x10,
		StmAdcConvertTriggerTim1TiggerOutRisingEdge,
		StmAdcConvertTriggerTim2Channel1RisingEdge,
		StmAdcConvertTriggerTim2TriggerOutRisingEdge,
		StmAdcConvertTriggerTim3Channel2RisingEdge,
		StmAdcConvertTriggerTim3Channel4RisingEdge,
		StmAdcConvertTriggerTim4Channel1RisingEdge,
		StmAdcConvertTriggerTim4Channel2RisingEdge,
		StmAdcConvertTriggerTim4Channel3RisingEdge,
		StmAdcConvertTriggerTim4TriggerOutRisingEdge,
		StmAdcConvertTriggerTim5Channel4RisingEdge,
		StmAdcConvertTriggerTim5TriggerOutRisingEdge,
		StmAdcConvertTriggerTim8Channel2RisingEdge,
		StmAdcConvertTriggerTim8Channel3RisingEdge,
		StmAdcConvertTriggerTim8Channel4RisingEdge,
		StmAdcConvertTriggerExti5RisingEdge,

		StmAdcConvertTriggerTim1Channel4FallingEdge = 0x20,
		StmAdcConvertTriggerTim1TiggerOutFallingEdge,
		StmAdcConvertTriggerTim2Channel1FallingEdge,
		StmAdcConvertTriggerTim2TriggerOutFallingEdge,
		StmAdcConvertTriggerTim3Channel2FallingEdge,
		StmAdcConvertTriggerTim3Channel4FallingEdge,
		StmAdcConvertTriggerTim4Channel1FallingEdge,
		StmAdcConvertTriggerTim4Channel2FallingEdge,
		StmAdcConvertTriggerTim4Channel3FallingEdge,
		StmAdcConvertTriggerTim4TriggerOutFallingEdge,
		StmAdcConvertTriggerTim5Channel4FallingEdge,
		StmAdcConvertTriggerTim5TriggerOutFallingEdge,
		StmAdcConvertTriggerTim8Channel2FallingEdge,
		StmAdcConvertTriggerTim8Channel3FallingEdge,
		StmAdcConvertTriggerTim8Channel4FallingEdge,
		StmAdcConvertTriggerExti5FallingEdge,

		StmAdcConvertTriggerTim1Channel4AnyEdge = 0x30,
		StmAdcConvertTriggerTim1TiggerOutAnyEdge,
		StmAdcConvertTriggerTim2Channel1AnyEdge,
		StmAdcConvertTriggerTim2TriggerOutAnyEdge,
		StmAdcConvertTriggerTim3Channel2AnyEdge,
		StmAdcConvertTriggerTim3Channel4AnyEdge,
		StmAdcConvertTriggerTim4Channel1AnyEdge,
		StmAdcConvertTriggerTim4Channel2AnyEdge,
		StmAdcConvertTriggerTim4Channel3AnyEdge,
		StmAdcConvertTriggerTim4TriggerOutAnyEdge,
		StmAdcConvertTriggerTim5Channel4AnyEdge,
		StmAdcConvertTriggerTim5TriggerOutAnyEdge,
		StmAdcConvertTriggerTim8Channel2AnyEdge,
		StmAdcConvertTriggerTim8Channel3AnyEdge,
		StmAdcConvertTriggerTim8Channel4AnyEdge,
		StmAdcConvertTriggerExti5AnyEdge,

	};

	extern "C" void ADC_IRQHandler();

	class StmAdc : public Adc
	{
	public:
		using Adc::convert;

		Word convert(AdcChannel** channels, StmAdcConvertTrigger trigger, Response* response);

		StmAdcChannel* channel0();
		StmAdcChannel* channel1();
		StmAdcChannel* channel2();
		StmAdcChannel* channel3();
		StmAdcChannel* channel4();
		StmAdcChannel* channel5();
		StmAdcChannel* channel6();
		StmAdcChannel* channel7();
	protected:
		StmAdc(ADC_TypeDef* port, const void* privates);
		virtual ~StmAdc();

		void handleInjectedEoc();
		virtual Word openDevice();
		virtual Word closeDevice();

	private:
		virtual Word convertChannels(AdcChannel** channels, Response* response);
		virtual Word valueOf(AdcChannel* channel);

		class InjectedSvcTask : public Task
		{
			virtual void execute();
		};

		ADC_TypeDef*		m_port;
		UShort				m_data[16];
		InjectedSvcTask		m_injectedSvcTask;
		Response*			m_response;

		StmAdcChannel m_channel0;
		StmAdcChannel m_channel1;
		StmAdcChannel m_channel2;
		StmAdcChannel m_channel3;
		StmAdcChannel m_channel4;
		StmAdcChannel m_channel5;
		StmAdcChannel m_channel6;
		StmAdcChannel m_channel7;

		friend void ADC_IRQHandler();
	};

	inline StmAdcChannel* StmAdc::channel0()
	{
		return &m_channel0;
	}

	inline StmAdcChannel* StmAdc::channel1()
	{
		return &m_channel1;
	}

	inline StmAdcChannel* StmAdc::channel2()
	{
		return &m_channel2;
	}

	inline StmAdcChannel* StmAdc::channel3()
	{
		return &m_channel3;
	}

	inline StmAdcChannel* StmAdc::channel4()
	{
		return &m_channel4;
	}

	inline StmAdcChannel* StmAdc::channel5()
	{
		return &m_channel5;
	}

	inline StmAdcChannel* StmAdc::channel6()
	{
		return &m_channel6;
	}

	inline StmAdcChannel* StmAdc::channel7()
	{
		return &m_channel7;
	}

} /* namespace Art */

#include <Art/Private/stm32/stm32f4/StmAdc1.h>

#endif /* SOURCE_ART_PRIVATE_STM32_STM32F4_STMADC_H_ */
