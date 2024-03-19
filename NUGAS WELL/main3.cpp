#include <iostream>

using namespace std;

bool isLeapYear(int year) {
	
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
string getDayOfWeek(int year, int month, int day) {
    int q = day;
    int m = month;
    if (m == 1 || m == 2) {
        m += 12;
        year--;
    }
    int K = year % 100;
 
    int J = year / 100;
  
    int h = (q + ((13*(m+1))/5) + K + (K/4) + (J/4) + (5*J)) % 7;
   
    
    string days[] = {"Sabtu", "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
    return days[h];
}

int nextDay(int &year, int &month, int &day) {
    if (month == 2) {
        if ((day == 29 && isLeapYear(year)) || day == 28) {
            day = 1;
            month = 3;
        } else {
            day++;
        }
    } else {
        if ((day == 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)) ||
            (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day == 31 && month == 12)) {
            day = 1;
            if (month == 12) {
                month = 1;
                year++;
            } else {
                month++;
            }
        } else {
            day++;
        }
    }
    return 0;
}

int previousDay(int &year, int &month, int &day) {
    if (day == 1) {
        if (month == 3 && isLeapYear(year)) {
            day = 29;
            month = 2;
        } else if (month == 3 && !isLeapYear(year)) {
            day = 28;
            month = 2;
        } else if (month == 1) {
            day = 31;
            month = 12;
            year--;
        } else if ((month == 5 || month == 7 || month == 10 || month == 12)) {
            day = 30;
            month--;
        } else {
            day = 31;
            month--;
        }
    } else {
        day--;
    }
    return 0;
}

int main() {
    int year, month, day;

    cout << "Masukkan tahun: ";
    cin >> year;
    cout << "Masukkan bulan: ";
    cin >> month;
    cout << "Masukkan tanggal: ";
    cin >> day;

    // Menentukan hari pada tanggal yang diinputkan
    string dayOfWeek = getDayOfWeek(year, month, day);
  
    // Mencetak tanggal hari ini beserta hari
    cout << "Hari ini: " << year << "/" << month << "/" << day << ", Hari: " << dayOfWeek << endl;

    // Mencetak tanggal besok
    nextDay(year, month, day);
    dayOfWeek = getDayOfWeek(year, month, day);
    cout << "Besok: " << year << "/" << month << "/" << day << ", Hari: " << dayOfWeek << endl;

    // Mengembalikan tanggal ke hari ini
    previousDay(year, month, day);

    // Mencetak tanggal kemarin
    previousDay(year, month, day);
    dayOfWeek = getDayOfWeek(year, month, day);
    cout << "Kemarin: " << year << "/" << month << "/" << day << ", Hari: " << dayOfWeek << endl;
   // cout << isLeapYear(year);
    return 0;
}
