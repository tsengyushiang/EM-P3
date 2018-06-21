#include "FT.h"

FT::FT()
{
}

void FT::equalizeHist(int M,int N,int** InputImage, int** OutputImage)
{
	int totalPixels =M*N;
	int Px[256] = { 0 };
	

	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < N; col++)
		{
			int value = InputImage[row][col];
			if (value > 255)value = 255;
			else if (value < 0) value = 0;
			Px[value]++;
		}
	}

	double cdf[256] = { 0 };
	double accumalater = 0;
	for (int value = 0; value < 256; value++)
	{
		accumalater += (double)(Px[value]) / (double)(totalPixels);
		cdf[value] += accumalater;
	}

	for (int row = 0; row < M; row++)
	{
		for (int col = 0; col < M; col++)
		{
			int value = InputImage[row][col];
			if (value > 255)value = 255;
			else if (value < 0) value = 0;
			Px[value]++;
			OutputImage[row][col] = cdf[value] * 255;
		}
	}
}

void FT::DiscreteFourierTransform(int** InputImage, int** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
	int M = h;
	int N = w;

	double** pFreq = new double*[M];
	for (int newcnt = 0; newcnt<M; newcnt++)
	{
		pFreq[newcnt] = new double[N]; // 傅立葉頻率陣列
	}
	for (int forzero_i = 0; forzero_i<M; forzero_i++)
	{
		for (int forzero_j = 0; forzero_j<N; forzero_j++)
		{
			pFreq[forzero_i][forzero_j] = 0.0f;
		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			DFT(FreqReal, FreqImag, InputImage,M, N, j, i);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 將計算好的傅立葉實數與虛數部分作結合 
			pFreq[i][j] = sqrt(pow(FreqReal[i][j], (double) 2.0) + pow(FreqImag[i][j], (double) 2.0));
			// 結合後之頻率域丟入影像陣列中顯示 
			OutputImage[i][j] = pFreq[i][j];
		}
	}
	//-------------------------------------------
	for (int delcnt = 0; delcnt < M; delcnt++)
	{
		delete[] pFreq[delcnt];
	}
	delete[] pFreq;
}

void FT::DFT(double ** pFreqReal, double ** pFreqImag, int ** InputImage, int h, int w, int u, int v)
{
	// M = N 必須是方陣
	int M = h;
	int N = w;

	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			// 可先計算Eular's equation e^{j*theta} = cos{theta}+j*sin{theta}			
			double angleDFT = (-1.0f * 2.0f * 3.14159 * (double)(u*x + v*y) / (double)M);
			double c = cos(angleDFT);
			double s = sin(angleDFT);

			// 利用Eular's equation計算傅立葉之實虛數部分
			pFreqReal[u][v] += (double)InputImage[y][x] * c;
			pFreqImag[u][v] -= (double)InputImage[y][x] * s;
		}
	}

	pFreqReal[u][v] = pFreqReal[u][v] / (double)(M);
	pFreqImag[u][v] = pFreqImag[u][v] / (double)(M);
}

void FT::InverseDiscreteFourierTransform(int ** InputImage, int ** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
	int M = h;
	int N = w;

	double** InverseReal = new double*[M];
	double** InverseImag = new double*[M];
	double** pFreq = new double*[M];

	for (int i = 0; i<M; i++)
	{
		InverseReal[i] = new double[N];
		InverseImag[i] = new double[N];
		pFreq[i] = new double[N]; // 傅立葉頻率陣列
	}

	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{
			InverseReal[i][j] = 0.0f;
			InverseImag[i][j] = 0.0f;
			pFreq[i][j] = 0.0f;
		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			InverseDFT(InverseReal, InverseImag,FreqReal, FreqImag, M, N, j, i);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 將計算好的傅立葉實數與虛數部分作結合 
			pFreq[i][j] = sqrt(pow(InverseReal[i][j], (double) 2.0) + pow(InverseImag[i][j], (double) 2.0));
			// 結合後之頻率域丟入影像陣列中顯示 
			OutputImage[i][j] = pFreq[i][j];
			//存下反傅立葉實數與虛數部分
			FreqReal[i][j] = InverseReal[i][j];
			FreqImag[i][j] = InverseImag[i][j];

		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		delete[] pFreq[i];
		delete[] InverseReal[i];
		delete[] InverseImag[i];

	}
	delete[] pFreq;
	delete[] InverseReal;
	delete[] InverseImag;

}

