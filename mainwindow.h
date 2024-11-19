#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QAction>
#include <QMenu>

#include "ApartmentContainer.h"
#include "Apartment.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Методы для обновления таблицы и взаимодействия с данными
    void updateTable();
    void addApartmentToTable(const Apartment& apartment);
    void showAbout(); // Слот для показа окна "ABOUT"
    void showContextMenu(const QPoint &pos); // Слот для показа контекстного меню таблицы

    void onTableSelectionChanged(); // Метод для обновления состояния кнопок
    int getSelectedRowIndex(); // Метод для получения индекса выбранной строки
    void Exit_action(); // Слот для выхода из приложения

    Ui::MainWindow* getUi() { return ui; }
    ApartmentContainer& getApartmentContainer() { return apartmentContainer; } // Геттер для apartmentContainer
    const QString& getCurrentDatabaseFile() const { return currentDatabaseFile; } // Геттер для currentDatabaseFile
    void setCurrentDatabaseFile(const QString& filename) { currentDatabaseFile = filename; }  // Сеттер для currentDatabaseFile

private:
    Ui::MainWindow *ui;
    ApartmentContainer apartmentContainer; // Контейнер для хранения квартир
    QString currentDatabaseFile; // Имя текущего файла базы данных
};

#endif // MAINWINDOW_H
