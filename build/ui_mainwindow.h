/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewDatabase;
    QAction *actionLoadDatabase;
    QAction *actionSaveDatabase;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionAddAp;
    QAction *actionEditAp;
    QAction *actionDelAp;
    QAction *actionMergeDatabase;
    QAction *actionSaveAsDatabase;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuWrite;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 700);
        MainWindow->setMinimumSize(QSize(800, 700));
        MainWindow->setMaximumSize(QSize(800, 700));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/iconApartment.ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionNewDatabase = new QAction(MainWindow);
        actionNewDatabase->setObjectName("actionNewDatabase");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/file_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNewDatabase->setIcon(icon1);
        actionNewDatabase->setAutoRepeat(false);
        actionNewDatabase->setMenuRole(QAction::MenuRole::NoRole);
        actionLoadDatabase = new QAction(MainWindow);
        actionLoadDatabase->setObjectName("actionLoadDatabase");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/open_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionLoadDatabase->setIcon(icon2);
        actionLoadDatabase->setAutoRepeat(false);
        actionLoadDatabase->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveDatabase = new QAction(MainWindow);
        actionSaveDatabase->setObjectName("actionSaveDatabase");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/save_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveDatabase->setIcon(icon3);
        actionSaveDatabase->setAutoRepeat(false);
        actionSaveDatabase->setMenuRole(QAction::MenuRole::NoRole);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/exit_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionExit->setIcon(icon4);
        actionExit->setAutoRepeat(false);
        actionExit->setMenuRole(QAction::MenuRole::NoRole);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/help_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionHelp->setIcon(icon5);
        actionHelp->setAutoRepeat(false);
        actionHelp->setMenuRole(QAction::MenuRole::NoRole);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/about_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAbout->setIcon(icon6);
        actionAbout->setAutoRepeat(false);
        actionAbout->setMenuRole(QAction::MenuRole::NoRole);
        actionAddAp = new QAction(MainWindow);
        actionAddAp->setObjectName("actionAddAp");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/add_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionAddAp->setIcon(icon7);
        actionAddAp->setAutoRepeat(false);
        actionAddAp->setMenuRole(QAction::MenuRole::NoRole);
        actionEditAp = new QAction(MainWindow);
        actionEditAp->setObjectName("actionEditAp");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/edit_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionEditAp->setIcon(icon8);
        actionEditAp->setAutoRepeat(false);
        actionEditAp->setMenuRole(QAction::MenuRole::NoRole);
        actionDelAp = new QAction(MainWindow);
        actionDelAp->setObjectName("actionDelAp");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/delete_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionDelAp->setIcon(icon9);
        actionDelAp->setAutoRepeat(false);
        actionDelAp->setMenuRole(QAction::MenuRole::NoRole);
        actionMergeDatabase = new QAction(MainWindow);
        actionMergeDatabase->setObjectName("actionMergeDatabase");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/merge_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionMergeDatabase->setIcon(icon10);
        actionMergeDatabase->setAutoRepeat(false);
        actionMergeDatabase->setMenuRole(QAction::MenuRole::NoRole);
        actionSaveAsDatabase = new QAction(MainWindow);
        actionSaveAsDatabase->setObjectName("actionSaveAsDatabase");
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/save_as_negate.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionSaveAsDatabase->setIcon(icon11);
        actionSaveAsDatabase->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 180, 761, 411));
        tableWidget->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setShowGrid(true);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->horizontalHeader()->setVisible(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setMinimumSectionSize(125);
        tableWidget->horizontalHeader()->setDefaultSectionSize(127);
        tableWidget->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        tableWidget->horizontalHeader()->setStretchLastSection(false);
        tableWidget->verticalHeader()->setCascadingSectionResizes(false);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuBar->setNativeMenuBar(true);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName("menuFile");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        menuWrite = new QMenu(menuBar);
        menuWrite->setObjectName("menuWrite");
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setEnabled(true);
        toolBar->setIconSize(QSize(36, 36));
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuWrite->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewDatabase);
        menuFile->addAction(actionLoadDatabase);
        menuFile->addAction(actionSaveDatabase);
        menuFile->addAction(actionSaveAsDatabase);
        menuFile->addAction(actionMergeDatabase);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);
        menuWrite->addAction(actionAddAp);
        menuWrite->addAction(actionEditAp);
        menuWrite->addAction(actionDelAp);
        toolBar->addAction(actionNewDatabase);
        toolBar->addAction(actionLoadDatabase);
        toolBar->addAction(actionSaveDatabase);
        toolBar->addAction(actionSaveAsDatabase);
        toolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ApartmentManager", nullptr));
        actionNewDatabase->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\204\320\260\320\271\320\273", nullptr));
#if QT_CONFIG(tooltip)
        actionNewDatabase->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLoadDatabase->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        actionLoadDatabase->setToolTip(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSaveDatabase->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(tooltip)
        actionSaveDatabase->setToolTip(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205 \320\262 \321\204\320\260\320\271\320\273", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264 \320\270\320\267 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_CONFIG(tooltip)
        actionHelp->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        actionAddAp->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        actionEditAp->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        actionDelAp->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        actionMergeDatabase->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\264\320\270\320\275\320\265\320\275\320\270\320\265 \320\221\320\224", nullptr));
        actionSaveAsDatabase->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\272\320\276\320\274\320\275\320\260\321\202", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 (\320\274\302\262)", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\276\321\202\320\264\320\265\320\273\320\272\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\261\320\260\320\273\320\272\320\276\320\275\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 (\342\202\275)", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        menuWrite->setTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
