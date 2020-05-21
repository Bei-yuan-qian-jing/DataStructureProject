#ifndef LISTCOW_H
#define LISTCOW_H
#include"cow.h"
#include<list>

extern int specie[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern bool checkBoard(int x,int y);
extern int fourmax(int x, int y);
class Listcow
{
private:

    int size;
    int grassContent;//represent total grass store of the herd
    int productivity;//each cycle +=1 if a cow is adult.-20 and birth+1 If >20
    int birth;//-=1 and repro a new cow if >0 .
    int direction[2];//represent 4 direction's trend. every cow contribute to it
    std::list<Cow>clist;//list for store the cows of a herd
    std::list<Cow>::iterator c1;//iterator for traverse the list
	
	//---------self defined value---------
	int addGrassEachTime = 5;//the starvationValue increment by one grass
	int ProReproNeeded = 7;//the value needed to let birth++
	int ContentReproNeeded = 10;
	int sentivityToTiger = 2; //if one find tiger, the diretion trend will increse x times
	//---------self defined value---------
public:
    Listcow(int x,int y);
    int updatedir();//choose the largest trend direction
    void appendList(Cow c);
    void removeList(std::list<Cow>::iterator a);
    bool traverse();//excute every cycle and traverse all cows

    void setDirection(int i,int j);//set the i-th num to j

    int getBirth() const;
    void setBirth(int value);

    int getSize() const;
    void setSize(int value);


    int getProductivity() const;
    void setProductivity(int value);


    int getGrassContent() const;
    void setGrassContent(int value);

};

#endif // LISTCOW_H
