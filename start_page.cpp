#include "headers.cpp"
#include "login_page.cpp"
using namespace std;
string set_uname();
string set_upwd();

void start(){
	int num = 0;
	while(num != 3){
		cout << "1. New User?\n2. Login\n3. Exit\nEnter: ";
		cin >> num;
		system("cls");
		if(num == 1){
			ofstream users("user.txt", ios::app);
			string user_name = set_uname();
			string user_pwd = set_upwd();
			system("cls");
			users << user_name << " " << user_pwd << endl;
			cout << "Registration Done.";
			users.close();
		}
		else if(num == 2){
			string Iuser_name, Iuser_pass;
			int found = 0;
			cout << "Enter Username: ";
			cin >> Iuser_name;
			Iuser_pass = pwd_getter();
			ifstream users("user.txt");
			string user_name, user_pwd;
			while(found == 0 && !users.eof()){
				users >> user_name >> user_pwd;
				if(user_name == Iuser_name){
					if(user_pwd == Iuser_pass){
						cout << "Login Successful\n";
						found = 1;
						system("pause");
					}
					else{
						cout << "Wrong Password. Login Failed\n";
						found = 2;
					}
				}
			}
			users.close();
			if(found == 0)
				cout << "User Not Found\n";
			else if(found == 1)
				login_page(user_name, user_pwd);
			system("pause");
		}
		system("cls");
		if(num == 3)
			cout << "\nThanks\n";
	}
}

string set_uname(){
	string u_name;
	cout << "Enter Username(without spaces): ";
	cin >> u_name;
	return u_name;
}
	
string set_upwd(){
	string u_pwd;
	system("cls");
	int pass_set = 0;
	string pass = "";
	cout << "Minimum Length of Password should be 8 and Use of special character(@) is Recommended For a strong Password\n";
	while(pass_set != 1){
		pass = pwd_getter();
		if(pass.size() >= 8)
			pass_set = 1;
		else
			cout << "Minimum Length Should Be 8. Pls Re-Enter\n";
	}
	u_pwd = pass;
	cout << "Password Accepted\n";
	system("pause");
	return u_pwd;
}
