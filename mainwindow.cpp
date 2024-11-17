#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_addapartmentdialog.h"
#include "DatabaseManager.h"
#include "ApartmentContainer.h"
#include "addapartmentdialog.h"


#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionEditAp->setEnabled(false);
    ui->actionDelAp->setEnabled(false);

    // Подключаем действие "About" к слоту
    connect(ui->actionAbout, &QAction::triggered, this, &MainWindow::showAbout);
    // Подключаем слот для вызова контекстного меню
    connect(ui->tableWidget, &QTableWidget::customContextMenuRequested,
            this, &MainWindow::showContextMenu);

    connect(ui->actionAddAp, &QAction::triggered, this, &MainWindow::AddAp_action);
    connect(ui->actionEditAp, &QAction::triggered, this, &MainWindow::EditAp_action);
    connect(ui->actionDelAp, &QAction::triggered, this, &MainWindow::DelAp_action);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onTableSelectionChanged);
    connect(ui->actionNewDatabase, &QAction::triggered, this, &MainWindow::NewDatabase_action);
    connect(ui->actionSaveDatabase, &QAction::triggered, this, &MainWindow::SaveDatabase_action);
    connect(ui->actionSaveAsDatabase, &QAction::triggered, this, &::MainWindow::SaveAsDatabase_action);
    connect(ui->actionLoadDatabase, &QAction::triggered, this, &MainWindow::LoadDatabase_action);
    connect(ui->actionMergeDatabase, &QAction::triggered, this, &MainWindow::MergeDatabase_action);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::Exit_action);
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

// Слот для редактирования выбранной квартиры
void MainWindow::EditAp_action() {
    int selectedIndex = getSelectedRowIndex();
    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите строку для редактирования");
        return;
    }

    // Получаем данные о выбранной квартире
    Apartment* selectedApartment = apartmentContainer.getApartment(selectedIndex);

    // Открываем диалоговое окно для редактирования
    AddApartmentDialog editDialog(this);
    editDialog.setWindowTitle("Редактировать квартиру");

    // Заполняем диалог существующими данными
    editDialog.ui->lineEditFloor->setText(QString::number(selectedApartment->getFloor()));
    editDialog.ui->lineEditRooms->setText(QString::number(selectedApartment->getRooms()));
    editDialog.ui->lineEditArea->setText(QString::number(selectedApartment->getArea()));
    editDialog.ui->checkBoxRenovation->setChecked(selectedApartment->hasRenovation());
    editDialog.ui->checkBoxBalcony->setChecked(selectedApartment->hasBalcony());
    editDialog.ui->lineEditPrice->setText(QString::number(selectedApartment->getPrice()));

    // Если пользователь нажал "ОК", обновляем данные
    if (editDialog.exec() == QDialog::Accepted) {
        Apartment updatedApartment = editDialog.getApartmentData();
        if (apartmentContainer.editApartment(selectedIndex, updatedApartment)) {
            updateTable(); // Обновляем таблицу после изменения
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось обновить данные квартиры");
        }
    }
}
void MainWindow::DelAp_action() {
    // Получаем индекс выбранной строки
    int selectedIndex = getSelectedRowIndex();
    if (selectedIndex == -1) {
        QMessageBox::warning(this, "Ошибка", "Выберите строку для удаления");
        return;
    }

    // Подтверждение удаления
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение удаления",
                                  "Вы уверены, что хотите удалить выбранную квартиру?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Удаляем квартиру из контейнера
        apartmentContainer.removeApartment(selectedIndex);
        updateTable(); // Обновляем таблицу после удаления
    }
}

void MainWindow::AddAp_action() {
    // Открытие диалогового окна для добавления квартиры
    AddApartmentDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        // Проверка корректности введённых данных
        if (dialog.isDataValid()) {
            Apartment newApartment = dialog.getApartmentData();

            // Добавляем новую квартиру в контейнер
            apartmentContainer.addApartment(newApartment);

            // Обновляем таблицу
            addApartmentToTable(newApartment);
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректные данные. Пожалуйста, заполните все поля.");
        }
    }
}

void MainWindow::updateTable() {
    // Очистить таблицу перед обновлением
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(apartmentContainer.size());

    // Заполняем таблицу данными из контейнера
    for (int i = 0; i < apartmentContainer.size(); ++i) {
        const Apartment* apartment = apartmentContainer.getApartment(i);

        // Заполняем каждую ячейку данными из объекта Apartment
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(apartment->getFloor())));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(apartment->getRooms())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(apartment->getArea())));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(apartment->hasRenovation() ? "Да" : "Нет"));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(apartment->hasBalcony() ? "Да" : "Нет"));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(apartment->getPrice(), 'f', 2))); // Стоимость с двумя знаками после запятой
    }
}

