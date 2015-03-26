//============================================================================
// Name        : ZipfTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stat.h"
#include <cmath>
#include <stdlib.h>

using namespace std;


/**
 * H = for i=1:N sum(1/(i + q))
 */
double getH( long N, double q, double s) {
	assert(N > 0);

	double H = 0.0, temp;

	for (int i = 1; i <= N; i++) {
		temp = pow((i + q), -s);
		H += temp;
	}

	return H;
}

/**
 *  k = (H*f)^1/s - q
 */
long ZipfMandelbrot(long N, double q, double s) {
	assert(N > 0);

	double C = 4.015777;	//getH(N, q, s);

	Random rand = Random();
	double f = rand.uniform();
	double temp = pow(C*f, -1.0 / s);
	long zipfValue = temp - q  + 1;

	cout << zipfValue << " ";"\n";

	return zipfValue;
}

/**
 *  y = a*x^b + c
 *  k = ((y-c)/a)^1/b
 */
long ZipfMandelbrot2(double a, double b, double c) {

	double f = rand()/(double)RAND_MAX;
	double d = (f-c)/a;
	double temp = pow(d, 1.0/b);
	long zipfValue = temp  + 1;

	//cout << zipfValue << " \n";

	return zipfValue;
}

/**
 *  y = a*(x-b)^(-c)+d
 *  k = b + ((f-d)/a)^(-1/c)
 */
long ZipfMandelbrot3(double a, double b, double c, double d) {

	double f = rand()/(double)RAND_MAX;
	double e = (f-d)/a;
	double temp = pow(e, -1.0/c);
	long zipfValue = temp  +b+1;

	//cout << zipfValue << " \n";

	return zipfValue;
}

int main() {

	//long N = 20;
	//double zipValue, q = 0.08532212, s = 0.2938252;
	int turn = 10000;
	int k;

	ofstream ofs("generateddata.csv", ios::out);
		if(!ofs) return 0;

	srand((unsigned)time(NULL));		//generate random number series
	for(int i = 1; i <= turn; i++){
		//k = ZipfMandelbrot2(0.2627, -1.33, 0);
		k = ZipfMandelbrot3(0.1382, 0.4796, 1.023, -5.572e-06);
		ofs<<i<<","<<k<<endl;
	}

	ofs.close();

	//zipValue = ZipfMandelbrot(N, q, s);
	return 0;
}
