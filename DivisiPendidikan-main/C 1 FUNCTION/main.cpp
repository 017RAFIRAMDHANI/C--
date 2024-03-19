#include <iostream>
#include <string>

using namespace std;

string happyBirthDay(string name){
	cout << "Hallo " << name << endl;
	cout << "Apa kabarmu  " << name << endl;
	cout << "Semoga sehat selalu  " << name << endl;
	
	return name;
}

int hitungan(int hitung){
	int jml;
	jml = hitung * 2;
	
	return jml;
}
int main(){
	
    string name = "Rafi Ramdhani";
    int hitung,hasil;
    
    cout << "Masukan angka ";
    cin >> hitung;
	
	happyBirthDay(name);
	hasil = hitungan(hitung);
	cout << hasil;
}