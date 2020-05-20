#include "widget.h"
#include "ui_widget.h"
#include<QDebug>
//1
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    setWindowTitle("Ecosytem");
    setFixedSize(1000, 800);
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

}
