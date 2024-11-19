#ifndef DBACTIONS_H
#define DBACTIONS_H

#include <QObject>
#include "mainwindow.h"

class DbActions : public QObject
{
    Q_OBJECT

public:
    explicit DbActions(MainWindow *mainWindow, QObject *parent = nullptr);
    void connectActions();

public slots:
    void NewDatabase_action();
    void SaveDatabase_action();
    void SaveAsDatabase_action();
    void LoadDatabase_action();
    void MergeDatabase_action();

private:
    MainWindow *m_mainWindow;  // Указатель на MainWindow
};

#endif // DBACTIONS_H
