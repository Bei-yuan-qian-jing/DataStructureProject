#ifndef LISTSHEEP_H
#define LISTSHEEP_H
#include"sheep.h"
#include<list>

extern int specie[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern bool checkBoard(int x,int y);
extern int fourmax(int x_minus, int y_minus, int x, int y);class Listsheep
{
private:

    int size;
    int grassContent;//represent total grass store of the herd
    int productivity;//each cycle +1 if a cow is adult.-20 and birth+1 If >20
    int birth;//-1 and repro a new cow if >0 .
    int direction[4];//represent 4 direction's trend. every cow contribute to it
    std::list<Sheep>slist;//list for store the cows of a herd
    std::list<Sheep>::iterator s1;//iterator for traverse the list

	//---------self defined value---------
    int addGrassEachTime = 8;//the starvationValue increment by one grass
	int ProReproNeeded = 4;//the value needed to let birth++
	int ContentReproNeeded = 8;
	int sentivityToTiger = 4;//if one find tiger, the diretion trend will increse x times
	//---------self defined value---------
public:
    Listsheep(int x,int y);
    int updatedir();//choose the largest trend direction
    void appendList(Sheep c);
    void removeList(std::list<Sheep>::iterator a);
    bool traverse();//excute every cycle and traverse all cows
    void setDirection(int i,int j);//第i个数设成j


    int getBirth() const;
    void setBirth(int value);

    int getSize() const;
    void setSize(int value);

    int getProductivity() const;
    void setProductivity(int value);


    int getGrassContent() const;
    void setGrassContent(int value);
    void addx(int x);
    void addy(int y);
};


#endif // LISTSHEEP_H
