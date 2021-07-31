/***************************************************************************
This file contains the pwd_getter() function which makes the password hidden.
No one is able to see the password and only user knows what he entered.
It takes characters as input without echoing them and printing '*' instead.
Only a-z, A-Z, 0-9 and '@' will be taken as input.
No other special character allowed.
***************************************************************************/

#include "headers.cpp"
using namespace std;

string pwd_getter(){
	int pass_set = 0;
	string pass = "";
	cout << "Enter Password: ";
	while(pass_set != 1){
		char ch = getch();
		int ch_int = ch;
		if((ch_int>=64 && ch_int<=90)||(ch_int>=97 && ch_int<=122)||(ch_int>=48 && ch_int<=57)){
			putchar('*');
			pass.push_back(ch);
		}
		else if(ch_int == 13){
			pass_set = 1;
			cout << endl;
		}
		else if(ch_int == 8)
			if(pass.size() > 0){
				CONSOLE_SCREEN_BUFFER_INFO cinfoc;
				GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &cinfoc);
				COORD c = {cinfoc.dwCursorPosition.X -1, cinfoc.dwCursorPosition.Y};  
  				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
				putchar(' ');
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
				pass.pop_back();
			}
	}
	return pass;
}
