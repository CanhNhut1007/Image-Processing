#include "Process_File_Bitmap.h"

void Read_Bitmap_FileHeader(ifstream & file_in, Image & image)
{
	file_in.seekg(0);
	file_in.read((char*)&image.file_Header, sizeof(BITMAPFILEHEADER));
}

void Read_Bitmap_InfoHeader(ifstream & file_in, Image & image)
{
	file_in.seekg(sizeof(image.file_Header));
	file_in.read((char*)&image.Info_Header, sizeof(BITMAPINFOHEADER));
}

void Create_Array(Image & image)
{
	image.height = image.Info_Header.biHeight;
	image.width = image.Info_Header.biWidth;

	image.data = new Pixel*[image.height];

	for (int i = 0; i < image.height; i++)
	{
		image.data[i] = new Pixel[image.width];
	}
}

void Read_Data_BitMap(ifstream & file_in, Image & image)
{
	int vt = image.file_Header.bfOffBits;

	int padding = image.width % 4;

	for (int i = image.height - 1; i >= 0; i--)
	{
		file_in.seekg(vt);

		for (int j = 0; j < image.width; j++)
		{
			Pixel temp;
			file_in.read((char*)&image.data[i][j], sizeof(Pixel));
		}

		vt += image.width * 3 + padding;
	}
}

int Read_Image(string Ten_file, Image &image)
{
	ifstream file_in(Ten_file, ios::binary);

	if (file_in.fail())
	{
		cout << "No image open!" << endl;
		return 1;
	}

	Read_Bitmap_FileHeader(file_in, image);

	if (image.file_Header.bfType != 0x4D42)
		return 1;

	Read_Bitmap_InfoHeader(file_in, image);

	Create_Array(image);

	Read_Data_BitMap(file_in, image);

	file_in.close();

	image.isRead = true;

	return 0;
}

void Print_Image(const Image & image, unsigned int x, unsigned int y)
{
	HWND My_Console = GetConsoleWindow();

	HDC My_DC = GetDC(My_Console);

	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			SetPixelV(My_DC, j + y, i + x, RGB(image.data[i][j].Red, image.data[i][j].Green, image.data[i][j].Blue));
		}
	}
}

int Save_Image(Image & image, string file_output)
{
	ofstream file_out(file_output, ios::binary);

	if (file_out.fail() || image.isRead == false)
	{
		cout << "No image open!" << endl;
	}

	image.Info_Header.biHeight = image.height;
	image.Info_Header.biWidth = image.width;

	file_out.write((char*)&image.file_Header, sizeof(BITMAPFILEHEADER));

	file_out.write((char*)&image.Info_Header, sizeof(BITMAPINFOHEADER));

	file_out.seekp(image.file_Header.bfOffBits);

	char ki_tu = '\0';

	int vt = image.file_Header.bfOffBits;

	for (int i = image.height - 1; i >= 0; i--)
	{
		int padding = 0;
		file_out.seekp(vt);

		for (int j = 0; j < image.width; j++)
		{
			file_out.write((char*)&image.data[i][j], sizeof(Pixel));
		}
		while ((image.width * 3 + padding) % 4 != 0)
		{
			padding++;
			file_out.write((char*)&ki_tu, sizeof(char));
		}
		vt += image.width * 3 + padding;
	}

	file_out.close();

	return 0;
}

void Free_Memorry_Array(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		delete[] image.data[i];
	}

	delete[] image.data;

	image.data = NULL;
}
