#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
#include"game.h"
#include<QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    setWindowTitle("Ecosytem");
    setFixedSize(1000, 800);
    myGame = new Game();

    timer = new QTimer(this);

    // timeout
    connect(timer, &QTimer::timeout, [=](){
        this->myGame->nexterm();
//        myGame->show();
    });

    // draw the board
    connect(timer, &QTimer::timeout, [=](){
        update();
    });

}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_Start_clicked()
{
    int grass_num = ui->Grass_num->value();
    int cow_num = ui->Cow_num->value();
    int sheep_num = ui->Sheep_num->value();
    int tiger_num = ui->Tiger_num->value();
//    qDebug() << grass_num << " " << cow_num << " " << sheep_num << " " << tiger_num << endl;

    myGame->init(grass_num, cow_num, sheep_num, tiger_num);
    timer->start(this->timeinterval);
}


void Widget::on_dial_valueChanged(int value)
{
    this->timeinterval = value;
    ui->Move_Speed->setValue(value);
//    std::cout << this->timeinterval << std::endl;
   // std::cout << ui->Move_Speed->value() << std::endl;

    // change the speed of the movement dynamicly.
     if(timer->isActive())
         timer->setInterval(this->timeinterval);

}

void Widget::on_Stop_clicked()
{
    timer->stop();
   // std::cout << timer->isActive() << std::endl;
}

void Widget::on_Continue_clicked()
{
    timer->start(this->timeinterval);
}

void Widget::on_End_clicked()
{
    timer->stop();
}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QBrush brush(Qt::cyan);
    brush.setStyle(Qt::Dense6Pattern);
    painter.setBrush(brush);
    painter.translate(30, 30);
    painter.drawRect(QRect(0, 0, 600, 600));

    brush.setColor(Qt::green);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

//    painter.drawPie(50, 50, 50, 50, 45 * 16, 90 * 16);
//    painter.drawRect(QRect(100, 100, 30, 30));
//    painter.drawEllipse(200, 200, 30, 30);
//    painter.drawEllipse(500, 500, 40, 20);
//    painter.drawRect(QRect(200, 400, 20, 40));

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            switch (myGame->board[i][j]) {
            // grass
            case 1 : painter.drawPie(i * 5, j * 5, 20, 20, 45 * 16, 90 * 16); break;
            // cow
            case 2 : painter.drawEllipse(i * 5, j * 5, 12, 12); break;
            // sheep
            case 3 : painter.drawEllipse(i * 5, j * 5, 16, 8); break;
            //tiger
            case 4 : painter.drawRect(QRect(i * 5, j * 5, 10, 10)); break;
            }
        }
    }
}
