#include "Address.h"


Address::Address() : city{ "Неизвестный город" }, street{ "Неизвестная улица" }, houseNumber{}, apartmentNumber{} {}

void Address::setCity(const std::string _city) { city = _city; }

void Address::setStreet(const std::string _street) { street = _street; }

void Address::setHouseNumber(int _houseNumber) { houseNumber = _houseNumber; }

void Address::setApartmentNumber(const int _apartmentNumber) { apartmentNumber = _apartmentNumber; }

std::string Address::getCity() { return city; }

std::string Address::getStreet() { return street; }

int Address::getHouseNumber() { return houseNumber; }

int Address::getApartmentNumber() { return apartmentNumber; }

std::string Address::getFullAddress() { return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber); }