#pragma once
#include <iostream>
#include <algorithm>
#include <complex>
class FT
{
private:
	
public:
	FT();
	

	void equalizeHist(int M, int N, int** InputImage,int** OutputImage);

	void DiscreteFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void DFT(double** pFreqReal, double** pFreqImag, int** InputImage, int h, int w, int u, int v);

	void InverseDiscreteFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void InverseDFT(double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y);

	void FastFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void FFT(double** pFreqReal, double** pFreqImag, int** InputImage, int h, int w, int u, int v);

	void InverseFastFourierTransform(double **filter, int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w);
	void InverseFFT(double **filter, double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y);

	void LowpassFilter(double** filter, int h, int w , double R);
	void HighpassFilter(double** filter,  int h, int w, double R);

private:

};



