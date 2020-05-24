#ifndef LISTSHEEP_H
#define LISTSHEEP_H
#include"sheep.h"
#include<list>

extern int specie[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern int checkBoard(int x);
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
    int addGrassEachTime = 7;//the starvationValue increment by one grass
    int ProReproNeeded = 25;//the value needed to let birth++
    int ContentReproNeeded = 8;
    int alert = 3;
    int enemy[4];//each cycle the direction array - i's enemy[i]*alert
    int enemy_plus = 3;//when find enemy in j, enemy[j]+=enemy_plus
    int sentivityToTiger = 5;//if one find tiger, the diretion trend will increse x times
    int init_birth=3;//the init number of list
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

    void clearDirection();
    int getProReproNeeded() const;
    void setProReproNeeded(int value);
};


#endif // LISTSHEEP_H
