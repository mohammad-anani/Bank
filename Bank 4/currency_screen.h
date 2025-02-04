#pragma once
#include <iostream>
#include <iomanip>
#include "utility.h"
#include "screen.h"
#include "currency_list.h"
#include "find_currency.h"
#include "calculator.h"
#include "update_rate.h"
using namespace std;

class clscurrency_screen:protected clsscreen
{
	enum enoption
	{
		list = 1,
		find=2,
		update=3,
		calculator=4,
		back=5
	};

	static void _reset()
	{
		system("cls");
	}

	static void _go_back_to_currency_menu()
	{
		cout << "\n\tPress any key to return to Currencies menu...";
		system("pause>0");
	}

	static enoption _read_choice()
	{
		int choicenumber;

		do
		{
			cout << "\t\t\t\t\t" << "Choose what you want to do(1 to 5) : ";
			choicenumber = clsutility::read_positive_number();
		} while (choicenumber < 1 || choicenumber > 5);
		return enoption(choicenumber);
	}

	static void _transaction_screen()
	{
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "        Currency Exchange menu" << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "         [1]Show Currencies list" << endl;
		cout << "\t\t\t\t\t" << "         [2]Find currency" << endl;
		cout << "\t\t\t\t\t" << "         [3]Update rate" << endl;
		cout << "\t\t\t\t\t" << "         [4]Rate calculator" << endl;
		cout << "\t\t\t\t\t" << "         [5]Exit" << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
	}

	static bool _performoption(enoption choice)
	{

		switch (choice)
		{
		case(enoption::list):
			_reset();
			clscurrency_list::show_currency_list_screen();
			_go_back_to_currency_menu();
			break;
		case (enoption::find):
			_reset();
			clsfind_currency::find();
			_go_back_to_currency_menu();
			break;
		case (enoption::update):
			_reset();
			update_rate::update();
			_go_back_to_currency_menu();
			break;
		case (enoption::calculator):
			_reset();
			calculator::calculate_rate();
			_go_back_to_currency_menu();
			break;
		case enoption::back:
			_reset();
			return 1;
		}
	}
public:

	static void currency_screen()
	{
		clsscreen::draw_header_screen("Currency Exchange screen");
		_transaction_screen();
		bool is_back = _performoption(_read_choice());
		if (!is_back)
		{
			_reset();
			currency_screen();
		}
	}

};

