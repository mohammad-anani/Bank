#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <string>
#include <cctype>
using namespace std;

class clsutility
{
	static string _convertdigittotext(long long int number)
	{
		if (number == 1)
			return "one ";
		else if (number == 2)
			return "two ";
		else if (number == 3)
			return "three ";
		else if (number == 4)
			return "four ";
		else if (number == 5)
			return "five ";
		else if (number == 6)
			return "six ";
		else if (number == 7)
			return "seven ";
		else if (number == 8)
			return "eight ";
		else if (number == 9)
			return "nine ";
		else if (number == 10)
			return "ten ";
		else if (number == 11)
			return "eleven ";
		else if (number == 12)
			return "twelve ";
		else if (number == 13)
			return "thirteen ";
		else if (number == 14)
			return "fourteen ";
		else if (number == 15)
			return "fifteen ";
		else if (number == 16)
			return "sixteen ";
		else if (number == 17)
			return "seventeen ";
		else if (number == 18)
			return "eighteen ";
		else if (number == 19)
			return "nineteen ";
		else if (number < 30)
			return "twenty ";
		else if (number < 40)
			return "thirty ";
		else if (number < 50)
			return "fourty ";
		else if (number < 60)
			return "fifty ";
		else if (number < 70)
			return "sixty ";
		else if (number < 80)
			return "seventy ";
		else if (number < 90)
			return "eighty ";
		else if (number < 100)
			return "ninety ";
	}

	static string convertnumbertotext(long long int number, string& text)
	{
		if (number <= 10)
		{
			if (number > 0)
			{
				text += _convertdigittotext(number);
			}
		}
		else if (number < 20)
		{
			text += _convertdigittotext(number);
		}
		else if (number < 100)
		{
			text += _convertdigittotext(number);
			convertnumbertotext(number % 10, text);
		}
		else if (number < 1000)
		{
			text += _convertdigittotext(number / 100);
			text += "hundred ";
			convertnumbertotext(number % 100, text);
		}
		else if (number < 10000)
		{
			text += _convertdigittotext(number / 1000);
			text += "thousand ";
			convertnumbertotext(number % 1000, text);
		}
		else if (number < 100000)
		{
			convertnumbertotext(number / 1000, text);
			text += "thousand ";
			convertnumbertotext(number % 1000, text);
		}
		else if (number < 1000000)
		{
			convertnumbertotext(number / 1000, text);
			text += "thousand ";
			convertnumbertotext(number % 1000, text);
		}
		else if (number < 10000000)
		{
			text += _convertdigittotext(number / 1000000);
			text += "million ";
			convertnumbertotext(number % 1000000, text);
		}
		else if (number < 100000000)
		{
			text += _convertdigittotext(number / 1000000);
			text += " million ";
			convertnumbertotext(number % 1000000, text);
		}
		else if (number < 1000000000)
		{
			convertnumbertotext(number / 1000000, text);
			text += "million ";
			convertnumbertotext(number % 1000000, text);
		}
		else
		{
			text += _convertdigittotext(number / 1000000000);
			text += "billion ";
			convertnumbertotext(number % 1000000000, text);
		}
		return text;
	}

public:

	static string lower_all_letters(string word)
	{
		string newword="";
		for (int s = 0; s < word.length(); s++)
		{
			newword+=tolower(word[s]);
		}
		return newword;
	}

	static void print_date()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		cout << now->tm_mday << "/" << now->tm_mon + 1 << "/" << now->tm_year + 1900;
	}

	static string print_time()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		string time = to_string(now->tm_mday) + "/" + to_string((now->tm_mon + 1)) + "/"+
			to_string((now->tm_year + 1900)) + "-" +
			to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
		return time;
		
	}

	static int read_number()
	{
		int number = 0;
		cout << "Please enter number : ";
		cin >> number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid number,please try again\n";
			cin >> number;
		}
		return number;
	}

	static int read_positive_number()
	{
		int number = 0;
		cin >> number;
		while (cin.fail() || number < 0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout <<  "Invalid number,please try again\n";
			cin >> number;
		}
		return number;
	}

	static string read_string()
	{
		string message;
		getline(cin >> ws, message);
		return message;
	}

	static int generate_random_number(int from, int to)
	{
		return rand() % (to - from + 1) + from;
	}

	static void swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	static void shuffle_array(int arr[], int length)
	{
		for (int s = 0; s < length; s++)
		{
			swap(arr[generate_random_number(0, length - 1)], arr[generate_random_number(0, length - 1)]);
		}
	}

	static void fill_array(int arr[], int length)
	{
		for (int s = 0; s < length; s++)
		{
			cout << "Please enter number " << s + 1 << " : ";
			cin >> arr[s];
		}
	}

	static void print_array(int arr[], int length)
	{
		cout << "Array elements :\n";
		for (int s = 0; s < length; s++)
		{
			cout << arr[s] << endl;
		}
	}

	static string encrypt(string message)
	{
		for (int s = 0; s < message.length(); s++)
		{
			message[s] = char(message[s] + 1);
		}
		return message;
	}

	static string decrypt(string message)
	{
		for (int s = 0; s < message.length(); s++)
		{
			message[s] = char(message[s] - 1);
		}
		return message;
	}

	static vector<string> split_string(string message,string delimiter)
	{
		int pos = 0;
		vector<string> vwords;
		while ((pos = message.find(delimiter)) != std::string::npos)
		{
			vwords.push_back(message.substr(0, pos));

			message.erase(0, pos+delimiter.length());
		}

		vwords.push_back(message);
		return vwords;
	}

	static string convert_number_to_text( int number)
	{
		string text = "";
		if (number <= 10)
		{
			if (number > 0)
			{
				text += _convertdigittotext(number);
			}
		}
		else if (number < 20)
		{
			text += _convertdigittotext(number);
		}
		else if (number < 100)
		{
			text += _convertdigittotext(number);
			convertnumbertotext(number % 10, text);
		}
		else if (number < 1000)
		{
			text += _convertdigittotext(number / 100);
			text += "hundred ";
			convertnumbertotext(number % 100, text);
		}
		else if (number < 10000)
		{
			text += _convertdigittotext(number / 1000);
			text += "thousand ";
			convertnumbertotext(number % 1000, text);
		}
		else if (number < 100000)
		{
			convertnumbertotext(number / 1000, text);
			text += "thousand ";
			convertnumbertotext(number % 1000, text);
		}
		else if (number < 1000000)
		{
			convertnumbertotext(number / 1000, text);
			text += "thousand ";
			convertnumbertotext(number % 1000, text);
		}
		else if (number < 10000000)
		{
			text += _convertdigittotext(number / 1000000);
			text += "million ";
			convertnumbertotext(number % 1000000, text);
		}
		else if (number < 100000000)
		{
			text += _convertdigittotext(number / 1000000);
			text += " million ";
			convertnumbertotext(number % 1000000, text);
		}
		else if (number < 1000000000)
		{
			convertnumbertotext(number / 1000000, text);
			text += "million ";
			convertnumbertotext(number % 1000000, text);
		}
		else
		{
			text += _convertdigittotext(number / 1000000000);
			text += "billion ";
			convertnumbertotext(number % 1000000000, text);
		}
		return text;
	}

};



