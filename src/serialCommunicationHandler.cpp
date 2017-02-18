#include "serialCommunicationHandler.h"

void serialCommunicationHandler::setup(const char* portName,int baudRate)
{
	isAvailable = serial.setup(portName, baudRate);
	this->startThread();
}

void serialCommunicationHandler::close()
{
	if (isAvailable && serial.isInitialized()) {
		serial.close();
	}
	
	this->stopThread();
}

void serialCommunicationHandler::write(int msg)
{
	lock();
	unsigned char m = msg;
	serial.writeByte(m);
	unlock();
}

void serialCommunicationHandler::setOnDataReceivedCallback(onDataReceived callback)
{
	onDataReceivedCallback = callback;
}

void serialCommunicationHandler::threadedFunction()
{
	while (true) {
		if (isAvailable && serial.isInitialized()) {
			for (auto i = 0; i < serial.available(); i++) {
				auto msg = serial.readByte();
				if (onDataReceivedCallback != nullptr) onDataReceivedCallback(msg);
			}
		}
		this->sleep(1);
	}
}
