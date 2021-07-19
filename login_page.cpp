#include "headers.cpp"
using namespace std;

void login_page(string u_name, string u_pwd){
	int num = 0;
	while(num != 3){
		system("cls");
		cout << "1. Change Username\n2. Change Password\n3. Logout\nEnter: ";
		cin >> num;
		if(num == 1)
			return;
		else if(num == 2){
			string user_name;
			string user_pwd;
			fstream users("user.txt");
			users >> user_name;
			while(user_name != u_name){
				users >> user_pwd >> user_name;
			}
			users.unget();
			cout << "Enter Password: ";
			cin >> user_pwd;
			users << user_pwd << endl;
			users.close();
			system("pause");
		}
		else if(num == 3)
			return;
	}
}
