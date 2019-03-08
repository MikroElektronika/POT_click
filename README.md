![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# POT Click

- **CIC Prefix**  : POT
- **Author**      : Nemanja Medakovic
- **Verison**     : 1.0.0
- **Date**        : Dec 2018.

---

### Software Support

We provide a library for the POT Click on our [LibStock](https://libstock.mikroe.com/projects/view/2700/pot-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes GPIO interface for the desired mikrobus selection.
For more details check documentation.

Key functions :

- ``` void pot_gpioDriverInit( T_POT_P gpioObj ) ``` - Function initializes GPIO driver for the desired mikrobus.

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes peripherals and pins.
- Application Initialization - Initializes GPIO interface and ADC.
- Application Task - (code snippet) - Makes the averaged results by using the desired number of samples of AD conversion.
  The averaged results will be calculated to millivolts [mV] and sent to the uart terminal.
Note : The AD conversion will be performed on the analog (AN) pin on the mikrobus 1.


```.c
void applicationTask()
{
    for (nSamples = 0; nSamples < N_SAMPLES; nSamples++)
    {
        adcRead = ADC_Get_Sample( 0 );
        
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2700/pot-click) page.

Other mikroE Libraries used in the example:

- ADC
- Conversions 
- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
