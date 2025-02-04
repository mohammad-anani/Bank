#pragma once
#include <iostream>
#include "user.h"
#include "screen.h"
using namespace std;


class clsshow_user_list : protected clsscreen
{
	static void _print_list()
	{
		vector<clsuser> users = clsuser::get_users_list();

		cout << "\t\t";
		for (int s = 1; s < 80; s++)
			cout << "-";
		cout << endl << endl;

		cout << "\t\t| " << left << setw(15) << "User name";
		cout << "| " << left << setw(30) << "Full name";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << endl << endl;

		cout << "\t\t";
		for (int s = 1; s < 80; s++)
			cout << "-";
		cout << endl << endl;

		for (clsuser& user : users)
		{
			cout << "\t\t| " << left << setw(15) << user.username;
			cout << "| " << left << setw(30) << user.get_fullname();
			cout << "| " << left << setw(10) << user.password;
			cout << "| " << left << setw(10) << user.permissions_number << endl;
		}
		cout << endl;
		cout << "\t\t";
		for (int s = 1; s < 80; s++)
			cout << "-";
		cout << endl << endl;
	}

public:
	static void users_list()
	{
		clsscreen::draw_header_screen("Users List Screen", clsuser::get_users_number() + " users");
		_print_list();
	}
};

