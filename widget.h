#ifndef WIDGET_H
#define WIDGET_H
#include<game.h>
#include <QWidget>
#include<QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_Start_clicked();

    void on_dial_valueChanged(int value);

    void on_Stop_clicked();

    void on_Continue_clicked();

    void on_End_clicked();

    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
    Game * myGame;
    int timeinterval;
    QTimer * timer;
};
#endif // WIDGET_H
