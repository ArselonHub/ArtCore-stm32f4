# ArtCore-stm32f4
ArtCore is a library for STM32F4xx series devices..

ArtCore is the core library in Art Framework.. It provides platform
dependent core implementations. All other libraries of Art Framework
depends on this package.. It supplies:

* Preemptive operating system
* Synchronization primitives
* IO encapsulations
	* GPIO
	* UART
	* SPI
	* I2C
	* RTC
	* TIMERS
* String handling
* Flash memory handling
* Statup codes 

As all the microcontroller dependant implementations are done in ArtCore,
the libraries and projects using ArtCore are lightweight and strongly 
portable. This package is for devices STM32F4XXX microcontrollers such as
STM32F429..

# Usage
* Download and install System Workbench from http://www.openstm32.org
* Download or clone this package
* Open System Workbench
* Select a workspace to work with.
* Import the package by right clicking in Project Explorer of the IDE, than 
  clicking "General/Existing Projects into Workspace"
* Select the package ArtCore-stm32f4 folder or .zip file

You may download the examples and import the projects similar way to 
get started..

* https://github.com/ArselonHub/ArtCoreExamples-stm32f429i-disco
