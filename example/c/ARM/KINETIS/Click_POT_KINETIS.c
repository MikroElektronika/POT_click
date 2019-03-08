/*
Example for POT Click

    Date          : Dec 2018.
    Author        : Nemanja Medakovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface and ADC.
- Application Task - (code snippet) - Makes the averaged results by using the desired number of samples of AD conversion.
  The averaged results will be calculated to millivolts [mV] and sent to the uart terminal.
Note : The AD conversion will be performed on the analog (AN) pin on the mikrobus 1.

*/

#include "Click_POT_types.h"
#include "Click_POT_config.h"

uint16_t adcRead;
uint16_t nSamples;
uint16_t adcMax;
uint16_t adcMin;
float adcAvrg;
char text[ 30 ];

const uint16_t N_SAMPLES         = 100;
const uint16_t ADC_V_REF_MV      = 3303;
const uint16_t ADC_12BIT_RESOL   = 4096;
const uint16_t ADC_10BIT_RESOL   = 1024;

void systemInit()
{
    mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_AN_PIN, _GPIO_INPUT );

    mikrobus_logInit( _MIKROBUS2, 9600 );
    mikrobus_logWrite( "*** Initializing... ***", _LOG_LINE );

    Delay_ms( 100 );
}

void applicationInit()
{
    pot_gpioDriverInit( (T_POT_P)&_MIKROBUS1_GPIO );
    Delay_ms( 100 );
    
    ADC1_Init();
    Delay_ms( 100 );
    
    mikrobus_logWrite( "** POT is initialized **", _LOG_LINE );
    mikrobus_logWrite( "", _LOG_LINE );
}

void applicationTask()
{
    for (nSamples = 0; nSamples < N_SAMPLES; nSamples++)
    {
        adcRead = ADC1_Get_Sample( 12 );

        if (nSamples == 0)
        {
            adcMax = adcRead;
            adcMin = adcRead;
        }
        if (adcRead > adcMax)
        {
            adcMax = adcRead;
        }
        else if (adcRead < adcMin)
        {
            adcMin = adcRead;
        }
        
        Delay_ms( 1 );
    }

    adcAvrg = adcMax;
    adcAvrg += adcMin;
    adcAvrg /= 2;
    adcAvrg /= ADC_12BIT_RESOL;
    adcAvrg *= ADC_V_REF_MV;
    adcRead = adcAvrg;
    
    WordToStr( adcRead, text );
    mikrobus_logWrite( "** AN : ", _LOG_TEXT );
    mikrobus_logWrite( text, _LOG_TEXT );
    mikrobus_logWrite( " mV **", _LOG_LINE );
    
    Delay_ms( 100 );
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}
