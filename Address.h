#pragma once

#include <string>


class Address {
public:
	Address();

	void setCity(const std::string _city);
	void setStreet(const std::string _street);
	void setHouseNumber(const int _houseNumber);
	void setApartmentNumber(const int _apartmentNumber);

	std::string getCity();
	std::string getStreet();
	int getHouseNumber();
	int getApartmentNumber();
	std::string getFullAddress();

private:
	std::string city;
	std::string street;
	int houseNumber;
	int apartmentNumber;
};

