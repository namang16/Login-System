/*********************************************************************
This file contains function to check
if there is a file named user.txt already present or not.
If not, then create a user.txt file which will be used for the project
*********************************************************************/

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
