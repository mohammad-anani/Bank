#pragma once
#include "person.h"
#include "utility.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class clsuser : public clsperson
{

	struct stpermissions
	{
		bool fullaccess;
		bool accesstolist;
		bool accesstoadd;
		bool accesstoupdate;
		bool accesstodelete;
		bool accesstofind;
		bool accesstotrans;
		bool accesstomanage;
	};

	string _username;
	int _password;
	int _permission_number;
	
	enum usermode { u_empty = 0, u_update = 1, u_add = 2, u_delete = 3 };
	usermode _mode;

	static clsuser _convert_line_to_user(string line, string delimiter)
	{
		vector<string> users = clsutility::split_string(line, delimiter);
		return clsuser(usermode::u_update, users[0], users[1], users[2],
			stoi(users[3]), users[4], stoi(clsutility::decrypt(users[5])),
			stoi(users[6]));
	}

	static vector<clsuser>  _user_file_to_vector()
	{
		vector<clsuser> _clients;
		fstream file;
		string line = "";
		file.open("users.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				_clients.push_back(_convert_line_to_user(line, "#//#"));
			}
			file.close();
		}
		return _clients;
	}

	string _convert_user_to_line(clsuser user, string delimiter)
	{
		return user.firstname + delimiter +
			user.lastname + delimiter +
			user.email + delimiter +
			to_string(user.phone) + delimiter +
			user.username + delimiter +
			clsutility::encrypt(to_string(user.password)) + delimiter +
			to_string(user.permissions_number);
	}

	void _vector_to_user_file(vector<clsuser> _users)
	{
		fstream file;
		file.open("users.txt", ios::out);
		if (file.is_open())
		{
			for (clsuser user : _users)
			{
				if (!user.is_empty())
				{
					file << _convert_user_to_line(user, "#//#") << endl;
				}
			}
			file.close();
		}
	}


	static clsuser _get_empty_user()
	{
		return clsuser(usermode::u_empty, "", "", "", 0, "", 0, 0);
	}

	void _update()
	{
		vector<clsuser> _users = _user_file_to_vector();
		for (clsuser& user : _users)
		{
			if (user.username == username)
			{
				user= *this;
				break;
			}
		}
		_vector_to_user_file(_users);
	}

	void _add()
	{
		fstream file;
		string line = "";
		file.open("users.txt", ios::app);
		if (file.is_open())
		{
			file << _convert_user_to_line(*this, "#//#") << endl;
			file.close();
		}
	}

	void _delete()
	{
		vector<clsuser> _users = _user_file_to_vector();
		for (clsuser& user : _users)
		{
			if (user.username==username)
			{
				user = _get_empty_user();
				break;
			}
		}
		_vector_to_user_file(_users);
	}


public:

	enum enpermissions
	{
		fullaccess = -1,
		accesstolist = 1,
		accesstoadd = 2,
		accesstoupdate = 4,
		accesstodelete = 8,
		accesstofind = 16,
		accesstotrans = 32,
		accesstomanage = 64
	};
	stpermissions permissions;

	void set_username(string username)
	{
		_username = username;
	}

	string get_username()
	{
		return _username;
	}
	 void set_password(int password)
	{
		 _password = password;
	 }

	int get_password()
	{
		return _password;
	}

	static void empty_user(clsuser& user)
	{
		user = _get_empty_user();
	}

	__declspec(property(get = get_username))string username;
	__declspec(property(put = set_password, get = get_password))int password;
	
	void set_permissions(int permissionsnum)
	{
		_permission_number = permissionsnum;
	}

	int get_permissions()
	{
		return _permission_number;
	}

	__declspec(property(get = get_permissions, put = set_permissions))int permissions_number;

	clsuser()
	{

	}

	clsuser(usermode mode, string first_name, string last_name, string email, int phone, 
		string username, int password, int permissionsnum):
		clsperson(first_name, last_name, email, phone)
	{
		
		_username = username;
		_password = password;
		_permission_number = permissionsnum;
		_mode = mode;
	}

	bool is_empty()
	{
		return (_mode == usermode::u_empty);
	}

	static clsuser find(string username)
	{
		fstream file;
		string line = "";
		file.open("users.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsuser user = _convert_line_to_user(line, "#//#");
				if (user.username==username)
					return user;
			}
			return _get_empty_user();
			file.close();
		}
	}

	static clsuser find(string username, int password)
	{
		fstream file;
		string line = "";
		file.open("users.txt", ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				clsuser user = _convert_line_to_user(line, "#//#");
				if (user.username == username && user.password==password)
					return user;
			}

			return _get_empty_user();
			file.close();
		}
	}

	static bool user_exist(string username)
	{
		return !(clsuser::find(username).is_empty());
	}

	static bool user_exist(string username,int password)
	{
		return !(clsuser::find(username,password).is_empty());
	}

	enum en_save_result { failed_empty = 0, succeeded = 1, failed_exist = 2, failed_not_deleted = 3 };

	en_save_result save()
	{
		switch (_mode)
		{
		case usermode::u_empty:

			return en_save_result::failed_empty;

		case usermode::u_add:

			if (user_exist(_username))
				return en_save_result::failed_exist;
			else

			{
				_add();
				_mode = usermode::u_update;

				return en_save_result::succeeded;
			}

		case usermode::u_update:

			_update();
			return en_save_result::succeeded;

		case usermode::u_delete:

			_delete();
			if (clsuser::user_exist(_username))
				return en_save_result::failed_not_deleted;
			else
				return en_save_result::succeeded;

		}
	}

	void mark_to_delete()
	{
		_mode = usermode::u_delete;
	}

	static clsuser create_new_user(string username)
	{
		return clsuser(usermode::u_add, "", "", "", 0, username, 0, 0);
	}

	static vector<clsuser> get_users_list()
	{
		return _user_file_to_vector();
	}

	static int get_users_number()
	{
		return _user_file_to_vector().size();
	}

	 bool check_if_accessible(enpermissions permission)
	{
		 return ((permission & this->permissions_number) == permission || this->permissions_number==-1);
	}

	 static void print_access_denied()
	 {
		 cout << "\t\t\t\t\t" << "-----------------------------" << endl;
		 cout << "\t\t\t\t\t" << "        Access Denied." << endl;
		 cout << "\t\t\t\t\t" << "      Contact your admin." << endl;
		 cout << "\t\t\t\t\t" << "-----------------------------" << endl;
	 }
};

