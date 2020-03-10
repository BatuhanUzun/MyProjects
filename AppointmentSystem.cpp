#include<iostream>
#include<string>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Person {
protected:
	string name;
	string surname;
	string department;
	string email;
	string phoneNumber;
public:
	void setName(string name);
	void setSurname(string surname);
	void setDepartment(string department);
	void setEmail(string email);
	void setPhoneNumber(string phoneNumber);
	string getName();
	string getSurname();
	string getDepartment();
	string getEmail();
	string getPhoneNumber();
}*ptrPer;
class Academician : public Person {
private:
	string registrationNumber;
	string title;
public:
	void setRegistrationNumber(string registrationNumber);
	void setTitle(string title);
	string getRegistrationNumber();
	string getTitle();

	void editAcademician(string file1, string file2, string file3);		//AKADEMISYEN DUZENLEYEN FONKSIYON
	void addAcademician(string file1, string file2, string file3);		//AKADEMISYEN EKLEYEN FONKSIYON
	void removeAcademician(string file1, string file2, string file3);	//AKADEMISYEN SILEN FONKSIYON
	void viewInformation();												//AKADEMISYEN BILGILERINI GOSTEREN FONKSIYON
	void saveFile(fstream& file);										//BILGILERI DOSYAYA YAZAN FONKSIYON
	Academician search(string number);									//ILGILI AKADEMISYENI BULAN FONKSIYON
}*ptrAca;
class Student :public Person {
private:
	string number;
	string registrationYear;
public:
	void setNumber(string number);
	void setRegistrationYear(string registrationYear);
	string getNumber();
	string getRegistrationYear();

	void addStudent(string file1, string file2, string file3);		//OGRENCI EKLEYEN FONKSIYON
	void editStudent(string file1, string file2, string file3);		//OGRENCI DUZENLEYEN FONKSIYON
	void removeStudent(string file1, string file2, string file3);	//OGRENCI SILEN FONKSIYON
	void viewInformation();											//OGRENCI BILGILERINI GOSTEREN FONKSIYON
	void saveFile(fstream& file);									//BILGILERI DOSYAYA YAZAN FONKSIYON
	Student search(string number);									//ILGILI OGRENCIYI BULAN FONKSIYON
}*ptrStu;
class Appointments {
private:
	Academician academician;
	Student student;
	string date;
	string startHour;
	string finishHour;
public:
	Appointments();
	void setAcademican(Academician academician);
	void setStudent(Student student);
	void setDate(string date);
	void setStartHour(string startHour);
	void setFinishHour(string finishHour);
	Academician getAcademician();
	Student		getStudent();
	string		getDate();
	string		getStartHour();
	string		getFinishHour();

	void saveFile(fstream& file);															//BILGILERI DOSYAYA YAZAN FONKSIYON
	int  viewAppointments(string number, string acaNumber, string date, string strtHour);	//RANDEVU BILGILERINI GOSTEREN FONKSIYON
	void addAppointment(string file1, string file2, string file3);							//RANDEVU EKLEYEN FONKSIYON
	void editAppointment(string file1, string file2, string file3);							//RANDEVU DUZENLEYEN FONKSIYON
	void removeAppointment(string file1, string file2, string file3);						//RANDEVU SILEN FONKSIYON
}*ptrApp;

void updateToSystem(string file1, string file2, string file3);			//SISTEMI GUNCEL TUTAN FONKSIYON.
int viewProfil(string number, string acaNumber);						//ISTENILEN KISININ PROFILINI GOSTEREN FONKSIYON.
string appointmentsHour(string t);										//RANDEVU BITIS SAATINI AYARLAYAN FONKSIYON.
string operator+ (const string& lhs, const string& rhs);				//'+' OPERATORU ICIN OVERLOADED FONKSIYONU (STR TOPLAMA).
int areThereCollision(string number, string date, string hour);			//CAKISMALARI KONTROL EDEN FONKSIYON.

