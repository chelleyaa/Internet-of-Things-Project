# Internet-of-Things-Project
A project to develop an IoT-based smart baby incubator designed to enhance the quality of infant health monitoring. This system integrates sensors and actuators controlled by an ESP32 microcontroller and allows for remote monitoring via the Blynk application, aiming to ease the workload of medical staff. 

# About The Project
In modern healthcare, medical equipment like baby incubators is crucial for providing a stable environment for infants.  Traditional incubators require manual and constant supervision. This project enhances a standard baby incubator with 

Internet of Things (IoT) technology to allow for remote monitoring and control of the infant's environment. The system uses an ESP32 microcontroller as its core, connecting various sensors and actuators to maintain optimal conditions and monitor the baby's vital signs. All data is transmitted to the Blynk platform, enabling medical personnel to monitor conditions in real-time from a smartphone, receive critical notifications, and ensure the infant's safety and well-being with greater efficiency. 

Optimal Conditions
  1. Incubator Temperature: 33°C to 35°C 
  2. Incubator Humidity: 40% to 60%

# Key Features
1. Remote Monitoring: Track incubator temperature, humidity, and the infant's ECG in real-time via the Blynk mobile app. 
2. Automated Climate Control: The system automatically controls a heater and fan to maintain the incubator's internal temperature within a safe, pre-defined range. 
3. Vital Signs Monitoring: An integrated ECG module monitors the infant's heart activity. 
4. Local Display: An LCD screen provides on-site, immediate readouts of temperature, humidity, and heart rate data. 
5. Remote Notifications: The Blynk platform can send alerts to medical staff if conditions become critical, such as abnormal temperature or heart rate.

# Monitored Parameters
The smart incubator is designed to monitor several key health parameters in real-time:
  1. Ambient Temperature 
  2. Relative Humidity 
  3. Heart Rate (ECG) 

# Technology Stack
1. Hardware --> Microcontroller: ESP32, Sensors: DHT11 Temperature & Humidity Sensor, ECG Module (AD8232 based),Actuators: 12V DC Brushless Fan, 220V 100W Blower Heater, 2-Channel Relay Module, LED, Display: I2C LCD 
2. Software --> Development Environment: Arduino IDE, IoT Platform: Blynk, Design Tool: Fritzing

# System Architecture
The system is designed based on a standard three-layer IoT architecture:

1. Perception Layer: This layer includes all physical hardware that interacts with the environment. It consists of the DHT11 sensor to collect temperature/humidity data, the ECG module to monitor heart rate, and actuators like the heater, fan, and LED. The ESP32 acts as the central processing unit for this layer. 


2. Network Layer: This layer is responsible for data transmission. The built-in Wi-Fi module of the ESP32 connects the device to the internet, sending sensor data to the application layer and receiving commands. 

3. Application Layer: This is the user-facing layer. The Blynk platform provides a mobile app interface where medical staff can view real-time data, visualize trends, and control certain device functions remotely.

# Methodology & Workflow
1. Initialization: The ESP32 starts, connects to the local Wi-Fi network, and establishes a connection with the Blynk server. All sensors and the LCD are initialized. 


2. Data Collection: The DHT11 sensor continuously measures temperature and humidity, while the ECG module measures the infant's heart signal. 

3. Local Processing & Display: The ESP32 processes the raw sensor data and displays the current conditions on the I2C LCD screen. The data is also sent to the Blynk server. 

4. Automated Control:
   If the temperature is
     ≤ 30°C, the heater turns ON.
   If the temperature is between
     30°C and 35°C, the heater and fan are OFF.
   If the temperature is
     ≥ 35°C, the heater turns OFF and the fan turns ON to circulate air. 

5. Remote Monitoring & Control: A user can monitor all parameters (temperature, humidity, ECG) in real-time through the Blynk app on a smartphone and remotely control the onboard LED. 
