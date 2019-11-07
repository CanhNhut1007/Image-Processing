#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;

struct Pixel
{
	unsigned char Blue;
	unsigned char Green;
	unsigned char Red;
};

struct Image
{
	BITMAPFILEHEADER file_Header;

	BITMAPINFOHEADER Info_Header;

	Pixel **data;

	bool isRead;

	unsigned int width;
	unsigned int height;

	Image()
	{
		width = 0;
		height = 0;
		isRead = false;
	}
};

void Read_Bitmap_FileHeader(ifstream &file_in, Image &image);

void Read_Bitmap_InfoHeader(ifstream &file_in, Image &image);

void Create_Array(Image &image);

void Read_Data_BitMap(ifstream &file_in, Image &image);

int Read_Image(string Ten_file, Image &image);

void Print_Image(const Image &image, unsigned int x, unsigned int y);

int Save_Image(Image &image, string file_output);

void Free_Memorry_Array(Image &image);


