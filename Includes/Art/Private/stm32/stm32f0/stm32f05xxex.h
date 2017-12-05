#ifndef ART_STM32_STM32F0XX_H
#define ART_STM32_STM32F0XX_H

#define RCC_AHBENR_TSCEN	(1 << 24)
#define RCC_AHBENR_IOPFEN	(1 << 22)
#define RCC_AHBENR_IOPEEN	(1 << 21)
#define RCC_AHBENR_IOPDEN	(1 << 20)
#define RCC_AHBENR_IOPCEN	(1 << 19)
#define RCC_AHBENR_IOPBEN	(1 << 18)
#define RCC_AHBENR_IOPAEN	(1 << 17)
#define RCC_AHBENR_CRCEN	(1 << 16)
#define RCC_AHBENR_FLITFEN	(1 << 4)
#define RCC_AHBENR_SRAMEN	(1 << 2)
#define RCC_AHBENR_DMAEN	(1 << 0)

#endif