void FT::InverseDFT(double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y)
{
	// M = N 必須是方陣
	int M = h;
	int N = w;

	for (int v = 0; v < M; v++)
	{
		for (int u = 0; u < N; u++)
		{
			// 可先計算Eular's equation e^{j*theta} = cos{theta}+j*sin{theta}			
			double angleIDFT = (2.0f * 3.14159 * (double)(u*x + v*y) / (double)M);
			double c = cos(angleIDFT);
			double s = sin(angleIDFT);

			// 利用Eular's equation計算傅立葉之實虛數部分
			InverseReal[x][y] += (pFreqReal[v][u] * c - pFreqImag[v][u] * s);
			InverseImag[x][y] += (pFreqReal[v][u] * s + pFreqImag[v][u] * c);
		}
	}
	InverseReal[x][y] = InverseReal[x][y] / (float)M;
	InverseImag[x][y] = InverseImag[x][y] / (float)M;
}

void FT::FastFourierTransform(int ** InputImage, int ** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
	int M = h;
	int N = w;

	double** pFreq = new double*[M];
	for (int newcnt = 0; newcnt<M; newcnt++)
	{
		pFreq[newcnt] = new double[N]; // 傅立葉頻率陣列
	}
	for (int forzero_i = 0; forzero_i<M; forzero_i++)
	{
		for (int forzero_j = 0; forzero_j<N; forzero_j++)
		{
			pFreq[forzero_i][forzero_j] = 0.0f;
		}
	}
	//-------------------------------------------

	FFT(FreqReal, FreqImag, InputImage, M, N,0,0);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 將計算好的傅立葉實數與虛數部分作結合 
			pFreq[i][j] = sqrt(pow(FreqReal[i][j], (double) 2.0) + pow(FreqImag[i][j], (double) 2.0))*N;
			// 結合後之頻率域丟入影像陣列中顯示 
			OutputImage[i][j] = pFreq[i][j];
		}
	}
	//-------------------------------------------
	for (int delcnt = 0; delcnt < M; delcnt++)
	{
		delete[] pFreq[delcnt];
	}
	delete[] pFreq;
}

void FT::FFT(double ** pFreqReal, double ** pFreqImag, int ** InputImage, int h, int w, int u, int v)
{
	int M = h;
	int N = w;

	std::complex<double>** output = new std::complex<double>*[M];
	for (int i = 0; i < N; i++)output[i] = new std::complex<double>[N];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::complex<double> temp(InputImage[j][i], 0);
			output[i][j] = temp;
		}
	}

	for (int row = 0; row < M; row++) {
		
		for (int i = 1, j = 0; i < N; ++i) {
			for (int k = N >> 1; !((j ^= k)&k); k >>= 1);
			if (i > j)
				swap(output[row][i], output[row][j]);
		}

		for (int k = 2; k <= N; k <<= 1) {
			double omega = -2.0 * 3.14159 / (1.0*k);
			std::complex<double> dtheta(cos(omega), sin(omega));
			for (int j = 0; j < N; j += k) {
				std::complex<double> theta(1, 0);
				for (int i = j; i < j + k / 2; i++) {
					std::complex<double> a = output[row][i];
					std::complex<double> b = output[row][i + k / 2] * theta;
					output[row][i] = a + b;
					output[row][i + k / 2] = a - b;
					theta *= dtheta;
				}
			}
		}
		for (int i = 0; i < N; i++)
			output[row][i] /= N;

	}

	for (int col = 0; col < N; col++) {
		
		for (int i = 1, j = 0; i < N; ++i) {
			for (int k = N >> 1; !((j ^= k)&k); k >>= 1);
			if (i > j)
				swap(output[i][col], output[j][col]);
		}
		
		for (int k = 2; k <= N; k <<= 1) {
			double omega = -2.0 * 3.14159 / (1.0*k);
			std::complex<double> dtheta(cos(omega), sin(omega));
			for (int j = 0; j < N; j += k) {
				std::complex<double> theta(1, 0);
				for (int i = j; i < j + k / 2; i++) {
					std::complex<double> a = output[i][col];
					std::complex<double> b = output[i + k / 2][col] * theta;
					output[i][col] = a + b;
					output[i + k / 2][col] = a - b;
					theta *= dtheta;
				}
			}
		}
		for (int i = 0; i < N; i++)
			output[i][col] /= N;
	}


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			pFreqImag[i][j] = output[i][j].imag();
			pFreqReal[i][j] = output[i][j].real();
		}
	}

	for (int i = 0; i < M; ++i)
		free(output[i]);
	free(output);

}

