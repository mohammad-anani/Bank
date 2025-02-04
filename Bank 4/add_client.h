#pragma once
#include <iostream>
#include "screen.h"
#include "utility.h"
#include "client.h"
#include "currentu.h"
using namespace std;

class clsadd_client:protected clsscreen
{
	static void _read_client(clsclient& client)
	{
		cout << "\nEnter first name : ";
		client.firstname = clsutility::read_string();
		cout << "\nEnter last name  : ";
		client.lastname = clsutility::read_string();
		cout << "\nEnter email      : ";
		client.email = clsutility::read_string();
		cout << "\nEnter phone num  : ";
		client.phone = clsutility::read_positive_number();
		cout << "\nEnter pincode    : ";
		client.pincode = clsutility::read_positive_number();
		cout << "\nEnter balance    : ";
		client.balance = clsutility::read_positive_number();
	}

	static void _print(clsclient client)
	{
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "          Client Info" << endl;
		cout << "-------------------------------" << endl;
		cout << "First name : " <<client.firstname << endl;
		cout << "Last name  : " <<client.lastname << endl;
		cout << "Full name  : " <<client.get_fullname() << endl;
		cout << "Email      : " <<client.email << endl;
		cout << "Phone      : " <<client.phone << endl;
		cout << "Acc.number : " <<client.account_number << endl;
		cout << "Pincode    : " <<client.pincode << endl;
		cout << "Balance    : " <<client.balance << endl;
		cout << "-------------------------------" << endl;
	}

public :

	static void add_client_screen()
	{
			clsscreen::draw_header_screen("Add client screen");

			string accnum = "";
			cout << "Enter account number : ";
			accnum = clsutility::read_string();
			while (clsclient::client_exist(accnum))
			{
				cout << "\nAccount number already exists.Try again : ";
				accnum = clsutility::read_string();
			}
			clsclient new_client = clsclient::create_new_client(accnum);

			_read_client(new_client);

			switch (new_client.save())
			{
			case clsclient::en_save_result::failed_empty:
				cout << "Error:Empty object :-(\n";
				break;
			case  clsclient::en_save_result::failed_exist:
				cout << "Error:Account already exists :-(\n";
				break;
			case  clsclient::en_save_result::succeeded:
				cout << "\n\nClient added successfully\n";
				_print(new_client);
				break;

			}
		
	}
		
	
};

