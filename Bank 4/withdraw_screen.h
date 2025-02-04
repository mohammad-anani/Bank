#pragma once
#include <iostream>
#include "screen.h"
#include "client.h"
#include <vector>
#include "utility.h"
#include "transfer.h"
using namespace std;

class clswithdraw_screen :protected clsscreen
{
	static int _readamount(string message)
	{
		int amount = 0;
		do
		{
			cout << "\nEnter the amount you want to " << message << " : ";
			cin >> amount;
		} while (amount <= 0);
		return amount;
	}

	static int _performingtransaction(int balance, int amount, int posorneg)
	{
		return balance + (amount * posorneg);
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
	static void witdrawamount()
	{
		draw_header_screen("Withdraw screen");
		clsclient client;
		vector<clsclient> clients = clsclient::get_clients_list();

		cout << "Enter account number : ";
		string accnum = clsutility::read_string();

		while (!clsclient::client_exist(accnum))
		{
			cout << "\nClient not found.Try again : ";
			string accnum = clsutility::read_string();
		}
		client = clsclient::find(accnum);
		_print(client);

		int amount = _readamount("withdraw");
		while (amount > client.balance)
		{
			cout << "\nAmount exceeds balance!";
		     amount = _readamount("withdraw");
		}
		
		client.balance = _performingtransaction(client.balance,amount, -1);
		client.save();
		
			cout << "\nTransaction successful.Your new balance is : " << client.balance << endl;

	}
};

