/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
    QHBoxLayout *horizontalLayout_2;
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
    QVBoxLayout *verticalLayout_3;
    QLabel *informationLabel;
    QPushButton *colorButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1212, 859);
        horizontalLayout_2 = new QHBoxLayout(Widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        ImageShowStack = new QStackedWidget(Widget);
        ImageShowStack->setObjectName("ImageShowStack");
        ImageShowStack->setMinimumSize(QSize(800, 800));
        ImageShowStack->setMaximumSize(QSize(800, 800));
        page = new QWidget();
        page->setObjectName("page");
        ImageShowStack->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        ImageShowStack->addWidget(page_2);

        verticalLayout_2->addWidget(ImageShowStack);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        seasonLabel = new QLabel(Widget);
        seasonLabel->setObjectName("seasonLabel");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        seasonLabel->setFont(font);
        seasonLabel->setFocusPolicy(Qt::NoFocus);
        seasonLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(seasonLabel);

        dial = new QDial(Widget);
        dial->setObjectName("dial");
        dial->setMaximum(3);

        verticalLayout->addWidget(dial);


        horizontalLayout->addLayout(verticalLayout);

        detailsButton = new QPushButton(Widget);
        detailsButton->setObjectName("detailsButton");
        QFont font1;
        font1.setPointSize(14);
        detailsButton->setFont(font1);

        horizontalLayout->addWidget(detailsButton);

        atmosphereButton = new QPushButton(Widget);
        atmosphereButton->setObjectName("atmosphereButton");
        atmosphereButton->setFont(font1);

        horizontalLayout->addWidget(atmosphereButton);

        timeButton = new QPushButton(Widget);
        timeButton->setObjectName("timeButton");
        timeButton->setFont(font1);

        horizontalLayout->addWidget(timeButton);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        informationLabel = new QLabel(Widget);
        informationLabel->setObjectName("informationLabel");
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(25, 25, 112, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        informationLabel->setPalette(palette);
        QFont font2;
        font2.setPointSize(14);
        font2.setStyleStrategy(QFont::PreferAntialias);
        informationLabel->setFont(font2);

        verticalLayout_3->addWidget(informationLabel);

        colorButton = new QPushButton(Widget);
        colorButton->setObjectName("colorButton");
        colorButton->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(colorButton);


        horizontalLayout_2->addLayout(verticalLayout_3);


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
        informationLabel->setText(QCoreApplication::translate("Widget", "\345\275\223\344\275\240\347\202\271\345\207\273\344\270\200\344\270\252\346\230\237\345\272\247\357\274\214\350\277\231\351\207\214\344\274\232\345\207\272\347\216\260\345\256\203\347\232\204\344\273\213\347\273\215\343\200\202", nullptr));
        colorButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
