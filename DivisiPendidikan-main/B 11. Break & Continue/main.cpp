#include <iostream>
#include <cmath>

using namespace std;
int main(){
	
    int age = 1;
    
    for(age; age < 20; age++){
    	if(age == 13){
    	//	break;
    		continue;
		}
    	 cout << age << "\n";
	}
	return 0;
}