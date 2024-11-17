#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <fstream>
#include "ApartmentContainer.h"

class DatabaseManager {
public:
    // Создание нового контейнера для данных
    static bool createNewDatabase(const std::string& filename);

    // Сохранение данных в файл
    static bool saveToFile(const ApartmentContainer& container, const std::string& filename);

    // Загрузка данных из файла
    static bool loadFromFile(ApartmentContainer& container, const std::string& filename);

    // Объединение двух контейнеров
    static void mergeContainers(ApartmentContainer& container1, const ApartmentContainer& container2);
};

#endif // DATABASEMANAGER_H
