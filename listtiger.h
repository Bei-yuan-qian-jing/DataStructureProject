#ifndef LISTTIGER_H
#define LISTTIGER_H
#include"tiger.h"
#include<list>
extern int specie[100][100];
extern int grassa[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern int move3[24][2];
extern int checkBoard(int x);
extern int fourmax(int x_minus, int y_minus, int x, int y);
class Listtiger
{
private:
    int size;
    std::list<Tiger>tlist;// list for store all tiger in the world
    std::list<Tiger>::iterator t1;
    int movetimes;//move times each cycle
public:
    Listtiger(int Size=0);
    void append(Tiger t);
    int getSize() const;
    void setSize(int value);
    bool traverse();//excute every cycle.
	bool checkempty();//check if the list is empty
    void cleartiger();
    int getMovetimes() const;
    void setMovetimes(int value);
};

#endif // LISTTIGER_H
