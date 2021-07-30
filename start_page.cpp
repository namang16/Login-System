#include "headers.cpp"
#include "login_page.cpp"
#include "userfile_checker.cpp"
using namespace std;
string set_uname();
string set_upwd();

void start(){
	file_exist();
	int num = 0;
	while(num != 3){
		system("cls");
		cout << "1. New User?\n2. Login\n3. Exit\nEnter: ";
		cin >> num;
		if(num == 1){
			system("cls");
			string user_name = set_uname();
			if(user_name != "U_N_exist" && user_name != "U_N_NAllowed"){
				string user_pwd = set_upwd();
				cout << "Please Re-Enter your password for Confirmation\n";
				string user_pwd_re = pwd_getter();
				if(user_pwd == user_pwd_re){
					system("cls");
					ofstream users("user.txt", ios::app);
					users << user_name << " " << user_pwd << endl;
					users.close();
					cout << "Registration Done. You may login now\n";
				}
				else
					cout << "\nYour passwords dont match\n";
			}
		}
		else if(num == 2){
			system("cls");
			string Iuser_name, Iuser_pass;
			int found = 0;
			cout << "Enter Username: ";
			cin.ignore();
			getline(cin, Iuser_name);
			Iuser_pass = pwd_getter();
			if(Iuser_name.find(' ') != string::npos || (Iuser_name[0] - '0' >= 0 && Iuser_name[0] - '0' <= 9))
				found = 3;
			else{
				int i=0;
				while(i < Iuser_name.size()){
					if(isupper(Iuser_name[i]))
						Iuser_name[i] = tolower(Iuser_name[i]);
					i++;
				}
			}
			ifstream users("user.txt");
			string user_name, user_pwd;
			users >> user_name >> user_pwd;
			while(found == 0 && !users.eof()){
				if(user_name == Iuser_name){
					if(user_pwd == Iuser_pass)
						found = 1;
					else
						found = 2;
				}
				users >> user_name >> user_pwd;
			}
			users.close();
			if(found == 0)
				cout << "\nUser Not Found\n";
			else if(found == 1){
				cout << "\nLogin Successful\n";
				system("pause");
				login_page(Iuser_name, Iuser_pass);
			}
			else if(found == 2)
				cout << "\nWrong Password. Login Failed\n";
			else if(found == 3)
				cout << "\nUsername not valid\n";
		}
		else if(num == 3){
			system("cls");
			cout << "Thanks\n\n";
		}
		else
			cout << "\nWrong Choice\n";
		system("pause");
	}
}

string set_uname(){
	string u_name;
	cout << "Username can be 4-10 characters long and cannot start with a digit\n";
	cout << "Enter Username(without spaces): ";
	cin.ignore();
	getline(cin, u_name);
	if(u_name.find(' ') != string::npos){
		cout << "\nUsername not valid\n";
		return "U_N_NAllowed";
	}
	if(u_name.size() < 4 || u_name.size() > 10){
		cout << "\nUsername should be 4-10 characters long\n";
		return "U_N_NAllowed";
	}
	if(u_name[0] - '0' >= 0 && u_name[0] - '0' <= 9){
		cout << "\nUsername cannot start with a digit\n";
		return "U_N_NAllowed";
	}
	int i=0;
	while(i < u_name.size()){
		if(isupper(u_name[i]))
			u_name[i] = tolower(u_name[i]);
		i++;
	}
	ifstream users("user.txt");
	string user_nameFFile, user_pwdFFile;
	users >> user_nameFFile >> user_pwdFFile;
	while(!users.eof()){
		if(user_nameFFile == u_name){
			cout << "\nThis Username already exists!\n";
			users.close();
			return "U_N_exist";	
		}
		users >> user_nameFFile >> user_pwdFFile;
	}
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
	return u_pwd;
}
