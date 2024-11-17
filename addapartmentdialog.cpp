#include "addapartmentdialog.h"
#include "ui_addapartmentdialog.h"
#include <QMessageBox>

AddApartmentDialog::AddApartmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddApartmentDialog),
    validData(false)
{
    ui->setupUi(this);

    // Подключаем сигналы изменения полей к проверке корректности данных
    connect(ui->lineEditFloor, &QLineEdit::textChanged, this, &AddApartmentDialog::validateInput);
    connect(ui->lineEditRooms, &QLineEdit::textChanged, this, &AddApartmentDialog::validateInput);
    connect(ui->lineEditArea, &QLineEdit::textChanged, this, &AddApartmentDialog::validateInput);
    connect(ui->lineEditPrice, &QLineEdit::textChanged, this, &AddApartmentDialog::validateInput);

    // Подключаем кнопки к соответствующим слотам
    connect(ui->pushButton_add, &QPushButton::clicked, this, &AddApartmentDialog::accept);
    connect(ui->pushButton_cancel, &QPushButton::clicked, this, &AddApartmentDialog::reject);

    // Изначально кнопка "добавить" неактивна, пока данные невалидны
    ui->pushButton_add->setEnabled(false);
}

AddApartmentDialog::~AddApartmentDialog() {
    delete ui;
}

Apartment AddApartmentDialog::getApartmentData() const {
    int floor = ui->lineEditFloor->text().toInt();
    int rooms = ui->lineEditRooms->text().toInt();
    double area = ui->lineEditArea->text().toDouble();
    bool hasRenovation = ui->checkBoxRenovation->isChecked();
    bool hasBalcony = ui->checkBoxBalcony->isChecked();
    double price = ui->lineEditPrice->text().toDouble();

    return Apartment(floor, rooms, area, hasRenovation, hasBalcony, price);
}

bool AddApartmentDialog::isDataValid() const {
    return validData;
}

void AddApartmentDialog::validateInput() {
    // Проверка всех полей на корректность
    bool floorOk = !ui->lineEditFloor->text().isEmpty();
    bool roomsOk = !ui->lineEditRooms->text().isEmpty();
    bool areaOk = !ui->lineEditArea->text().isEmpty();
    bool priceOk = !ui->lineEditPrice->text().isEmpty();

    validData = floorOk && roomsOk && areaOk && priceOk;
    ui->pushButton_add->setEnabled(validData);
}
