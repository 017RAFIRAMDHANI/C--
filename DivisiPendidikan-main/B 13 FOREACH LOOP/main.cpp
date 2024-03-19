#include <iostream>
#include <string>

using namespace std;
int main(){
	
    string students[] ={
	    "Rafi",
	    "M Rizki",
	    "M Febri"
	};
	
	for(string item : students){
		cout << item << endl;
	}

	return 0;
}