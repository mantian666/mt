#include "widget.h"
#include "./ui_widget.h"
#include "ImageSwitcher.h"
#include "addConstellation.h"
#include <QDir>

//注:CroppedStarPics在build->debug中


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    season = 0;//初始设置季节为0,0春 1夏 2秋 3冬
    atmosphere = true;//初始带大气层
    details = 0;//初始细节为0,也就是只显示星星,1为显示连线,2为显示连线+名字
    time = 1000;//一开始在早上
    file_place = "CroppedStarPics\\";
    introFilePath = "intro.txt";
    starposFilePath[0] = "0401-2200.txt";
    starposFilePath[1] = "0701-2200.txt";
    starposFilePath[2] = "1001-2200.txt";
    starposFilePath[3] = "0101-2200.txt";

    // 创建 ImageSwitcher 对象
    imageSwitcher = new ImageSwitcher(this,ui->ImageShowStack);

    // 初始化图片
    QVector<QString> imagePaths = {
        "CroppedStarPics\\0101-1000-atmosphere.png",
        "CroppedStarPics\\0101-1000-blank.png",
        "CroppedStarPics\\0101-2200-atmosphere.png",
        "CroppedStarPics\\0101-2200-blank.png",
        "CroppedStarPics\\0101-2200-line.png",
        "CroppedStarPics\\0101-2200-name.png",

        "CroppedStarPics\\0401-1000-atmosphere.png",
        "CroppedStarPics\\0401-1000-blank.png",
        "CroppedStarPics\\0401-2200-atmosphere.png",
        "CroppedStarPics\\0401-2200-blank.png",
        "CroppedStarPics\\0401-2200-line.png",
        "CroppedStarPics\\0401-2200-name.png",

        "CroppedStarPics\\0701-1000-atmosphere.png",
        "CroppedStarPics\\0701-1000-blank.png",
        "CroppedStarPics\\0701-2200-atmosphere.png",
        "CroppedStarPics\\0701-2200-blank.png",
        "CroppedStarPics\\0701-2200-line.png",
        "CroppedStarPics\\0701-2200-name.png",

        "CroppedStarPics\\1001-1000-atmosphere.png",
        "CroppedStarPics\\1001-1000-blank.png",
        "CroppedStarPics\\1001-2200-atmosphere.png",
        "CroppedStarPics\\1001-2200-blank.png",
        "CroppedStarPics\\1001-2200-line.png",
        "CroppedStarPics\\1001-2200-name.png",
    };
    imageSwitcher->initializeImages(imagePaths);
    qDebug() << "Current working directory:" << QDir::currentPath();

    //初始化星座信息
    initializeConstellation(introFilePath, CTS);
    for(int i = 0; i < 4; i++){
        initializeMonthlyPosition(starposFilePath[i], STP[i]);
    }

    //检查结果---星座的录入
    /*
    for (const auto& constellation : CTS) {
        qDebug() << "Name:" << constellation.name;
        qDebug() << "Intro:" << constellation.intro;
        qDebug() << "Symbol:" << constellation.symbol;
        qDebug() << "Stars:" << constellation.stars;
        qDebug() << "Best Month:" << constellation.best_month;
        qDebug() << "---------------------------";
    }
    */
    //检查结果---星座位置的录入

    for(const auto& position : STP[2]){
        qDebug() << "Name:" << position.name;
        qDebug() << "Pos:";
        for(const auto& pos : position.pos){
            qDebug() << pos.first << " " << pos.second;
        }
        qDebug() <<"R:";
        qDebug() << "(" << position.R[0] <<", " << position.R[1] << ") (" << position.R[2] <<", " << position.R[3] << ")";
    }


    // 初始化用于显示星座信息的 QLabel 现已弃用
    infoLabel = new QLabel(this);
    infoLabel->setStyleSheet("QLabel { color : white; }");
    infoLabel->setWordWrap(true); // 允许文字换行
    infoLabel->setGeometry(20, 20, 800, 70); // 设置位置和大小

    // 设置 QLabel 的背景为透明
    QPalette palette = infoLabel->palette();
    palette.setColor(QPalette::Window, Qt::transparent);
    infoLabel->setPalette(palette);
    infoLabel->setAttribute(Qt::WA_TranslucentBackground);

    infoLabel->setVisible(false); // 默认隐藏
    // 连接星座点击信号
    connect(imageSwitcher, &ImageSwitcher::constellationClicked, this, &Widget::showConstellationInfo);

    imageSwitcher->switchToAppointedImage(getPicName());
    fooTimes = 0;


    isWhite = true;
    triggeredColorChange = false;
    ui->colorButton->setStyleSheet("QPushButton { background: transparent; }");

    //设置各个按钮的形状 颜色

    ui->informationLabel->setStyleSheet("background-color:rgb(220, 220, 220);  border-radius: 30px;");
    ui->atmosphereButton->setStyleSheet("background-color:rgb(220, 220, 220);  border-radius: 10px;");
    ui->detailsButton->setStyleSheet("background-color:rgb(220, 220, 220);  border-radius: 10px;");
    ui->timeButton->setStyleSheet("background-color:rgb(220, 220, 220);  border-radius: 10px;");
    ui->seasonLabel->setStyleSheet("background-color:rgb(220, 220, 220);  border-radius: 10px;");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_dial_valueChanged(int value)
{
    season = value;
    imageSwitcher->switchToAppointedImage(getPicName());
    switch(season)
    {
    case 0:
        qDebug()<<"season: Spring(Apr)";
        ui->seasonLabel->setText("更改季节（目前为春季）");
        break;
    case 1:
        qDebug()<<"season: Summer(Jul)";
        ui->seasonLabel->setText("更改季节（目前为夏季）");
        break;
    case 2:
        qDebug()<<"season: Autumn(Oct)";
        ui->seasonLabel->setText("更改季节（目前为秋季）");
        break;
    case 3:
        qDebug()<<"season: Winter(Jan)";
        ui->seasonLabel->setText("更改季节（目前为冬季）");
        break;
    default:
        //理论上不会运行到这里
        qDebug()<<"Error occured when changing season";
    }
}

