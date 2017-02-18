#pragma once
#include "ofMain.h"

using onDataReceived = void(*)(const int);
namespace
{
	onDataReceived onDataReceivedCallback = nullptr;
}

class serialCommunicationHandler:ofThread {
	
public:
	void setup(const char* portName,int baudRate);
	void close();
	ofSerial serial;
	bool isAvailable;
	void write(int msg);
	void setOnDataReceivedCallback(onDataReceived callback);

private:
	void threadedFunction();
};
