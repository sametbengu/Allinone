#include<iostream>
#include <string>

using namespace std;

class Student
{
public:
	void setStudent(string _name, int _id)
	{
		name = _name;
		id = _id;
	}


	void submitGrade(int grade) {
		if (gradeCounter != 20) {
			gradeCounter++;
			grades[gradeCounter - 1] = grade;
		}
	}

	float calculateGrade() {
		float sum = 0;
		for (int i = 0; i < gradeCounter; i++) {
			sum += grades[i];
		}
		return sum / gradeCounter;
	}

	void printGrades() {
		cout << name << "'nin notlari : ";
		for (int i = 0; i < gradeCounter; i++) {
			cout << grades[i];
			if (i != gradeCounter - 1) {
				cout << " , ";
			}
		}
	}



	void print()
	{

		cout << "Isim : " << name << endl;
		cout << "Ogrenci Numarasi   : " << id << endl;
		cout << "Not Ortalamasi   : " << calculateGrade() << endl;

	}


private:
	string name;
	int id;
	int grades[20];
	int gradeCounter = 0;
};

class Clock
{
public:
	void getTime(int& hours, int& minutes, int& seconds) const {
		hours = hr;
		minutes = min;
		seconds = sec;
	}

	Clock(long miliseconds) {
		hr = miliseconds / 1000 / 3600;
		min = miliseconds / 1000 / 60;
		sec = miliseconds / 1000 / 1;
	}

	Clock(int hours = 0, int minutes = 0, int seconds = 0) {
		setTime(hours, minutes, seconds);
	}

	void setTime(int hours, int minutes, int seconds)
	{
		if (0 <= hours && hours < 24)
			hr = hours;
		else
			hr = 0;

		if (0 <= minutes && minutes < 60)
			min = minutes;
		else
			min = 0;

		if (0 <= seconds && seconds < 60)
			sec = seconds;
		else
			sec = 0;
	}

	void incrementHours()
	{
		hr++;
		if (hr > 23)
			hr = 0;
	}

	void incrementMinutes()
	{
		min++;
		if (min > 59) {
			min = 0;
			incrementHours();
		}
	}

	void incrementSeconds()
	{
		sec++;
		if (sec > 59) {
			sec = 0;
			incrementMinutes();
		}
	}


	void printTime()
	{
		if (hr < 10)
			cout << "0";
		cout << hr << ":";
		if (min < 10)
			cout << "0";
		cout << min << ":";
		if (sec < 10)
			cout << "0";
		cout << sec << endl;
	}
	bool isEqual(Clock a) {
		if (a.hr == hr && a.sec == sec && a.min == min)
			return true;
		else
			return false;
	}
	void  incrementSeconds(int sec1)
	{
		sec = sec + sec1;
		if (sec > 59) {
			sec = 0;
			incrementMinutes(); 
		}
	}


private:
	int hr;
	int min;
	int sec;
};


void Clocktest();
void StudentTest();
void checkEqual(Clock, Clock);

int main() {
	Clocktest();
	StudentTest();
	return 0;
}


void Clocktest(){
	cout << "------------Clock sinifi test fonksiyonu-----------"<<endl;
	int h, m, s;
	Clock saat1(0,0,0);
	Clock saat2(0,0,0);
	for (int i = 0; i < 2; i++) {
		cout << "Saat " << i + 1 << " icin saat giriniz : ";
		cin >> h;
		cout << "Saat " << i + 1 << " icin dakika giriniz : ";
		cin >> m;
		cout << "Saat " << i + 1 << " icin saniye giriniz : ";
		cin >> s;
		if (i == 0) saat1.setTime(h, m, s);
		else saat2.setTime(h, m, s);
	}
	

	cout <<endl<< "--Arttirma isleminden once--" << endl;

	cout << "Saat 1 : ";
	saat1.printTime();
	cout << "Saat 2 : ";
	saat2.printTime();
	checkEqual(saat1, saat2);
	cout << endl;


	saat1.incrementHours();
	saat1.incrementMinutes();
	saat1.incrementSeconds();

	cout << "--Arttirma isleminden sonra--" << endl;

	cout << "Saat 1 : ";
	saat1.printTime();
	cout << "Saat 2 : ";
	saat2.printTime();
	checkEqual(saat1, saat2);
	cout << endl;


	cout << "--Saat 1'i 30 saniye arttirdiktan sonra--" << endl;
	saat1.incrementSeconds(30);
	cout << "Saat 1 : ";
	saat1.printTime();
	cout << endl;

}


void StudentTest() {
	string name;
	int id,n,grade;
	cout << "------------Student sinifi test fonskiyonu---------------"<<endl;
	cout << "Ogrenci adi giriniz : ";
	cin >> name;
	cout << "Ogrenci numarasi giriniz : ";
	cin >> id;
	Student student;
	student.setStudent(name, id);
	cout << "Kac adet not girmek istersiniz? : ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << ". not : ";
		cin >> grade;
		student.submitGrade(grade);
	}
	student.print();
	student.printGrades();
	cout << endl;
}
void checkEqual(Clock a, Clock b) {
	if (a.isEqual(b)) {
		cout << "Iki saat birbirine esit!" << endl;
	}
	else
		cout << "Saatler birbirine esit degil!" << endl;
}