void FT::InverseFastFourierTransform(double **filter, int ** InputImage, int ** OutputImage, double ** FreqReal, double ** FreqImag, int h, int w)
{
	int M = h;
	int N = w;

	double** InverseReal = new double*[M];
	double** InverseImag = new double*[M];
	double** pFreq = new double*[M];

	for (int i = 0; i<M; i++)
	{
		InverseReal[i] = new double[N];
		InverseImag[i] = new double[N];
		pFreq[i] = new double[N]; // 傅立葉頻率陣列
	}

	for (int i = 0; i<M; i++)
	{
		for (int j = 0; j<N; j++)
		{
			InverseReal[i][j] = 0.0f;
			InverseImag[i][j] = 0.0f;
			pFreq[i][j] = 0.0f;
		}
	}
	//-------------------------------------------

	InverseFFT(filter,InverseReal, InverseImag, FreqReal, FreqImag, M, N, 0, 0);
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 將計算好的傅立葉實數與虛數部分作結合 
			pFreq[i][j] = sqrt(pow(InverseReal[i][j], (double) 2.0) + pow(InverseImag[i][j], (double) 2.0));
			// 結合後之頻率域丟入影像陣列中顯示 
			OutputImage[i][j] = pFreq[i][j];
			//存下反傅立葉實數與虛數部分
			FreqReal[i][j] = InverseReal[i][j];
			FreqImag[i][j] = InverseImag[i][j];

		}
	}
	//-------------------------------------------
	for (int i = 0; i < M; i++)
	{
		delete[] pFreq[i];
		delete[] InverseReal[i];
		delete[] InverseImag[i];

	}
	delete[] pFreq;
	delete[] InverseReal;
	delete[] InverseImag;
}

void FT::InverseFFT(double **filter,double ** InverseReal, double ** InverseImag, double ** pFreqReal, double ** pFreqImag, int h, int w, int x, int y)
{
	int M = h;
	int N = w;

	std::complex<double>** output = new std::complex<double>*[M];
	for (int i = 0; i < N; i++)output[i] = new std::complex<double>[N];

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			std::complex<double> temp(pFreqReal[j][i]*filter[j][i], pFreqImag[j][i]*filter[j][i]);
			output[i][j] = temp;
		}
	}

	for (int row = 0; row < M; row++) {

		for (int i = 1, j = 0; i < N; ++i) {
			for (int k = N >> 1; !((j ^= k)&k); k >>= 1);
			if (i > j)
				swap(output[row][i], output[row][j]);
		}

		for (int k = 2; k <= N; k <<= 1) {
			double omega = 2.0 * 3.14159 / (1.0*k);
			std::complex<double> dtheta(cos(omega), sin(omega));
			for (int j = 0; j < N; j += k) {
				std::complex<double> theta(1, 0);
				for (int i = j; i < j + k / 2; i++) {
					std::complex<double> a = output[row][i];
					std::complex<double> b = output[row][i + k / 2] * theta;
					output[row][i] = a + b;
					output[row][i + k / 2] = a - b;
					theta *= dtheta;
				}
			}
		}		

	}

	for (int col = 0; col < N; col++) {

		for (int i = 1, j = 0; i < N; ++i) {
			for (int k = N >> 1; !((j ^= k)&k); k >>= 1);
			if (i > j)
				swap(output[i][col], output[j][col]);
		}

		for (int k = 2; k <= N; k <<= 1) {
			double omega = 2.0 * 3.14159 / (1.0*k);
			std::complex<double> dtheta(cos(omega), sin(omega));
			for (int j = 0; j < N; j += k) {
				std::complex<double> theta(1, 0);
				for (int i = j; i < j + k / 2; i++) {
					std::complex<double> a = output[i][col];
					std::complex<double> b = output[i + k / 2][col] * theta;
					output[i][col] = a + b;
					output[i + k / 2][col] = a - b;
					theta *= dtheta;
				}
			}
		}		
	}


	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			InverseImag[i][j] = output[i][j].imag();
			InverseReal[i][j] = output[i][j].real();
		}
	}

	for (int i = 0; i < M; ++i)
		free(output[i]);
	free(output);
}


void FT::LowpassFilter(double** filter, int h, int w,double R)
{
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (pow(row-h/2, 2.0) + pow(col-w/2, 2.0) < R*R)
			{
				filter[row][col] = 1;
			}			
			else 
			{
				filter[row][col] = 0;
			}
		}
	}
}

void FT::HighpassFilter(double** filter,int h, int w, double R)
{
	for (int row = 0; row < h; row++)
	{
		for (int col = 0; col < w; col++)
		{
			if (pow(row-h/2, 2.0) + pow(col-w/2, 2.0) < R * R)
			{
				filter[row][col] = 0;
			}			
			else
			{
				filter[row][col] = 1;
			}
		}
	}

}
