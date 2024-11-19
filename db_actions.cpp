#include "db_actions.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include "DatabaseManager.h"
#include "ApartmentContainer.h"

DbActions::DbActions(MainWindow *mainWindow, QObject *parent)
    : QObject(parent), m_mainWindow(mainWindow) {}

void DbActions::connectActions() {
    connect(m_mainWindow->getUi()->actionNewDatabase, &QAction::triggered, this, &DbActions::NewDatabase_action);
    connect(m_mainWindow->getUi()->actionSaveDatabase, &QAction::triggered, this, &DbActions::SaveDatabase_action);
    connect(m_mainWindow->getUi()->actionSaveAsDatabase, &QAction::triggered, this, &DbActions::SaveAsDatabase_action);
    connect(m_mainWindow->getUi()->actionLoadDatabase, &QAction::triggered, this, &DbActions::LoadDatabase_action);
    connect(m_mainWindow->getUi()->actionMergeDatabase, &QAction::triggered, this, &DbActions::MergeDatabase_action);
}

void DbActions::NewDatabase_action() {
    QString filename = QFileDialog::getSaveFileName(m_mainWindow, "Создать новую базу данных", "", "Database Files (*.db)");
    if (filename.isEmpty()) { return; }

    DatabaseManager dbManager;
    if (dbManager.createNewDatabase(filename.toStdString())) {
        m_mainWindow->getApartmentContainer().clear(); // Очистить текущий контейнер через геттер
        m_mainWindow->setCurrentDatabaseFile(filename); // Используем сеттер для currentDatabaseFile
        QMessageBox::information(m_mainWindow, "Успех", "База данных успешно создана.");
    } else {
        QMessageBox::critical(m_mainWindow, "Ошибка", "Не удалось создать базу данных.");
    }
}

void DbActions::SaveDatabase_action() {
    if (m_mainWindow->getCurrentDatabaseFile().isEmpty()) {
        SaveAsDatabase_action();
        return;
    }

    DatabaseManager dbManager;
    bool success = dbManager.saveToFile(m_mainWindow->getApartmentContainer(), m_mainWindow->getCurrentDatabaseFile().toStdString());
    if (success) {
        QMessageBox::information(m_mainWindow, "Успех", "Данные успешно сохранены.");
    } else {
        QMessageBox::critical(m_mainWindow, "Ошибка", "Не удалось сохранить данные.");
    }
}

void DbActions::SaveAsDatabase_action() {
    QString filename = QFileDialog::getSaveFileName(m_mainWindow, "Сохранить базу данных", "", "Database Files (*.db)");
    if (filename.isEmpty()) { return; }

    DatabaseManager dbManager;
    bool success = dbManager.saveToFile(m_mainWindow->getApartmentContainer(), filename.toStdString());
    if (success) {
        m_mainWindow->setCurrentDatabaseFile(filename); // Используем сеттер для currentDatabaseFile
        QMessageBox::information(m_mainWindow, "Успех", "Данные успешно сохранены.");
    } else {
        QMessageBox::critical(m_mainWindow, "Ошибка", "Не удалось сохранить данные.");
    }
}

void DbActions::LoadDatabase_action() {
    QString filename = QFileDialog::getOpenFileName(m_mainWindow, "Загрузить базу данных", "", "Database Files (*.db)");
    if (filename.isEmpty()) { return; }

    DatabaseManager dbManager;
    bool success = dbManager.loadFromFile(m_mainWindow->getApartmentContainer(), filename.toStdString());
    if (success) {
        m_mainWindow->setCurrentDatabaseFile(filename); // Используем сеттер для currentDatabaseFile
        QMessageBox::information(m_mainWindow, "Успех", "Данные успешно загружены.");
        m_mainWindow->updateTable(); // Обновляем отображение таблицы

        // Сохраняем путь к последнему открытому файлу
        QSettings settings("MyCompany", "MyApp");
        settings.setValue("lastOpenedFile", filename);
    } else {
        QMessageBox::critical(m_mainWindow, "Ошибка", "Не удалось загрузить данные.");
    }
}

void DbActions::MergeDatabase_action() {
    QString filename = QFileDialog::getOpenFileName(m_mainWindow, "Загрузить вторую базу данных для объединения с текущей", "", "Database Files (*.db)");
    if (filename.isEmpty()) { return; }

    DatabaseManager dbManager;
    ApartmentContainer secondContainer;
    bool success = dbManager.loadFromFile(secondContainer, filename.toStdString());
    if (success) {
        dbManager.mergeContainers(m_mainWindow->getApartmentContainer(), secondContainer);
        QMessageBox::information(m_mainWindow, "Успех", "Базы данных успешно объединены.");
        m_mainWindow->updateTable(); // Обновляем отображение таблицы
    } else {
        QMessageBox::critical(m_mainWindow, "Ошибка", "Не удалось загрузить вторую базу данных.");
    }
}
