#ifndef COW_H
#define COW_H
#include<cmath>
#include<cstdlib>
extern int specie[100][100];
extern int grassa[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern int checkBoard(int x);
extern int fourmax(int x_minus, int y_minus, int x, int y);
class Cow
{
private:
    int starvationValue;//0-6. 0-1:full, 2-3:hungry, 4-5 extreme hungry, 6:die
    int health;//0-40. 40-31: kid, 30-11: adult, 10-1: old, 0: die
    int x,y;
    int cowDirection[4];//to calculate the direction trend by traverse
    bool findEnemy=0;

	//---------self defined value---------
    int weigh[5] = { -1,-3,0,3,1 }; //when dis is 1, 2, the weigh is 3, 1
    int kidhealth = 600; // the initial health value of the new born baby cow
    int adulthealth = 520; // dividing line between the health value of baby cow and adult cow
    int oldhealth = 50;
	int fullStar = 1;
	int hungryStar = 3;
    int extreStar = 5;
	//---------self defined value---------

public:

    Cow(int x,int y);

    bool live();//excute in each cycle,change the state, return live or die
    bool add();// check if grass is in its direction.
    int eat();//eat grass from herd's grassContent
    int update();
    //used for view surrending 12 locations, check grass or tiger and finally choose a direction and upload to herd
    void addx(int x);
    void addy(int y);

    int reproduction(int dir);
    //check if surrending 4 locations has an empty one and return the number.
    void moveCow(int i);
    //move to given direction i.
    int getStarvationValue() const;
    void setStarvationValue(int value);

    int getHealth() const;
    void setHealth(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);


    void setCowDirection(int minus_x, int minus_y,int x, int y);
    bool getFindEnemy() const;
    void setFindEnemy(bool value);
};

#endif // COW_H
