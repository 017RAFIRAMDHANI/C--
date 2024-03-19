#include <iostream>
using namespace std;
//struktur tipe ttanggal
typedef struct {
	int nohari, tanggal, bulan, tahun;
} ttanggal;

int harike(ttanggal t1) {
	int d = t1.tanggal, m = t1.bulan, y = t1.tahun;
	int LeapYears = (int)y / 4; //tahun kabisat
	long a = (y - LeapYears) * 365 + LeapYears * 366; //365 atau 365 hari
	if (m >= 2) a += 31; //bulan Peb, berarti nambah 31 hari
	if (m >= 3 && (int)y / 4 == y / 4) a += 29; //maret ada kabisat +1 hri
	else if (m >= 3) a += 28; //maret biasa
	if (m >= 4) a += 31; //april
	if (m >= 5) a += 30; //mei
	if (m >= 6) a += 31; //juni
	if (m >= 7) a += 30; //juli
	if (m >= 8) a += 31;   //agustuss
	if (m >= 9) a += 31;  //sept
	if (m >= 10) a += 30; //okt
	if (m >= 11) a += 31;  //nop
	if (m == 12) a += 30;  //des
	a += d;
	int b = (a - 2) % 7;  //0-6
	if (b > 0) {
		return (b);
	}
	else {
		return(7);
	}
}

int nomorharibesok(int harisekarang) {
	if (harisekarang == 7) {
		return (1);
	}
	else {
		return(harisekarang + 1);
	}
}

string namahari(int nomorhari) {
	string nm = "";
	switch (nomorhari) {
	case 1:
		nm = "Minggu";
		break;
	case 2:
		nm = "Senin";
		break;
	case 3:
		nm = "Selasa";
		break;
	case 4:
		nm = "Rabu";
		break;
	case 5:
		nm = "Kamis";
		break;
	case 6:
		nm = "Jum'at";
		break;
	case 7:
		nm = "Sabtu";
	}
	return(nm);
}

int nextbulan(int b1) {
	if (b1 == 12) {
		return(1);
	}
	else {
		return (b1 + 1);
	}
}

int nexttahun(int h) {
	return (h + 1);
}

bool kabisat(int th) {
	return (th % 4 == 0);
}
ttanggal besok(ttanggal t) {
	ttanggal next;
	next.nohari = nomorharibesok(t.nohari);
	if (t.bulan == 2) {
		next.tahun = t.tahun;
		switch (t.tanggal) {
		case 28:
			if (kabisat(t.tahun)) {
				next.tanggal = t.tanggal + 1;
				next.bulan = t.bulan;
			}
			else {
				next.tanggal = 1;
				next.bulan = nextbulan(t.bulan);
			}
			break;
		case 29:
			next.tanggal = 1;
			next.bulan = nextbulan(t.bulan);
			break;
		default:
			next.tanggal = t.tanggal + 1;
			next.bulan = t.bulan;
		}
	}

	else {
		if ((t.bulan == 1) || (t.bulan == 3) || (t.bulan == 5) || (t.bulan == 7) ||
			(t.bulan == 8) || (t.bulan == 10) || (t.bulan == 12)) {
			if (t.tanggal == 31) {
				next.tanggal = 1;
				next.bulan = nextbulan(t.bulan);
				next.tahun = t.tahun;
				if (next.bulan == 1) {
					next.tahun = nexttahun(t.tahun);
				}
			}
			else {
				next.tanggal = t.tanggal + 1;
				next.bulan = t.bulan;
				next.tahun = t.tahun;
			}
		}
		else {
			if ((t.bulan == 4) || (t.bulan == 6) || (t.bulan == 9) || (t.bulan == 11)) {
				next.tahun = t.tahun;
				if (t.tanggal == 30) {
					next.tanggal = 1;
					next.bulan = nextbulan(t.bulan);
				}
				else {
					next.tanggal = t.tanggal + 1;
					next.bulan = t.bulan;
				}
			}
		}
	}
	return (next);
}

ttanggal kemarin(ttanggal t) {
	ttanggal prev;
	prev.nohari = (t.nohari == 1) ? 7 : t.nohari - 1;
	if (t.bulan == 3 && t.tanggal == 1) {
		if (kabisat(t.tahun))
			prev.tanggal = 29;
		else
			prev.tanggal = 28;
		prev.bulan = 2;
		prev.tahun = t.tahun;
	}
	else if (t.tanggal == 1) {
		if (t.bulan == 1) {
			prev.tanggal = 31;
			prev.bulan = 12;
			prev.tahun = t.tahun - 1;
		}
		else if (t.bulan == 5 || t.bulan == 7 || t.bulan == 10 || t.bulan == 12) {
			prev.tanggal = 30;
			prev.bulan = t.bulan - 1;
			prev.tahun = t.tahun;
		}
		else {
			prev.tanggal = 31;
			prev.bulan = t.bulan - 1;
			prev.tahun = t.tahun;
		}
	}
	else {
		prev.tanggal = t.tanggal - 1;
		prev.bulan = t.bulan;
		prev.tahun = t.tahun;
	}
	return prev;
}

void cetak(ttanggal tgl) {
	cout << namahari(tgl.nohari) << " " << tgl.tanggal << "/" << tgl.bulan << "/" << tgl.tahun;
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	ttanggal t1, t2, t3;  //t1 saat ini, t2 besok t3 kemarin
						  //input tanggal
	cout << "Tanggal sekarang ? (dd/mm/yyyy) ";
	scanf("%d/%d/%d", &t1.tanggal, &t1.bulan, &t1.tahun);
	t1.nohari = harike(t1); //hari ke berapa ?
	t2 = besok(t1);  //besok
	t3 = kemarin(t1); //kemarin
					 //tampilkan
	cout << "sekarang ";
	cetak(t1);
	cout << endl;
	cout << "dan besok ";
	cetak(t2);
	cout << endl;
	cout << "dan kemarin ";
	cetak(t3);
	cout << endl;
	//7 haari lagi
	for (int i = 1; i < 7; i = i + 1) {
		t2 = besok(t2);
	}
	cout << "dan 7 hari lagi : ";
	cetak(t2);
	cout << endl;
	//cout<<"dan kemarin "; cetak(t3);cout<<endl;
	//tekan sembarang tombol
	system("pause");
	return 0;
}
