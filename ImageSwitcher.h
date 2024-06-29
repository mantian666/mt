#ifndef IMAGESWITCHER_H
#define IMAGESWITCHER_H

#include <QWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QPropertyAnimation>
#include <QVector>
#include <QMap>
#include <QMessageBox>
#include "ClickableLabel.h"

class ImageSwitcher : public QWidget {
    Q_OBJECT

public:
    ImageSwitcher(QWidget *parent = nullptr,QStackedWidget* UIstack = nullptr);

    // 初始化图片
    void initializeImages(const QVector<QString> &imagePaths);

    // 切换到下一张图片，带透明度变化
    void switchToNextImage();

    //切换到指定图片
    void switchToAppointedImage(QString str);


signals:
    void constellationClicked(const int x, const int y);


private:
    QStackedWidget *stackedWidget;
    QVector<QLabel*> labels;
    int currentIndex;
    QMap<QString, int> maploader;
    QMap<QString, QRect> constellationRegions;
    // 创建透明度动画
    QPropertyAnimation* createFadeAnimation(QWidget *widget, qreal startValue, qreal endValue, int duration);

    // 增添：显示星座介绍
    void showConstellationInfo(const QString &constellationName);

private slots:
    // 切换完成后调用的槽函数
    void onFadeOutFinished();
    void handleLabelClicked(const QPoint &pos);
};

#endif // IMAGESWITCHER_H
