#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include <bits/stdc++.h>

#include "listtiger.h"
#include "listcow.h"
#include"listsheep.h"

#include "cow.h"
#include"grass.h"

extern int specie[100][100];
extern int grassa[100][100];
extern int row, column;
extern int move1[4][2];
extern int move2[12][2];
extern bool checkBoard(int x, int y);
extern int fourmax(int x, int y);


class gameControl : public QObject
{
    Q_OBJECT
public:
    explicit gameControl(QObject *parent = nullptr);

    int grassNum = 1000;
    int cowherdNum = 10;
    int sheepherdNum = 10;
    int tigerNum = 100;
    const int tigerView = 3;//initial range of view of tiger
    const int herdView = 3;//initial range of view of herd of cow and sheep
    Grass* grassList[100][100];
    Listtiger tigerlist;

    std::list<Listcow>cowlist;
    std::list<Listcow>::iterator lc;
    std::list<Listsheep>sheeplist;
    std::list<Listsheep>::iterator ls;

    void initGrass(int GrassNumber);
    void initTiger(int tigerNumber);
    void initCow(int CowherdNumber);
    void initsheep(int SheepherdNumber);
    void init(int GrassNumber, int CowherdNumber, int SheepHerdNumber, int TigerNumber);
    void nextTurn();


signals:

};

#endif // GAMECONTROL_H
