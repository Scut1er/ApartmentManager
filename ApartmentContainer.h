// ApartmentContainer.h
#ifndef APARTMENTCONTAINER_H
#define APARTMENTCONTAINER_H

#include "Apartment.h"
#include <vector>

class ApartmentContainer {
public:
    ApartmentContainer() = default;

    // Добавление квартиры
    void addApartment(const Apartment& apartment);

    // Удаление квартиры по индексу
    bool removeApartment(int index);

    // Редактирование квартиры по индексу
    bool editApartment(int index, const Apartment& newApartment);

    // Получение квартиры по индексу
    Apartment* getApartment(int index) const;

    // Просмотр всех квартир
    void viewAllApartments() const;

    // Поиск квартир по минимальной площади
    std::vector<Apartment*> findApartmentsByArea(double minArea) const;

    // Количество квартир в контейнере
    int size() const;

    // Очистка всех квартир
    void clear();

    // Итераторы для перебора квартир
    std::vector<Apartment>::iterator begin();
    std::vector<Apartment>::iterator end();
    std::vector<Apartment>::const_iterator cbegin() const;
    std::vector<Apartment>::const_iterator cend() const;

private:
    std::vector<Apartment> apartments;
};

#endif // APARTMENTCONTAINER_H
