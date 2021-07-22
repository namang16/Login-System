#include "headers.cpp"
#include "pwd_getter.cpp"
using namespace std;
void change_uname(string);
void change_pass(string, string);

void login_page(string Iuser_name, string Iuser_pwd){
	int num = 0;
	while(num != 3){
		system("cls");
		cout << "1. Change Username\n2. Change Password\n3. Logout\nEnter: ";
		cin >> num;
		if(num == 1)
			change_uname(Iuser_name);
		else if(num == 2)
			change_pass(Iuser_name, Iuser_pwd);
		else if(num == 3)
			cout << "\nLog Out Successful\n";
		else
			cout << "\nWrong Choice\n";
	}
	return;
}

void change_uname(string user_name){
	system("cls");
	string new_uname, user_pwd;
	cout << "Username can be 4-10 characters long and cannot start with a digit\n";
	cout << "Enter New Username(without spaces): ";
	cin >> new_uname;
	if(new_uname.size() < 4 || new_uname.size() > 10){
		cout << "\nUsername should be 4-10 characters long\n";
		system("pause");
		return;
	}
	if(new_uname[0] - '0' >= 0 && new_uname[0] - '0' <= 9){
		cout << "\nUsername cannot start with digits\n";
		system("pause");
		return;
	}
	int i=0;
	while(i < new_uname.size()){
		if(isupper(new_uname[i]))
			new_uname[i] = tolower(new_uname[i]);
		i++;
	}
	ifstream users("user.txt");
	ofstream temp("temp.txt");
	string user_nameFFile, user_pwdFFile;
	users >> user_nameFFile >> user_pwdFFile;
	while(!users.eof()){
		if(user_nameFFile == user_name){
			temp << new_uname << " " << user_pwdFFile << endl;
		}
		else if(user_nameFFile == new_uname){
			cout << "\nThis Username already exists!\n";
			temp.close();
			users.close();
			remove("temp.txt");
			system("pause");
			return;
		}
		else
			temp << user_nameFFile << " " << user_pwdFFile << endl;
		users >> user_nameFFile >> user_pwdFFile;
	}
	users.close();
	temp.close();
	remove("user.txt");
	rename("temp.txt", "user.txt");
	cout << "\nUsername Changed Successfully\n";
	system("pause");
	return;
}

void change_pass(string user_name, string user_pwd){
	system("cls");
	string current_pass;
	string new_pass, new_pass_re;
	cout << "Please Enter Your Current Password:\n";
	current_pass = pwd_getter();
	cout << "Please Enter Your New Password:\n";
	new_pass = pwd_getter();
	cout << "Please Re-Enter Your New password:\n";
	new_pass_re = pwd_getter();
	if(current_pass != user_pwd){
		cout << "\nYour Current Password is Incorrect!!\n";
		system("pause");
	}
	else if(new_pass != new_pass_re){
		cout << "\nYour Passwords don\'t match\n";
		system("pause");
	}
	else{
		ifstream users("user.txt");
		ofstream temp("temp.txt");
		string user_nameFFile, user_pwdFFile;
		users >> user_nameFFile >> user_pwdFFile;
		while(!users.eof()){
			if(user_nameFFile == user_name)
				temp << user_name << " " << new_pass << endl;
			else
				temp << user_nameFFile << " " << user_pwdFFile << endl;
			users >> user_nameFFile >> user_pwdFFile;
		}
		users.close();
		temp.close();
		remove("user.txt");
		rename("temp.txt", "user.txt");
		cout << "\nPassword Changed Successfully\n";
		system("pause");
	}
	return;
}










