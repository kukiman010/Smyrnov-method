#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;

class Balistic
{
	int shooting;
	int *distance;

	float P1, P2, P;
	float B1, B2, B;

	int line;

	int DELET;
	int cache;
	
	int shooting_2;
	int *distance_2;
	float sum = 0.0, sum_2 = 0.0;

	//const 
	const float E = 0.6745;
	const float M = 0.995;
	
	float malfunction;

	float alpha;
	float Bg, Tn;

	int arraY[14] = {2824,2844,2875,2875,2914,
					2919,2950,2954,2962,2978,
					2986,3002,3006,3083};
	
	int arraY2[5] = { 1404,1400,1396,1392,1376 };


	double sd[5][24] = { {0,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25},
					{0.1,16.8,7.35,5.78,5.18,4.87,4.71,4.60,4.52,4.48,4.44,4.42,4.40,4.39,4.39,4.38,4.38,4.38,4.38,4.38,4.38,4.39,4.39,4.39},
					{0.05,32.3,10.7,7.54,6.43,5.89,5.58,5.38,5.24,5.15,5.08,5.02,4.98,4.94,4.92,4.90,4.89,4.87,4.86,4.85 ,4.85,4.84,4.84,4.85},
					{0.025,105,15.0,9.65,7.87,7.02,6.52,6.20,5.99,5.84,5.72,5.62,5.56,5.50,5.45,5.42,5.38,5.36,5.34,5.32,5.31,5.29,5.28,5.27},
					{0.010,105,23.6,13.3,10.2,8.70,7.89,7.38,7.03,6.79,6.60,6.45,6.34,6.24,6.17,6.10,6.05,6.00,5.97,5.93,5.90,5.88,5.86,5.84}};

public:
	Balistic();

	void one();
	void two();
	void metod_Smirnova();
	void menu();
	void tree();

	~Balistic();
};