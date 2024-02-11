#include <iostream>
#include <cmath>

using namespace std;
int main(){
	
    string car[] = {
       "Carera",
       "Mustang",
       "Camry",
	   };
	   
	 

    int size = sizeof(car); // Calculate the size of the array

    for(int i = 0; i < size; i++) {
        cout << car[i] << endl; // Print all elements of the array
    }

	return 0;
}