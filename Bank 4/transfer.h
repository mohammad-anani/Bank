#pragma once
#include <iostream>
#include "screen.h"
#include <fstream>
#include "utility.h"
using namespace std;
#include "client.h"

#include "currentu.h"


class clstransfer:protected clsscreen
{
	static void _add_transfer_to_file(clsclient sender,clsclient receiver,int amount,string delimiter = "#//#")
	{
		fstream file;
		string line = "";
		file.open("transfers.txt", ios::app);
		if (file.is_open())
		{
			file << sender.account_number << delimiter
				<< receiver.account_number << delimiter << currentuser.username << delimiter << clsutility::print_time() << endl;
			file.close();
		}
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

	static int _performingtransaction(int balance, int amount, int posorneg)
	{
		return balance + (amount * posorneg);
	}

	static void _transfer_amount()
	{
		cout << "Enter account number of sender : ";
		string accnum = clsutility::read_string();
		while (!clsclient::client_exist(accnum))
		{
			cout << "\nClient not found.Try again : ";
			accnum = clsutility::read_string();
		}
		clsclient sender = clsclient::find(accnum);
		cout << endl;
		_print(sender);

		cout << "\nEnter account number of receiver : ";
		string accnum2 = clsutility::read_string();
		while (!clsclient::client_exist(accnum2))
		{
			cout << "\nClient not found.Try again : ";
			accnum2 = clsutility::read_string();
		}
		clsclient receiver= clsclient::find(accnum2);
		cout << endl;
		_print(receiver);
		cout << "\nEnter amount you want to transfer : ";
		int amount = clsutility::read_positive_number();
		while (amount > sender.balance)
		{
			cout << "\nAmount exceeds sender balance!\nTry again : ";
			amount = clsutility::read_positive_number();
		}

		sender.balance = _performingtransaction(sender.balance, amount, -1);
		receiver.balance = _performingtransaction(receiver.balance, amount, 1);
		sender.save();
		receiver.save();

		cout << "\nTransfer done successfully.\n";
		cout << sender.get_fullname() << " balance :" << sender.balance << endl;
		cout << receiver.get_fullname() << " balance :" << receiver.balance << endl;
		_add_transfer_to_file(sender, receiver, amount);
	}

public:
	static void transfer()
	{
		draw_header_screen("Transfer screen");
		_transfer_amount();
	}
};

