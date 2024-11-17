// ApartmentContainer.cpp
#include "ApartmentContainer.h"
#include <iostream>

// Добавление квартиры
void ApartmentContainer::addApartment(const Apartment& apartment) {
    apartments.push_back(apartment);
}

// Удаление квартиры по индексу
bool ApartmentContainer::removeApartment(int index) {
    if (index >= 0 && index < static_cast<int>(apartments.size())) {
        apartments.erase(apartments.begin() + index);
        return true;
    }
    return false;
}

// Редактирование квартиры по индексу
bool ApartmentContainer::editApartment(int index, const Apartment& newApartment) {
    if (index >= 0 && index < static_cast<int>(apartments.size())) {
        apartments[index] = newApartment;
        return true;
    }
    return false;
}

// Получение квартиры по индексу
Apartment* ApartmentContainer::getApartment(int index) const {
    if (index >= 0 && index < static_cast<int>(apartments.size())) {
        return const_cast<Apartment*>(&apartments[index]);
    }
    return nullptr;
}

// Просмотр всех квартир (для отладки)
void ApartmentContainer::viewAllApartments() const {
    for (const auto& apartment : apartments) {
        std::cout << apartment.toString().toStdString() << std::endl;
    }
}

// Поиск квартир по минимальной площади
std::vector<Apartment*> ApartmentContainer::findApartmentsByArea(double minArea) const {
    std::vector<Apartment*> result;
    for (const auto& apartment : apartments) {
        if (apartment.getArea() >= minArea) {
            result.push_back(const_cast<Apartment*>(&apartment));
        }
    }
    return result;
}

// Количество квартир в контейнере
int ApartmentContainer::size() const {
    return apartments.size();
}

// Очистка всех квартир в контейнере
void ApartmentContainer::clear() {
    apartments.clear();
}

// Итератор на начало контейнера
std::vector<Apartment>::iterator ApartmentContainer::begin() {
    return apartments.begin();
}

// Итератор на конец контейнера
std::vector<Apartment>::iterator ApartmentContainer::end() {
    return apartments.end();
}

// Константный итератор на начало контейнера
std::vector<Apartment>::const_iterator ApartmentContainer::cbegin() const {
    return apartments.cbegin();
}

// Константный итератор на конец контейнера
std::vector<Apartment>::const_iterator ApartmentContainer::cend() const {
    return apartments.cend();
}
