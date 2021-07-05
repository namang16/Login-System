#include<iostream>
#include<conio.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include "user_pass.cpp"
using namespace std;

int main(){
	int num = 0;
	while(num != 3){
		cout << "1. New User?\n2. Login\n3. Exit\nEnter: ";
		cin >> num;
		system("cls");
		if(num == 1){
			ofstream users("user.txt", ios::app);
			user_pass t1;
			t1.set_uname();
			t1.set_upwd();
			system("cls");
			users << t1.get_uname() << " " << t1.get_upwd() << endl;
			cout << "Registration Done.";
			users.close();
		}
		else if(num == 2){
			string user_nameE, user_passE;
			int found = 0;
			cout << "Enter Username: ";
			cin >> user_nameE;
			cout << "Enter Password: ";
			cin >> user_passE;
			ifstream users("user.txt");
			string user_name, user_pwd;
			while(found == 0 && !users.eof()){
				users >> user_name >> user_pwd;
				if(user_name == user_nameE){
					if(user_pwd == user_passE){
						cout << "Login Successful\n";
						found = 1;
					}
					else{
						cout << "Wrong Password. Login Failed";
						found = 2;
					}
				}
			}
			if(found == 0){
				cout << "User Not Found";
			}
			system("pause");
			users.close();
		}
		system("cls");
		if(num == 3)
			cout << "\nThanks\n";
	}
	
	return 0;
}
