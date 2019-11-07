#pragma once
#include <iostream>
#include <string>
#include "console.h"
#include "Process_Effect.h"
#include "Matrix.h"
#include "Process_File_Bitmap.h"
using namespace std;

void menu1();

void menu2();

int Process_menu2(Image & image, string file_name);

int Process_menu1(Image &image, string &file_name);

void Process();



