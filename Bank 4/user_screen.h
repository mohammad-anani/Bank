#pragma once
#include "user.h"
#include <iostream>
#include "show_user_list.h"
#include "screen.h"
#include "add_user.h"
#include "find_user.h"
#include "delete_user.h"
#include "update_user.h"
#include "login_list.h"
using namespace std;

class clsuser_screen:protected clsscreen
{
	enum manageusersoptions
	{
		ulist = 1,
		uadd = 2,
		uupdate = 3,
		udelete = 4,
		ufind = 5,
		logins=6
	};

	static void _users_menu()
	{
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "             Manage users         " << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
		cout << "\t\t\t\t\t" << "         [1]Show users list" << endl;
		cout << "\t\t\t\t\t" << "         [2]Add user" << endl;
		cout << "\t\t\t\t\t" << "         [3]Update user" << endl;
		cout << "\t\t\t\t\t" << "         [4]Delete user" << endl;
		cout << "\t\t\t\t\t" << "         [5]Find user" << endl;
		cout << "\t\t\t\t\t" << "         [6]Show logins list" << endl;
		cout << "\t\t\t\t\t" << "         [7]Go to main menu" << endl;
		cout << "\t\t\t\t\t" << "======================================" << endl;
	}

	static manageusersoptions _read_choice()
	{
		int choice = 0;
		do
		{
			cout << "\t\t\t\t\tChoose what you want to do (1 to 7): ";
			cin >> choice;
		} while (choice < 1 || choice >7);
		return manageusersoptions(choice);
	}

	static void _go_back_to_users_menu()
	{
		cout << "\tPress any key to return to Users Menu...";
		system("pause>0");
	}

	static bool _perform_option(manageusersoptions choice)
	{
		switch (choice)
		{
		case manageusersoptions::ulist:
			system("cls");
			clsshow_user_list::users_list();
			_go_back_to_users_menu();
			system("cls");
			break;
		case manageusersoptions::uadd:
			system("cls");
			clsadd_user::add();
			_go_back_to_users_menu();
			system("cls");
			break;
		case manageusersoptions::uupdate:
			system("cls");
			clsupdate_user::update();
			_go_back_to_users_menu();
			system("cls");
			break;
		case manageusersoptions::udelete:
			system("cls");
			clsdelete_user::delete_user();
			_go_back_to_users_menu();
			system("cls");
			break;
		case manageusersoptions::ufind:
			system("cls");
			clsfind_user::find();
			_go_back_to_users_menu();
			system("cls");
			break;
		case manageusersoptions::logins:
			system("cls");
			login_list::print_list();
			_go_back_to_users_menu();
			system("cls");
			break;
		default:
			return 1;
		}
	}

public:
	static void users_screen()
	{
		clsscreen::draw_header_screen("Manage Users Screen");
		_users_menu();
		if (_perform_option(_read_choice()))
		{

		}
		else
		users_screen();
	}
};

