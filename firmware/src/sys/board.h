/*
 * Copyright (c) 2014 Courierdrone, courierdrone.com
 * Distributed under the MIT License, available in the file LICENSE.
 * Author: Pavel Kirienko <pavel.kirienko@courierdrone.com>
 */

#pragma once

/// Assert is needed for STM32 SPL (if it is being used, that is)
#include <assert.h>
#define assert_param(x) assert(x)

#define STM32_HSECLK            8000000

#define STM32F10X_CL

#define UBLOX_SD  SD2

/*
 * GPIO
 */
// Misc
#define GPIO_PORT_SERIAL_RX     GPIOA
#define GPIO_PIN_SERIAL_RX      10

// LED
#define GPIO_PORT_LED_STATUS    GPIOB
#define GPIO_PIN_LED_STATUS     0

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 *
 * The digits have the following meaning:
 *   0 - Analog input.
 *   1 - Push Pull output 10MHz.
 *   2 - Push Pull output 2MHz.
 *   3 - Push Pull output 50MHz.
 *   4 - Digital input.
 *   5 - Open Drain output 10MHz.
 *   6 - Open Drain output 2MHz.
 *   7 - Open Drain output 50MHz.
 *   8 - Digital input with PullUp or PullDown resistor depending on ODR.
 *   9 - Alternate Push Pull output 10MHz.
 *   A - Alternate Push Pull output 2MHz.
 *   B - Alternate Push Pull output 50MHz.
 *   C - Reserved.
 *   D - Alternate Open Drain output 10MHz.
 *   E - Alternate Open Drain output 2MHz.
 *   F - Alternate Open Drain output 50MHz.
 * Please refer to the STM32 Reference Manual for details.
 */

#define VAL_GPIOACRL            0x88888888      // 7..0
#define VAL_GPIOACRH            0x888888b3      // 15..8
#define VAL_GPIOAODR            0x00000000

#define VAL_GPIOBCRL            0x88888888
#define VAL_GPIOBCRH            0x88888888
#define VAL_GPIOBODR            0x00000000

#define VAL_GPIOCCRL            0x88888888
#define VAL_GPIOCCRH            0x88888888
#define VAL_GPIOCODR            0x00000000

#define VAL_GPIODCRL            0x88888888
#define VAL_GPIODCRH            0x88888888
#define VAL_GPIODODR            0x00000000

#define VAL_GPIOECRL            0x88888888
#define VAL_GPIOECRH            0x88888888
#define VAL_GPIOEODR            0x00000000

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
    void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */
