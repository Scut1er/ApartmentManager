#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include "Apartment.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AddApartmentDialog;
}
QT_END_NAMESPACE

class AddApartmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddApartmentDialog(QWidget *parent = nullptr);
    ~AddApartmentDialog();

    // Метод для получения данных из диалогового окна
    Apartment getApartmentData() const;
    bool isDataValid() const;
    Ui::AddApartmentDialog *ui;

private slots:
    void validateInput();  // Слот для проверки корректности введенных данных

private:
    bool validData;  // Переменная для хранения состояния валидности данных
};

#endif // ADD_H
