 
#include <iostream>
using namespace std;
// Struktur tipe ttanggal
typedef struct {
 int nohari, tanggal, bulan, tahun;
} ttanggal;
// Fungsi menentukan hari ke dalam jumlah hari dalam satu tahun
int harike(ttanggal t1) {
 int d = t1.tanggal, m = t1.bulan, y = t1.tahun;
 int LeapYears = (int)y / 4; // Tahun kabisat
 long a = (y - LeapYears) * 365 + LeapYears * 366; // Jumlah hari dalam tahun
 if (m >= 2) a += 31; // Januari dan Februari
 if (m >= 3 && (int)y / 4 == y / 4) a += 29; // Maret dalam tahun kabisat
 else if (m >= 3) a += 28; // Maret dalam tahun biasa
 if (m >= 4) a += 31; // April
 if (m >= 5) a += 30; // Mei
 if (m >= 6) a += 31; // Juni
 if (m >= 7) a += 30; // Juli
 if (m >= 8) a += 31; // Agustus
 if (m >= 9) a += 31; // September
 if (m >= 10) a += 30; // Oktober
 if (m >= 11) a += 31; // November
 if (m == 12) a += 30; // Desember
 a += d;
 int b = (a - 2) % 7; // Hari dalam seminggu
 if (b > 0) {
 return (b);
 }
 else {
 return (7);
 }
}
// Fungsi menentukan nomor hari besok
int nomorharibesok(int harisekarang) {
 if (harisekarang == 7) {
 return (1);
 }
 else {
 return (harisekarang + 1);
 }
}
// Fungsi menentukan nama hari dari nomor hari
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
 return (nm);
}
// Fungsi menentukan bulan berikutnya
int nextbulan(int b1) {
 if (b1 == 12) {
 return(1);
 }
 else {
 return (b1 + 1);
 }
}
// Fungsi menentukan tahun berikutnya
int nexttahun(int h) {
 return (h + 1);
}
// Fungsi menentukan apakah tahun adalah tahun kabisat
bool kabisat(int th) {
 return (th % 4 == 0);
}
// Fungsi menentukan tanggal besok dari tanggal yang diberikan
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
// Fungsi menentukan bulan sebelumnya
int prevbulan(int b1) {
 if (b1 == 1) {
 return 12;
 } else {
 return b1 - 1;
 }
}
// Fungsi menentukan tahun sebelumnya
int prevtahun(int h) {
 return h - 1;
}
// Fungsi menentukan tanggal kemarin
ttanggal kemarin(ttanggal t) {
 ttanggal prev;
 prev.nohari = (t.nohari == 1) ? 7 : t.nohari - 1; // Jika hari ini Minggu (nomor 1), maka kemarin 
//adalah Sabtu (nomor 7), jika tidak, kurangi 1
 if (t.tanggal == 1) {
 prev.bulan = prevbulan(t.bulan);
 prev.tahun = (t.bulan == 1) ? prevtahun(t.tahun) : t.tahun;
 switch (prev.bulan) {
 case 2:
 if (kabisat(prev.tahun)) {
 prev.tanggal = 29;
 } else {
 prev.tanggal = 28;
 }
 break;
 case 1:
 case 3:
 case 5:
 case 7:
 case 8:
 case 10:
 case 12:
 prev.tanggal = 31;
 break;
 default:
 prev.tanggal = 30;
 }
 } else {
 prev.tanggal = t.tanggal - 1;
 prev.bulan = t.bulan;
 prev.tahun = t.tahun;
 }
 return prev;
}
// Fungsi untuk mencetak tanggal
void cetak(ttanggal tgl) {
 cout << namahari(tgl.nohari) << " " << tgl.tanggal << "/" << tgl.bulan << "/" << tgl.tahun;
}
int main(int argc, char** argv) {
 ttanggal t1, t2, t3, t4, t5; // t1 saat ini, t2 besok, t3 kemarin, t4 tahun lalu, t5 bulan lalu
 // Input tanggal
 cout << "Tanggal sekarang ? (dd/mm/yyyy) ";
 scanf("%d/%d/%d", &t1.tanggal, &t1.bulan, &t1.tahun);
 t1.nohari = harike(t1); // Hari ke berapa ?
 t2 = besok(t1); // Besok
 t3 = kemarin(t1); // Kemarin
 
 // Tampilkan
 cout << "sekarang: ";
 cetak(t1);
 cout << endl;
 cout << "dan besok: ";
 cetak(t2);
 cout << endl;
 cout << "dan kemarin: ";
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