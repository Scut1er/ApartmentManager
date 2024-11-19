#include "ap_actions.h"
#include <QMessageBox>
#include <QFileDialog>
#include "addapartmentdialog.h"
#include "ui_addapartmentdialog.h"
#include "ui_mainwindow.h"

ApActions::ApActions(MainWindow *mainWindow, QObject *parent)
    : QObject(parent), m_mainWindow(mainWindow) {}

void ApActions::connectActions() {
    connect(m_mainWindow->getUi()->actionAddAp, &QAction::triggered, this, &ApActions::AddAp_action);
    connect(m_mainWindow->getUi()->actionEditAp, &QAction::triggered, this, &ApActions::EditAp_action);
    connect(m_mainWindow->getUi()->actionDelAp, &QAction::triggered, this, &ApActions::DelAp_action);
}


void ApActions::AddAp_action() {
    AddApartmentDialog dialog(m_mainWindow);
    if (dialog.exec() == QDialog::Accepted) {
        if (dialog.isDataValid()) {
            Apartment newApartment = dialog.getApartmentData();
            m_mainWindow->getApartmentContainer().addApartment(newApartment);  // Используем геттер
            m_mainWindow->addApartmentToTable(newApartment);
        } else {
            QMessageBox::warning(m_mainWindow, "Ошибка", "Некорректные данные. Пожалуйста, заполните все поля.");
        }
    }
}

void ApActions::EditAp_action() {
    int selectedIndex = m_mainWindow->getSelectedRowIndex();
    if (selectedIndex == -1) {
        QMessageBox::warning(m_mainWindow, "Ошибка", "Выберите строку для редактирования");
        return;
    }

    Apartment* selectedApartment = m_mainWindow->getApartmentContainer().getApartment(selectedIndex);  // Используем геттер
    AddApartmentDialog editDialog(m_mainWindow);
    editDialog.setWindowTitle("Редактировать квартиру");

    editDialog.ui->lineEditFloor->setText(QString::number(selectedApartment->getFloor()));
    editDialog.ui->lineEditRooms->setText(QString::number(selectedApartment->getRooms()));
    editDialog.ui->lineEditArea->setText(QString::number(selectedApartment->getArea()));
    editDialog.ui->checkBoxRenovation->setChecked(selectedApartment->hasRenovation());
    editDialog.ui->checkBoxBalcony->setChecked(selectedApartment->hasBalcony());
    editDialog.ui->lineEditPrice->setText(QString::number(selectedApartment->getPrice()));

    if (editDialog.exec() == QDialog::Accepted) {
        Apartment updatedApartment = editDialog.getApartmentData();
        if (m_mainWindow->getApartmentContainer().editApartment(selectedIndex, updatedApartment)) {  // Используем геттер
            m_mainWindow->updateTable();
        } else {
            QMessageBox::warning(m_mainWindow, "Ошибка", "Не удалось обновить данные квартиры");
        }
    }
}

void ApActions::DelAp_action() {
    int selectedIndex = m_mainWindow->getSelectedRowIndex();
    if (selectedIndex == -1) {
        QMessageBox::warning(m_mainWindow, "Ошибка", "Выберите строку для удаления");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(m_mainWindow, "Подтверждение удаления", "Вы уверены, что хотите удалить выбранную квартиру?", QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        m_mainWindow->getApartmentContainer().removeApartment(selectedIndex);  // Используем геттер
        m_mainWindow->updateTable();
    }
}
