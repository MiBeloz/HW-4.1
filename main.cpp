#include "Address.h"

#include <iostream>
#include <fstream>


int readNumAddress(const std::string fileName);

bool readAddress(Address* address, const int size, const std::string fileName);

bool writeAddress(Address* address, const int size, const std::string fileName);

void printAddressFromIn(Address* address, const int size);


int main() {
	setlocale(LC_ALL, "ru");

	std::string fileIn = "in.txt";
	std::string fileOut = "out.txt";
	Address* address = nullptr;
	int size{};

	std::cout << "Чтение адресов из файла '" << fileIn << "' и запись в другом формате в обратном порядке в файл '" << fileOut << "'.\n\n";
	std::cout << "Нажмите любую клавишу, чтобы считать данные из файла...\n\n";
	system("pause > nul");
	
	// Считать количество адресов
	size = readNumAddress(fileIn);
	if (size > 0) {
		address = new Address[size];
	}
	else if (size == -1) {
		std::cout << "Ошибка открытия файла '" << fileIn << "'!" << std::endl;
		system("pause > nul");
		return 0;
	}
	else {
		std::cout << "В файле '" << fileIn << "' нет адресов!\n";
		system("pause > nul");
		return 0;
	}

	// Считать все адреса
	if (!readAddress(address, size, fileIn)) {
		std::cout << "Ошибка открытия файла '" << fileIn << "'!" << std::endl;

		delete[] address;
		address = nullptr;

		system("pause > nul");
		return 0;
	}
	
	std::cout << "Данные считаны в формате:" << std::endl;
	printAddressFromIn(address, size);
	std::cout << std::endl;

	// Запись всех адресов
	std::cout << "Данные записаны в формате:" << std::endl;
	if (!writeAddress(address, size, fileOut)) {
		std::cout << "Ошибка открытия файла '" << fileOut << "'!" << std::endl;

		delete[] address;
		address = nullptr;

		system("pause > nul");
		return 0;
	}

	delete[] address;
	address = nullptr;

	system("pause > nul");
	return 0;
}

int readNumAddress(const std::string fileName) {
	std::fstream file;
	int size{};

	file.open(fileName, std::fstream::in);
	if (file.is_open()) {
		file >> size;
	}
	else {
		return -1;
	}
	file.close();
	return size;
}

bool readAddress(Address* address, const int size, const std::string fileName) {
	std::fstream file;
	std::string str;
	int x{};

	file.open(fileName, std::fstream::in);
	if (file.is_open()) {
		file.seekg(1, std::fstream::beg);
		for (int i = 0; i < size; i++) {
			file >> str;
			address[i].setCity(str);
			file >> str;
			address[i].setStreet(str);
			file >> x;
			address[i].setHouseNumber(x);
			file >> x;
			address[i].setApartmentNumber(x);
		}
	}
	else {
		return false;
	}
	file.close();
	return true;
}

bool writeAddress(Address* address, const int size, const std::string fileName) {
	std::fstream file;

	std::cout << size << std::endl;
	file.open(fileName, std::fstream::out);
	if (file.is_open()) {
		file << size << std::endl;
		for (int i = size - 1; i >= 0; i--) {
			file << address[i].getFullAddress() << std::endl;
			std::cout << address[i].getFullAddress() << std::endl;
		}
	}
	else {
		return false;
	}
	file.close();
	return true;
}

void printAddressFromIn(Address* address, const int size) {
	std::cout << size << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << address[i].getCity() << std::endl;
		std::cout << address[i].getStreet() << std::endl;
		std::cout << address[i].getHouseNumber() << std::endl;
		std::cout << address[i].getApartmentNumber() << std::endl;
	}
}