#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>
#include <QDebug>
#include <QPushButton>
#include <QVBoxLayout>
#include <QVector>
#include "ImageSwitcher.h"
#include "addConstellation.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_dial_valueChanged(int value);

    void on_atmosphereButton_clicked();

    void on_detailsButton_clicked();

    void on_timeButton_clicked();

    void showConstellationInfo(const int x, const int y);

    void on_colorButton_clicked();

private:
    Ui::Widget *ui;
    int season;//季节
    bool atmosphere;//是否打开大气层
    int details;//显示的详细程度
    int time;//时间
    ImageSwitcher* imageSwitcher;
    QString getPicName();
    QLabel *infoLabel;  // 增添
    QVector<ClickableLabel*> labels;  // 增添
    QString file_place;//文件存放的地址 主要是图片,文字...
    QVector<Constellation> CTS; //星座 狠狠地标记!
    QVector<StarPosition> STP[4]; // 4-7-10-1月的星星位置!
    QString introFilePath;//介绍文档的路径
    QString starposFilePath[4]; //星星位置文档的路径 分别为4月-7月-10月-1月

    int fooTimes; //多按几次details就知道是干什么用的了

    bool isWhite; // 界面的深色/浅色控制
    bool triggeredColorChange; //找到切换颜色的彩蛋了吗?
};
#endif // WIDGET_H
