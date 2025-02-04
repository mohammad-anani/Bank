#pragma once
#include <iostream>
#include "utility.h"
#include "currency.h"
#include "screen.h"
using namespace std;

class calculator:protected clsscreen
{
	static void print(clscurrency currency)
	{
		cout << endl;
		cout << "-------------------------------" << endl;
		cout << "        Currency Info" << endl;
		cout << "-------------------------------" << endl;
		cout << "Country Name  : " << currency.country_name << endl;
		cout << "Currency Code : " << currency.code << endl;
		cout << "Currency Name :" << currency.currency_name << endl;
		cout << "Rate/(1$)     :" << currency.rate << endl;
		cout << "-------------------------------" << endl;
	}
	
	static clscurrency find()
		{
		string message = "";
		cout << "Enter country name or currency code : ";
		message = clsutility::read_string();
		clscurrency currency;
		if (message.length() == 3)
		{
			if (clscurrency::currency_exist(message))
			{
				currency = clscurrency::find_by_code(message);
				return currency;
			}

		}
		else
		{
			if (clscurrency::currency_exist_name(message))
			{
				currency = clscurrency::find_by_name(message);
				return currency;
			}
		}
		}

	static float calculate(float fromrate, float torate, float amount)
	{
		return (amount / fromrate) * torate;
	}
public:
	static void calculate_rate()
	{
		bool repeat = 0;
		do
		{
			system("cls");
			draw_header_screen("Calculator screen");
			cout << "\nEntering from rate:\n";
			clscurrency from = find();
			if (from.code == "")
			{
				cout << "Currency not found.Try again later.\n";
				return;
			}
			print(from);
			cout << "\nEntering to rate:\n";
			clscurrency to = find();
			if (to.code == "")
			{
				cout << "Currency not found.Try again later.\n";
				return;
			}
			print(to);

			cout << "\nEnter amount you want to convert : ";
			float amount = 0;
			cin >> amount;
			cout << endl << fixed << amount << " " << from.code << " = " <<
				fixed << calculate(from.rate, to.rate, amount) << " " <<
				to.code << endl;
			cout << "Do you want to perform another calculation(1/0)?";
			cin >> repeat;
		} while (repeat);
	}
};

