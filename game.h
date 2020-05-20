#ifndef GAME_H
#define GAME_H
#include <QObject>
#include<bits/stdc++.h>
const int maxn = 100;

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = nullptr);
    int grass_num;
    int cow_num;
    int sheep_num;
    int tiger_num;
    int board[maxn][maxn];
    void init(int, int, int, int);
    void nexterm();
    void show();


signals:

};

#endif // GAME_H
