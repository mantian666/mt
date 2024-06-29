#include "addConstellation.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

void initializeConstellation(const QString& fileString, QVector<Constellation>& CTS) {
    QFile file(fileString);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    QString line;
    QString name, intro, symbol;
    short stars = 0, best_month = 0;

    while (!in.atEnd()) {
        line = in.readLine().trimmed();
        if (line.startsWith("name: ")) {
            if (!name.isEmpty()) {
                // 保存上一个星座对象
                CTS.append(Constellation(name, intro.trimmed(), symbol, stars, best_month));
            }
            // 初始化新的星座信息
            name = line.mid(6).trimmed();
            intro = "";
            symbol = "";
            stars = 0;
            best_month = 0;
        } else if (line.startsWith("intro: ")) {
            intro = line.mid(7).trimmed();
        } else if (line.startsWith("symbol: ")) {
            symbol = line.mid(8).trimmed();
        } else if (line.startsWith("stars: ")) {
            stars = line.mid(7).trimmed().toShort();
        } else if (line.startsWith("best_month: ")) {
            QString monthStr = line.mid(12).trimmed();
            if (monthStr.endsWith("月")) {
                monthStr.chop(1);  // 去掉“月”字
            }
            best_month = monthStr.toShort();
        } else if (!line.isEmpty()) {
            // 多行intro处理，添加换行符
            intro += "\n" + line;
        }
    }

    // 最后一个星座对象
    if (!name.isEmpty()) {
        CTS.append(Constellation(name, intro.trimmed(), symbol, stars, best_month));
    }

    file.close();
}


void initializePosition(StarPosition pos,QVector<Constellation>& CTS){
    for ( auto& constellation : CTS){
        if(constellation.name == pos.name){
            constellation.star_pos = pos.pos;
        }
    }
}

QString Constellation::getConstellationInfo(const QString comp_name) const{
    QString info = "";
    if(comp_name != name){
        return info;
    }
    info += "[星座名称] " + name + "\n" + "[介绍] " + intro + "\n" +
            "[象征] " + symbol + "\n" + "[最佳观测月份] " + QString::number(best_month) + "月" + "\n"
            + "[亮星数目] " + QString::number(stars) + "\n";

    // 限制每行最多显示25个字符
    int maxLineLength = 25;
    QStringList lines = info.split("\n");
    QString formattedInfo;
    foreach (QString line, lines) {
        for (int i = 0; i < line.length(); i += maxLineLength) {
            formattedInfo += line.mid(i, maxLineLength) + "\n";
        }
    }
    return formattedInfo;

}

StarPosition::StarPosition(QString name, QVector<QPair<int, int>> pos):name(name), pos(pos){
    // 检查 star_pos 是否已经被初始化
    if (pos.isEmpty()) {
        return; // 未初始化，直接返回
    }

    // 初始化最小和最大值
    int minX = 9999;
    int minY = 9999;
    int maxX = 0;
    int maxY = 0;

    // 遍历 star_pos，找到最小的 x 和 y，以及最大的 x 和 y
    for (const QPair<int, int>& position : pos) {
        if (position.first < minX) {
            minX = position.first;
        }
        if (position.second < minY) {
            minY = position.second;
        }
        if (position.first > maxX) {
            maxX = position.first;
        }
        if (position.second > maxY) {
            maxY = position.second;
        }
    }

    // 设置 R[4] 的值
    R[0] = minX;
    R[1] = minY;
    R[2] = maxX;
    R[3] = maxY;
}

void initializeMonthlyPosition(const QString& fileString, QVector<StarPosition>& STP) {
    QFile file(fileString);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    QString name;
    QVector<QPair<int, int>> positions;

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.contains("：")) {
            // 如果已经有星座数据，先保存之前的星座
            if (!name.isEmpty() && !positions.isEmpty()) {
                STP.append(StarPosition(name, positions));
                positions.clear();
            }

            QStringList parts = line.split("：");
            name = parts[0];

            // 处理该行剩余部分
            if (parts.size() > 1 && !parts[1].isEmpty()) {
                QStringList coords = parts[1].split(",");
                if (coords.size() == 2) {
                    int x = coords[0].toInt();
                    int y = coords[1].toInt();
                    positions.append(qMakePair(x, y));
                }
            }
        } else {
            QStringList coords = line.split(",");
            if (coords.size() == 2) {
                int x = coords[0].toInt();
                int y = coords[1].toInt();
                positions.append(qMakePair(x, y));
            }
        }
    }

    // 保存最后一个星座的数据
    if (!name.isEmpty() && !positions.isEmpty()) {
        STP.append(StarPosition(name, positions));
    }
}



QVector<QString> getInfos(const int x, const int y,
                                      const QVector<StarPosition>& STP, const QVector<Constellation>& CTS){
    QVector<QString> info;
    QVector<StarPosition> starposes;
    //首先判定是否落在R中
    for(const auto& starpos : STP){
        if(x >= starpos.R[0] && y >= starpos.R[1] &&
            x <= starpos.R[2] && y <= starpos.R[3]){
            starposes.append(starpos);
        }
    }
    //如果没有 返回空向量
    if(starposes.length() == 0){
        qDebug() << "没有星座被选中了";
        qDebug() << "x = " << std::to_string(x) << " y = " << std::to_string(y);
        return info;
    }
    //测试
    qDebug() << "x = " << std::to_string(x) << " y = " << std::to_string(y);
    for(const auto& starpos : starposes){
        qDebug() << "备选:" << starpos.name;
    }
    //如果有且仅有一个就直接返回
    if(starposes.length() == 1){
        for(const auto& constellation : CTS){
            QString temp_info = constellation.getConstellationInfo(starposes[0].name);
            //qDebug() << temp_info;
            if(temp_info != "")info.append(temp_info);
        }
        return info;
    }
    //有多个则分开判定
    //第一次判定:找manhattan距离
    for(const auto& starpos : starposes){
        bool can_do = false;

        for(const auto& pos : starpos.pos){
            if(std::abs(x - pos.first) + std::abs(y - pos.second) <= 70) //manhattan距离小于100px
            {
                can_do = true;
            }
        }
        if(can_do)
            for(const auto& constellation : CTS){
                QString temp_info = constellation.getConstellationInfo(starpos.name);
                if(temp_info != "")info.append(temp_info);

            }
    }
    if(info.length() == 0 || info.length() == 1)return info;

    //第二次判定:找垂直距离
    for(const auto& starpos : starposes){
        bool can_do = false;
        int len = starpos.pos.length();
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int x1 = starpos.pos[i].first, y1 = starpos.pos[i].second;
                int x2 = starpos.pos[j].first, y2 = starpos.pos[j].second;
                double k = double(y2 - y1) / double(x2 - x1);
                double b = double(x2 * y1 - x1 * y2) / double(x2 - x1);
                double d = (k * x - y + b) / std::sqrt(1 + k * k);
                if(d <= 50 && d >= -50){
                    can_do = true;
                    break;
                }
            }
            if(can_do)break;
        }
        if(can_do)
            for(const auto& constellation : CTS){
                QString temp_info = constellation.getConstellationInfo(starpos.name);
                if(temp_info != "")info.append(temp_info);
            }
    }
    return info;
}
