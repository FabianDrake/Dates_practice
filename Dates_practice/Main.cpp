#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

class Date {
protected:
	int dia;
	int mes;
	int a�o;
public:
	void date(int, int, int);
	void validar_dia(int);
	void validar_a�o(int);
	void validar_mes(int);
	void bisiesto(int);
	void febrero(int);
	void dias_febrero(int);

	void setDate(int, int, int);
	int getDia();
	int getMes();
	int getA�o();

	void Run();
};

void Date::date(int _dia, int _mes, int _a�o) {
	dia = _dia;
	mes = _mes;
	a�o = _a�o;
}

void Date::setDate(int dia, int mes, int a�o) {
	this->dia = dia;
	this->mes = mes;
	this->a�o = a�o;
}
int Date::getDia() {
	return dia;
}
int Date::getMes() {
	return mes;
}
int Date::getA�o() {
	return a�o;
}

//-----------------------------------------------------------------------------------------------------------------

void Date::validar_dia(int _a�o) {
	this->a�o = _a�o;
	if (dia >= 1 && dia <= 31) {
		bisiesto(a�o);
	}
	else {
		cout << "EL DIA NO ES VALIDO \n";
		/*
		validar_dia(a�o);
		*/
	}
}

void Date::validar_mes(int _a�o) {
	this->a�o = _a�o;
	if (mes >= 1 && mes <= 12) {
		febrero(a�o);
	}
	else {
		cout << "EL MES NO ES VALIDO \n";
	}
}

void Date::validar_a�o(int _a�o) {
	this->a�o = _a�o;
	if (a�o >= 19990 && a�o <= 3000 || a�o >= 1 && a�o <= 99) {
		validar_mes(a�o);
	}
}

//------------------------------------------------------------------------------------------------------------------

void Date::febrero(int _a�o) {
	this->a�o = _a�o;
	if (mes == 2) {
		dias_febrero(a�o);
	}
	else {
		validar_dia(a�o);
	}
}

void Date::dias_febrero(int _a�o) {
	this->a�o = _a�o;
	if (dia >= 1 && dia <= 29) {
		bisiesto(a�o);
	}
	else {
		cout << "EL DIA NO ES VALIDO \n";
	}
}

void Date::bisiesto(int _a�o) {
	this->a�o = _a�o;

	cout << "LA FECHA INGRESADA FUE: " << dia << "/" << mes << "/" << a�o << endl;

	if (a�o % 4 != 0 || (a�o % 100 == 0 && a�o % 400 != 0)) {
		cout << "EL A�O NO ES BISIESTO\n";
	}
	else {
		cout << "EL A�O ES BISIESTO\n";
	}
}

void Date::Run() {
	string fecha;
	cout << "Ingrese la fecha:  dd/mm/aa \n";
	cout << "Fecha: ";
	cin >> fecha;
	string diaa, mees, aa�o;
	stringstream input(fecha);

	getline(input, diaa, '/');
	getline(input, mees, '/');
	getline(input, aa�o, '/');

	cout << "\nDia:" << diaa << "\n";
	cout << "\nMes:" << mees << "\n";
	cout << "\nA�o:" << aa�o << "\n";

	dia = stoi(diaa);
	mes = stoi(mees);
	a�o = stoi(aa�o);

	validar_a�o(a�o);
}

int main() {
	Date o;
	o.Run();
}
