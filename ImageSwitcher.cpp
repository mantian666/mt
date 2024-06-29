#include "ImageSwitcher.h"
#include "ClickableLabel.h"
#include <QParallelAnimationGroup>
#include <map>
#include <QDir>
#include <QDebug>
ImageSwitcher::ImageSwitcher(QWidget *parent,QStackedWidget* UIstack)
    : QWidget(parent), currentIndex(0) {
    stackedWidget = UIstack;

    //增添
    // 初始化星座名称和矩形区域
    constellationRegions = {
            {"双子座", QRect(104, 46, 60, 30)},
            {"大熊座", QRect(731, 13, 60, 30)},
            {"御夫座", QRect(55, 41, 60, 30)},
            {"英仙座", QRect(183, 107, 60, 30)},
            {"鹿豹座", QRect(407, 109, 60, 30)},
            {"仙后座", QRect(176, 32, 60, 30)},
            {"仙女座", QRect(135, 155, 60, 30)},
            {"小熊座", QRect(801, 41, 60, 30)},
            {"天龙座", QRect(768, 66, 60, 30)},
            {"武仙座", QRect(723, 159, 60, 30)},
            {"天琴座", QRect(764, 227, 60, 30)},
            {"天鹅座", QRect(587, 191, 60, 30)},
            {"狐狸座", QRect(664, 247, 60, 30)},
            {"天箭座", QRect(701, 257, 60, 30)},
            {"海豚座", QRect(762, 283, 60, 30)},
            {"鹰夫座", QRect(696, 306, 60, 30)},
            {"天马座", QRect(302, 254, 60, 30)},
            {"宝瓶座", QRect(408, 324, 60, 30)},
            {"双鱼座", QRect(457, 221, 60, 30)},
            {"鲸鱼座", QRect(245, 349, 60, 30)},
            {"摩羯座", QRect(422, 435, 60, 30)},
            {"玉夫座", QRect(548, 450, 60, 30)},
            {"南鱼座", QRect(369, 486, 60, 30)},
            {"凤凰座", QRect(23, 501, 60, 30)},
            {"天鹤座", QRect(65, 566, 60, 30)},
            {"鹈鹕座", QRect(535, 516, 60, 30)},
            {"孔雀座", QRect(476, 610, 60, 30)},
            {"南极座", QRect(571, 672, 60, 30)},
            {"矩尺座", QRect(679, 668, 60, 30)},
            {"雕具座", QRect(764, 673, 60, 30)},
            {"半人马座", QRect(851, 648, 60, 30)},
            {"船尾座", QRect(935, 662, 60, 30)},
            {"罗盘座", QRect(1041, 668, 60, 30)},
            {"南船座", QRect(1152, 661, 60, 30)},
            {"豺狼座", QRect(1258, 657, 60, 30)},
            {"蛇尾座", QRect(1325, 597, 60, 30)},
            {"苍蝇座", QRect(1396, 532, 60, 30)},
            {"南十字座", QRect(1415, 488, 60, 30)},
            {"昆虫座", QRect(1465, 448, 60, 30)},
            {"网罟座", QRect(1518, 404, 60, 30)},
            {"飞鱼座", QRect(1555, 361, 60, 30)},
            {"船帆座", QRect(1556, 287, 60, 30)},
            {"南极洲", QRect(1623, 218, 60, 30)},
            {"太阳系", QRect(1671, 157, 60, 30)},
            {"南极洲", QRect(1676, 64, 60, 30)},
            {"后发座", QRect(1653, 10, 60, 30)},
            {"狮子座", QRect(1452, 21, 60, 30)},
            {"巨蟹座", QRect(1365, 77, 60, 30)},
            {"小马座", QRect(1341, 176, 60, 30)},
            {"天秤座", QRect(1251, 111, 60, 30)},
            {"巨蛇座", QRect(1164, 151, 60, 30)},
            {"巨蛇座", QRect(1036, 106, 60, 30)},
            {"人马座", QRect(954, 68, 60, 30)},
            {"武仙座", QRect(844, 73, 60, 30)},
            {"天蝎座", QRect(732, 114, 60, 30)},
            {"北冕座", QRect(663, 159, 60, 30)},
            {"巨蛇座", QRect(598, 200, 60, 30)},
            {"武仙座", QRect(502, 168, 60, 30)},
            {"天琴座", QRect(388, 211, 60, 30)},
            {"狐狸座", QRect(285, 272, 60, 30)},
            {"天箭座", QRect(220, 291, 60, 30)},
            {"天马座", QRect(191, 368, 60, 30)},
            {"宝瓶座", QRect(182, 439, 60, 30)},
            {"人马座", QRect(215, 507, 60, 30)},
            {"北冕座", QRect(277, 517, 60, 30)},
            {"南十字座", QRect(353, 537, 60, 30)},
            {"天龙座", QRect(419, 536, 60, 30)},
            {"半人马座", QRect(509, 515, 60, 30)},
            {"船尾座", QRect(583, 532, 60, 30)},
            {"罗盘座", QRect(662, 561, 60, 30)},
            {"南船座", QRect(715, 546, 60, 30)},
            {"天兔座", QRect(813, 557, 60, 30)},
            {"小马座", QRect(886, 541, 60, 30)},
            {"蛇夫座", QRect(986, 570, 60, 30)},
            {"天琴座", QRect(1065, 590, 60, 30)},
            {"南十字座", QRect(1144, 570, 60, 30)},
            {"网罟座", QRect(1245, 556, 60, 30)},
            {"飞鱼座", QRect(1315, 541, 60, 30)},
            {"半人马座", QRect(1403, 554, 60, 30)},
            {"船尾座", QRect(1510, 571, 60, 30)},
            {"巨蛇座", QRect(1585, 554, 60, 30)},
            {"南极洲", QRect(1653, 519, 60, 30)},
            {"后发座", QRect(1715, 482, 60, 30)},
            {"太阳系", QRect(1781, 463, 60, 30)},
            {"南极洲", QRect(1841, 414, 60, 30)},
            {"天鹰座", QRect(1913, 371, 60, 30)},
            {"仙女座", QRect(1981, 328, 60, 30)},
            {"南冕座", QRect(2037, 274, 60, 30)},
            {"凤凰座", QRect(2081, 213, 60, 30)},
            {"天鹤座", QRect(2147, 183, 60, 30)},
            {"巨蛇座", QRect(2216, 116, 60, 30)},
            {"孔雀座", QRect(2278, 54, 60, 30)}
        };
}

