#include "Process_Display.h"

void menu1()
{
	cout << "-----------------Menu----------------------" << endl;
	cout << "          1.Open Image                     " << endl;
	cout << "          2.Save Image                     " << endl;
	cout << "          3.View Image                     " << endl;
	cout << "          4.Adjustment                     " << endl;
	cout << "          0.Exit                           " << endl;
	cout << "-------------------------------------------" << endl;

}

void menu2()
{
	cout << "-----------------Menu----------------------" << endl;
	cout << "          1.Brighten                       " << endl;
	cout << "          2.Darken                         " << endl;
	cout << "          3.Hot                            " << endl;
	cout << "          4.Cool                           " << endl;
	cout << "          5.GrayScale                      " << endl;
	cout << "          6.Contrast                       " << endl;
	cout << "          7.Flip_Vertical                  " << endl;
	cout << "          8.Flip_Horizontal                " << endl;
	cout << "          9.Rotate 90 Degree               " << endl;
	cout << "          10.Border                        " << endl;
	cout << "          11.Blur                          " << endl;
	cout << "          12.Sharpen                       " << endl;
	cout << "          13.Edge detect                   " << endl;
	cout << "          14.Mosaic                        " << endl;
	cout << "          15.Crop                          " << endl;
	cout << "          16.Fill                          " << endl;
	cout << "          17.Discard effect                " << endl;
	cout << "          0.Come back                      " << endl;
	cout << "-------------------------------------------" << endl;
}

