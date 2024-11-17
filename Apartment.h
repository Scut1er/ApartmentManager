// Apartment.h
#ifndef APARTMENT_H
#define APARTMENT_H

#include <QString>

class Apartment {
public:
    // Конструктор с параметрами по умолчанию
    Apartment(int floor = 1, int rooms = 1, double area = 0.0, bool hasRenovation = false, bool hasBalcony = false, double price = 0.0);

    // Геттеры
    int getFloor() const;
    int getRooms() const;
    double getArea() const;
    bool hasRenovation() const;
    bool hasBalcony() const;
    double getPrice() const;


    // Сеттеры
    void setFloor(int floor);
    void setRooms(int rooms);
    void setArea(double area);
    void setRenovation(bool hasRenovation);
    void setBalcony(bool hasBalcony);
    void setPrice(double price);

    // Метод для получения информации об объекте
    QString toString() const;

private:
    int floor;                // Этаж
    int rooms;                // Количество комнат
    double area;              // Площадь квартиры
    bool renovation;          // Наличие ремонта
    bool balcony;             // Наличие балкона
    double price;             // Стоимость квартиры
};

#endif // APARTMENT_H
