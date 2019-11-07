#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "console.h"
#include <fstream>
#include "Process_File_Bitmap.h"
using namespace std;

void Brighten(Image &image);

void Darken(Image &image);

void Hot(Image &image);

void Cool(Image &image);

void GrayScale(Image &image);

void Contrast(Image &image);

void Flip_Vertical(Image &image);

void Flip_Horizontal(Image & image);

Image Rotate__90_Degree(Image &image);

void Border(Image &image);

void Convolution_Matrix(Image &image, double *filter, int filterHeight, int filterWidth, double factor);

void Mosaic(Image &image);

void Fill(Image &image);

Image Crop(Image &image);

