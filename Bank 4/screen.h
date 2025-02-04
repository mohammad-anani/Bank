#pragma once
#include <iostream>
#include <iomanip>
#include "utility.h"
#include "currentu.h"
#include "user.h"
using namespace std;

class clsscreen
{
protected:
	static void draw_header_screen(string title,string subtitle="")
	{
		cout << "\t\t\t\t\t" << "--------------------------------------" << endl << endl;
		cout << "\t\t\t\t\t" << "          " << title << endl;
		cout << "\t\t\t\t\t" << "          " << subtitle << endl;
		cout << endl;
		cout << "\t\t\t\t\t" << "--------------------------------------" << endl;
		cout << "\t\t\t\t\t"; clsutility::print_date();
		cout << endl;
		cout << "\t\t\t\t\t" << "user:" << currentuser.username << endl << endl;
	}
};

