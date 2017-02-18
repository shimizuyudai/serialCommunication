#pragma once
#include "ofMain.h"
#include "serialCommunicationHandler.h"

#define SERIAL_COMMUNICATION_API __declspec(dllexport)

extern "C" {
	SERIAL_COMMUNICATION_API void setOnDataReceivedCallback(onDataReceived);
	SERIAL_COMMUNICATION_API void setup(const char* portName, int baudRate);
	SERIAL_COMMUNICATION_API void write(int msg);
	SERIAL_COMMUNICATION_API void close();
	serialCommunicationHandler* serial;
}