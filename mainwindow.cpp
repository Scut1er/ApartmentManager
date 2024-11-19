#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ApartmentContainer.h"
#include "Apartment.h"
#include "DatabaseManager.h".h"
#include "ap_actions.h"
#include "db_actions.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QSettings>
#include <QMenu>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionEditAp->setEnabled(false);
    ui->actionDelAp->setEnabled(false);

    ApActions *apActions = new ApActions(this);
    DbActions *dbActions = new DbActions(this);

    // Подключаем действие "About" к слоту
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
    // Подключаем слот для вызова контекстного меню
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested,
            this, &MainWindow::showContextMenu);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onTableSelectionChanged);

    // Подключаем действия для квартир через ApActions
    apActions->connectActions();

    // Подключаем действия для базы данных через DbActions
    dbActions->connectActions();

    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::Exit_action);

    QSettings settings("MyCompany", "MyApp");  // Сохраняем информацию о приложении
    QString lastFilePath = settings.value("lastOpenedFile").toString();

    if (!lastFilePath.isEmpty() || QFile::exists(lastFilePath)) {
        DatabaseManager dbManager;
        dbManager.loadFromFile(apartmentContainer, lastFilePath.toStdString());
        updateTable();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Метод для обновления состояния кнопки при изменении выбора
void MainWindow::onTableSelectionChanged() {
    ui->actionEditAp->setEnabled(ui->tableWidget->selectedItems().count() > 0);
    ui->actionDelAp->setEnabled(ui->tableWidget->selectedItems().count() > 0);
}

// Метод для получения индекса выбранной строки
int MainWindow::getSelectedRowIndex() {
    QList<QTableWidgetItem*> selectedItems = ui->tableWidget->selectedItems();
    if (!selectedItems.isEmpty()) {
        return selectedItems.first()->row();
    }
    return -1;
}

// Метод для обновления таблицы
void MainWindow::updateTable() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(apartmentContainer.size());

    for (int i = 0; i < apartmentContainer.size(); ++i) {
        const Apartment* apartment = apartmentContainer.getApartment(i);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(apartment->getFloor())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(apartment->getRooms())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(apartment->getArea())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(apartment->hasRenovation() ? "Да" : "Нет"));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(apartment->hasBalcony() ? "Да" : "Нет"));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(apartment->getPrice(), 'f', 2))); // Стоимость с двумя знаками после запятой
    }
}

// Метод для добавления квартиры в таблицу
void MainWindow::addApartmentToTable(const Apartment& apartment) {
    int row = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row);

    ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(apartment.getFloor())));
    ui->tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(apartment.getRooms())));
    ui->tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(apartment.getArea())));
    ui->tableWidget->setItem(row, 3, new QTableWidgetItem(apartment.hasRenovation() ? "Да" : "Нет"));
    ui->tableWidget->setItem(row, 4, new QTableWidgetItem(apartment.hasBalcony() ? "Да" : "Нет"));
    ui->tableWidget->setItem(row, 5, new QTableWidgetItem(QString::number(apartment.getPrice())));
}

// Слот для показа контекстного меню
void MainWindow::showContextMenu(const QPoint &pos) {
    QMenu contextMenu(this);
    contextMenu.addAction(ui->actionAddAp);
    contextMenu.addAction(ui->actionEditAp);
    contextMenu.addAction(ui->actionDelAp);
    contextMenu.exec(ui->tableWidget->mapToGlobal(pos));
}

// Слот для показа окна "ABOUT"
void MainWindow::showAbout() {
    QMessageBox aboutBox;
    aboutBox.setWindowTitle("О программе");
    aboutBox.setText(
        "                                              ApartmentManager v1.0\n\n"
        "ApartmentManager — это программа для управления данными о квартирах.\n"
        "\nОсновные возможности:"
        "\n- Создание новой базы данных для хранения данных о квартирах."
        "\n- Загрузка существующей базы данных из файла."
        "\n- Сохранение данных в файл для последующего использования."
        "\n- Поиск квартир по заданным критериям (площадь, количество комнат, наличие отделки и балкона)."
        "\n- Удобный интерфейс для просмотра и редактирования информации."
        "\n\n                                                                     Разработчик: Ляшенко Стефан (ИКПИ-35)"
        );
    aboutBox.setWindowIcon(QIcon(":/icons/icons/about_negate.png"));
    aboutBox.exec();
}

// Слот для выхода из приложения
void MainWindow::Exit_action() {
    DbActions *dbActions = new DbActions(this);
    dbActions->SaveDatabase_action();
    QApplication::quit();
}
