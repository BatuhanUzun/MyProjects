#include<iostream>
#include<stdlib.h>
#include <fstream>
#include<ctime>
#include<iomanip>
#include "space.h"

using namespace std;

class space {
private:
	int horizontal;
	int vertical;
public:
	class Box {
	private:
		double density;
		double width;
		double height;
	public:
		class coord {
		private:
			double start_x;
			double start_y;
			double finish_x;
			double finish_y;
		public:
			coord();
			void set_start_x(int new_x);
			void set_start_y(int new_y);
			double get_start_x();
			double get_start_y();
			void set_finish_x(int new_x);
			void set_finish_y(int new_y);
			double get_finish_x();
			double get_finish_y();
		}coord;
		Box();
		void set_density(int new_den);
		void set_width(int new_wid);
		void set_height(int new_hei);
		double get_density();
		double get_width();
		double get_height();
	}kutular[20];
	space();
	space(int default_h, int default_v);
	void set_horizontal(int new_hor);
	void set_vertical(int new_ver);
	int get_horizontal();
	int get_vertical();
	void fillRandomBox(int total_box, int max_box_size, int box_density);
	void printBoxCoordinates();
	void printCenterOfMass();
	bool BoxCollision(Box A, Box B);
	void printFile();
	void inputDestiny(int total_box, int max_box_size, int max_density);
};

space::space() {
	horizontal = 10;
	vertical = 10;
	cout << horizontal << "x" << vertical << "default space was created." << endl;
}
space::space(int default_h, int default_v) {
	horizontal = default_h;
	vertical = default_v;
	cout << horizontal << "x" << vertical << " space was created." << endl;
}
void space::set_horizontal(int new_hor) { horizontal = new_hor; }
void space::set_vertical(int new_ver)	{ vertical = new_ver; }
int space::get_horizontal()				{ return horizontal; }
int space::get_vertical()				{ return vertical; }




void space::fillRandomBox(int total_box, int max_box_size, int box_density)
{
	int temp;
	srand(time(NULL));
	for (int i = 0; i < total_box; i++)
	{
		kutular[i].set_height((rand() % max_box_size) + 1);
		kutular[i].set_width((rand() % max_box_size) + 1);
		kutular[i].set_density(box_density);

		if (kutular[i].get_height() > vertical && kutular[i].get_width() > horizontal) {
			kutular[i].coord.set_start_x(horizontal + 1);
			kutular[i].coord.set_start_y(vertical + 1);
			continue;
		}


		for (size_t x = 0; x < horizontal; x++)
		{
			for (size_t y = 0; y < vertical; y++)
			{
				kutular[i].coord.set_start_x(x);
				kutular[i].coord.set_start_y(y);
				kutular[i].coord.set_finish_x(kutular[i].coord.get_start_x() + kutular[i].get_width());
				kutular[i].coord.set_finish_y(kutular[i].coord.get_start_y() + kutular[i].get_height());


				//TASMA VARMI
				if (kutular[i].coord.get_start_x() + kutular[i].get_width() > horizontal ||
					kutular[i].coord.get_start_y() + kutular[i].get_height() > vertical)
				{
					//VARSA VE SON KONUMDAYSA
					if (kutular[i].coord.get_start_x() == horizontal - 1 && kutular[i].coord.get_start_y() == vertical - 1) {

						kutular[i].coord.set_start_x(horizontal + 1);
						kutular[i].coord.set_start_y(vertical + 1);
						goto stop;
					}
					continue;
				}

				//CAKISMA VARMI
				for (size_t j = 0; j < i; j++)
				{
					if (BoxCollision(kutular[i], kutular[j])) {

						//VARSA VE SON KONUMDAYSA
						if (kutular[i].coord.get_start_x() == horizontal - 1 && kutular[i].coord.get_start_y() == vertical - 1)
							kutular[i].coord.set_start_x(horizontal + 1);
						//VARSA
						goto stop1;
					}
				}

				goto stop;
			stop1:;
			}
		}

	stop:;
	}


}

