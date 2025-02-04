#pragma once
#include <iostream>
using namespace std;

class clsperson
{
private:
	string _first_name;
	string _last_name;
	string _email;
	int _phone_number;

	

public:
	clsperson()
	{

	}

	void set_first_name(string firstname)
	{
		_first_name = firstname;
	}
	void set_last_name(string lastname)
	{
		_last_name = lastname;
	}
	void set_email(string email)
	{
		_email = email;
	}
	void set_phone(int phone)
	{
		_phone_number = phone;
	}
	string get_firstname()
	{
		return _first_name;
	}
	string get_lastname()
	{
		return _last_name;
	}
	string get_email()
	{
		return _email;
	}
	int get_phonenumber()
	{
		return _phone_number;
	}


	string get_fullname()
	{
		return _first_name + " " + _last_name;
	}

	clsperson(string firstname, string lastname, string email, int phone)
	{
		_first_name = firstname;
		_last_name = lastname;
		_email = email;
		_phone_number = phone;
	}


	__declspec(property(get = get_firstname, put = set_first_name))string firstname;
	__declspec(property(get = get_lastname, put = set_last_name))string lastname;
	__declspec(property(get = get_email, put = set_email))string email;
	__declspec(property(get = get_phonenumber, put = set_phone))int phone;

	void print()
	{
		cout << "-------------------------------" << endl;
		cout << "          Person Info" << endl;
		cout << "-------------------------------" << endl;
		cout << "First name : " << _first_name << endl;
		cout << "Last name  : " << _last_name << endl;
		cout << "Full name  : " << get_fullname() << endl;
		cout << "Email      : " << _email << endl;
		cout << "Phone      : " << _phone_number << endl;
		cout << "-------------------------------" << endl;
	}
};

