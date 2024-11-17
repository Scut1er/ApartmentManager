#include "DatabaseManager.h"
#include <iostream>

// Создание нового контейнера для данных (очистка старых данных и создание нового файла)
bool DatabaseManager::createNewDatabase(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка создания файла базы данных.\n";
        return false;
    }
    // Здесь можно добавить логику для инициализации базы данных (например, запись пустой структуры данных)
    file.close();
    return true;
}

// Сохранение данных из контейнера в файл
bool DatabaseManager::saveToFile(const ApartmentContainer& container, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка открытия файла для записи.\n";
        return false;
    }

    // Запись данных из контейнера в файл с использованием const_iterator
    for (auto it = container.cbegin(); it != container.cend(); ++it) {
        file.write(reinterpret_cast<const char*>(&(*it)), sizeof(Apartment));
    }

    file.close();
    return true;
}

// Загрузка данных из файла в контейнер
bool DatabaseManager::loadFromFile(ApartmentContainer& container, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Ошибка открытия файла для чтения.\n";
        return false;
    }

    container.clear(); // Очистить контейнер перед загрузкой новых данных

    // Загрузка данных из файла в контейнер
    Apartment apartment(0, 0, 0.0, false, false, 0.0);
    while (file.read(reinterpret_cast<char*>(&apartment), sizeof(Apartment))) {
        container.addApartment(apartment);
    }

    file.close();
    return true;
}



// Объединение двух контейнеров
void DatabaseManager::mergeContainers(ApartmentContainer& container1, const ApartmentContainer& container2) {
    // Использование const_iterator для объединения
    for (auto it = container2.cbegin(); it != container2.cend(); ++it) {
        container1.addApartment(*it);
    }
}
