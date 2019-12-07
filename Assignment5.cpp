#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void encryptMe(){
	string path;
	cout << "file name :" << endl;
	cin >> path;
	string data;
	fstream temp, file;
	file.open(path);// open the file;
	if (!file)
		cout << "oops!! file not found" << endl;
	temp.open("newFile.txt");
	if (!temp)
	{
		cout << "oops!! temp disk file not found" << endl;
	}
	while (getline(file, data)) {
		int n = data.length();
		// Swap character starting from two sides 
		for (int i = 0; i < n / 2; i++)
			swap(data[i], data[n - i - 1]);
		temp << data;
	}
	file.close();
	temp.close();

	file.open(path);
	if (!file)
		cout << "oops!! file not found" << endl;
	temp.open("newFile.txt");
	if (!temp)
	{
		cout << "oops!! temp disk file not found" << endl;
	}
	while (temp.eof() == 0)
	{
		temp >> data;
		file << data;
	}
	file.close();
	temp.close();


}//End of encryptMe Function

void decryptMe(){
	string path;
	cout << "File name with path" << endl;
	cin >> path;
	string data;
	fstream temp, file;
	if (!file)
		cout << "oops!! file not found" << endl;
	temp.open("newFile.txt");
	if (!temp)
	{
		cout << "oops!! temp disk file not found" << endl;
		file.close();
	}
	while (getline(temp, data)) {
		int n = data.length();
		// Swap character starting from two sides 
		for (int i = 0; i < n / 2; i++)
			swap(data[i], data[n - i - 1]);
		file << data;
	}
	file.close();
	temp.close();


}//End of decryptMe Function
void main(){
	int choice;
	do{
		cout << "choose option" << endl;
		cout << "1-Encrypt" << endl;
		cout << "2-Decrypt" << endl;
		cout << "3-Exit" << endl;
		cin >> choice;
		switch(choice){
		case 1:encryptMe();
			break;
		case 2:decryptMe();
			break;
		}
	} while (choice != 3);
	
}


