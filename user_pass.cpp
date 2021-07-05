#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
using namespace std;

class user_pass{
private:
	string u_name;
	string u_pwd;
public:
	void set_uname(){
		cout << "Enter Username(without spaces): ";
		cin >> u_name;
	}
	void set_upwd(){
		system("cls");
		int pass_set = 0;
		int pass_len = 0;
		string pass = "";
		cout << "Minimum Length of Password should be 8 and Use of special character(@) is Recommended For a strong Password";
		cout << "\nPress Backspace to Re-Enter Password";
		cout << "\nEnter Password: ";
		while(pass_set != 1){
			char ch = getch();
			int ch_int = ch;
			if((ch_int>=64 && ch_int<=90)||(ch_int>=97 && ch_int<=122)||(ch_int>=48 && ch_int<=57)){
				putchar('*');
				pass.push_back(ch);
				pass_len += 1;
			}
			else if(ch_int == 13){
				if(pass_len >= 8){
					cout << "\nPassword Accepted\n";
					pass_set = 1;
				}
				else {
					cout << "Minimum Length Should Be 8. Pls Re-Enter\n";
					cout << "Enter Password: ";
					pass = "";
					pass_len = 0;
				}
			}
			else if(ch_int == 8){
				system("cls");
				cout << "Minimum Length of Password should be 8 and Use of special character(@) is Recommended For a strong Password";
				cout << "\nPress Backspace to Re-Enter Password";
				cout << "\nEnter Password: ";
				pass = "";
				pass_len = 0;
			}
			else{
				cout << "\nThis Character is Not Allowed. Pls Re-Enter";
				cout << "\nEnter Password: ";
				pass = "";
				pass_len = 0;
			}
		}
		u_pwd = pass;
		system("pause");
	}
	string get_uname(){
		return u_name;
	}
	string get_upwd(){
		return u_pwd;
	}
};
