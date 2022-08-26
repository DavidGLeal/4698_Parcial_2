#pragma once
#include <engine.h>
#include <iostream>
#include <limits>
#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "BigO.h"

#pragma comment ( lib , "libmat.lib")
#pragma comment ( lib , "libmx.lib")
#pragma comment ( lib , "libmex.lib")
#pragma comment ( lib , "libeng.lib")

using namespace std;

class Matlab {
public:
    Matlab();
    ~Matlab();
    void procesoMatlab();
	void procesoPython();
};

Matlab::Matlab(){
}

Matlab::~Matlab(){
}

void Matlab :: procesoMatlab(){
    Engine* m_pEngine;
	m_pEngine = engOpen("null");

	const int arraySize = 20;
	const double degTorad = .0245;

	double SinArray[arraySize];
	double CosArray[arraySize];
	double TanArray[arraySize];
	double Degrees[arraySize];

	for (int iii = 0; iii < arraySize; iii++) {
		Degrees[iii] = iii;
		SinArray[iii] = sin(iii * degTorad);
		CosArray[iii] = cos(iii * degTorad);
		TanArray[iii] = tan(iii * degTorad);
	}
	mxArray* SIN = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
	std::memcpy((void*)mxGetPr(SIN), (void*)SinArray, sizeof(double) * arraySize);
	engPutVariable(m_pEngine, "SinGraph", SIN);

	mxArray* COS = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
	std::memcpy((void*)mxGetPr(COS), (void*)CosArray, sizeof(double) * arraySize);
	engPutVariable(m_pEngine, "CosGraph", COS);

	mxArray* TAN = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
	std::memcpy((void*)mxGetPr(TAN), (void*)TanArray, sizeof(double) * arraySize);
	engPutVariable(m_pEngine, "TanGraph", TAN);

	mxArray* DEG = mxCreateDoubleMatrix(arraySize, 1, mxREAL);
	std::memcpy((void*)mxGetPr(DEG), (void*)Degrees, sizeof(double) * arraySize);
	engPutVariable(m_pEngine, "Degrees", DEG);


	engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 0 1 1 1]),");
	engEvalString(m_pEngine, "plot(Degrees,TanGraph,'r',Degrees,CosGraph,'b'), grind minor, title('Notacion Big O'),");
}

void Matlab :: procesoPython(){
	Engine* m_pEngine;
	m_pEngine = engOpen("BigO.py");

	const int arraySize = 20;
	const double degTorad = .0245;

	double Degrees[arraySize];

	for (int iii = 0; iii < arraySize; iii++) {
		BigO obj;
		Degrees[iii] = iii;
	}

	engEvalString(m_pEngine, "figure('units','normalized','outerposition',[0 0 0 1 1 1]),");
	engEvalString(m_pEngine, "plot(BMH,'g',preBMBc,'b',imprimirBMH,'y'), grind minor, title('Notacion BigO'),");


}