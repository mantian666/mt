/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *ImageShowStack;
    QWidget *page;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *seasonLabel;
    QDial *dial;
    QPushButton *detailsButton;
    QPushButton *atmosphereButton;
    QPushButton *timeButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(Widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        ImageShowStack = new QStackedWidget(Widget);
        ImageShowStack->setObjectName(QString::fromUtf8("ImageShowStack"));
        ImageShowStack->setMinimumSize(QSize(800, 800));
        ImageShowStack->setMaximumSize(QSize(1600, 1600));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        ImageShowStack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        ImageShowStack->addWidget(page_2);

        verticalLayout_2->addWidget(ImageShowStack);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        seasonLabel = new QLabel(Widget);
        seasonLabel->setObjectName(QString::fromUtf8("seasonLabel"));

        verticalLayout->addWidget(seasonLabel);

        dial = new QDial(Widget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMaximum(3);

        verticalLayout->addWidget(dial);


        horizontalLayout->addLayout(verticalLayout);

        detailsButton = new QPushButton(Widget);
        detailsButton->setObjectName(QString::fromUtf8("detailsButton"));

        horizontalLayout->addWidget(detailsButton);

        atmosphereButton = new QPushButton(Widget);
        atmosphereButton->setObjectName(QString::fromUtf8("atmosphereButton"));

        horizontalLayout->addWidget(atmosphereButton);

        timeButton = new QPushButton(Widget);
        timeButton->setObjectName(QString::fromUtf8("timeButton"));

        horizontalLayout->addWidget(timeButton);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 7);
        verticalLayout_2->setStretch(1, 1);

        retranslateUi(Widget);

        ImageShowStack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        seasonLabel->setText(QCoreApplication::translate("Widget", "\346\233\264\346\224\271\345\255\243\350\212\202\357\274\210\347\233\256\345\211\215\344\270\272\346\230\245\345\255\243\357\274\211", nullptr));
        detailsButton->setText(QCoreApplication::translate("Widget", "\350\277\236\347\272\277\346\230\276\347\244\272\346\230\237\345\272\247", nullptr));
        atmosphereButton->setText(QCoreApplication::translate("Widget", "\346\212\212\345\244\247\346\260\224\345\261\202\345\205\263\351\227\255", nullptr));
        timeButton->setText(QCoreApplication::translate("Widget", "\345\260\206\346\227\266\351\227\264\350\260\203\345\210\260\346\231\232\344\270\212", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
