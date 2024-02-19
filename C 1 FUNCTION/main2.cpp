#include <iostream>
#include <string>

using namespace std;

string besok(string hariini){
	if(hariini == "senin") {
		hariini = "selasa";
	}
	else if(hariini == "selasa"){
		hariini = "rabu";
	}
	else if(hariini == "rabu"){
		hariini = "kamis";
	}
	else if(hariini == "kamis"){
		hariini = "jumat";
	}
	else if(hariini == "jumat"){
		hariini = "sabtu";
	}
	else if(hariini == "sabtu"){
		hariini = "minggu";
	}
	else if(hariini == "minggu"){
		hariini = "senin";
	}
	
	return hariini;
}

string kemarin(string hariini){
	if(hariini == "senin") {
		hariini = "minggu";
	}
	else if(hariini == "selasa"){
		hariini = "senin";
	}
	else if(hariini == "rabu"){
		hariini = "selasa";
	}
	else if(hariini == "kamis"){
		hariini = "rabu";
	}
	else if(hariini == "jumat"){
		hariini = "kamis";
	}
	else if(hariini == "sabtu"){
		hariini = "jumat";
	}
	else if(hariini == "minggu"){
		hariini = "sabtu";
	}
	
	return hariini;
}

int main(){
    string hariini,haribesok,harikemarin;
    
    cout << "Hari ini ? ";
    cin >> hariini;
   
    haribesok = besok(hariini);
    harikemarin = kemarin(hariini);
    cout << "maka hari esok "<< haribesok << endl;
    cout << "dan hari kemarin " << harikemarin << endl;
}