void Blur(Image &image)
{
	cout << "************************************" << endl;
	cout << "*1.Mean3x3                         *" << endl;
	cout << "*2.Mean5x5                         *" << endl;
	cout << "*3.Mean7x7                         *" << endl;
	cout << "*4.Mean9x9                         *" << endl;
	cout << "*5.GaussianBlur3x3                 *" << endl;
	cout << "*6.GaussianBlur5x5                 *" << endl;
	cout << "*7.MotionBlur5x5                   *" << endl;
	cout << "*8.MotionBlur7x7                   *" << endl;
	cout << "*9.MotionBlur9x9                   *" << endl;
	cout << "************************************" << endl;
	int choose1;
	while (1)
	{
		cout << "You choose : ";
		cin >> choose1;
		switch (choose1)
		{
		case 1:
		{
			Matrix_Mean_3x3 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 2:
		{
			Matrix_Mean_5x5 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 3:
		{
			Matrix_Mean_7x7 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 4:
		{
			Matrix_Mean_9x9 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 5:
		{
			Matrix_GaussianBlur_3x3 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 6:
		{
			Matrix_GaussianBlur_5x5 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 7:
		{
			Matrix_MotionBlur_5x5 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 8:
		{
			Matrix_MotionBlur_7x7 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 9:
		{
			Matrix_MotionBlur_9x9 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		default:
			cout << "Invalid request!" << endl;
			break;
		}
		if (choose1 >= 1 && choose1 <= 9)
			break;
	}
}

void Sharpen(Image &image)
{
	cout << "************************************" << endl;
	cout << "*1.Sharpen 7 To 1                  *" << endl;
	cout << "*2.Sharpen 9 To 1                  *" << endl;
	cout << "*3.Sharpen 12 To 1                 *" << endl;
	cout << "*4.Sharpen 5 To 4                  *" << endl;
	cout << "*5.Sharpen 10 To 8                 *" << endl;
	cout << "*6.Sharpen 821                     *" << endl;
	cout << "************************************" << endl;
	int choose1;
	while (1)
	{
		cout << "You choose : ";
		cin >> choose1;
		switch (choose1)
		{
		case 1:
		{
			Matrix_Sharpen_7To1 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 2:
		{
			Matrix_Sharpen_9To1 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 3:
		{
			Matrix_Sharpen_12To1 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 4:
		{
			Matrix_Sharpen_5To4 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 5:
		{
			Matrix_Sharpen_10To8 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 6:
		{
			Matrix_Sharpen_821 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		default:
			cout << "Invalid request!" << endl;
			break;
		}
		if (choose1 >= 1 && choose1 <= 6)
			break;
	}
}

void Edge_detection(Image &image)
{
	cout << "************************************" << endl;
	cout << "*1.Laplacian 3x3                   *" << endl;
	cout << "*2.Laplacian 5x5                   *" << endl;
	cout << "************************************" << endl;
	int choose1;
	while (1)
	{
		cout << "You choose : ";
		cin >> choose1;
		switch (choose1)
		{
		case 1:
		{
			Matrix_Laplacian_3x3 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		case 2:
		{
			Matrix_Laplacian_5x5 filter;
			Convolution_Matrix(image, filter.filter, filter.filterHeight, filter.filterWidth, filter.factor);
			break;
		}
		default:
			cout << "Invalid request!" << endl;
			break;
		}
		if (choose1 >= 1 && choose1 <= 2)
			break;
	}
}

int Process_menu2(Image &image, string file_name)
{
	clrscr();
	menu2();

	int choose;

	while (1)
	{
		cout << "You choose : ";
		cin >> choose;
		if (choose == 0)
			return 1;
		cin.ignore();

		switch (choose)
		{
		case 1:
			Brighten(image);
			Print_Image(image, 10, 400);
			break;
		case 2:
			Darken(image);
			Print_Image(image, 10, 400);
			break;
		case 3:
			Hot(image);
			Print_Image(image, 10, 400);
			break;
		case 4:
			Cool(image);
			Print_Image(image, 10, 400);
			break;
		case 5:
			GrayScale(image);
			Print_Image(image, 10, 400);
			break;
		case 6:
			Contrast(image);
			Print_Image(image, 10, 400);
			break;
		case 7:
			Flip_Vertical(image);
			Print_Image(image, 10, 400);
			break;
		case 8:
			Flip_Horizontal(image);
			Print_Image(image, 10, 400);
			break;
		case 9:
			image = Rotate__90_Degree(image);
			Print_Image(image, 10, 400);
			break;
		case 10:
			Border(image);
			Print_Image(image, 10, 400);
			break;
		case 11:
			Blur(image);
			Print_Image(image, 10, 400);
			break;
		case 12:
			Sharpen(image);
			Print_Image(image, 10, 400);
			break;
		case 13:
			Edge_detection(image);
			Print_Image(image, 10, 400);
			break;
		case 14:
			Mosaic(image);
			Print_Image(image, 10, 400);
			break;
		case 15:
			image = Crop(image);
			Print_Image(image, 10, 400);
			break;
		case 16:
			Fill(image);
			Print_Image(image, 10, 400);
			break;
		case 17:
			cout << "Are you sure ? (y/n)";
			while (1)
			{
				char a = _getch();
				if (a == 'y' || a == 'Y')
				{
					Image image1;
					Read_Image(file_name, image1);
					Free_Memorry_Array(image);
					image = image1;
					return 0;
				}
				else if (a == 'n' || a == 'N')
					return 0;
			}
			break;
		default:
			cout << "Invalid request!" << endl;
			break;
		}

		if (choose >= 0 && choose <= 16)
			break;
	}

	cout << "Do you want to save image?(y/n)";
	while (1)
	{
		char a = _getch();
		if (a == 'y' || a == 'Y')
		{
			string file_output;
			cout << "\nInput file output : ";
			if (choose >= 10 && choose <= 16)
				cin.ignore();
			getline(cin, file_output);
			Save_Image(image, file_output);
			cout << "Success ! Image is saved" << endl;

			cout << "Do you want to continue ?(y/n)";
			while (1)
			{
				char b = _getch();
				if (b == 'n' || b == 'N')
					return 1;
				else if (b == 'y' || b == 'Y')
					return 0;
			}
		}
		else if (a == 'n' || a == 'N')
			return 0;
	}
}



int Process_menu1(Image &image, string &file_name)
{
	string file_output;
	string file_input;
	int choose;

	menu1();

	while (1)
	{
		cout << "You choose : ";
		cin >> choose;

		cin.ignore();
		switch (choose)
		{
		case 0:
			return 1;
		case 1:
			cout << "Input filename : ";

			getline(cin, file_input);

			if (Read_Image(file_input, image) == 0)
				file_name = file_input;

			if (image.width >= 1000 || image.height >= 1000)
				cout << "size Image is large.Cann't display" << endl;
			else
				Print_Image(image, 10, 400);

			break;
		case 2:
			cout << "Input filename output : ";
			getline(cin, file_output);

			if (image.isRead == true)
			{
				Save_Image(image, file_output);

				cout << "Success ! Image is saved" << endl;

				Print_Image(image, 10, 400);
			}
			else
			{
				cout << "No image open!" << endl;
			}

			break;
		case 3:
			if (image.isRead == false)
			{
				cout << "No image open!" << endl;
			}
			else
			{
				cout << "Height : " << image.Info_Header.biHeight << endl;
				cout << "Width : " << image.Info_Header.biWidth << endl;

				Print_Image(image, 10, 400);
			}
			break;
		case 4:
			if (image.isRead == false)
			{
				cout << "No image open!" << endl;
			}
			else
			{
				while (inputKey())
				{
					clrscr();
					if (Process_menu2(image, file_name) == 1)
						return 2;
				}
			}
			break;
		default:
			cout << "Invalid request!" << endl;
			break;
		}

		if (choose >= 1 && choose <= 4)
			break;
	}
	return 0;
}

void Process()
{
	ancontro();
	Image image;
	string file_name;

	while (1)
	{
		char key;
		int x = Process_menu1(image, file_name);
		if (x == 1)
		{
			break;
		}
		else if (x != 2)
		{
			while (inputKey())
			{
				key = getch();

				if (key == 13)
				{
					clrscr();
					break;
				}
			}
		}
		clrscr();
	}
	if (image.isRead == true)
	{
		Free_Memorry_Array(image);
	}
	cout << endl;
}

