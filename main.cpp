#include "headers.cpp"
#include "user_pass.cpp"
#include "login_page.cpp"
using namespace std;

void start(){
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
			user_passE = pwd_getter();
			ifstream users("user.txt");
			string user_name, user_pwd;
			while(found == 0 && !users.eof()){
				users >> user_name >> user_pwd;
				if(user_name == user_nameE){
					if(user_pwd == user_passE){
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
				cout << "User Not Found";
			else if(found == 1)
				login_page(user_name, user_pwd);
			system("pause");
		}
		system("cls");
		if(num == 3)
			cout << "\nThanks\n";
	}
}

int main(){
	start();
	return 0;
}
