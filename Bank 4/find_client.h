#pragma once
#include <iostream>
#include "client.h"
#include "utility.h"
#include "screen.h"
using namespace std;


class clsfind_client:protected clsscreen
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

	static void find_client()
	{
		clsscreen::draw_header_screen("Find client screen");
		cout << "Enter account number : ";
		string accnum = clsutility::read_string();
		while (!clsclient::client_exist(accnum))
		{
			cout << "\nClient not found.Try again : ";
			accnum = clsutility::read_string();
		}
		_print(clsclient::find(accnum));
		
	}

};

