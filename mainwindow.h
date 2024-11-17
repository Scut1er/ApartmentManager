#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "DatabaseManager.h"
#include "ApartmentContainer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: // Секция для слотов
    void updateTable();
    void addApartmentToTable(const Apartment& apartment);
    void showAbout(); // Слот для показа окна "ABOUT"
    void showContextMenu(const QPoint &pos); // Слот для показа контекстного меню таблицы

    void NewDatabase_action();
    void SaveDatabase_action();
    void SaveAsDatabase_action();
    void LoadDatabase_action();
    void MergeDatabase_action();
    void Exit_action();

    void AddAp_action();
    void EditAp_action();
    void DelAp_action();
    void onTableSelectionChanged();


private:
    Ui::MainWindow *ui;
    ApartmentContainer apartmentContainer;
    DatabaseManager dbManager;
    QString currentDatabaseFile;

    void loadApartmentsIntoTable();
    int getSelectedRowIndex();
};
#endif // MAINWINDOW_H
