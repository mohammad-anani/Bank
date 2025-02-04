#pragma once
#include <iostream>
using namespace std;
#include "screen.h"
#include "client.h"
#include <string>

class clsshow_client_list :protected clsscreen
{
	static void _print_client_line(clsclient client)
	{
		cout << "\t| " << left << setw(15) << client.account_number;
		cout << "| " << left << setw(10) << client.pincode;
		cout << "| " << left << setw(19) << client.get_fullname();
		cout << "| " << left << setw(19) << client.email;
		cout << "| " << left << setw(15) << client.phone;
		cout << "| " << left << setw(10) << client.balance << endl;
	}

	static void _print_client_list()
	{
		vector<clsclient> clients = clsclient::get_clients_list();
		if (clients.size() == 0)
			cout << "\n\n\t\tNo clients available\n\n";
		else
		{
			cout << "\t";
			for (int s = 1; s < 102; s++)
				cout << "-";
			cout << endl << endl;

			cout << "\t| " << left << setw(15) << "Account number";
			cout << "| " << left << setw(10) << "Pin code";
			cout << "| " << left << setw(19) << "Client's name";
			cout << "| " << left << setw(19) << "Email";
			cout << "| " << left << setw(15) << "Phone number";
			cout << "| " << left << setw(10) << "Balance";
			cout << endl << endl;

			cout << "\t";
			for (int s = 1; s < 102; s++)
				cout << "-";
			cout << endl << endl;

			for (clsclient& client : clients)
			{
				_print_client_line(client);
			}
			cout << endl;
			cout << "\t";
			for (int s = 1; s < 102; s++)
				cout << "-";
			cout << endl << endl;
		}
	}
public:

	static void show_client_list_screen()
	{

		draw_header_screen("Clients list screen", "    (" + to_string(clsclient::get_clients_number()) + ") clients");
		_print_client_list();
	}
};

