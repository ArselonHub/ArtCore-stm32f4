	enum PinConfig
	{  
		PinConfigInput 			= 0x0000,
		PinConfigOutput 		= 0x0001,
		PinConfigAnalog			= 0x0003,		
		PinConfigAlternate0		= 0x0002 + 0x0000,
		PinConfigAlternate1		= 0x0002 + 0x0010,
		PinConfigAlternate2		= 0x0002 + 0x0020,
		PinConfigAlternate3		= 0x0002 + 0x0030,
		PinConfigAlternate4		= 0x0002 + 0x0040,
		PinConfigAlternate5		= 0x0002 + 0x0050,
		PinConfigAlternate6		= 0x0002 + 0x0060,
		PinConfigAlternate7		= 0x0002 + 0x0070,

		PinConfigPullUp			= 0x0100,
		PinConfigPullDown		= 0x0200,		
		PinConfigPushPull		= 0x0000,
		PinConfigOpenDrain		= 0x0400,

		PinConfigSpeedLow		= 0x0000,
		PinConfigSpeedMedium	= 0x1000,
		PinConfigSpeedHigh		= 0x3000,
	};
	ENUMFLAGS(PinConfig)

	enum PinId
	{
		PA0 = (0x00 | 0x00), PA1, PA2,  PA3,  PA4,  PA5,  PA6,  PA7, 
		PA8 = (0x00 | 0x08), PA9, PA10, PA11, PA12, PA13, PA14, PA15,
		
		PB0 = (0x10 | 0x00), PB1, PB2,  PB3,  PB4,  PB5,  PB6,  PB7,
		PB8 = (0x10 | 0x08), PB9, PB10, PB11, PB12, PB13, PB14, PB15,
		
		PC0 = (0x20 | 0x00), PC1, PC2,  PC3,  PC4,  PC5,  PC6,  PC7,
		PC8 = (0x20 | 0x08), PC9, PC10, PC11, PC12, PC13, PC14, PC15,
		
		PD2 = (0x30 | 0x02), 
		
		PF0 = (0x50 | 0x00), PF1, 
		PF4 = (0X50 | 0x04), PF5, PF6, PF7,
		
		PNULL = 0xFF
	};
