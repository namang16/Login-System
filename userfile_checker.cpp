#include "headers.cpp"

void file_exist(){
	ifstream users("user.txt");
	if(users)
		users.close();
	else{
		users.close();
		ofstream create_file("user.txt");
		create_file << "FILE" << " " << "CREATED" << endl;
		create_file.close();
	}
	return;
}
