/*
Headerfile PIDRegler

Autor: Axel Utech
August 2012
Version 1.0

*/
 
#ifndef _PID_H_INCLUDED
#define _PID_H_INCLUDED

#include <stdio.h>
#include <Arduino.h>

class PIDClass{
public:
	PIDClass(float, float, float, int);
	int regel(float, float);
	void reset(void);
private: 
	float kp, ki , kd;
		int maxOut;
	//Hilfwerte Regler
	float summeI;
	float IMax;
	float wertAlt;
};

#endif
