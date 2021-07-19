#include "headers.cpp"
#include "pwd_getter.cpp"
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
		cout << "Minimum Length of Password should be 8 and Use of special character(@) is Recommended For a strong Password\n";
		while(pass_set != 1){
			pass = pwd_getter();
			if(pass.size() >= 8)
				pass_set = 1;
			else
				cout << "\nMinimum Length Should Be 8. Pls Re-Enter\n";
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
