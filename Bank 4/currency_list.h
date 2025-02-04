#pragma once
#include <iostream>
using namespace std;
#include "screen.h"
#include "currency.h"
#include <string>

class clscurrency_list :protected clsscreen
{
	static void _print_currency_line(clscurrency currency)
	{
		cout << "\t| " << left << setw(40) << currency.country_name;
		cout << "| " << left << setw(11) << currency.code;
		cout << "| " << left << setw(40) << currency.currency_name;
		cout << "| " << left << setw(11) << currency.rate << endl;
	}

	static void _print_currency_list()
	{
		vector<clscurrency> currencies = clscurrency::get_currencies_list();
		if (currencies.size() == 0)
			cout << "\n\n\t\tNo currencies available\n\n";
		else
		{
			cout << "\t";
			for (int s = 1; s < 102; s++)
				cout << "-";
			cout << endl << endl;

			cout << "\t| " << left << setw(40) << "Country name";
			cout << "| " << left << setw(11) << "Code";
			cout << "| " << left << setw(40) << "Currency name";
			cout << "| " << left << setw(11) << "Rate/(1$)";
			cout << endl << endl;

			cout << "\t";
			for (int s = 1; s < 102; s++)
				cout << "-";
			cout << endl << endl;

			for (clscurrency& currency : currencies)
			{
				_print_currency_line(currency);
			}
			cout << endl;
			cout << "\t";
			for (int s = 1; s < 102; s++)
				cout << "-";
			cout << endl << endl;
		}
	}
public:

	static void show_currency_list_screen()
	{

		draw_header_screen("Currencies list screen", "    (" + to_string(clscurrency::get_currencies_number()) + ") currencies");
		_print_currency_list();
	}
};

