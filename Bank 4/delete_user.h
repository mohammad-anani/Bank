#pragma once
#include "user.h"
#include <iostream>
#include "screen.h"
using namespace std;

class clsdelete_user:protected clsscreen
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
	static void delete_user()
	{
		clsscreen::draw_header_screen("Delete user Screen");
		string account_number = "";
		cout << "Enter username : ";
		account_number = clsutility::read_string();
		while (!clsuser::user_exist(account_number))
		{
			cout << "\nUser not found.Try again : ";
			account_number = clsutility::read_string();
		}
		clsuser user = clsuser::find(account_number);
		print(user);

		cout << "\nAre you sure you want to delete(y/n)?";
		char confirm = 'n';
		cin >> confirm;

		if (confirm == 'y' || confirm == 'Y')
		{
			user.mark_to_delete();
			switch (user.save())
			{
			case clsuser::en_save_result::failed_not_deleted:
				cout << "Error:User not deleted\n";
			case clsuser::en_save_result::succeeded:
				cout << "\n\nUser deleted successfully\n\n";
			}
		}
	}
};

