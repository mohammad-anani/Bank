#pragma once
#include <iostream>
#include "currency.h"
#include "utility.h"
#include "screen.h"
using namespace std;

class update_rate:protected clsscreen
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

	static bool confirm()
	{
		cout << "Are you sure you want to update(1/0)?";
		bool up;
		cin >> up;
		return up;
	}

public:

	static void update()
	{
		clsscreen::draw_header_screen("Update Rate Screen");
		string message = "";
		cout << "Enter country name or currency code : ";
		message = clsutility::read_string();
		clscurrency currency;
		if (message.length() == 3)
		{
			if (clscurrency::currency_exist(message))
			{
			    currency = clscurrency::find_by_code(message);
			}
			else
			{
				cout << "\nCurrency not found.Try again later.\n";
				return;
			}

		}
		else
		{
			if (clscurrency::currency_exist_name(message))
			{
				currency = clscurrency::find_by_name(message);
			}
			else
			{
				cout << "\nCurrency not found.Try again later.\n";
				return;
			}
		}
		print(currency);
		if (confirm())
		{
			cout << "\nEnter new rate : ";
			float rate = 0;
			cin >> rate;
			currency.rate = rate;
			currency.save();
			cout << "\nCurrency rate updated successfully.\nNew rate is : " << currency.rate;
		}
	}
};