//GETTER VE SETTER FONKSIYONLARI
Appointments::Appointments()												{ std::cout << "Constructor Uretildi....\n\n"; }
void		Appointments::setAcademican(Academician academician)			{ this->academician = academician;					}
void		Appointments::setStudent(Student student)						{ this->student = student;							}
void		Appointments::setDate(string date)								{ this->date = date;								}
void		Appointments::setStartHour(string startHour)					{ this->startHour = startHour;						}
void		Appointments::setFinishHour(string finishHour)					{ this->finishHour = finishHour;					}
Academician Appointments::getAcademician()									{ return academician;								}
Student		Appointments::getStudent()										{ return student;									}
string		Appointments::getDate()											{ return date;										}
string		Appointments::getStartHour()									{ return startHour;									}
string		Appointments::getFinishHour()									{ return finishHour;								}
void		Person::setName(string name)									{ this->name = name;								}
void		Person::setSurname(string surname)								{ this->surname = surname;							}
void		Person::setDepartment(string department)						{ this->department = department;					}
void		Person::setEmail(string email)									{ this->email = email;								}
void		Person::setPhoneNumber(string phoneNumber)						{ this->phoneNumber = phoneNumber;					}
string		Person::getName()												{ return name;										}
string		Person::getSurname()											{ return surname;									}
string		Person::getDepartment()											{ return department;								}
string		Person::getEmail()												{ return email;										}
string		Person::getPhoneNumber()										{ return phoneNumber;								}
void		Academician::setRegistrationNumber(string registrationNumber)	{ this->registrationNumber = registrationNumber;	}
void		Academician::setTitle(string title)								{ this->title = title;								}
string		Academician::getRegistrationNumber()							{ return registrationNumber;						}
string		Academician::getTitle()											{ return title;										}
void		Student::setNumber(string number)								{ this->number = number;							}
void		Student::setRegistrationYear(string registrationYear)			{ this->registrationYear = registrationYear;		}
string		Student::getNumber()											{ return number;									}
string		Student::getRegistrationYear()									{ return registrationYear;							}

Student Student::search(string number) {
	size_t i;
	for (i = 0; ptrStu[i].getNumber() != ""; i++)
	{
		if (ptrStu[i].getNumber() == number)
			return ptrStu[i];
	}
	cout << "NOT FOUND" << endl;
	return ptrStu[i];
}
Academician Academician::search(string number) {
	size_t i;
	for (i = 0; ptrAca[i].getRegistrationNumber() != ""; i++)
	{
		if (ptrAca[i].getRegistrationNumber() == number)
			return ptrAca[i];
	}
	cout << "NOT FOUND";
	return ptrAca[i];
}

