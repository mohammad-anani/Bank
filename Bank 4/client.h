#pragma once
#include "person.h"
#include "utility.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class clsclient:public clsperson
{
	string _account_number;
	int _pincode;
	int _balance;
	enum clientmode { c_empty = 0, c_update = 1, c_add = 2,c_delete=3 };
	clientmode _mode;

	static clsclient _convert_line_to_client_object(string line,string delimiter)
	{
		vector<string> client_members = clsutility::split_string(line, delimiter);
		return clsclient(clientmode::c_update, client_members[0], client_members[1], client_members[2],
			stoi(client_members[3]), client_members[4], stoi(client_members[5]),
			stoi(client_members[6]));
	}

	static vector<clsclient>  _client_file_to_vector()
	{
		vector<clsclient> _clients;
		fstream file;
		string line = "";
		file.open("clients.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				_clients.push_back(_convert_line_to_client_object(line,"#//#"));
			}
			file.close();
		}
		return _clients;
	}

	string _convert_client_to_line(clsclient client,string delimiter)
	{
		return client.firstname + delimiter +
			client.lastname + delimiter +
			client.email + delimiter +
			to_string(client.phone) + delimiter +
			client.account_number + delimiter +
			to_string(client.pincode) + delimiter +
			to_string(client.balance);
	}

	void _vector_to_client_file(vector<clsclient> _clients)
	{
		fstream file;
		file.open("clients.txt", ios::out);
		if (file.is_open())
		{
			for (clsclient client : _clients)
			{
				if(!client.is_empty())
				{
					file << _convert_client_to_line(client, "#//#") << endl;
				}
			}
			file.close();
		}
	}


	static clsclient _get_empty_client()
	{
		return clsclient(clientmode::c_empty, "", "", "", 0, "", 0, 0);
	}

	void _update()
	{
		vector<clsclient> _clients = _client_file_to_vector();
		for (clsclient& client : _clients)
		{
			if (client.account_number == account_number)
			{
				client = *this;
				break;
			}
		}
		_vector_to_client_file(_clients);
	}

	void _add()
	{
		fstream file;
		string line = "";
		file.open("clients.txt", ios::app);
		if (file.is_open())
		{
			file << _convert_client_to_line(*this, "#//#") << endl;
			file.close();
		}
	}

	void _delete()
	{
		vector<clsclient> _clients = _client_file_to_vector();
		for (clsclient& client : _clients)
		{
			if (client.account_number == _account_number)
			{
				client = _get_empty_client();
				break;
			}
		}
		_vector_to_client_file(_clients);
	}



	

	

public:

	clsclient()
	{

	}

	clsclient(clientmode mode, string firstname, string lastname, string email, int phone, string accnum, int pincode, int balance) :
		clsperson(firstname, lastname, email, phone)
	{
		_account_number = accnum;
		_pincode = pincode;
		_balance = balance;
		_mode = mode;
	}

	string get_account_number()
	{
		return _account_number;
	}



	void set_pincode(int pincode)
	{
		_pincode = pincode;
	}

	int get_pincode()
	{
		return _pincode;
	}



	void set_balance(int balance)
	{
		_balance = balance;
	}

	int get_balance()
	{
		return _balance;
	}

	bool is_empty()
	{
		return (_mode == clientmode::c_empty);
	}

	__declspec(property(get = get_account_number))string account_number;
	__declspec(property(get = get_pincode, put = set_pincode))int pincode;
	__declspec(property(get = get_balance, put = set_balance))int balance;

	static clsclient find(string accnum)
	{
			fstream file;
			string line = "";
			file.open("clients.txt", ios::in);
			if (file.is_open())
			{
				while (getline(file, line))
				{
					clsclient client = _convert_line_to_client_object(line, "#//#");
					if (client.account_number == accnum)
						return client;
				}
				return _get_empty_client();
				file.close();
			}
	}

	static clsclient find(string accnum,int pincode)
	{
		fstream file;
		string line = "";
		file.open("clients.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsclient client = _convert_line_to_client_object(line, "#//#");
				if (client.account_number == accnum && client.pincode==pincode)
					return client;
			}

			return _get_empty_client();
			file.close();
		}
	}

	static bool client_exist(string accnum)
	{
		return !(clsclient::find(accnum).is_empty());
    }

	enum en_save_result { failed_empty = 0, succeeded = 1, failed_exist = 2 ,failed_not_deleted=3};

	en_save_result save()
	{
		switch (_mode)
		{
		case clientmode::c_empty:

			return en_save_result::failed_empty;

		case clientmode::c_add:

			if (client_exist(_account_number))
				return en_save_result::failed_exist;
			else

			{
				_add();
				_mode = clientmode::c_update;

				return en_save_result::succeeded;
			}

		case clientmode::c_update:
			
			_update();
			return en_save_result::succeeded;

		case clientmode::c_delete:

			_delete();
			if (clsclient::client_exist(_account_number))
				return en_save_result::failed_not_deleted;
			else
				return en_save_result::succeeded;

		}
	}

	void mark_to_delete()
	{
		_mode = clientmode::c_delete;
	}

	static clsclient create_new_client(string accnum)
	{
		return clsclient(clientmode::c_add, "", "", "", 0, accnum, 0, 0);
	}

	static vector<clsclient> get_clients_list()
	{
		return _client_file_to_vector();
	}

	

	static int get_clients_number()
	{
		return _client_file_to_vector().size();
	}

	
};

