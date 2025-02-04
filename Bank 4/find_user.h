#pragma once
#include <iostream>
#include "screen.h"
#include "user.h"
using namespace std;

class clsfind_user:protected clsscreen
{
	static void print(clsuser user)
	{
		cout << "-------------------------------" << endl;
		cout << "          User Info" << endl;
		cout << "-------------------------------" << endl;
		cout << "First name : " << user.firstname << endl;
		cout << "Last name  : " << user.lastname << endl;
		cout << "Full name  : " << user.get_fullname() << endl;
		cout << "Email      : " << user.email << endl;
		cout << "Phone      : " << user.phone << endl;
		cout << "Username   : " << user.username << endl;
		cout << "Password   : " << user.password << endl;
		cout << "Permissions: " << user.permissions_number << endl;
		cout << "-------------------------------" << endl;
	}

public:

	static void find()
	{
		clsscreen::draw_header_screen("Find user Screen");
		string username = "";
		cout << "Enter username : ";
		cin >> username;
		while (!(clsuser::user_exist(username)))
		{
			cout << "\nUser not found.Try again : ";
				cin >> username;
		}
		cout << endl << endl;
		clsuser user = clsuser::find(username);
		print(user);
	}
};