void ImageSwitcher::initializeImages(const QVector<QString> &imagePaths) {
    int num = 0;
    for (const QString &path : imagePaths) {
        // 修改，使支持点击（ClickableLabel继承自QLabel）
        ClickableLabel *label = new ClickableLabel;
        QPixmap pix(path);
        //qDebug()<<stackedWidget->size();
        pix = pix.scaled(stackedWidget->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
        label->setPixmap(pix);
        label->setScaledContents(true);
        stackedWidget->addWidget(label);
        labels.append(label);
        maploader[path] = num;
        num++;
        // 连接信号和槽
        connect(label, &ClickableLabel::clicked, this, &ImageSwitcher::handleLabelClicked);
    }
    stackedWidget->setCurrentWidget(labels[maploader["D:\\桌面\\CroppedStarPics\\0401-1000-atmosphere.png"]]);
}

void ImageSwitcher::handleLabelClicked(const QPoint &pos) {
    // 0 <= pos.first , pos.second <= 800
    //其中800为窗口的大小
    //目的：将0~800的数字转换到0~1750
    qDebug() << "Pressed on" << pos;
    int length = 800; //图像窗口的大小
    double percentage = 1750.0 / double(length);
    emit constellationClicked(int(pos.x() * percentage), int(pos.y() * percentage));

}

void ImageSwitcher::switchToNextImage() {
    if (labels.isEmpty()) return;

    int nextIndex = (currentIndex + 1) % labels.size();
    //QLabel *currentLabel = labels[currentIndex];
    QLabel *nextLabel = labels[nextIndex];


    /*
    QPropertyAnimation *fadeOut = createFadeAnimation(currentLabel, 0.0, 0.0, 1000);
    QPropertyAnimation *fadeIn = createFadeAnimation(nextLabel, 0.0, 0.0, 1000);

    // 创建并行动画组
    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup(this);


    animationGroup->addAnimation(fadeOut);
    animationGroup->addAnimation(fadeIn);

    // 设置动画结束后的信号槽连接
    connect(animationGroup, &QParallelAnimationGroup::finished, this, [=]() {
        stackedWidget->setCurrentWidget(nextLabel);
        qDebug()<<"1";
        nextLabel->setWindowOpacity(0.0); // 重置下一张图片的透明度
        currentIndex = nextIndex;
    });

    // 启动并行动画组
    animationGroup->start();
    */
    stackedWidget->setCurrentWidget(nextLabel);
    qDebug()<<"state change: "<<currentIndex<<" -> "<<nextIndex;
    currentIndex = nextIndex;


}


void ImageSwitcher::switchToAppointedImage(QString str)
{
    if (labels.isEmpty()) return;

    int nextIndex = maploader[str];
    //QLabel *currentLabel = labels[currentIndex];
    QLabel *nextLabel = labels[nextIndex];

    stackedWidget->setCurrentWidget(nextLabel);
    qDebug()<<"state change: "<<currentIndex<<" -> "<<nextIndex;
    currentIndex = nextIndex;
}


QPropertyAnimation* ImageSwitcher::createFadeAnimation(QWidget *widget, qreal startValue, qreal endValue, int duration) {
    QPropertyAnimation *animation = new QPropertyAnimation(widget, "windowOpacity");
    animation->setDuration(duration);
    animation->setStartValue(startValue);
    animation->setEndValue(endValue);
    return animation;
}

void ImageSwitcher::onFadeOutFinished() {
    labels[currentIndex]->setWindowOpacity(1.0);
    currentIndex = (currentIndex + 1) % labels.size();
    stackedWidget->setCurrentIndex(currentIndex);
}


