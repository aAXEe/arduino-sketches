/*

Libary zur PID Regelung

Autor: Axel Utech

August 2012
Version: 1.0
*/

#include "PIDRegler.h"

PIDClass::PIDClass(float kp_, float ki_, float kd_, int _maxOut){
	kp = kp_; ki = ki_; kd = kd_; maxOut = _maxOut;
	IMax = maxOut/ki;
	summeI=0;
	wertAlt=0;
}

// Berechnet den Reglerausgabewert
// Rückgabe: Ausgangsgröße 0 .. 255
int PIDClass::regel(float istWert, float sollWert){
	
	float e = sollWert - istWert;

	//D Rechnung
	float reglerD = (wertAlt - e)*kd;
	wertAlt = e;

	//I Rechnung
	summeI += e;
	if(summeI > IMax) summeI=IMax;
	if(summeI < -IMax) summeI = -IMax;
	float reglerI = ki * summeI;

	float reglerP = kp * e;

	//Reglerausgangsgröße
	int pi=reglerP + reglerI + reglerD;
	
	if(pi>maxOut)
		pi=maxOut;
	if(pi<0)  
		pi=0;

	return pi;
}

void PIDClass::reset(void){
	summeI=0;
	wertAlt=0;
}