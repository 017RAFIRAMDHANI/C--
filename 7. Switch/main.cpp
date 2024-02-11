#include <iostream>
#include <cmath>

using namespace std;
int main(){
	
    int month;
    
    cout << "Enter Month ? ";
    cin >> month;
    
    switch(month){
    	case 1:
    	 cout << "Cukup";
	     break;
    	case 2:
    	 cout << "Lumayan";
	     break;
    	default:
    	 cout << "Bagus";
	     break;
	}
	return 0;
}