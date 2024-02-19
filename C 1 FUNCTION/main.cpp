#include <iostream>
#include <string>

using namespace std;

string happyBirthDay(string name){
	cout << "Hallo " << name << endl;
	cout << "Apa kabarmu  " << name << endl;
	cout << "Semoga sehat selalu  " << name << endl;
	
	return name;
}

int main(){
	
    string name = "Rafi Ramdhani";
	
	happyBirthDay(name);
	return 0;
}