# Plant-Irrigation-System

# Proposal
## Project Significance:
Indoor plants not only enliven the room, but are also known to improve quality of air. Unfortunately, people sometimes forget to water their plants due 
to busy schedules. My automatic watering system will help plant owners by doing all the work for them! A moisture sensor is placed in the plant’s soil 
and once it detects that the soil is too dry, the device will water the plant until the moisture level is normal again. Instead of remembering when to 
water each plant, all a person needs are sensors in each of the plants’ soil and the vegetation health will be taken care of!

## Technical Description:
I will utilize the following parts:
* Arduino
* Soil moisture sensors
* Tubes
* 4 channel relays
* 4 water pumps
The 4 soil moisture sensors are connected to the arduino through the jumper wires (so they can reach to a plant). The arduino is connected to the 4 channel 
relay. The 4 channel relay is connected to the small water pumps and the batteries. Once the device is finished, the sensors will be inserted into the soil 
and if the soil is too dry, the water pumps will irrigate it.

## Projects I was inspired by:
* https://youtu.be/nUHizmtyt74 
* https://youtu.be/JdvnfENodak
* https://www.youtube.com/watch?v=BFLPmhYbRfY 

# Project Steps:
First, I am testing one moisture sensor to make sure it works properly. 
Moisture sensors measure resistance, which varies based on the amount of water present in soil. Wet soil is much butter at conducting electricity than dry,
which means that wet soil has a lower resistance than dry soil (https://lastminuteengineers.com/soil-moisture-sensor-arduino-tutorial/). To test that the sensor is working correctly, I set a threshold of 460 in the code. When the reading is above 500, then the soil is too dry and the plant needs to be watered. Then, in the serial monitor, I display the results.

![Diagram](Moisture_Sensor.PNG)
I first just lay the sensor on the table (the air is dry, so reading > 460) and then dip it in a cup of water to test (water reading is obviously < 460).

















































































