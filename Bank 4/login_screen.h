#pragma once
#include <iostream>
using namespace std;
#include "user.h"
#include "utility.h"
#include "screen.h"
#include "currentu.h"
#include "main_screen.h"

class clslogin_screen :protected clsscreen
{
	static void _add_user_to_file(string delimiter="#//#")
	{
		fstream file;
		string line = "";
		file.open("logins.txt", ios::app);
		if (file.is_open())
		{
			file << currentuser.username << delimiter << clsutility::print_time() << endl;
			file.close();
		}
	}
public:
	static bool login()
	{
		int trials = 3;
		bool not_found=0;
		string username = "";
		int password = 0;
		do
		{
			system("cls");
			draw_header_screen("Login Screen");
			if (not_found)
			{
				trials--;
				cout << "Incorrect username/password." << trials << " trials left.\n";
			}

			if (trials == 0)
			{
				system("cls");
				draw_header_screen("Login Screen");
				cout << "System locked.3 failed trials.";
				return 0;
			}
			
			
			cout << "Enter username : ";
			username = clsutility::read_string();
			cout << "Enter password : ";
			password = clsutility::read_positive_number();
			not_found = !(clsuser::user_exist(username, password));
			
		} while (not_found);

		currentuser = clsuser::find(username);
		_add_user_to_file();
		clsmain_screen::main_menu();
	}
};

