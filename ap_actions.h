#ifndef APACTIONS_H
#define APACTIONS_H

#include <QObject>
#include "mainwindow.h"

class ApActions : public QObject
{
    Q_OBJECT

public:
    explicit ApActions(MainWindow *mainWindow, QObject *parent = nullptr);
    void connectActions();

    // Слоты для обработки действий с квартирами
public slots:
    void AddAp_action();
    void EditAp_action();
    void DelAp_action();

private:
    MainWindow *m_mainWindow;  // Указатель на MainWindow
};

#endif // APACTIONS_H
