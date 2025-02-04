#include "login_screen.h"

int main()
{
	bool repeat = 1;
	while(repeat)
	{
		repeat=clslogin_screen::login();
	}
	system("pause>0");
}