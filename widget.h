#ifndef WIDGET_H
#define WIDGET_H
#include<game.h>
#include <QWidget>
#include<QTimer>
#include<gamecontrol.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


extern int specie[100][100];
extern int grassa[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern bool checkBoard(int x,int y);
extern int fourmax(int x, int y);


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
   // Game * myGame;
    gameControl * myGame;
    int timeinterval;
    QTimer * timer;
};
#endif // WIDGET_H
