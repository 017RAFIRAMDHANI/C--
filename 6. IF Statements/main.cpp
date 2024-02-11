#include <iostream>
#include <cmath>

using namespace std;
int main(){
	
    int age;
    
    cout << "What is your age ? ";
    cin >> age;
    
    if(age < 18){
    	cout << "Cukup";
	}else if(age <50){
    	cout << "Lumayan";
		
	}else{
		if(age < 150){
    	cout << "Bagus";
			
		}else{
    	cout << "Sangat Bagus";
			
		}
	}
	return 0;
}