void Widget::on_atmosphereButton_clicked()
{
    atmosphere = !atmosphere;
    if(atmosphere==true)
    {
        ui->atmosphereButton->setText("把大气层关闭");
        //more...
        imageSwitcher->switchToAppointedImage(getPicName());
    }
    else
    {
        ui->atmosphereButton->setText("把大气层打开");
        //more...
        imageSwitcher->switchToAppointedImage(getPicName());
    }
}


void Widget::on_detailsButton_clicked()
{
    details ++;
    if(details > 2)details = 0;
    imageSwitcher->switchToAppointedImage(getPicName());
    if(atmosphere == false || time == 1000)fooTimes++;
    switch(details)
    {
    case 0:
        ui->detailsButton->setText("连线显示星座");
        break;
    case 1:
        ui->detailsButton->setText("连线+名称显示星座");
        break;
    case 2:
        ui->detailsButton->setText("关闭连线显示");
        break;
    default:
        qDebug() << "Error occured when changing details";
    }
    if(fooTimes >= 10){
        ui->informationLabel->setText("只有在打开大气层的晚上，才可以显示星座的连线和名称哦~");
        fooTimes = 0;
    }
}

QString Widget::getPicName()
{
    QString name = file_place;
    switch(season)
    {
    case 0:
        name += "0401";
        break;
    case 1:
        name += "0701";
        break;
    case 2:
        name += "1001";
        break;
    case 3:
        name += "0101";
        break;
    }
    name += "-";
    if(time == 1000)
        name += "1000";
    else if(time == 2200)
        name += "2200";
    name += "-";

    //白天的情况
    if(time == 1000){
        if(atmosphere == true)
            name += "atmosphere";
        else
            name += "blank";
    }
    //晚上的情况
    if(time == 2200){
        if(atmosphere == false)
            name += "blank";
        else
        {
            if(details == 0)
                name += "atmosphere";
            if(details == 1)
                name += "line";
            if(details == 2)
                name += "name";
        }
    }


    name += ".png";
    qDebug() << name;
    return name;
}

void Widget::on_timeButton_clicked()
{
    if(time == 1000)
    {
        time = 2200;
        ui->timeButton->setText("将时间调到白天");
    }
    else
    {
        time = 1000;
        ui->timeButton->setText("将时间调到晚上");
    }
    imageSwitcher->switchToAppointedImage(getPicName());
}

void Widget::showConstellationInfo(const int x, const int y)
{
    // 显示星座信息的逻辑
    if(atmosphere == true && time == 2200){
        auto info = getInfos(x, y, STP[season], CTS);

        //调试：输出info
        /*
        qDebug() << "info长度:" << info.length();
        for(const auto& singleInfo : info){
            qDebug() << singleInfo;
         qDebug() << "--------------------------------";
        }
        */
        for(const auto& information : info){
            ui->informationLabel->setText(information);
        }
    }



}



void Widget::on_colorButton_clicked()
{
    isWhite = !isWhite;
    if(!isWhite){
        this->setStyleSheet("background-color: black;");
        ui->informationLabel->setStyleSheet("background-color:rgb(50, 50, 50); color:rgb(200, 200, 200); border-radius: 30px;");
        ui->atmosphereButton->setStyleSheet("background-color:rgb(50, 50, 50); color:rgb(200, 200, 200); border-radius: 10px;");
        ui->detailsButton->setStyleSheet("background-color:rgb(50, 50, 50); color:rgb(200, 200, 200); border-radius: 10px;");
        ui->timeButton->setStyleSheet("background-color:rgb(50, 50, 50); color:rgb(200, 200, 200); border-radius: 10px;");
        ui->seasonLabel->setStyleSheet("background-color:rgb(50, 50, 50); color:rgb(200, 200, 200); border-radius: 10px;");
    }
    else{
        this->setStyleSheet("background-color: light grey;");
        ui->informationLabel->setStyleSheet("background-color:rgb(220, 220, 220); color:rgb(256, 256, 256); border-radius: 30px;");
        ui->atmosphereButton->setStyleSheet("background-color:rgb(220, 220, 220); color:rgb(256, 256, 256); border-radius: 10px;");
        ui->detailsButton->setStyleSheet("background-color:rgb(220, 220, 220); color:rgb(256, 256, 256); border-radius: 10px;");
        ui->timeButton->setStyleSheet("background-color:rgb(220, 220, 220); color:rgb(256, 256, 256); border-radius: 10px;");
        ui->seasonLabel->setStyleSheet("background-color:rgb(220, 220, 220); color:rgb(256, 256, 256); border-radius: 10px;");
    }
    if(!triggeredColorChange){
        triggeredColorChange = true;
        ui->informationLabel->setText("恭喜!你找到了切换到深色模式的方法!");
    }
}