//CAKISMA KONTROLU
bool space::BoxCollision(Box A, Box B)
{
	return  B.coord.get_start_x() < A.coord.get_start_x() + A.get_width() &&
		A.coord.get_start_x() < B.coord.get_start_x() + B.get_width() &&
		B.coord.get_start_y() < A.coord.get_start_y() + A.get_height() &&
		A.coord.get_start_y() < B.coord.get_start_y() + B.get_height();
}


void space::printBoxCoordinates() {
	cout << endl << "n.box" << setw(17) << "Size of box" << setw(10) << "start" 
		 << setw(14) << "finish" << setw(14) << "density" << endl << endl;

	for (int counter = 0; kutular[counter].get_density() != 0; counter++) {

		if (kutular[counter].coord.get_start_x() == horizontal + 1)
			continue;

		cout << counter << ".box "
			<< setw(10) << kutular[counter].get_height() << "x" << kutular[counter].get_width()
			<< setw(10) << "(" << kutular[counter].coord.get_start_x() << "," << kutular[counter].coord.get_start_y() << ")"
			<< setw(10) << "(" << kutular[counter].coord.get_finish_x() << "," << kutular[counter].coord.get_finish_y() << ")"
			<< setw(10) << kutular[counter].get_density()
			<< endl;
	}
	cout << endl << "--------------------------------------------------------------------" << endl;
	for (int counter = 0; kutular[counter].get_density() != 0; counter++)
	{
		if (kutular[counter].coord.get_start_x() == horizontal + 1)
		{
			cout << counter << ".box " << setw(10) << kutular[counter].get_height()
				<< "x" << kutular[counter].get_width() << "	Failed." << endl;
		}
	}
}

void space::printCenterOfMass() {
	double mass = 0, total_mass = 0, total_mass_coordx = 0, total_mass_coordy = 0, COMx = 0, COMy = 0;

	for (int counter = 0; kutular[counter].get_density() != 0; counter++) {

		if (kutular[counter].coord.get_start_x() == horizontal + 1)
			continue;

		mass = kutular[counter].get_height()*kutular[counter].get_width()*kutular[counter].get_density();
		total_mass += mass;
		total_mass_coordx += mass * ((kutular[counter].coord.get_start_x() + kutular[counter].coord.get_finish_x()) / 2);
		total_mass_coordy += mass * ((kutular[counter].coord.get_start_y() + kutular[counter].coord.get_finish_y()) / 2);
	}
	COMx = total_mass_coordx / total_mass;
	COMy = total_mass_coordy / total_mass;

	cout << endl << "Center Of Mass : (" << COMx << "," << COMy << ")" << endl;
}

void space::printFile()
{
	double mass = 0, total_mass = 0, total_mass_coordx = 0, total_mass_coordy = 0, COMx = 0, COMy = 0;

	ofstream dosya1;
	dosya1.open("Print.txt", ios::out);

	dosya1 << endl << "n.box" << setw(17) << "Size of box" << setw(10) << "start" << setw(14) << "finish" << endl << endl;

	for (int counter = 0; kutular[counter].get_density() != 0; counter++) {

		if (kutular[counter].coord.get_start_x() == horizontal + 1)
			continue;

		dosya1 << counter << ".box "
			<< setw(10) << kutular[counter].get_height() << "x" << kutular[counter].get_width()
			<< setw(10) << "(" << kutular[counter].coord.get_start_x() << "," << kutular[counter].coord.get_start_y() << ")"
			<< setw(10) << "(" << kutular[counter].coord.get_finish_x() << "," << kutular[counter].coord.get_finish_y() << ")"
			<< endl;
	}
	dosya1 << endl << "--------------------------------------------------------------------" << endl;
	for (int counter = 0; kutular[counter].get_density() != 0; counter++)
	{
		if (kutular[counter].coord.get_start_x() == horizontal + 1)
		{
			dosya1 << counter << ".box " << setw(10) << kutular[counter].get_height()
				<< "x" << kutular[counter].get_width() << "	Failed." << endl;
		}
	}

	for (int counter = 0; kutular[counter].get_density() != 0; counter++) {

		if (kutular[counter].coord.get_start_x() == horizontal + 1)
			continue;

		mass = kutular[counter].get_height()*kutular[counter].get_width()*kutular[counter].get_density();
		total_mass += mass;
		total_mass_coordx += mass * ((kutular[counter].coord.get_start_x() + kutular[counter].coord.get_finish_x()) / 2);
		total_mass_coordy += mass * ((kutular[counter].coord.get_start_y() + kutular[counter].coord.get_finish_y()) / 2);
	}
	COMx = total_mass_coordx / total_mass;
	COMy = total_mass_coordy / total_mass;

	dosya1 << endl << "Center Of Mass : (" << COMx << "," << COMy << ")" << endl;

	dosya1.close();
}

