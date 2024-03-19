#include <iostream>
#include <string>

using namespace std;

int besok(int tanggalsekarang){
	if(tanggalsekarang >= 1 && tanggalsekarang <= 30) {
		
		tanggalsekarang +=1;
	}else if(tanggalsekarang  == 31){
			tanggalsekarang = 1;
	} 
	
	return tanggalsekarang;
}
 
int main(){
    int tanggalsekarang,tanggalbesok,harikemarin;
    
    cout << "Tanggal hari ini ? ";
    cin >> tanggalsekarang;
   
    tanggalbesok = besok(tanggalsekarang);
    
    if (tanggalbesok >= 32){
    cout << "tanggal yg anda inputkan tidak ada dalam calendar" ;
    	
	}else{
    cout << "maka tanggal esok "<< tanggalbesok << endl;
		
	}
    
}