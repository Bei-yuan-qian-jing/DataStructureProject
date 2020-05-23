#ifndef GRASS_H
#define GRASS_H
#include<cstdlib>

extern int grassa[100][100];
extern int row,column;
extern int move1[4][2];
extern int checkBoard(int x);
class Grass{

private:

    int x;
    int y;
    const int prob=1;// 10% to repro
public:
    Grass(int X,int Y);
    Grass();

    void live();// excute each cycle, used for change health and reproduction
    void reproduction();// check empty and repro in "prob" possibility
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

};

#endif // GRASS_H

