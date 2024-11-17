/********************************************************************************
** Form generated from reading UI file 'addapartmentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDAPARTMENTDIALOG_H
#define UI_ADDAPARTMENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddApartmentDialog
{
public:
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEditFloor;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEditRooms;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditArea;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QCheckBox *checkBoxRenovation;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QCheckBox *checkBoxBalcony;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *lineEditPrice;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_add;

    void setupUi(QWidget *AddApartmentDialog)
    {
        if (AddApartmentDialog->objectName().isEmpty())
            AddApartmentDialog->setObjectName("AddApartmentDialog");
        AddApartmentDialog->resize(372, 431);
        label = new QLabel(AddApartmentDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 371, 41));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(AddApartmentDialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 50, 371, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(140, 0));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        lineEditFloor = new QLineEdit(verticalLayoutWidget);
        lineEditFloor->setObjectName("lineEditFloor");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditFloor->sizePolicy().hasHeightForWidth());
        lineEditFloor->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(lineEditFloor);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(135, 0));
        label_3->setFont(font1);

        horizontalLayout_3->addWidget(label_3);

        lineEditRooms = new QLineEdit(verticalLayoutWidget);
        lineEditRooms->setObjectName("lineEditRooms");
        sizePolicy1.setHeightForWidth(lineEditRooms->sizePolicy().hasHeightForWidth());
        lineEditRooms->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEditRooms);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName("label_4");
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(140, 0));
        label_4->setFont(font1);

        horizontalLayout_4->addWidget(label_4);

        lineEditArea = new QLineEdit(verticalLayoutWidget);
        lineEditArea->setObjectName("lineEditArea");
        sizePolicy1.setHeightForWidth(lineEditArea->sizePolicy().hasHeightForWidth());
        lineEditArea->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(lineEditArea);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName("label_7");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMinimumSize(QSize(187, 0));
        label_7->setFont(font1);

        horizontalLayout_7->addWidget(label_7, 0, Qt::AlignmentFlag::AlignHCenter);

        checkBoxRenovation = new QCheckBox(verticalLayoutWidget);
        checkBoxRenovation->setObjectName("checkBoxRenovation");
        sizePolicy1.setHeightForWidth(checkBoxRenovation->sizePolicy().hasHeightForWidth());
        checkBoxRenovation->setSizePolicy(sizePolicy1);
        checkBoxRenovation->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(checkBoxRenovation);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName("label_9");
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMinimumSize(QSize(187, 0));
        label_9->setFont(font1);

        horizontalLayout_9->addWidget(label_9, 0, Qt::AlignmentFlag::AlignHCenter);

        checkBoxBalcony = new QCheckBox(verticalLayoutWidget);
        checkBoxBalcony->setObjectName("checkBoxBalcony");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkBoxBalcony->sizePolicy().hasHeightForWidth());
        checkBoxBalcony->setSizePolicy(sizePolicy3);
        checkBoxBalcony->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_9->addWidget(checkBoxBalcony);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName("label_5");
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setMinimumSize(QSize(145, 0));
        label_5->setFont(font1);

        horizontalLayout_5->addWidget(label_5);

        lineEditPrice = new QLineEdit(verticalLayoutWidget);
        lineEditPrice->setObjectName("lineEditPrice");
        sizePolicy1.setHeightForWidth(lineEditPrice->sizePolicy().hasHeightForWidth());
        lineEditPrice->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEditPrice);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayoutWidget = new QWidget(AddApartmentDialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(200, 390, 168, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_cancel = new QPushButton(horizontalLayoutWidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_add = new QPushButton(horizontalLayoutWidget);
        pushButton_add->setObjectName("pushButton_add");

        horizontalLayout->addWidget(pushButton_add);


        retranslateUi(AddApartmentDialog);

        QMetaObject::connectSlotsByName(AddApartmentDialog);
    } // setupUi

    void retranslateUi(QWidget *AddApartmentDialog)
    {
        AddApartmentDialog->setWindowTitle(QCoreApplication::translate("AddApartmentDialog", "Form", nullptr));
        label->setText(QCoreApplication::translate("AddApartmentDialog", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\262\320\260\321\200\321\202\320\270\321\200\321\213", nullptr));
        label_2->setText(QCoreApplication::translate("AddApartmentDialog", "\320\255\321\202\320\260\320\266", nullptr));
        label_3->setText(QCoreApplication::translate("AddApartmentDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\276\320\274\320\275\320\260\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("AddApartmentDialog", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214 (\320\274\302\262)", nullptr));
        label_7->setText(QCoreApplication::translate("AddApartmentDialog", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\276\321\202\320\264\320\265\320\273\320\272\320\270", nullptr));
        checkBoxRenovation->setText(QString());
        label_9->setText(QCoreApplication::translate("AddApartmentDialog", "\320\235\320\260\320\273\320\270\321\207\320\270\320\265 \320\261\320\260\320\273\320\272\320\276\320\275\320\260", nullptr));
        checkBoxBalcony->setText(QString());
        label_5->setText(QCoreApplication::translate("AddApartmentDialog", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214 (\342\202\275)", nullptr));
        pushButton_cancel->setText(QCoreApplication::translate("AddApartmentDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_add->setText(QCoreApplication::translate("AddApartmentDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddApartmentDialog: public Ui_AddApartmentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDAPARTMENTDIALOG_H
