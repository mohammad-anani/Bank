#pragma once
#include <iostream>
#include "screen.h"
#include "currency.h"
using namespace std;

class clsfind_currency :protected clsscreen
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

public:

	static void find()
	{
		clsscreen::draw_header_screen("Find Currency Screen");
		string message = "";
		cout << "Enter country name or currency code : ";
		message = clsutility::read_string();
		if (message.length() == 3)
		{
			if (clscurrency::currency_exist(message))
			{
				print(clscurrency::find_by_code(message));
			}
			else
			{
				cout << "\nCurrency not found.Try again later.\n";
			}

		}
		else
		{
			if (clscurrency::currency_exist_name(message))
			{
				print(clscurrency::find_by_name(message));
			}
			else
			{
				cout << "\nCurrency not found.Try again later.\n";
			}
		}
	}
};

