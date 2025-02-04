#pragma once
#include "screen.h"
#include <iostream>
#include <iomanip>
#include "utility.h"
#include "delete_client.h"
#include "add_client.h"
#include "update_client.h"
#include "find_client.h"
#include "show_client_list.h"
#include "currentu.h"
#include "transactions_main_screen.h"
#include "currency_screen.h"
#include "user_screen.h"
using namespace std;


class clsmain_screen :protected clsscreen
{
	enum enchoice
	{
		showclient = 1,
		addclient = 2,
		updateclient = 3,
		deleteclient = 4,
		findclient = 5,
		transactions = 6,
		manageusers = 7,
		currency=8,
		logout = 9
	};

	static enchoice _read_choice()
	{
		int choicenumber;

		do
		{
			cout << "\t\t\t\t\t" << "Choose what you want to do(1 to 9) : ";
			choicenumber = clsutility::read_positive_number();
		} while (choicenumber < 1 || choicenumber > 9);
		return enchoice(choicenumber);
	}

	static void _print_main_menu_screen()
	{
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "              Main menu              " << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "         [1]Show client list     " << endl;
		cout << "\t\t\t\t\t" << "         [2]Add client     " << endl;
		cout << "\t\t\t\t\t" << "         [3]Update client list     " << endl;
		cout << "\t\t\t\t\t" << "         [4]Delete client list     " << endl;
		cout << "\t\t\t\t\t" << "         [5]Find client list     " << endl;
		cout << "\t\t\t\t\t" << "         [6]Transactions     " << endl;
		cout << "\t\t\t\t\t" << "         [7]Manage users" << endl;
		cout << "\t\t\t\t\t" << "         [8]Currency exchange" << endl;
		cout << "\t\t\t\t\t" << "         [9]Logout     " << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
	}

	static void _reset()
	{
		system("cls");
	}

	static void _go_back_to_main_menu()
	{
		cout << "\n\tPress any key to return to main menu...";
		system("pause>0");
	}

	static void _client_list_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstolist)))
		{
			clsuser::print_access_denied();
			return;
		}
		else
		clsshow_client_list::show_client_list_screen();
		/*cout << "Client list screen will be added soon\n\n";*/
	}

	static void _add_client_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstoadd)))
		{
			clsuser::print_access_denied();
			return;
		}
		else
		clsadd_client::add_client_screen();
		/*cout << "Add client screen will be added soon\n\n";*/
	}

	static void _update_client_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstoupdate)))
		{
			clsuser::print_access_denied();
			return;
		}
		else
		clsupdate_client::update_client();
		/*cout << "Update client screen will be added soon\n\n";*/
	}

	static void _delete_client_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstodelete)))
		{
			clsuser::print_access_denied();
			return;
		}
		else
		clsdelete_client::delete_client();
		/*cout << "Delete client screen will be added soon\n\n";*/
	}

	static void _find_client_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstofind)))
		{
			clsuser::print_access_denied();
			return;
		}
		else
		clsfind_client::find_client();
		/*cout << "Find client screen will be added soon\n\n";*/
	}

	static void _transaction_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstotrans)))
		{
			clsuser::print_access_denied();
			_go_back_to_main_menu();
		}
		else
		clstransactions_main_screen::transactions_screen();
		/*cout << "Transactions screen will be added soon\n\n";*/
	}

	static void _manage_users_screen()
	{
		if (!(currentuser.check_if_accessible(clsuser::enpermissions::accesstomanage)))
		{
			clsuser::print_access_denied();
			_go_back_to_main_menu();
		}
		else
		clsuser_screen::users_screen();
		/*cout << "Manage users screen will be added soon\n\n";*/
	}


	static bool _perform_main_option(enchoice choice)
	{

		switch (choice)
		{
		case enchoice::showclient:
		{
			_reset();
			_client_list_screen();
			_go_back_to_main_menu();
			break;
		}
		case enchoice::addclient:
		{
			_reset();
			_add_client_screen();
			_go_back_to_main_menu();
			break;
		}
		case enchoice::updateclient:
		{
			_reset();
			_update_client_screen();
			_go_back_to_main_menu();
			break;

		}
		case enchoice::deleteclient:
		{
			_reset();
			_delete_client_screen();
			_go_back_to_main_menu();
			break;
		}
		case enchoice::findclient:
		{
			_reset();
			_find_client_screen();
			_go_back_to_main_menu();
			return 0;
		}
		case enchoice::transactions:
		{
			_reset();
			_transaction_screen();
			return 0;
		}
		case enchoice::manageusers:
		{
			_reset();
			_manage_users_screen();
			return 0;
		}
		case enchoice::currency:
			_reset();
			clscurrency_screen::currency_screen();
			return 0;
		case enchoice::logout:
			return 1;
			break;
		}
	}
	
public:

	static void main_menu()
	{
		_reset();
		draw_header_screen("   Main screen");
		_print_main_menu_screen();
		bool back=_perform_main_option(_read_choice());
		if (back)
		{
			clsuser::empty_user(currentuser);
		}
		else
		{
			_reset();
			main_menu();
		}
	}
	
};

