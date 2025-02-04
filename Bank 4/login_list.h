#pragma once
#include <iostream>
#include <iomanip>
#include "utility.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "screen.h"

class login_list:protected clsscreen
{
public:
	static void print_list()
	{
		draw_header_screen("Logins list");
			cout << "\t\t";
			for (int s = 1; s < 80; s++)
				cout << "-";
			cout << endl << endl;

			cout << "\t\t| " << left << setw(35) << "Username";
			cout << "| " << "Date";
			cout << endl << endl;

			cout << "\t\t";
			for (int s = 1; s < 80; s++)
				cout << "-";
			cout << endl << endl;

			fstream file;
			file.open("logins.txt", ios::in);
				if (file.is_open())
				{
					string line = "";
					while (getline(file, line))
					{
						cout << "\t\t| " << left << setw(35) << line.substr(0, line.find("#//#"));
						line.erase(0, line.find("#//#") + 4);
						cout << "| " << line << endl;
					}
				}
			cout << endl;
			cout << "\t\t";
			for (int s = 1; s < 80; s++)
				cout << "-";
			cout << endl << endl;
	}
};

