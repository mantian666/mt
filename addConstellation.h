#ifndef CONSTELLATION_H
#define CONSTELLATION_H

#include <QString>
#include <QVector>
#include <QPair>

class Constellation { //单个星座的信息
public:
    QString name;
    QString intro;
    QString symbol;
    short stars;
    short best_month;
    int R[4]; // Rectangle: 左上x，左上y，右下x，右下y
    QVector<QPair<int, int>> star_pos;

    Constellation(QString name, QString intro, QString symbol, short stars, short best_month) : //初始化单个星座的信息
        name(name), intro(intro), symbol(symbol), stars(stars), best_month(best_month) {}

    QString getConstellationInfo(const QString comp_name) const; //比对传入的comp_name参数与里面的name是否相同 如果相同就返回星座信息 否则返回空字符串
};

class StarPosition{ //单个星座在某一时间下的位置
public:
    QString name;
    QVector<QPair<int, int>> pos;
    int R[4]; // Rectangle: 左上x，左上y，右下x，右下y
    StarPosition(QString name, QVector<QPair<int, int>> pos);
};

void initializeConstellation(const QString& fileString, QVector<Constellation>& CTS); //从文件地址 fileString 初始化所有星座的信息
void initializePosition(StarPosition pos,QVector<Constellation>& CTS); // 由单个星座在某一时间下的位置 来增补 单个星座的信息 没用
void initializeMonthlyPosition(const QString& fileString, QVector<StarPosition>& STP); //从文件地址 fileString 初始化所有星座在某一时间下的位置
QVector<QString> getInfos(const int x, const int y,
                                      const QVector<StarPosition>& STP, const QVector<Constellation>& CTS); //由x,y坐标得到当前鼠标所点击位置的星座介绍
#endif // CONSTELLATION_H