// Функция для добавления квартиры в таблицу
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



void MainWindow::NewDatabase_action() {
    QString filename = QFileDialog::getSaveFileName(this, "Создать новую базу данных", "", "Database Files (*.db)");
    if (filename.isEmpty()) { return; }
    else {
        if (dbManager.createNewDatabase(filename.toStdString())) {
            apartmentContainer.clear(); // Очистить текущий контейнер
            currentDatabaseFile = filename;
            QMessageBox::information(this, "Успех", "База данных успешно создана.");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось создать базу данных.");
        }
    }
}

void MainWindow::SaveDatabase_action() {
    // Вызываем функцию сохранить как если текущий файл не выбран
    if (currentDatabaseFile.isEmpty()) {
        SaveAsDatabase_action();
        return;
    }

    // Сохраняем данные в файл
    bool success = dbManager.saveToFile(apartmentContainer, currentDatabaseFile.toStdString());

    // Если данные сохранены, показываем сообщение об успехе
    if (success) {
        QMessageBox::information(this, "Успех", "Данные успешно сохранены.");
    } else {
        // В случае ошибки показываем сообщение об ошибке
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные.");
    }
}

void MainWindow::SaveAsDatabase_action() {
    QString filename = QFileDialog::getSaveFileName(this, "Сохранить базу данных", "", "Database Files (*.db)");
    if (filename.isEmpty()) {
        return; // Если файл не выбран, выходим из функции
    }

    // Сохраняем данные в файл
    bool success = dbManager.saveToFile(apartmentContainer, filename.toStdString());

    // Если данные сохранены, показываем сообщение об успехе
    if (success) {
        currentDatabaseFile = filename; // Обновляем путь
        QMessageBox::information(this, "Успех", "Данные успешно сохранены.");
    } else {
        // В случае ошибки показываем сообщение об ошибке
        QMessageBox::critical(this, "Ошибка", "Не удалось сохранить данные.");
    }
}


void MainWindow::LoadDatabase_action() {
    QString filename = QFileDialog::getOpenFileName(this, "Загрузить базу данных", "", "Database Files (*.db)");
    // Если файл не был выбран, выходим
    if (filename.isEmpty()) {
        return;
    }
    currentDatabaseFile = filename;

    // Попытка загрузить данные из файла
    bool success = dbManager.loadFromFile(apartmentContainer, currentDatabaseFile.toStdString());
    // Отображаем информацию о результате загрузки
    if (success) {
        QMessageBox::information(this, "Успех", "Данные успешно загружены.");
        updateTable(); // Обновляем отображение таблицы
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось загрузить данные.");
    }
}

void MainWindow::MergeDatabase_action() {
    // Откроем диалог для выбора второго файла базы данных
    QString filename = QFileDialog::getOpenFileName(this, "Загрузить вторую базу данных для объединения с текущей", "", "Database Files (*.db)");
    if (filename.isEmpty()) {
        return; // Если файл не выбран, выходим
    }

    // Попытка загрузить данные из второго файла
    ApartmentContainer secondContainer;
    bool success = dbManager.loadFromFile(secondContainer, filename.toStdString());
    if (success) {
        // Объединение контейнеров
        dbManager.mergeContainers(apartmentContainer, secondContainer);
        QMessageBox::information(this, "Успех", "Базы данных успешно объединены.");
        updateTable(); // Обновляем отображение таблицы
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось загрузить вторую базу данных.");
    }
}

void MainWindow::Exit_action() {
    SaveDatabase_action();
    // Завершаем приложение
    QApplication::quit();
}


void MainWindow::showContextMenu(const QPoint &pos)
{
    // Создаём контекстное меню
    QMenu contextMenu(this);

    // Добавляем действия из ui
    contextMenu.addAction(ui->actionAddAp);
    contextMenu.addAction(ui->actionEditAp);
    contextMenu.addAction(ui->actionDelAp);

    // Отображаем меню в позиции курсора относительно tableWidget
    contextMenu.exec(ui->tableWidget->mapToGlobal(pos));
}

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

    // Установка иконки
    aboutBox.setWindowIcon(QIcon(":/icons/icons/about_negate.png"));

    // Отображение окна
    aboutBox.exec();
}

