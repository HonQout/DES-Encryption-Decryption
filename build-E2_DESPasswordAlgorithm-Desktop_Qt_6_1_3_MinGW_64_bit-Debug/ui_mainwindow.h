/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *B3;
    QPushButton *B4;
    QGroupBox *TextC;
    QLabel *L1;
    QTextEdit *TE1;
    QLabel *L2;
    QComboBox *CB1;
    QLabel *L3;
    QTextEdit *TE2;
    QLabel *L4;
    QTextEdit *TE3;
    QGroupBox *FileC;
    QPushButton *B1;
    QLabel *L5;
    QTextBrowser *TB1;
    QTextBrowser *TB2;
    QPushButton *B2;
    QLabel *L5_2;
    QComboBox *CB2;
    QLabel *L7;
    QLabel *L8;
    QLabel *L9;
    QLabel *L10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(540, 560);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        B3 = new QPushButton(centralwidget);
        B3->setObjectName(QString::fromUtf8("B3"));
        B3->setGeometry(QRect(140, 510, 60, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\256\213\344\275\223")});
        font.setPointSize(10);
        B3->setFont(font);
        B4 = new QPushButton(centralwidget);
        B4->setObjectName(QString::fromUtf8("B4"));
        B4->setGeometry(QRect(340, 510, 60, 30));
        B4->setFont(font);
        TextC = new QGroupBox(centralwidget);
        TextC->setObjectName(QString::fromUtf8("TextC"));
        TextC->setGeometry(QRect(20, 60, 500, 330));
        TextC->setFont(font);
        L1 = new QLabel(TextC);
        L1->setObjectName(QString::fromUtf8("L1"));
        L1->setGeometry(QRect(10, 20, 40, 25));
        L1->setFont(font);
        TE1 = new QTextEdit(TextC);
        TE1->setObjectName(QString::fromUtf8("TE1"));
        TE1->setGeometry(QRect(10, 45, 480, 100));
        TE1->setFont(font);
        L2 = new QLabel(TextC);
        L2->setObjectName(QString::fromUtf8("L2"));
        L2->setGeometry(QRect(10, 160, 70, 25));
        L2->setFont(font);
        CB1 = new QComboBox(TextC);
        CB1->addItem(QString());
        CB1->addItem(QString());
        CB1->setObjectName(QString::fromUtf8("CB1"));
        CB1->setGeometry(QRect(80, 160, 70, 25));
        CB1->setFont(font);
        L3 = new QLabel(TextC);
        L3->setObjectName(QString::fromUtf8("L3"));
        L3->setGeometry(QRect(250, 160, 40, 25));
        L3->setFont(font);
        TE2 = new QTextEdit(TextC);
        TE2->setObjectName(QString::fromUtf8("TE2"));
        TE2->setGeometry(QRect(290, 160, 200, 25));
        TE2->setFont(font);
        L4 = new QLabel(TextC);
        L4->setObjectName(QString::fromUtf8("L4"));
        L4->setGeometry(QRect(10, 190, 40, 25));
        L4->setFont(font);
        TE3 = new QTextEdit(TextC);
        TE3->setObjectName(QString::fromUtf8("TE3"));
        TE3->setGeometry(QRect(10, 215, 480, 100));
        TE3->setFont(font);
        FileC = new QGroupBox(centralwidget);
        FileC->setObjectName(QString::fromUtf8("FileC"));
        FileC->setGeometry(QRect(20, 400, 500, 100));
        FileC->setFont(font);
        B1 = new QPushButton(FileC);
        B1->setObjectName(QString::fromUtf8("B1"));
        B1->setGeometry(QRect(410, 20, 80, 25));
        B1->setFont(font);
        L5 = new QLabel(FileC);
        L5->setObjectName(QString::fromUtf8("L5"));
        L5->setGeometry(QRect(10, 20, 70, 25));
        L5->setFont(font);
        TB1 = new QTextBrowser(FileC);
        TB1->setObjectName(QString::fromUtf8("TB1"));
        TB1->setGeometry(QRect(80, 20, 320, 25));
        TB2 = new QTextBrowser(FileC);
        TB2->setObjectName(QString::fromUtf8("TB2"));
        TB2->setGeometry(QRect(80, 55, 320, 25));
        B2 = new QPushButton(FileC);
        B2->setObjectName(QString::fromUtf8("B2"));
        B2->setGeometry(QRect(410, 55, 80, 25));
        B2->setFont(font);
        L5_2 = new QLabel(FileC);
        L5_2->setObjectName(QString::fromUtf8("L5_2"));
        L5_2->setGeometry(QRect(10, 55, 70, 25));
        L5_2->setFont(font);
        CB2 = new QComboBox(centralwidget);
        CB2->addItem(QString());
        CB2->addItem(QString());
        CB2->setObjectName(QString::fromUtf8("CB2"));
        CB2->setGeometry(QRect(90, 20, 80, 25));
        CB2->setFont(font);
        L7 = new QLabel(centralwidget);
        L7->setObjectName(QString::fromUtf8("L7"));
        L7->setGeometry(QRect(20, 20, 70, 25));
        L7->setFont(font);
        L8 = new QLabel(centralwidget);
        L8->setObjectName(QString::fromUtf8("L8"));
        L8->setGeometry(QRect(350, 20, 70, 25));
        L8->setFont(font);
        L9 = new QLabel(centralwidget);
        L9->setObjectName(QString::fromUtf8("L9"));
        L9->setGeometry(QRect(420, 20, 80, 25));
        L9->setFont(font);
        L10 = new QLabel(centralwidget);
        L10->setObjectName(QString::fromUtf8("L10"));
        L10->setGeometry(QRect(500, 20, 20, 25));
        L10->setFont(font);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "E2_DESAlgorithm", nullptr));
        B3->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206", nullptr));
        B4->setText(QCoreApplication::translate("MainWindow", "\350\247\243\345\257\206", nullptr));
        TextC->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\212\240\345\257\206", nullptr));
        L1->setText(QCoreApplication::translate("MainWindow", "\346\230\216\346\226\207\357\274\232", nullptr));
        L2->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206\346\226\271\345\274\217\357\274\232", nullptr));
        CB1->setItemText(0, QCoreApplication::translate("MainWindow", "ECB", nullptr));
        CB1->setItemText(1, QCoreApplication::translate("MainWindow", "CBC", nullptr));

        L3->setText(QCoreApplication::translate("MainWindow", "\345\257\206\351\222\245\357\274\232", nullptr));
        L4->setText(QCoreApplication::translate("MainWindow", "\345\257\206\346\226\207\357\274\232", nullptr));
        FileC->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\212\240\345\257\206", nullptr));
        B1->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        L5->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\357\274\232", nullptr));
        B2->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266\345\244\271", nullptr));
        L5_2->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207\344\275\215\347\275\256\357\274\232", nullptr));
        CB2->setItemText(0, QCoreApplication::translate("MainWindow", "\346\226\207\346\234\254\345\212\240\345\257\206", nullptr));
        CB2->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\345\212\240\345\257\206", nullptr));

        L7->setText(QCoreApplication::translate("MainWindow", "\345\212\240\345\257\206\346\223\215\344\275\234\357\274\232", nullptr));
        L8->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214\346\227\266\351\227\264\357\274\232", nullptr));
        L9->setText(QString());
        L10->setText(QCoreApplication::translate("MainWindow", "\347\247\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
