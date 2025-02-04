#pragma once
#include <iostream>
#include "client.h"
#include "utility.h"
#include "screen.h"
using namespace std;

class clsupdate_client:protected clsscreen
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
		cout << "First name : " << client.firstname << endl;
		cout << "Last name  : " << client.lastname << endl;
		cout << "Full name  : " << client.get_fullname() << endl;
		cout << "Email      : " << client.email << endl;
		cout << "Phone      : " << client.phone << endl;
		cout << "Acc.number : " << client.account_number << endl;
		cout << "Pincode    : " << client.pincode << endl;
		cout << "Balance    : " << client.balance << endl;
		cout << "-------------------------------" << endl;
	}

public:
	static void update_client()
	{
		clsscreen::draw_header_screen("Update client screen");
		string account_number = "";
		cout << "Enter account number : ";
		account_number = clsutility::read_string();
		while (!clsclient::client_exist(account_number))
		{
			cout << "\nClient not found.Try again : ";
			account_number = clsutility::read_string();
		}
		clsclient client = clsclient::find(account_number);
		_print(client);

		cout << endl;
		cout << "---------------------------" << endl;
		cout << "      Updating Client" << endl;
		cout << "---------------------------" << endl;
		_read_client(client);

		switch (client.save())
		{
		case clsclient::en_save_result::failed_empty:

			cout << "Error:Empty object :-(\n";

		case clsclient::en_save_result::succeeded:

			cout << "\n\nClient updated successfully\n";
			_print(client);

		}



	}
};

