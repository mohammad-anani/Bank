#pragma once
#include<iostream>
#include"utility.h"
#include "screen.h"
#include "deposit_screen.h"
#include "withdraw_screen.h"
#include "total_balances_screen.h"
#include "transfer.h"
#include "transfer_list.h"
using namespace std;

class clstransactions_main_screen:protected clsscreen
{
	enum entransactions
	{
		totalbalances = 1,
		deposit = 2,
		withdraw = 3,
		transfer=4,
		transferlist=5,
		back = 6
	};

	static void _reset()
	{
		system("cls");
	}

	static void _go_back_to_trans_menu()
	{
		cout << "\n\tPress any key to return to transactions menu...";
		system("pause>0");
	}

	static entransactions _read_choice()
	{
		int choicenumber;

		do
		{
			cout << "\t\t\t\t\t" << "Choose what you want to do(1 to 6) : ";
			choicenumber = clsutility::read_positive_number();
		} while (choicenumber < 1 || choicenumber > 6);
		return entransactions(choicenumber);
	}

	static void _transaction_screen()
	{
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "          Transactions menu" << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "         [1]Show total balances" << endl;
		cout << "\t\t\t\t\t" << "         [2]Deposit" << endl;
		cout << "\t\t\t\t\t" << "         [3]Withdraw" << endl;
		cout << "\t\t\t\t\t" << "         [4]Transfer" << endl;
		cout << "\t\t\t\t\t" << "         [5]Transfer list" << endl;
		cout << "\t\t\t\t\t" << "         [6]Main menu" << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
	}

	static bool _performtransactions(entransactions choice)
	{
		
		switch (choice)
		{
		case(entransactions::totalbalances):
			_reset();
			clstotal_balances_screen::print_balance_list();
			_go_back_to_trans_menu();
			break;
		case (entransactions::deposit):
			_reset();
			clsdeposit_screen::depositamount();
			_go_back_to_trans_menu();
			break;
		case (entransactions::withdraw):
			_reset();
			clswithdraw_screen::witdrawamount();
			_go_back_to_trans_menu();
			break;
		case (entransactions::transfer):
			_reset();
			clstransfer::transfer();
			_go_back_to_trans_menu();
			break;
		case (entransactions::transferlist):
			_reset();
			transfer_list::print_list();
			_go_back_to_trans_menu();
			break;
		case entransactions::back:
			_reset();
			return 1;
		}
	}
public:

	static void transactions_screen()
	{
		clsscreen::draw_header_screen("Transactions screen");
		_transaction_screen();
		bool is_back=_performtransactions(_read_choice());
		if(!is_back)
		{
			_reset();
			transactions_screen();
		}
	}
};