void space::inputDestiny(int total_box, int max_box_size, int max_density)
{
	int temp, box_density;
	srand(time(NULL));

	for (int i = 0; i < total_box; i++)
	{
		kutular[i].set_height((rand() % max_box_size) + 1);
		kutular[i].set_width((rand() % max_box_size) + 1);
		kutular[i].set_density((rand() % max_density) + 1);

		if (kutular[i].get_height() > vertical && kutular[i].get_width() > horizontal) {
			kutular[i].coord.set_start_x(horizontal + 1);
			kutular[i].coord.set_start_y(vertical + 1);
			continue;
		}


		for (size_t x = 0; x < horizontal; x++)
		{
			for (size_t y = 0; y < vertical; y++)
			{
				kutular[i].coord.set_start_x(x);
				kutular[i].coord.set_start_y(y);
				kutular[i].coord.set_finish_x(kutular[i].coord.get_start_x() + kutular[i].get_width());
				kutular[i].coord.set_finish_y(kutular[i].coord.get_start_y() + kutular[i].get_height());


				//TAÞMA VARMI
				if (kutular[i].coord.get_start_x() + kutular[i].get_width() > horizontal ||
					kutular[i].coord.get_start_y() + kutular[i].get_height() > vertical)
				{
					//VARSA VE SON KONUMDAYSA
					if (kutular[i].coord.get_start_x() == horizontal - 1 && 
						kutular[i].coord.get_start_y() == vertical - 1) 
					{
						kutular[i].coord.set_start_x(horizontal + 1);
						kutular[i].coord.set_start_y(vertical + 1);
						goto stop;
					}
					continue;
				}

				//ÇAKIÞMA VARMI
				for (size_t j = 0; j < i; j++)
				{
					if (BoxCollision(kutular[i], kutular[j])) {

						//VARSA VE SON KONUMDAYSA
						if (kutular[i].coord.get_start_x() == horizontal - 1 && kutular[i].coord.get_start_y() == vertical - 1)
							kutular[i].coord.set_start_x(horizontal + 1);
						//VARSA
						goto stop1;
					}
				}
			goto stop;
			stop1:;
			}
		}
	stop:;
	}
}

space::Box::Box() {
	height = 1;
	width = 1;
	density = 0;
}
void space::Box::set_density(int new_den)	{ density = new_den; }
void space::Box::set_width(int new_wid)		{ width = new_wid;	 }
void space::Box::set_height(int new_hei)	{ height = new_hei;  }
double space::Box::get_density()			{ return density;	 }
double space::Box::get_width()				{ return width;		 }
double space::Box::get_height()				{ return height;	 }

space::Box::coord::coord() {
	start_x = 0;
	start_y = 0;
}
void space::Box::coord::set_start_x(int new_x)	{ start_x = new_x; }
void space::Box::coord::set_start_y(int new_y)	{ start_y = new_y; }
double space::Box::coord::get_start_x()			{ return start_x;  }
double space::Box::coord::get_start_y()			{ return start_y;  }

void space::Box::coord::set_finish_x(int new_x) { finish_x = new_x; }
void space::Box::coord::set_finish_y(int new_y) { finish_y = new_y; }
double space::Box::coord::get_finish_x()		{ return finish_x;  }
double space::Box::coord::get_finish_y()		{ return finish_y;  }


int main()
{
	space s(4,4);

	//s.fillRandomBox(10, 2, 1);
	s.inputDestiny(2, 3, 5);

	s.printBoxCoordinates();
	s.printCenterOfMass();
	s.printFile();
	
	return 0;
}