void updateToSystem(string file1, string file2, string file3) {

	string character;
	char ch;
	int lineNumber = 1;
	fstream appFile, acaFile, stuFile;

	acaFile.open(file2, ios::in);
	lineNumber = 1;
	if (acaFile.is_open())
	{
		while (acaFile >> character)
		{
			acaFile.get(ch);
			if (ch == '\n') lineNumber++;
		}
	}
	ptrAca = new Academician[lineNumber + 1]();
	ptrAca->saveFile(acaFile);
	acaFile.close();

	stuFile.open(file1, ios::in);
	lineNumber = 1;
	if (stuFile.is_open())
	{
		while (stuFile >> character)
		{
			stuFile.get(ch);
			if (ch == '\n') lineNumber++;
		}
	}
	ptrStu = new Student[lineNumber + 1]();
	ptrStu->saveFile(stuFile);
	stuFile.close();

	appFile.open(file3, ios::in);
	lineNumber = 1;
	if (appFile.is_open())
	{
		while (appFile >> character)
		{
			appFile.get(ch);
			if (ch == '\n') lineNumber++;
		}
	}
	ptrApp = new Appointments[lineNumber + 1]();
	ptrApp->saveFile(appFile);
	appFile.close();
}
int viewProfil(string number, string acaNumber = "")
{
	for (size_t i = 0; ptrApp[i].getStudent().getNumber() != ""; i++)
	{
		if (ptrApp[i].getStudent().getNumber() == number && ptrApp[i].getAcademician().getRegistrationNumber() == acaNumber)
		{
			cout << "\n\nRandevu ; \n"
				<< "Ogrenci No : "			<< ptrApp[i].getAcademician().getRegistrationNumber()
				<< "\nAkademisyen No: "		<< ptrApp[i].getStudent().getNumber()
				<< "\nTarih : "				<< ptrApp[i].getDate()
				<< "\nBaslangic Saati : "	<< ptrApp[i].getStartHour()
				<< "\nBitis Saati : "		<< ptrApp[i].getFinishHour()
				<< "\n\n";
		}
	}
	for (size_t i = 0; ptrStu[i].getName() != ""; i++)
	{
		if (ptrStu[i].getNumber() == number) {
			cout << "\n\nOgrenci ;\n\n"
				<< "Sicil no :   " << ptrStu[i].getNumber()
				<< "\nIsim :	 " << ptrStu[i].getName()
				<< "\nSoyisim :  " << ptrStu[i].getSurname()
				<< "\nBolumu :   " << ptrStu[i].getDepartment()
				<< "\nE-posta :  " << ptrStu[i].getRegistrationYear()
				<< "\nTelefon :  " << ptrStu[i].getEmail()
				<< "\nUnvan :    " << ptrStu[i].getPhoneNumber()
				<< endl << endl << endl;
			return i;
		}
	}

	for (size_t i = 0; ptrAca[i].getName() != ""; i++)
	{
		if (ptrAca[i].getRegistrationNumber() == number) {

			cout << "\n\nAkademisyen ; \n\n"
				<< "Sicil no :   " << ptrAca[i].getRegistrationNumber()
				<< "\nIsim :   " << ptrAca[i].getName()
				<< "\nSoyisim :   " << ptrAca[i].getSurname()
				<< "\nAna Bilim Dali :   " << ptrAca[i].getDepartment()
				<< "\nE-posta :   " << ptrAca[i].getEmail()
				<< "\nTelefon :   " << ptrAca[i].getPhoneNumber()
				<< "\nUnvan :	" << ptrAca[i].getTitle()
				<< endl << endl << endl;
			return i;
		}
	}
	cout << "\n\nKayit Bulunamadi...\n\n";
	getchar();
	return -1;
}
string appointmentsHour(string t)
{
	string sMinute, sHour;

	int hour = atoi(t.substr(0, 2).c_str());
	int minute = atoi(t.substr(3, 2).c_str());

	if (minute == 30) {
		hour++;
		sHour = to_string(hour);
		sMinute = "00";
		return sHour + ':' + sMinute;
	}
	else if (minute == 0) {
		sMinute = "30";
		sHour = to_string(hour);
		return sHour + ':' + sMinute;
	}
	else return "-1";
}
int areThereCollision(string number, string date = "", string hour = "")
{
	int counter = 0;

	for (size_t i = 0; ptrApp[i].getAcademician().getRegistrationNumber() != ""; i++)
	{
		if (ptrApp[i].getAcademician().getRegistrationNumber() == number &&
			ptrApp[i].getDate() == date && ptrApp[i].getStartHour() == hour) ++counter;
		if (counter == 1) {
			cout << "Bu tarihte bir randevu sistemde kayitli....\n" << endl;
			return 0;
		}
	}
	if (date != "") return 1;

	for (size_t i = 0; ptrStu[i].getName() != ""; i++)
	{
		if (ptrStu[i].getNumber() == number) counter++;
		if (counter == 1) {
			cout << "Bu ogrenci numarasi sistemde kayitli....\n" << endl;
			return 0;
		}
	}

	for (size_t i = 0; ptrAca[i].getName() != ""; i++)
	{
		if (ptrAca[i].getRegistrationNumber() == number) counter++;
		if (counter == 1) {
			cout << "Bu sicil numarasi sistemde kayitli....\n" << endl;
			return 0;
		}
	}


	getchar();
	return 1;
}

