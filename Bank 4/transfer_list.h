#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include "string"
#include "screen.h"

class transfer_list:protected clsscreen
{
public:
	static void print_list()
	{
		draw_header_screen("Transfers list");
		cout << "\t\t";
		for (int s = 1; s < 80; s++)
			cout << "-";
		cout << endl << endl;

		cout << "\t\t| " << left << setw(10) << "Sender";
		cout << "\t\t| " << left << setw(10) << "Receiver";
		cout << "\t\t| " << left << setw(10) << "User";
		cout << "| " << "Date";
		cout << endl << endl;

		cout << "\t\t";
		for (int s = 1; s < 80; s++)
			cout << "-";
		cout << endl << endl;

		fstream file;
		file.open("transfers.txt", ios::in);
		if (file.is_open())
		{
			string line = "";
			while (getline(file, line))
			{
				cout << "\t\t| " << left << setw(10) << line.substr(0, line.find("#//#"));
				line.erase(0, line.find("#//#") + 4);
				cout << "\t\t| " << left << setw(10) << line.substr(0, line.find("#//#"));
				line.erase(0, line.find("#//#") + 4);
				cout << "\t\t| " << left << setw(10) << line.substr(0, line.find("#//#"));
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

