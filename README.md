# HX710B non-blocking SPI (STM32F767ZI)
 An STM32 HAL example of reading the Avia Semiconductor HX710B 24-bit ADC for pressure sensors.

![Water level measuring](/Assets/Images/hx710b_mm_h2o.jpg)

![Preassure sensing](/Assets/Images/hx710b_kPa.jpg)

# Data rate selection
![AVIA Semiconductor 24-Bit ADC with (DVDD-AVDD) Voltage Difference Detection (HX710B): Fig.2 Data output, input and data rate selection timing and control](/Assets/Images/hx710b_data_rate_selection.JPG)
Source: [HX710B Datasheet](https://www.micros.com.pl/mediaserver/info-uphx710b%20smd.pdf)

In the example MOSI is used as CLK to produce the required number of cycles/pulses for HX710B. It enables a straightforward use of DMA just by calling HAL_SPI_TransmitReceive_DMA().

# Missing files?
Don't worry :slightly_smiling_face: Just hit Alt-K to generate /Drivers/CMCIS/ and /Drivers/STM32F7xx_HAL_Driver/ based on the .ioc file. After a couple of seconds your project will be ready for building.

# Exemplary hardware for breadboarding
* [HX710B water pressure sensor](https://allegro.pl/oferta/hx710b-czujnik-barometryczny-cisnienia-wody-13770065116)
* [Alphanumeric HD44780 LCD display](https://sklep.avt.pl/pl/products/wyswietlacz-lcd-alfanumeryczny-2x16-lcd-pc-1602an-diy-y-kk-1l-e6-c-pbf-blackline-176223.html)
* [PCF8574 I2C converter for HD44780 LCD display](https://botland.store/other-converters/2352-i2c-converter-for-hd44780-lcd-display-5903351248693.html)
* [Bidirectional 4-channel logic level shifter](https://botland.store/voltage-converters/2259-logic-level-bi-directional-converter-4-channel--5903351248716.html)

# Sources and inspirations
* MOSI as CLK for HX710B: My original idea, i.e. not copied from other sources. It doesn't mean that I'm the first one to do it this way - probably I'm not. I just didn't came across such a solution in other projects known to me.
* LCD: [kurs-stm32-e16-lcd](https://github.com/ptrre/kurs-stm32-e16-lcd) or [kurs-stm32-e17-lcd-znaki](https://github.com/ptrre/kurs-stm32-e17-lcd-znaki) (MIT license)

# Call for action
Start building your own [home laboratory/workshop/garage](http://ufnalski.edu.pl/control_engineering_for_hobbyists/2024_dzien_otwarty_we/Dzien_Otwarty_WE_2024_Control_Engineering_for_Hobbyists.pdf)! Get inspired by [ControllersTech](https://www.youtube.com/@ControllersTech), [DroneBot Workshop](https://www.youtube.com/@Dronebotworkshop), [Andreas Spiess](https://www.youtube.com/@AndreasSpiess), [GreatScott!](https://www.youtube.com/@greatscottlab), [ElectroBOOM](https://www.youtube.com/@ElectroBOOM), [Phil's Lab](https://www.youtube.com/@PhilsLab), [atomic14](https://www.youtube.com/@atomic14), [That Project](https://www.youtube.com/@ThatProject), [Paul McWhorter](https://www.youtube.com/@paulmcwhorter), and many other professional hobbyists sharing their awesome projects and tutorials! Shout-out/kudos to all of them!

> [!WARNING]
> Control engineering - try this at home :exclamation:

190+ challenges to start from: [Control Engineering for Hobbyists at the Warsaw University of Technology](http://ufnalski.edu.pl/control_engineering_for_hobbyists/Control_Engineering_for_Hobbyists_list_of_challenges.pdf).

Stay tuned!
