/********************************************************************************
** Form generated from reading UI file 'studentdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTDIALOG_H
#define UI_STUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBoxOrder;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBoxBy;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonSort;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonQueryAll;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLabel *label_2;
    QLineEdit *lineEdit_NAME;
    QLabel *label_3;
    QLineEdit *lineEdit_SCORE;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_INSERT;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_DELETE;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_UPDATE;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_SEARCH;

    void setupUi(QDialog *StudentDialog)
    {
        if (StudentDialog->objectName().isEmpty())
            StudentDialog->setObjectName(QString::fromUtf8("StudentDialog"));
        StudentDialog->resize(580, 370);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/C:/Users/hongz/Pictures/4171306_day_flower_gift_love_valentine_icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        StudentDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(StudentDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 561, 351));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        comboBoxOrder = new QComboBox(layoutWidget);
        comboBoxOrder->addItem(QString());
        comboBoxOrder->addItem(QString());
        comboBoxOrder->setObjectName(QString::fromUtf8("comboBoxOrder"));

        horizontalLayout->addWidget(comboBoxOrder);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBoxBy = new QComboBox(layoutWidget);
        comboBoxBy->addItem(QString());
        comboBoxBy->addItem(QString());
        comboBoxBy->addItem(QString());
        comboBoxBy->setObjectName(QString::fromUtf8("comboBoxBy"));

        horizontalLayout->addWidget(comboBoxBy);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButtonSort = new QPushButton(layoutWidget);
        pushButtonSort->setObjectName(QString::fromUtf8("pushButtonSort"));

        horizontalLayout->addWidget(pushButtonSort);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButtonQueryAll = new QPushButton(layoutWidget);
        pushButtonQueryAll->setObjectName(QString::fromUtf8("pushButtonQueryAll"));

        horizontalLayout->addWidget(pushButtonQueryAll);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit_ID = new QLineEdit(layoutWidget);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        horizontalLayout_2->addWidget(lineEdit_ID);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_NAME = new QLineEdit(layoutWidget);
        lineEdit_NAME->setObjectName(QString::fromUtf8("lineEdit_NAME"));

        horizontalLayout_2->addWidget(lineEdit_NAME);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_SCORE = new QLineEdit(layoutWidget);
        lineEdit_SCORE->setObjectName(QString::fromUtf8("lineEdit_SCORE"));

        horizontalLayout_2->addWidget(lineEdit_SCORE);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_INSERT = new QPushButton(layoutWidget);
        pushButton_INSERT->setObjectName(QString::fromUtf8("pushButton_INSERT"));

        horizontalLayout_3->addWidget(pushButton_INSERT);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_DELETE = new QPushButton(layoutWidget);
        pushButton_DELETE->setObjectName(QString::fromUtf8("pushButton_DELETE"));

        horizontalLayout_3->addWidget(pushButton_DELETE);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        pushButton_UPDATE = new QPushButton(layoutWidget);
        pushButton_UPDATE->setObjectName(QString::fromUtf8("pushButton_UPDATE"));

        horizontalLayout_3->addWidget(pushButton_UPDATE);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButton_SEARCH = new QPushButton(layoutWidget);
        pushButton_SEARCH->setObjectName(QString::fromUtf8("pushButton_SEARCH"));

        horizontalLayout_3->addWidget(pushButton_SEARCH);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(StudentDialog);

        QMetaObject::connectSlotsByName(StudentDialog);
    } // setupUi

    void retranslateUi(QDialog *StudentDialog)
    {
        StudentDialog->setWindowTitle(QCoreApplication::translate("StudentDialog", "\345\255\246\347\224\237\347\256\241\347\220\206\347\263\273\347\273\237 v1.0", nullptr));
        comboBoxOrder->setItemText(0, QCoreApplication::translate("StudentDialog", "\346\255\243\345\272\217", nullptr));
        comboBoxOrder->setItemText(1, QCoreApplication::translate("StudentDialog", "\345\200\222\345\272\217", nullptr));

        comboBoxBy->setItemText(0, QCoreApplication::translate("StudentDialog", "\346\214\211\345\255\246\345\217\267", nullptr));
        comboBoxBy->setItemText(1, QCoreApplication::translate("StudentDialog", "\346\214\211\346\210\220\347\273\251", nullptr));
        comboBoxBy->setItemText(2, QCoreApplication::translate("StudentDialog", "\346\214\211\345\247\223\345\220\215", nullptr));

        pushButtonSort->setText(QCoreApplication::translate("StudentDialog", "\346\225\260\346\215\256\346\216\222\345\272\217", nullptr));
        pushButtonQueryAll->setText(QCoreApplication::translate("StudentDialog", "\346\237\245\350\257\242\345\205\250\351\203\250", nullptr));
        label->setText(QCoreApplication::translate("StudentDialog", "\345\255\246 \345\217\267:", nullptr));
        label_2->setText(QCoreApplication::translate("StudentDialog", "\345\247\223 \345\220\215:", nullptr));
        label_3->setText(QCoreApplication::translate("StudentDialog", "\346\210\220 \347\273\251:", nullptr));
        pushButton_INSERT->setText(QCoreApplication::translate("StudentDialog", "\346\217\222\345\205\245\346\225\260\346\215\256", nullptr));
        pushButton_DELETE->setText(QCoreApplication::translate("StudentDialog", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        pushButton_UPDATE->setText(QCoreApplication::translate("StudentDialog", "\346\233\264\346\226\260\346\225\260\346\215\256", nullptr));
        pushButton_SEARCH->setText(QCoreApplication::translate("StudentDialog", "\346\237\245\350\257\242\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentDialog: public Ui_StudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTDIALOG_H
