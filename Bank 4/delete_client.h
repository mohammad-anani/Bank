#pragma once
#include <iostream>
#include "screen.h"
#include "client.h"
using namespace std;

class clsdelete_client:protected clsscreen
{
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
	static void delete_client()
	{
		clsscreen::draw_header_screen("Delete client screen");
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

		cout << "\nAre you sure you want to delete(y/n)?";
		char confirm = 'n';
		cin >> confirm;

		if (confirm == 'y' || confirm == 'Y')
		{
			client.mark_to_delete();
			switch (client.save())
			{
			case clsclient::en_save_result::failed_not_deleted:
				cout << "Error:Client not deleted\n";
			case clsclient::en_save_result::succeeded:
				cout << "\n\nClient deleted successfully\n";
			}
		}
	}
};

