// Apartment.cpp
#include "Apartment.h"

// Конструктор
Apartment::Apartment(int floor, int rooms, double area, bool hasRenovation, bool hasBalcony, double price)
    : floor(floor), rooms(rooms), area(area), renovation(hasRenovation), balcony(hasBalcony), price(price) {}

// Геттеры
int Apartment::getFloor() const { return floor; }
int Apartment::getRooms() const { return rooms; }
double Apartment::getArea() const { return area; }
bool Apartment::hasRenovation() const { return renovation; }
bool Apartment::hasBalcony() const { return balcony; }
double Apartment::getPrice() const { return price; }


// Сеттеры
void Apartment::setFloor(int floor) { this->floor = floor; }
void Apartment::setRooms(int rooms) { this->rooms = rooms; }
void Apartment::setArea(double area) { this->area = area; }
void Apartment::setRenovation(bool hasRenovation) { renovation = hasRenovation; }
void Apartment::setBalcony(bool hasBalcony) { balcony = hasBalcony; }
void Apartment::setPrice(double price) { this->price = price; }


// Метод для получения строки с описанием квартиры
QString Apartment::toString() const {
    QString result = QString("Floor: %1, Rooms: %2, Area: %3 m², Renovation: %4, Balcony: %5, Price: %6,")
                         .arg(floor)
                         .arg(rooms)
                         .arg(area)
                         .arg(renovation ? "Yes" : "No")
                         .arg(balcony ? "Yes" : "No")
                         .arg(price);
    return result;
}
