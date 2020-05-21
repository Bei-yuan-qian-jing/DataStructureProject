#ifndef TIGER_H
#define TIGER_H
#include<cstdlib>
extern int specie[100][100];
extern int grassa[100][100];
extern int row,column;
extern int move1[4][2];
extern int move2[12][2];
extern int move3[24][2];
extern bool checkBoard(int x,int y);
extern int fourmax(int x, int y);

class Tiger
{
private:
    int x,y;
    int health;//60-0 50-10:adult, 10-1:old, 0:die
    bool sex;//0:female, 1:male
    int starvationValue;//0-10: 0-2: full, 4-9: hungry, 10:die
    struct kid{
        int health=0;
        int starvation=0;
    }kids[2];
    //before adult, the kid only exixt in its mother's varible, after adult, create a new tiger.


	//---------self defined value---------
	const int successRate[4] = { 8,7,4,5 };
	//possibilty to hunt a kid or old cow:80%
	//possibilty to hunt a kid or old sheep:70%
	//possibilty to hunt a adult sheep:40%
	//possibilty to hunt a adult sheep:50%
	int weigh[5] = { -1,-3,0,3,1 };//when dis is 1, 2, the weigh is 3, 1
	int kidhealth = 60;//refer to health value and starvation value
	int adulthealth = 50;
	int oldhealth = 10;
	int fullStar = 5;
	int hungryStar = 20;
	//---------self defined value---------


   

public:
    Tiger(int x,int y,bool sex);//0:female , 1, male
    bool eat();// check surrending 4 locations and eat the kid and old first then adult.
    int leave(int no);// if kid's health<=40 it means become adult and leave its mother
    bool live();//change the state and check live or die
    bool checkHungry();//check if itself or kid is hungry
    void moveTiger(int e);// change to the given location
    bool update();// check surrending 12 locations and move 1 each time
    bool kidlive(int no);// change kid's state and check live or die and kid or adult.
    bool checkkid();//check if a tiger has kids.
    void reproduction();//for a female tiger repro a new kid

    void set_kidheal(int heal, int no);
    int get_kidheal(int no);
    void set_kidstar(int star,int no);
    int get_kidstar(int no);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getHealth() const;
    void setHealth(int value);
    bool getSex() const;
    void setSex(bool value);
    int getStarvationValue() const;
    void setStarvationValue(int value);
};

#endif // TIGER_H
