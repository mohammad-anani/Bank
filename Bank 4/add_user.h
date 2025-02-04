#pragma once
#include <iostream>
#include "utility.h"
#include "user.h"
#include "screen.h"
using namespace std;

class clsadd_user:protected clsscreen
{
	static void _read_user(clsuser& user)
	{
		cout << "\nEnter first name : ";
		user.firstname = clsutility::read_string();
		cout << "\nEnter last name  : ";
		user.lastname = clsutility::read_string();
		cout << "\nEnter email      : ";
		user.email = clsutility::read_string();
		cout << "\nEnter phone num  : ";
		user.phone = clsutility::read_positive_number();
		cout << "\nEnter password   : ";
		user.password = clsutility::read_positive_number();
		cout << "\nDo you want user to have full access? 1/0 : ";
		cin >> user.permissions.fullaccess;
		if (user.permissions.fullaccess)
		{
			user.permissions_number = -1;
		}
		else
		{
			cout << "\ndo you want the user to access : \n";
			cout << "\nClient list? 1/0   :"; cin >> user.permissions.accesstolist;
			if (user.permissions.accesstolist)
				user.permissions_number += clsuser::enpermissions::accesstolist;

			cout << "\nAdd client? 1/0    :"; cin >> user.permissions.accesstoadd;
			if (user.permissions.accesstoadd)
				user.permissions_number += clsuser::enpermissions::accesstoadd;

			cout << "\nUpdate client? 1/0 :"; cin >> user.permissions.accesstoupdate;
			if (user.permissions.accesstoupdate)
				user.permissions_number += clsuser::enpermissions::accesstoupdate;

			cout << "\nDelete client? 1/0 : "; cin >> user.permissions.accesstodelete;
			if (user.permissions.accesstodelete)
				user.permissions_number += clsuser::enpermissions::accesstodelete;

			cout << "\nFind client? 1/0   :"; cin >> user.permissions.accesstofind;
			if (user.permissions.accesstofind)
				user.permissions_number += clsuser::enpermissions::accesstofind;

			cout << "\nTransactions? 1/0  :"; cin >> user.permissions.accesstotrans;
			if (user.permissions.accesstotrans)
				user.permissions_number += clsuser::enpermissions::accesstotrans;

			cout << "\nManage users? 1/0  :"; cin >> user.permissions.accesstomanage;
			if (user.permissions.accesstomanage)
				user.permissions_number += clsuser::enpermissions::accesstomanage;
		}
	}

	static void print(clsuser user)
	{
		cout << "-------------------------------" << endl;
		cout << "          User Info" << endl;
		cout << "-------------------------------" << endl;
		cout << "First name : " << user.firstname << endl;
		cout << "Last name  : " << user.lastname<< endl;
		cout << "Full name  : " << user.get_fullname() << endl;
		cout << "Email      : " << user.email << endl;
		cout << "Phone      : " << user.phone << endl;
		cout << "Username   : " << user.username << endl;
		cout << "Password   : " << user.password << endl;
		cout << "Permissions: " << user.permissions_number << endl;
		cout << "-------------------------------" << endl;
	}

public :

	static void add()
	{
		draw_header_screen("Add user Screen");
		cout << "Enter username : ";
		string username = "";
		cin >> username;
		while (clsuser::user_exist(username))
		{
			cout << "\nUsername already exists.try again : ";
			cin >> username;
		}
		clsuser user = clsuser::create_new_user(username);
		_read_user(user);
		switch (user.save())
		{
		case clsuser::en_save_result::failed_exist:
			cout << "\nError:user already exists\n";
		case clsuser::en_save_result::succeeded:
			cout << "\nUser added successfully";
		}
		cout << endl << endl;
		print(user);
	}
};