void Appointments::saveFile(fstream& file)
{
	Student holdStu;
	Academician holdAca;
	string temp[5];
	int i = 0;

	file.clear();
	file.seekg(0, ios::beg);

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4];
			holdStu = ptrStu[0].search(temp[0]);
			holdAca = ptrAca[0].search(temp[1]);
			ptrApp[i].setAcademican(holdAca);
			ptrApp[i].setStudent(holdStu);
			ptrApp[i].setDate(temp[2]);
			ptrApp[i].setStartHour(temp[3]);
			ptrApp[i].setFinishHour(temp[4]);

			i++;
		}
	}
}
int  Appointments::viewAppointments(string number = "", string acaNumber = "", string date = "", string strtHour = "")
{
	int hold[20] = {}, counter = 1;
	system("cls");
	cout << "\nSISTEME KAYITLI RANDEVULAR\n\n";
	for (int i = 0; ptrApp[i + 1].getDate() != ""; i++)
	{
		if (ptrApp[i].getStudent().getNumber() == number || number == "") {
			cout << counter
				<< " - " << ptrApp[i].getAcademician().getRegistrationNumber()
				<< " " << ptrApp[i].getStudent().getNumber()
				<< " " << ptrApp[i].getDate()
				<< " " << ptrApp[i].getStartHour()
				<< " " << ptrApp[i].getFinishHour()
				<< "\n";
			counter++;
		}
		if (ptrApp[i].getStudent().getNumber() == number && ptrApp[i].getAcademician().getRegistrationNumber() == acaNumber
			&& ptrApp[i].getDate() == date && ptrApp[i].getStartHour() == strtHour) return i;
	}
	getchar();
	getchar();
}
void Appointments::addAppointment(string file1, string file2, string file3)
{
	string info[5];
	char selection;
	int index;

	while (true)
	{
		system("cls");
		cout << "\n---YENI RANDEVU---\n\n";
		cout << "Ogrenci Numarasi: ";	cin >> info[0];

		index = viewProfil(info[0]);
		if (index == -1) {
			cout << "\nOgrenci Bulunamadi...";
			cout << "\n\n\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}

		ptrAca->viewInformation();

		cout << "Akademisyenin Sicil Numarasi : ";	cin >> info[1];

		index = viewProfil(info[1]);
		if (index == -1)
		{
			cout << "\nAkademisyen Bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}

		cout << "Randevu tarihini \"01.01.1970\" formatinda giriniz..." << endl;
		cout << "Randevulari tam ve yarim saatlerde olacak sekilde \"15:00-15:00\" formatlariyla giriniz..." << endl;
		cout << "Randevular 30 dakika'dir. Baslangic saatine otomatik atanir...." << endl << endl << endl;

		cout << "Tarih : ";	cin >> info[2];
		cout << "Baslangic Saati : ";	cin >> info[3];
		info[4] = appointmentsHour(info[3]);
		if (info[4] == "-1") {
			cout << "\nSaat yanlis formatla girildi..." << endl;
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}
		if (!areThereCollision(info[1], info[2], info[3])) {
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}

		while (true)
		{
			cout << "\nBilgileri onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();
			if (selection == 'e' || selection == 'E')
			{
				fstream file;
				file.open(file3, ios::out | ios::app);

				file.clear();
				file.seekg(0, ios::beg);

				file << info[0] << " " << info[1] << " " << info[2] << " " << info[3] << " " << info[4] << "\n";

				file.close();
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else    cout << "Hatali tuslama\n";
		}
	}
}
void Appointments::editAppointment(string file1, string file2, string file3)
{
	string info[5];
	char selection;
	int index, *hold, index2, index3;

	while (true)
	{
		system("cls");
		cout << "\n---RANDEVU DUZENLEME---\n\n";
		cout << "Randevu tarihini \"01.01.1970\" formatinda giriniz..." << endl;
		cout << "Randevulari tam ve yarim saatlerde olacak sekilde \"15:00-15:00\" formatlariyla giriniz..." << endl;
		cout << "Randevular 30 dakika'dir. Baslangic saatine otomatik atanir...." << endl << endl << endl;

		cout << "Ogrenci no : ";	cin >> info[0];
		index = viewProfil(info[0]);
		if (index == -1)
		{
			cout << "\nOgrenci Bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			cin >> selection;
			if (selection == '0') return;
			else continue;
		}

		viewAppointments(info[0]);
		cout << "\nRandevuyu seciniz :\n\n";
		cout << "Akademisyenin Sicil Numarasi : ";	cin >> info[1];

		index = viewProfil(info[1]);
		if (index == -1)
		{
			cout << "\nAkademisyen Bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}
		cout << "Tarih : ";	cin >> info[2];
		cout << "Baslangic Saati : ";	cin >> info[3];
		info[4] = appointmentsHour(info[3]);

		index = viewAppointments(info[0], info[1], info[2], info[3]);
		cout << "\n\nYeni bilgileri giriniz....\n\n";

		cout << "Akademisyen Sicil No : "; cin >> info[1];
		cout << "Tarih : ";	cin >> info[2];
		cout << "Baslangic Saati : ";	cin >> info[3];
		info[4] = appointmentsHour(info[3]);

		if (info[4] == "-1") {
			cout << "\nSaat yanlis formatla girildi..." << endl;
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}
		if (!areThereCollision(info[1], info[2], info[3])) {
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}

		Academician aca = ptrAca[0].search(info[1]);
		Student stu = ptrStu[0].search(info[0]);

		ptrApp[index].setStudent(stu);
		ptrApp[index].setAcademican(aca);
		ptrApp[index].setDate(info[2]);
		ptrApp[index].setStartHour(info[3]);
		ptrApp[index].setFinishHour(info[4]);

		while (true)
		{
			cout << "\nBilgileri onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();
			if (selection == 'e' || selection == 'E')
			{
				ofstream file;
				file.open(file3, ios::trunc);

				if (file.is_open())
				{
					for (size_t i = 0; ptrApp[i + 1].getDate() != ""; i++)
					{
						file << ptrApp[i].getStudent().getNumber()
							<< " " << ptrApp[i].getAcademician().getRegistrationNumber()
							<< " " << ptrApp[i].getDate()
							<< " " << ptrApp[i].getStartHour()
							<< " " << ptrApp[i].getFinishHour()
							<< "\n";
					}
				}
				file.close();
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else	cout << "Hatali tuslama\n";
		}
	}
}
void Appointments::removeAppointment(string file1, string file2, string file3)
{
	string ogrNo, info[5], line, hold[5];
	int index;
	char selection;

	while (true)
	{
		system("cls");
		cout << "---RANDEVU IPTALI---\n\n" << endl;
		cout << "Ogrenci numaranizi giriniz : ";
		cin >> ogrNo;

		index = viewProfil(ogrNo);
		if (index == -1) {
			cout << "\nOgrenci Bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}

		viewAppointments(ogrNo);

		cout << "\nSilinecek randevu bilgilerini giriniz..." << endl;
		cout << "Akademisyenin Sicil Numarasi : ";	cin >> hold[1];
		cout << "Tarih : ";	cin >> hold[2];
		cout << "Baslangic Saati : ";	cin >> hold[3];

		while (true)
		{
			cout << "\nSilme islemini onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();

			if (selection == 'e' || selection == 'E')
			{
				ofstream temp;
				fstream file;
				file.open(file3);
				temp.open("temp.txt");

				file.clear();
				file.seekg(0, ios::beg);

				if (file.is_open())
				{
					while (!file.eof())
					{
						file >> info[0] >> info[1] >> info[2] >> info[3] >> info[4];

						if (file.eof()) break;

						if (info[0] != ogrNo || info[1] != hold[1] || info[2] != hold[2] || info[3] != hold[3]) {
							temp << info[0] << " " << info[1] << " " << info[2] << " " << info[3] << " " << info[4] << "\n";
						}
					}
				}
				file.close();
				temp.close();
				remove("randevu.txt");
				rename("temp.txt", "randevu.txt");
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else    cout << "Hatali tuslama\n";
		}
	}
}
void Academician::saveFile(fstream& file)
{
	string temp[7];
	int i = 0;

	file.clear();
	file.seekg(0, ios::beg);

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4] >> temp[5] >> temp[6];
			ptrAca[i].setRegistrationNumber(temp[0]);
			ptrAca[i].setName(temp[1]);
			ptrAca[i].setSurname(temp[2]);
			ptrAca[i].setDepartment(temp[3]);
			ptrAca[i].setEmail(temp[4]);
			ptrAca[i].setPhoneNumber(temp[5]);
			ptrAca[i].setTitle(temp[6]);
			i++;
		}
	}
}
void Academician::viewInformation()
{
	cout << endl;
	for (size_t i = 0; ptrAca[i + 1].getRegistrationNumber() != ""; i++)
	{
		cout << ptrAca[i].getRegistrationNumber() << " " <<
			ptrAca[i].getName() << " " <<
			ptrAca[i].getSurname() << " " <<
			ptrAca[i].getDepartment() << " " <<
			ptrAca[i].getEmail() << " " <<
			ptrAca[i].getPhoneNumber() << " " <<
			ptrAca[i].getTitle() << endl;
	}
	cout << endl;
}
void Academician::addAcademician(string file1, string file2, string file3)
{
	string info[7];
	char selection;

	while (true)
	{
		system("cls");
		cout << "\n---AKADEMISYEN EKLEME---\n\n";
		cout << "*Sicil Numarasi sonradan degistirilemeyecektir..." << endl;
		cout << "*Turkce karakter kullanmayiniz..." << endl;
		cout << "*Bosluk karakteri yerine '_' karakteriyle giris yapiniz..." << endl;
		cout << "*Telefon numarasi '+905XXXXXXXXX' formatiyla giris yapiniz....\n\n" << endl;

		cout << "Sicil no : ";	cin >> info[0];
		if (!areThereCollision(info[0])) {
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}
		cout << "Isim : ";				cin >> info[1];
		cout << "Soyisim : ";			cin >> info[2];
		cout << "Ana Bilim Dali : ";	cin >> info[3];
		cout << "E-posta : ";			cin >> info[4];
		cout << "Telefon : ";			cin >> info[5];
		cout << "Unvan : ";				cin >> info[6];

		while (true)
		{
			cout << "\nBilgileri onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();
			if (selection == 'e' || selection == 'E')
			{
				fstream file;
				file.open(file2, ios::app);

				file << info[0] << " " << info[1] << " " << info[2] << " " << info[3]
					<< " " << info[4] << " " << info[5] << " " << info[6]
					<< "\n";
				file.close();
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else		cout << "Hatali tuslama\n";
		}
	}
}
void Academician::editAcademician(string file1, string file2, string file3)
{
	string info[7];
	char selection;
	int index;

	while (true)
	{
		system("cls");
		cout << "\n---AKADEMISYEN DUZENLEME---\n\n";
		cout << "*Sicil Numarasi duzenlenemez..." << endl;
		cout << "*Turkce karakter kullanmayiniz..." << endl;
		cout << "*Bosluk karakteri yerine '_' karakteriyle giris yapiniz..." << endl;
		cout << "*Telefon numarasi '+905XXXXXXXXX' formatiyla giris yapiniz....\n\n" << endl;

		cout << "Sicil no : ";	cin >> info[0];
		index = viewProfil(info[0]);
		if (index == -1) {
			cout << "\nSicil numarasi bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			cin >> selection;
			if (selection == '0') return;
			else continue;
		}

		cout << "\n\nYeni bilgilerinizi giriniz....\n\n";
		cout << "Isim : ";				cin >> info[1];
		cout << "Soyisim : ";			cin >> info[2];
		cout << "Ana Bilim Dali : ";	cin >> info[3];
		cout << "E-posta : ";			cin >> info[4];
		cout << "Telefon : ";			cin >> info[5];
		cout << "Unvan : ";				cin >> info[6];

		ptrAca[index].setName(info[1]);
		ptrAca[index].setSurname(info[2]);
		ptrAca[index].setDepartment(info[3]);
		ptrAca[index].setEmail(info[4]);
		ptrAca[index].setPhoneNumber(info[5]);
		ptrAca[index].setTitle(info[6]);

		while (true)
		{
			cout << "\nBilgileri onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();
			if (selection == 'e' || selection == 'E')
			{
				ofstream file;
				file.open(file2, ios::trunc);

				if (file.is_open())
				{
					for (size_t i = 0; ptrAca[i + 1].getName() != ""; i++)
					{
						file << ptrAca[i].getRegistrationNumber()
							<< " " << ptrAca[i].getName()
							<< " " << ptrAca[i].getSurname()
							<< " " << ptrAca[i].getDepartment()
							<< " " << ptrAca[i].getEmail()
							<< " " << ptrAca[i].getPhoneNumber()
							<< " " << ptrAca[i].getTitle()
							<< "\n";
					}
				}
				file.close();
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else	cout << "Hatali tuslama\n";
		}
	}
}
void Academician::removeAcademician(string file1, string file2, string file3)
{
	string sicilNo, info[7], line;
	int index;
	char selection;

	while (true)
	{
		system("cls");
		cout << "---AKADEMISYEN SILME---\n\n" << endl;
		cout << "Sicil numaranizi giriniz : ";
		cin >> sicilNo;

		index = viewProfil(sicilNo);
		if (index == -1) {
			cout << "\nSicil numarasi bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}

		while (true)
		{
			cout << "\nSilme islemini onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();

			if (selection == 'e' || selection == 'E')
			{
				ofstream temp;
				fstream file;
				file.open(file2);
				temp.open("temp.txt");

				file.clear();
				file.seekg(0, ios::beg);

				if (file.is_open())
				{
					while (!file.eof())
					{
						file >> info[0] >> info[1] >> info[2] >> info[3]
							>> info[4] >> info[5] >> info[6];

						if (file.eof()) { break; }

						if (info[0] != sicilNo) {
							temp << info[0] << " " << info[1] << " " << info[2] << " " << info[3]
								<< " " << info[4] << " " << info[5] << " " << info[6] << "\n";
						}
					}
				}
				file.close();
				temp.close();
				remove("akademisyen.txt");
				rename("temp.txt", "akademisyen.txt");
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else	cout << "Hatali tuslama\n";
		}
	}
}
void Student::saveFile(fstream& file)
{
	string temp[7];
	int i = 0;

	file.clear();
	file.seekg(0, ios::beg);

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> temp[0] >> temp[1] >> temp[2] >> temp[3] >> temp[4] >> temp[5] >> temp[6];
			ptrStu[i].setNumber(temp[0]);
			ptrStu[i].setName(temp[1]);
			ptrStu[i].setSurname(temp[2]);
			ptrStu[i].setDepartment(temp[3]);
			ptrStu[i].setRegistrationYear(temp[4]);
			ptrStu[i].setEmail(temp[5]);
			ptrStu[i].setPhoneNumber(temp[6]);
			i++;
		}
	}
}
void Student::viewInformation()
{
	for (size_t i = 0; ptrStu[i].getName() != ""; i++)
	{
		cout << ptrStu[i].getNumber()
			<< " " << ptrStu[i].getName()
			<< " " << ptrStu[i].getSurname()
			<< " " << ptrStu[i].getDepartment()
			<< " " << ptrStu[i].getRegistrationYear()
			<< " " << ptrStu[i].getEmail()
			<< " " << ptrStu[i].getPhoneNumber() << endl;
	}
}
void Student::addStudent(string file1, string file2, string file3)
{
	string info[7];
	char selection;

	while (true)
	{
		system("cls");
		cout << "\n---OGRENCI EKLEME---\n\n";
		cout << "*Okul Numarasi sonradan degistirilemeyecektir..." << endl;
		cout << "*Turkce karakter kullanmayiniz..." << endl;
		cout << "*Bosluk karakteri yerine '_' karakteriyle giris yapiniz..." << endl;
		cout << "*Telefon numarasi '+905XXXXXXXXX' formatiyla giris yapiniz....\n\n" << endl;

		cout << "Okul no : ";	cin >> info[0];
		if (!areThereCollision(info[0])) {
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}
		cout << "Isim : ";			cin >> info[1];
		cout << "Soyisim : ";		cin >> info[2];
		cout << "Bolum : ";			cin >> info[3];
		cout << "Kayit Yili : ";	cin >> info[4];
		cout << "E-posta : ";		cin >> info[5];
		cout << "Telefon : ";		cin >> info[6];

		while (true)
		{
			cout << "\nBilgileri onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();
			if (selection == 'e' || selection == 'E')
			{
				fstream file;
				file.open(file1, ios::out | ios::app);

				file.clear();
				file.seekg(0, ios::beg);

				file << info[0] << " " << info[1] << " " << info[2] << " " << info[3]
					<< " " << info[4] << " " << info[5] << " " << info[6] << "\n";

				file.close();
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else     cout << "Hatali tuslama\n";
		}
	}
}
void Student::editStudent(string file1, string file2, string file3)
{
	string info[7];
	char selection;
	int index;

	while (true)
	{
		system("cls");
		cout << "\n---OGRENCI DUZENLEME---\n\n";
		cout << "*Ogrenci Numarasi duzenlenemez..." << endl;
		cout << "*Turkce karakter kullanmayiniz..." << endl;
		cout << "*Bosluk karakteri yerine '_' karakteriyle giris yapiniz..." << endl;
		cout << "*Telefon numarasi '+905XXXXXXXXX' formatiyla giris yapiniz....\n\n" << endl;

		cout << "Ogrenci no : ";	cin >> info[0];
		index = viewProfil(info[0]);
		if (index == -1) {
			cout << "\nOgrenci numarasi bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			cin >> selection;
			if (selection == '0') return;
			else continue;
		}
		cout << "\n\nYeni bilgilerinizi giriniz....\n\n";

		cout << "Isim : ";			cin >> info[1];
		cout << "Soyisim : ";		cin >> info[2];
		cout << "Bolum : ";			cin >> info[3];
		cout << "Kayit Yili : ";	cin >> info[4];
		cout << "E-posta : ";		cin >> info[5];
		cout << "Telefon : ";		cin >> info[6];

		ptrStu[index].setName(info[1]);
		ptrStu[index].setSurname(info[2]);
		ptrStu[index].setDepartment(info[3]);
		ptrStu[index].setRegistrationYear(info[4]);
		ptrStu[index].setEmail(info[5]);
		ptrStu[index].setPhoneNumber(info[6]);

		while (true)
		{
			cout << "\nBilgileri onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();
			if (selection == 'e' || selection == 'E')
			{
				ofstream file;
				file.open(file1, ios::trunc);

				if (file.is_open())
				{
					for (size_t i = 0; ptrStu[i + 1].getName() != ""; i++)
					{
						file << ptrStu[i].getNumber()
							<< " " << ptrStu[i].getName()
							<< " " << ptrStu[i].getSurname()
							<< " " << ptrStu[i].getDepartment()
							<< " " << ptrStu[i].getRegistrationYear()
							<< " " << ptrStu[i].getEmail()
							<< " " << ptrStu[i].getPhoneNumber()
							<< "\n";
					}
				}
				file.close();
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else	cout << "Hatali tuslama\n";
		}
	}
}
void Student::removeStudent(string file1, string file2, string file3)
{
	string ogrNo, info[7], line;
	int index;
	char selection;

	while (true)
	{
		system("cls");
		cout << "---OGRENCI SILME---\n\n" << endl;
		cout << "Ogrenci numaranizi giriniz : ";
		cin >> ogrNo;

		index = viewProfil(ogrNo);
		if (index == -1) {
			cout << "\nOgrenci numarasi bulunamadi...";
			cout << "\n\n\nAna menuye gitmek icin [0]... ";
			cout << "\nDevam etmek icin herhangi bir tusa basiniz...";
			selection = getchar();
			if (selection == '0') return;
			else continue;
		}
		while (true)
		{
			cout << "\nSilme islemini onayliyor musunuz? [e/h]...\n";
			cout << "Ana menuye gitmek icin [0]... ";
			selection = getchar();

			if (selection == 'e' || selection == 'E')
			{
				ofstream temp;
				fstream file;
				file.open(file1);
				temp.open("temp.txt");

				file.clear();
				file.seekg(0, ios::beg);

				if (file.is_open())
				{
					while (!file.eof())
					{
						file >> info[0] >> info[1] >> info[2] >> info[3]
							>> info[4] >> info[5] >> info[6];

						if (file.eof()) { break; }

						if (info[0] != ogrNo) {
							temp << info[0] << " " << info[1] << " " << info[2] << " " << info[3]
								<< " " << info[4] << " " << info[5] << " " << info[6] << "\n";
						}
					}
				}
				file.close();
				temp.close();
				remove("ogrenci.txt");
				rename("temp.txt", "ogrenci.txt");
				updateToSystem(file1, file2, file3);
				return;
			}
			else if (selection == 'h' || selection == 'H') break;
			else if (selection == '0') return;
			else	cout << "Hatali tuslama\n";
		}
	}
}

int main(int argc, char *argv[])
{

	if (argc != 4) cout << "eksik arguman ...";

	cout << argv[0] << endl << argc << endl;

	updateToSystem(argv[1], argv[2], argv[3]);

	while (true)
	{
		system("cls");
		cout << (" \n\nKTU AKADEMISYEN RANDEVU SISTEMI \n\n");
		cout << (" [1]	RANDEVU AL \n");
		cout << (" [2]	RANDEVULARI LISTELE \n");
		cout << (" [3]	RANDEVU IPTALI \n");
		cout << (" [4]	RANDEVU DUZENLE\n");
		cout << (" [5]	OGRENCI ISLEMLERI\n");
		cout << (" [6]	AKADEMISYEN ISLEMLERI\n");
		cout << (" [0]	PROGRAMDAN CIK \n");
		cout << (" \n SECIMINIZ [0..6] = ");

		char s;
		cin >> s;
		switch (s)
		{
		case '1':	ptrApp->addAppointment(argv[1], argv[2], argv[3]);		break;
		case '2':	ptrApp->viewAppointments();		break;
		case '3':	ptrApp->removeAppointment(argv[1], argv[2], argv[3]);	break;
		case '4':	ptrApp->editAppointment(argv[1], argv[2], argv[3]);		break;
		case '5':
			system("cls");
			cout << "[1]	OGRENCI KAYIT\n[2]	OGRENCI DUZENLE\n[3]	OGRENCI SIL\n[0]	ANA MENU\nSECIMINIZ [0..3] = ";
			cin >> s;
			switch (s) {
			case '1':	ptrStu->addStudent(argv[1], argv[2], argv[3]);	break;
			case '2':	ptrStu->editStudent(argv[1], argv[2], argv[3]);	break;
			case '3':	ptrStu->removeStudent(argv[1], argv[2], argv[3]);	break;
			case '0':	continue;
			default:	cout << "--GECERSIZ TUSLAMA--" << endl; getchar();
			}
			break;
		case '6':
			system("cls");
			cout << "[1]	AKADEMISYEN KAYIT\n[2]	AKADEMISYEN DUZENLE\n[3]	AKADEMISYEN SIL\n[0]	ANA MENU\nSECIMINIZ [0..3] = ";
			cin >> s;
			switch (s) {
			case '1':	ptrAca->addAcademician(argv[1], argv[2], argv[3]);	break;
			case '2':	ptrAca->editAcademician(argv[1], argv[2], argv[3]);	break;
			case '3':	ptrAca->removeAcademician(argv[1], argv[2], argv[3]);	break;
			case '0':	continue;
			default:	cout << "--GECERSIZ TUSLAMA--" << endl; getchar();
			}
			break;
		case '0':	return 0;
		default: cout << "--GECERSIZ TUSLAMA--" << endl; getchar();
		}
	}
	return 0;
}