#ifndef SHEEP_H
#define SHEEP_H
#include<cmath>
extern int specie[100][100];
extern int grassa[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern int checkBoard(int x);
extern int fourmax(int x_minus, int y_minus, int x, int y);

class Sheep//similar to cow, only different in some value
{
private:
    int starvationValue;//0-5. 0-1:full, 2-3:hungry, 4 extreme hungry, 5:die
    int health;//0-25. 25-21: kid, 20-6: adult, 5-1: old, 0: die
    int x,y;
    int sheepDirection[4];//used to record the trend of sheep
    bool findEnemy=0;

	//---------self defined value---------
	int weigh[5] = { -1,-3,0,3,1 };//when dis is 1, 2, the weigh is 3, 1
    int kidhealth = 600;//refer to health value and starvation value
    int adulthealth = 560;
    int oldhealth = 20;
	int fullStar = 1;
	int hungryStar = 3;
	int extreStar = 4;
	//---------self defined value---------
public:

    Sheep(int x,int y);

    bool live() ;//excute in each cycle,change the state, return live or die
    bool add();// check if grass is in its direction.
    int eat();//eat grass from herd's grassContent
    int update();
    //used for view surrending 12 locations, check grass or tiger and finally choose a direction and upload to herd
    void addx(int x);
    void addy(int y);

    int reproduction();
    //check if surrending 4 locations has an empty one and return the number.
    void moveSheep(int i);
    //move to given direction i.
    int getStarvationValue() const;
    void setStarvationValue(int value);

    int getHealth() const;
    void setHealth(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    void setSheepDirection(int minus_x, int minus_y,int x, int y);
    bool getFindEnemy() const;
    void setFindEnemy(bool value);
};

#endif // SHEEP_H
