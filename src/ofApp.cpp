#include "ofApp.h"

void setOnDataReceivedCallback(onDataReceived callback)
{
	if (serial != nullptr) {
		serial->setOnDataReceivedCallback(callback);
	}
}

void setup(const char* portName,int baudRate){
	serial = new serialCommunicationHandler();
	serial->setup(portName,baudRate);
}

void write(int msg)
{
	if (serial != nullptr) {
		serial->write(msg);
	}
}

void close()
{
	if (serial != nullptr) {
		serial->close();
		delete serial;
	}
}
