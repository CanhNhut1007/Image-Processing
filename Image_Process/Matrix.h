#pragma once
#include <iostream>
using namespace std;

//Blur
struct Matrix_Mean_3x3
{
	double filter[9] =
	{
		1, 1, 1,
		1, 1, 1,
		1, 1, 1,
	};
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0 / 9.0;
};

struct Matrix_Mean_5x5
{
	double filter[25] =
	{
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
		1, 1, 1, 1, 1,
	};
	int filterHeight = 5;
	int filterWidth = 5;
	double factor = 1.0 / 25.0;
};

struct Matrix_Mean_7x7
{
	double filter[49] =
	{
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1
	};
	int filterHeight = 7;
	int filterWidth = 7;
	double factor = 1.0 / 49.0;
};

struct Matrix_Mean_9x9
{
	double filter[81] =
	{
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1,
	};
	int filterHeight = 9;
	int filterWidth = 9;
	double factor = 1.0 / 81.0;
};

struct Matrix_GaussianBlur_3x3
{
	double filter[9] =
	{
		1, 2, 1,
		2, 4, 2,
		1, 2, 1,
	};
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0 / 16.0;
};

struct Matrix_GaussianBlur_5x5
{
	double filter[25] =
	{
		2,  4,  5,  4, 2,
		4,  9, 12,  9, 4,
		5, 12, 15, 12, 5,
		4,  9, 12,  9, 4,
		2,  4,  5,  4, 2
	};
	int filterHeight = 5;
	int filterWidth = 5;
	double factor = 1.0 / 159.0;
};

struct Matrix_MotionBlur_5x5
{
	double filter[25] =
	{
		1, 0, 0, 0, 1 ,
		0, 1, 0, 1, 0 ,
		0, 0, 1, 0, 0 ,
		0, 1, 0, 1, 0 ,
		1, 0, 0, 0, 1 };
	int filterHeight = 5;
	int filterWidth = 5;
	double factor = 1.0 / 9.0;
};

struct Matrix_MotionBlur_7x7
{
	double filter[49] =
	{
		1, 0, 0, 0, 0, 0, 1,
		0, 1, 0, 0, 0, 1, 0,
		0, 0, 1, 0, 1, 0, 0,
		0, 0, 0, 1, 0, 0, 0,
		0, 0, 1, 0, 1, 0, 0,
		0, 1, 0, 0, 0, 1, 0,
		1, 0, 0, 0, 0, 0, 1 };
	int filterHeight = 7;
	int filterWidth = 7;
	double factor = 1.0 / 13.0;
};

struct Matrix_MotionBlur_9x9
{
	double filter[81] =
	{
		1, 0, 0, 0, 0, 0, 0, 0, 1,
		0, 1, 0, 0, 0, 0, 0, 1, 0,
		0, 0, 1, 0, 0, 0, 1, 0, 0,
		0, 0, 0, 1, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 0,
		0, 0, 0, 1, 0, 1, 0, 0, 0,
		0, 0, 1, 0, 0, 0, 1, 0, 0,
		0, 1, 0, 0, 0, 0, 0, 1, 0,
		1, 0, 0, 0, 0, 0, 0, 0, 1 };
	int filterHeight = 9;
	int filterWidth = 9;
	double factor = 1.0 / 17.0;
};

struct Matrix_Sharpen_7To1
{
	double filter[9] =
	{
		1, 1, 1,
		1,-7, 1,
		1, 1, 1, };
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0;
};

struct Matrix_Sharpen_9To1
{
	double filter[9] =
	{
		-1, -1, -1,
		-1,  9, -1,
		-1, -1, -1, };
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0;
};

struct Matrix_Sharpen_12To1
{
	double filter[9] =
	{
		-1, -1, -1,
		-1, 12, -1,
		-1, -1, -1, };
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0 / 4.0;
};

struct Matrix_Sharpen_5To4
{
	double filter[9] =
	{
		0, -1,  0,
		-1,  5, -1,
		0, -1,  0, };
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0;
};

struct Matrix_Sharpen_10To8
{
	double filter[9] =
	{
		0, -2,  0,
		-2, 10, -2,
		0, -2,  0 };
	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 2.0;
};

struct Matrix_Sharpen_821
{
	double filter[25] =
	{
		-1,-1,-1,-1,-1,
		-1, 2, 2, 2,-1,
		-1, 2, 8, 2,-1,
		-1, 2, 2, 2,-1,
		-1,-1,-1,-1,-1
	};

	int filterHeight = 5;
	int filterWidth = 5;
	double factor = 1.0 / 8.0;
};


struct Matrix_Laplacian_3x3
{
	double filter[9] =
	{
		-1, -1, -1,
		-1,  8, -1,
		-1, -1, -1 };

	int filterHeight = 3;
	int filterWidth = 3;
	double factor = 1.0;
};

struct Matrix_Laplacian_5x5
{
	double filter[25] =
	{
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, 24, -1, -1,
		-1, -1, -1, -1, -1,
		-1, -1, -1, -1, -1 };
	int filterHeight = 5;
	int filterWidth = 5;
	double factor = 1.0;
};


















