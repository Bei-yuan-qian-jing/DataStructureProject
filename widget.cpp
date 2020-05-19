#include "widget.h"
#include "ui_widget.h"

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

