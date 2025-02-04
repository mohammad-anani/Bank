#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "utility.h"
#include <vector>

using namespace std;

class clscurrency
{
	string _country_name;
	string _code;
	string _currency_name;
	float _rate;

	static clscurrency _convert_line_to_currency(string line, string delimiter)
	{
		vector<string> currencies = clsutility::split_string(line, delimiter);
		return clscurrency(currencies[0], currencies[1], currencies[2],
			stof(currencies[3]));
	}

	static vector<clscurrency>  _currency_file_to_vector()
	{
		vector<clscurrency> _currencies;
		fstream file;
		string line = "";
		file.open("currencies.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				_currencies.push_back(_convert_line_to_currency(line, "#//#"));
			}
			file.close();
		}
		return _currencies;
	}

	string _convert_currency_to_line(clscurrency currency, string delimiter)
	{
		return currency.country_name + delimiter +
			currency.code + delimiter + 
			currency.currency_name + delimiter + 
			to_string(currency.rate);
	}

	void _vector_to_currency_file(vector<clscurrency> _currencies)
	{
		fstream file;
		file.open("currencies.txt", ios::out);
		if (file.is_open())
		{
			for (clscurrency currency : _currencies)
			{
					file << _convert_currency_to_line(currency, "#//#") << endl;
			}
			file.close();
		}
	}

	void _update()
	{
		vector<clscurrency> _currencies = _currency_file_to_vector();
		for (clscurrency& currency : _currencies)
		{
			if (currency.code == code)
			{
				currency = *this;
				break;
			}
		}
		_vector_to_currency_file(_currencies);
	}
	
	static clscurrency _get_empty_currency()
	{
		return clscurrency("", "", "", 0);
	}

public:

	clscurrency()
	{

	}

	string get_country_name()
	{
		return _country_name;
	}

	string get_code()
	{
		return _code;
	}

	string get_currency_name()
	{
		return _currency_name;
	}

	void set_rate(float rate)
	{
		_rate = rate;
	}

	float get_rate()
	{
		return _rate;
	}

	clscurrency(string country_name, string code, string currency_name, float rate)
	{
		_country_name = country_name;
		_code = code;
		_currency_name = currency_name;
		_rate = rate;
	}

	__declspec(property(put = set_rate, get = get_rate))float rate;
	__declspec(property(get = get_country_name))string country_name;
	__declspec(property(get = get_code))string code;
	__declspec(property(get = get_currency_name))string currency_name;

	static clscurrency find_by_name(string name)
	{
		vector<clscurrency>currencies = _currency_file_to_vector();
		for (clscurrency currency : currencies)
		{
			if ((clsutility::lower_all_letters(currency.country_name) == clsutility::lower_all_letters(name)))
			{
				return currency;
			}
		}
		return _get_empty_currency();
	}

	static clscurrency find_by_code(string code)
	{
		vector<clscurrency>currencies = _currency_file_to_vector();
		for (clscurrency currency : currencies)
		{
			if ((clsutility::lower_all_letters(currency.code) == clsutility::lower_all_letters(code)))
			{
				return currency;
			}
		}
		return _get_empty_currency();
	}

	void save()
	{
		this->_update();
	}

	static vector<clscurrency> get_currencies_list()
	{
		return _currency_file_to_vector();
	}

	static int get_currencies_number()
	{
		return _currency_file_to_vector().size();
	}

	static bool currency_exist(string code)
	{
		return !(clscurrency::find_by_code(code).code == _get_empty_currency().code);
	}

	static bool currency_exist_name(string name)
	{
		return !(clscurrency::find_by_name(name).code == _get_empty_currency().country_name);
	}
};

