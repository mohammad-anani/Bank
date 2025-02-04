#pragma once
#include <iostream>
#include "client.h"
#include "screen.h"
class clstotal_balances_screen:protected clsscreen
{
	static void _print_client_balance(clsclient client)
	{
		cout << "\t\t| " << left << setw(15) << client.account_number;
		cout << "| " << left << setw(40) << client.get_fullname();
		cout << "| " << left << setw(10) << client.balance << endl;
	}
	static int _calctotalbalances(vector<clsclient> clients)
	{
		int sum = 0;
		for (clsclient& client : clients)
			sum += client.balance;
		return sum;
	}

public:

	static void print_balance_list()
	{
		vector<clsclient> clients = clsclient::get_clients_list();
		draw_header_screen("Balances list", "    (" + to_string(clsclient::get_clients_number()) + ") clients");
	
		if (clients.size() == 0)
		{
			cout << "\n\n\t\t\tNo clients available\n\n";
		}
		else
		{
			cout << "\t\t";
			for (int s = 1; s < 80; s++)
				cout << "-";
			cout << endl << endl;

			cout << "\t\t| " << left << setw(15) << "Account number";
			cout << "| " << left << setw(40) << "Client's name";
			cout << "| " << left << setw(10) << "Balance";
			cout << endl << endl;

			cout << "\t\t";
			for (int s = 1; s < 80; s++)
				cout << "-";
			cout << endl << endl;

			for (clsclient& client : clients)
			{
				_print_client_balance(client);
			}
			cout << endl;
			cout << "\t\t";
			for (int s = 1; s < 80; s++)
				cout << "-";
			cout << endl << endl;
			int total = _calctotalbalances(clients);
			cout << right << setw(41) << "\tTotal balances : " << total << endl;
			cout << right << setw(25) << "\t(" << clsutility::convert_number_to_text(total) << "dollars)" << endl << endl;
		}
	}
};

