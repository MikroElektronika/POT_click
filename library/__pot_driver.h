/*
    __pot_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __pot_driver.h
@brief    POT Driver
@mainpage POT Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   POT
@brief      POT Click Driver
@{

| Global Library Prefix | **POT** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Dec 2018.**      |
| Developer             | **Nemanja Medakovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _POT_H_
#define _POT_H_

/** 
 * @macro T_POT_P
 * @brief Driver Abstract type 
 */
#define T_POT_P    const uint8_t*

/** @defgroup POT_COMPILE Compilation Config */              /** @{ */

//  #define   __POT_DRV_SPI__                            /**<     @macro __POT_DRV_SPI__  @brief SPI driver selector */
//  #define   __POT_DRV_I2C__                            /**<     @macro __POT_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __POT_DRV_UART__                           /**<     @macro __POT_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup POT_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup POT_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup POT_INIT Driver Initialization */              /** @{ */

#ifdef   __POT_DRV_SPI__
void pot_spiDriverInit(T_POT_P gpioObj, T_POT_P spiObj);
#endif
#ifdef   __POT_DRV_I2C__
void pot_i2cDriverInit(T_POT_P gpioObj, T_POT_P i2cObj, uint8_t slave);
#endif
#ifdef   __POT_DRV_UART__
void pot_uartDriverInit(T_POT_P gpioObj, T_POT_P uartObj);
#endif

void pot_gpioDriverInit(T_POT_P gpioObj);
                                                                       /** @} */
/** @defgroup POT_FUNC Driver Functions */                   /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_POT_STM.c
    @example Click_POT_TIVA.c
    @example Click_POT_CEC.c
    @example Click_POT_KINETIS.c
    @example Click_POT_MSP.c
    @example Click_POT_PIC.c
    @example Click_POT_PIC32.c
    @example Click_POT_DSPIC.c
    @example Click_POT_AVR.c
    @example Click_POT_FT90x.c
    @example Click_POT_STM.mbas
    @example Click_POT_TIVA.mbas
    @example Click_POT_CEC.mbas
    @example Click_POT_KINETIS.mbas
    @example Click_POT_MSP.mbas
    @example Click_POT_PIC.mbas
    @example Click_POT_PIC32.mbas
    @example Click_POT_DSPIC.mbas
    @example Click_POT_AVR.mbas
    @example Click_POT_FT90x.mbas
    @example Click_POT_STM.mpas
    @example Click_POT_TIVA.mpas
    @example Click_POT_CEC.mpas
    @example Click_POT_KINETIS.mpas
    @example Click_POT_MSP.mpas
    @example Click_POT_PIC.mpas
    @example Click_POT_PIC32.mpas
    @example Click_POT_DSPIC.mpas
    @example Click_POT_AVR.mpas
    @example Click_POT_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __pot_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */