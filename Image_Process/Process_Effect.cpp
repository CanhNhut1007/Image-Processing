#include "Process_Effect.h"

unsigned char Truncate(int value)
{
	if (value < 0)
		return 0;
	if (value > 255)
		return 255;
	return (unsigned char)value;
}

void Brighten(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			image.data[i][j].Blue = Truncate((int)image.data[i][j].Blue + 30);
			image.data[i][j].Green = Truncate((int)image.data[i][j].Green + 30);
			image.data[i][j].Red = Truncate((int)image.data[i][j].Red + 30);
		}
	}
}

void Darken(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			image.data[i][j].Blue = Truncate((int)image.data[i][j].Blue - 50);
			image.data[i][j].Green = Truncate((int)image.data[i][j].Green - 50);
			image.data[i][j].Red = Truncate((int)image.data[i][j].Red - 50);
		}
	}
}

void Hot(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			image.data[i][j].Red = Truncate((int)image.data[i][j].Red + 30);
		}
	}
}

void Cool(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			image.data[i][j].Blue = Truncate((int)image.data[i][j].Blue + 30);
		}
	}
}

void GrayScale(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			unsigned char temp = (image.data[i][j].Blue + image.data[i][j].Green + image.data[i][j].Red) / 3;
			image.data[i][j].Blue = image.data[i][j].Green = image.data[i][j].Red = temp;
		}
	}
}

void Contrast(Image &image)
{
	int contrast = 100;
	double factor = (259 * (contrast + 255)) * 1.0 / (255 * (259 - contrast));

	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			image.data[i][j].Blue = Truncate(factor * (image.data[i][j].Blue - 128) + 128);
			image.data[i][j].Green = Truncate(factor * (image.data[i][j].Green - 128) + 128);
			image.data[i][j].Red = Truncate(factor * (image.data[i][j].Red - 128) + 128);
		}
	}
}

void Flip_Vertical(Image & image)
{
	for (int i = 0; i < image.height / 2; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			Pixel temp = image.data[i][j];
			image.data[i][j] = image.data[image.height - 1 - i][j];
			image.data[image.height - 1 - i][j] = temp;
		}
	}
}

void Flip_Horizontal(Image & image)
{
	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width / 2; j++)
		{
			Pixel temp = image.data[i][j];
			image.data[i][j] = image.data[i][image.width - 1 - j];
			image.data[i][image.width - 1 - j] = temp;
		}
	}
}

Image Rotate__90_Degree(Image & image)
{
	Image newImage = image;

	Pixel **data1 = new Pixel*[image.width];

	for (int i = 0; i < image.width; i++)
	{
		data1[i] = new Pixel[image.height];
	}

	int row = 0;
	for (int i = image.height - 1; i >= 0; i--)
	{
		int col = 0;
		for (int j = 0; j < image.width; j++)
		{
			Pixel temp = image.data[i][j];
			data1[col][row] = temp;
			col++;
		}
		row++;
	}

	newImage.data = data1;
	newImage.width = image.height;
	newImage.height = image.width;

	Free_Memorry_Array(image);
	return newImage;
}

void Border(Image & image)
{
	int red, blue, green, size;
	cout << "Input color(0 <= color <= 255) " << endl;
	do
	{
		cout << "Input color red : ";
		cin >> red;
	} while (red < 0 || red > 255);

	do
	{
		cout << "Input color blue : ";
		cin >> blue;
	} while (blue < 0 || blue > 255);

	do
	{
		cout << "Input color green : ";
		cin >> green;
	} while (green < 0 || green > 255);

	do
	{
		cout << "Input size of border (size > 0 ): ";
		cin >> size;
	} while (size <= 0);

	for (int i = 0; i < image.height; i++)
	{
		for (int j = 0; j < image.width; j++)
		{
			if (i < size || j < size || i > image.height - size || j > image.width - size)
			{
				image.data[i][j].Red = red;
				image.data[i][j].Blue = blue;
				image.data[i][j].Green = green;
			}
		}
	}
}

void Convolution_Matrix(Image &image, double *filter, int filterHeight, int filterWidth, double factor)
{

	for (int i = image.height - 1; i >= 0; i--)
	{
		for (int j = 0; j < image.width; j++)
		{

			float sum_c1 = 0.0f;
			float sum_c2 = 0.0f;
			float sum_c3 = 0.0f;

			for (int kr = 0; kr < filterHeight; kr++) {
				int r_corr = i - kr;
				int x = r_corr;
				if (r_corr < 0)
					r_corr = 0;
				for (int kc = 0; kc < filterWidth; kc++) {
					int c_corr = j + kc;
					int y = r_corr;
					if (c_corr >= image.width)
						c_corr = image.width - 1;
					sum_c1 += image.data[r_corr][c_corr].Blue * filter[kr * filterHeight + kc];
					sum_c2 += image.data[r_corr][c_corr].Green * filter[kr * filterHeight + kc];
					sum_c3 += image.data[r_corr][c_corr].Red * filter[kr * filterHeight + kc];
					c_corr = y;
				}
				r_corr = x;
			}
			image.data[i][j].Blue = Truncate(sum_c1*factor);
			image.data[i][j].Green = Truncate(sum_c2*factor);
			image.data[i][j].Red = Truncate(sum_c3*factor);
		}
	}
}


void Mosaic(Image &image)
{
	int x1, y1, x2, y2;

	cout << "Input left corner coordinates" << endl;
	cout << "(0 <= x < " << image.width << " && 0 <= y < " << image.height << ")" << endl;
	do
	{
		cout << "Input x : ";
		cin >> x1;
		cout << "Input y : ";
		cin >> y1;
	} while (x1 < 0 || y1 < 0 || x1 >= image.width || y1 >= image.height);

	cout << "Input bottom right coordinates" << endl;
	cout << "(" << x1 << " < x < " << image.width << " && " << y1 << " < y < " << image.height << " )" << endl;
	do
	{
		cout << "Input x : ";
		cin >> x2;

		cout << "Input y : ";
		cin >> y2;
	} while (x2 < x1 || x2 >= image.width || y2 < y1 || y2 >= image.height);

	int n = 20;

	for (int i = y1; i <= y2; i += n)
	{
		for (int j = x1; j <= x2; j += n)
		{
			float avgR = 0, avgG = 0, avgB = 0;
			int k = 0;
			for (int col = i; col < i + n; col++)
			{
				int x = col;
				for (int row = j; row < j + n; row++)
				{
					int y = row;
					if (col < 0)
						col = 0;
					if (row < 0)
						row = 0;
					if (col > image.height - 1)
						col = image.height - 1;
					if (row > image.width - 1)
						row = image.width - 1;
					avgB += image.data[col][row].Blue;
					avgG += image.data[col][row].Green;
					avgR += image.data[col][row].Red;
					row = y;
				}
				col = x;
			}

			avgB /= 400.0;
			avgG /= 400.0;
			avgR /= 400.0;

			for (int col = i; col < i + n; col++)
			{
				for (int row = j; row < j + n; row++)
				{
					if (row >= image.width || col >= image.height)
						continue;
					Pixel temp;
					temp.Blue = Truncate((int)avgB);
					temp.Green = Truncate((int)avgG);
					temp.Red = Truncate((int)avgR);
					image.data[col][row] = temp;
				}
			}
		}
	}
}

bool operator!=(Pixel A, Pixel B)
{
	if ((A.Blue == B.Blue && A.Green == B.Green && A.Red == B.Red))
		return false;
	return true;
}

void Loang(Image &image, int x, int y, Pixel mau, Pixel vt_xy)
{
	if (x < 0 || y < 0 || x >= image.width || y >= image.height)
		return;
	if (image.data[y][x] != vt_xy)
		return;
	image.data[y][x] = mau;

	Loang(image, x + 1, y, mau, vt_xy);
	Loang(image, x - 1, y, mau, vt_xy);
	Loang(image, x, y - 1, mau, vt_xy);
	Loang(image, x, y + 1, mau, vt_xy);
}

void Fill(Image & image)
{
	int x, y;
	cout << "Nhap toa do ( 0 <= x < " << image.width << ") && ( 0 <= y < " << image.height << ")";
	do
	{
		cout << "\nNhap x : ";
		cin >> x;
		cout << "Nhap y : ";
		cin >> y;
	} while ((x < 0 || x >= image.width) && (y < 0 || y >= image.height));

	int red, blue, green;
	cout << "Input color(0 <= color <= 255) " << endl;
	do
	{
		cout << "Input color red : ";
		cin >> red;
	} while (red < 0 || red > 255);

	do
	{
		cout << "Input color blue : ";
		cin >> blue;
	} while (blue < 0 || blue > 255);

	do
	{
		cout << "Input color green : ";
		cin >> green;
	} while (green < 0 || green > 255);


	Pixel temp;
	temp.Red = Truncate(red);
	temp.Blue = Truncate(blue);
	temp.Green = Truncate(green);

	Loang(image, x, y, temp, image.data[y][x]);
}

Image Crop(Image &image)
{
	int x1, y1, x2, y2;

	cout << "Input left corner coordinates" << endl;
	cout << "(0 <= x < " << image.width << " && 0 <= y < " << image.height << ")" << endl;
	do
	{
		cout << "Input x : ";
		cin >> x1;
		cout << "Input y : ";
		cin >> y1;
	} while (x1 < 0 || y1 < 0 || x1 >= image.height || y1 >= image.width);

	cout << "Input bottom right coordinates" << endl;
	cout << "(" << x1 << " < x < " << image.width << " && " << y1 << " < y < " << image.height << " )" << endl;
	do
	{
		cout << "Input x : ";
		cin >> x2;

		cout << "Input y : ";
		cin >> y2;
	} while (x2 < x1 || x2 >= image.width || y2 < y1 || y2 >= image.height);

	Image newImage = image;

	Pixel **data1;

	newImage.width = x2 - x1 + 1;
	newImage.height = y2 - y1 + 1;

	data1 = new Pixel*[newImage.height];

	for (int i = 0; i < newImage.height; i++)
	{
		data1[i] = new Pixel[newImage.width];
	}

	int col = 0;

	for (int i = 0; i < image.height; i++)
	{
		if (i >= y1 && i <= y2)
		{
			int row = 0;
			for (int j = 0; j < image.width; j++)
			{
				if (j >= x1 && j <= x2)
				{
					data1[col][row] = image.data[i][j];
					row++;
				}
			}
			col++;
		}

	}

	newImage.data = data1;

	Free_Memorry_Array(image);

	return newImage;
}


