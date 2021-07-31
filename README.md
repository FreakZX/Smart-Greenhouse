# Smart-Greenhouse
Standalone greenhouse control system running on RT-Thread RTOS.

# Hardware Framework
To create this project, I used the [STM32-F767ZI Nucleo board](https://www.st.com/en/evaluation-tools/nucleo-f767zi.html).

Equipment list:
- Display Adafruit 2.8 TFT Touch; **(Not yet implemented)**
- loRaWAN module; **(Not yet implemented)**
- DH11 temperature sensor;
- Capacitive Soil Moisture Sensor v1.2;
- Water level sensor; **(Not yet implemented)**
- Servo drive MG995 for opening the tap or a water pump; **(Not yet implemented)**
- Solar panel; **(Not yet implemented)**
- Li-Ion Accumulator; **(Not yet implemented)**

# Software Framework
I used [RT-Thread Studio](https://www.rt-thread.io/studio.html) when creating this project.

# Connection
- Soil Moisture Sensor AOUT Pin to STM32 PC0;
- DH11 DATA Pin to STM32 PB12;
