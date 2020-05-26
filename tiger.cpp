#include "tiger.h"
#include<iostream>
int Tiger::getLastDir() const
{
    return lastDir;
}

void Tiger::setLastDir(int value)
{
    lastDir = value;
}

int Tiger::getKidhealth() const
{
    return kidhealth;
}

void Tiger::setKidhealth(int value)
{
    kidhealth = value;
}

Tiger::Tiger(int x, int y, bool sex)
{
    setX(x);
    setY(y);
    setSex(sex);

    setHealth(adulthealth+rand()%100-50);

	setStarvationValue(0);
    set_kidheal(0,0);
    set_kidheal(0,1);
    set_kidstar(0,0);//set the default condition of starvation is full
    set_kidstar(0,1);
    setLastDir(rand()%4);
	specie[x][y] = 8 - sex;
}

bool Tiger::eat()
{
	/*
	tiger's eating
	*/ 

    int target=-1;
    int newx,newy;
    int type=0;
    int temp = rand()%4;
    for (int i = temp; ; ) {

        newx = checkBoard(x+move2[i][0]);
        newy = checkBoard(y+move2[i][1]);
        if(specie[newx][newy]==4||specie[newx][newy]==6){
            target = i;
            type = 0;
            break;
         }
        if(specie[newx][newy]==1||specie[newx][newy]==3){
            target = i;
            type = 1;
            break;
         }
        if(specie[newx][newy]==2){
            target = i;
            type = 3;
        }
        if(specie[newx][newy]==5){
            target = i;
            type = 2;
        }

        i=(i+1)%4;
        if(i==temp)
            break;

    }

    if(target != -1&&rand()%10<successRate[target]){
        specie[checkBoard(getX()+move1[target][0])][checkBoard(getY()+move1[target][1])]=-1;//if ate, become-1
        setStarvationValue(getStarvationValue()-40);
        set_kidstar(get_kidstar(0) - 40, 0);
        set_kidstar(get_kidstar(1) - 40, 1);
        return true;

    }
    return false;
}

bool Tiger::update()
{
	/*
	find the move type of tiger
	*/ 

    if(eat())
        return true;
    int newx,newy;
    int target=-1;
    int temp = rand()%8+4;
    for (int i = temp;;)
	{
        newx = checkBoard(x+move2[i][0]);
        newy = checkBoard(y+move2[i][1]);

        if(specie[newx][newy]==4||specie[newx][newy]==6||specie[newx][newy]==1||specie[newx][newy]==3)
        {
            target = i;
            break;
        }
        else if(specie[newx][newy]==5||specie[newx][newy]==2)
        {
            target = i;
        }

        i=(i-3)%8+4;
        if(i==temp)
            break;
}
       if(target<0)
	   {
	   	/*
	    not found
		*/ 
           if(rand()%4!=0)
               moveTiger(lastDir);
           else
               moveTiger(rand()%4);
       }
       else if(target<8){
       	/*
		within the range of activities
		*/ 
            moveTiger(target-4);
       }
       else {
       	/*
		within the range of view,out of the range of activities
		*/ 

           if(rand()%2==0)
               moveTiger(target%2);//§move2
           else
               moveTiger(target/2-2);
       }

       return false;

}

bool Tiger::live()
{
	/*
	check whether the tiger is alive
	*/
    setHealth(getHealth()-1);
    setStarvationValue(getStarvationValue()+1);

    if(getHealth()<=0||getStarvationValue()>hungryStar)
	{
        specie[getX()][getY()]=0;
        return false;
    }
	specie[getX()][getY()] = (getSex() ? 7 : 8);

    return true;
}

bool Tiger::checkHungry()
{
    return (getStarvationValue()>fullStar||get_kidstar(0)>fullStar||get_kidstar(1)>fullStar);//returning 1 represents hungry
}

void Tiger::moveTiger(int i)
{
	/*
        if no specie, move to i direction and move the kid tiger
	*/ 
    int newx = checkBoard(x+move2[i][0]);
    int newy = checkBoard(y+move2[i][1]);
    if(specie[newx][newy]==0)
    {
        specie[newx][newy]=8-getSex();
        specie[getX()][getY()]=0;
        setX(newx);
        setY(newy);
        lastDir = i;
    }



}

bool Tiger::kidlive(int no)
{
	/*
	check and update the living condition of kids 
	*/ 
    if (kids[no].health == 0)
        return false;
    set_kidheal(get_kidheal(no)-1,no);
    set_kidstar(get_kidstar(no)+1,no);
    if(get_kidstar(no)==starvationValue){
        set_kidheal(0,no);
        set_kidstar(0,no);
        return false;
    }
    if(get_kidheal(no) <= adulthealth+rand()%50-25){
        return true;
    }
    return false;
}

bool Tiger::checkkid()
{
    return (get_kidheal(0)>0||get_kidheal(1)>0||getSex()==1||getHealth()<10)||getStarvationValue()<30;
}

void Tiger::reproduction()
{
	/*
	the reproduction of tiger 
	*/ 

    int i = rand()%2;
    for(int j = 0;j<=i;j++){
        set_kidheal(kidhealth,i);
        set_kidstar(0,i);
    }


}


int Tiger::leave(int no)
{
	/*
	the kid has become adult
	*/
    for(int i = 0;i<=3;i++)
	{
        int newx = checkBoard(x+move2[i][0]);
        int newy = checkBoard(y+move2[i][1]);
			if (specie[newx][newy] == 0)
			{
				set_kidheal(0, no);
				return i;
			}

	}
    return -1;
}

void Tiger::set_kidheal(int heal, int no)
{
    kids[no].health = heal;
}

int Tiger::get_kidheal(int no)
{
    return kids[no].health;
}

void Tiger::set_kidstar(int star, int no)
{
    kids[no].starvation = star;
}

int Tiger::get_kidstar(int no)
{
    return kids[no].starvation;
}

int Tiger::getY() const
{
    return y;
}

void Tiger::setY(int value)
{
    y = value;
}

int Tiger::getHealth() const
{
    return health;
}

void Tiger::setHealth(int value)
{
    health = value;
}

bool Tiger::getSex() const
{
    return sex;
}

void Tiger::setSex(bool value)
{
    sex = value;
}


int Tiger::getStarvationValue() const
{
    return starvationValue;
}

void Tiger::setStarvationValue(int value)
{
    starvationValue = value;
}

int Tiger::getX() const
{
    return x;
}

void Tiger::setX(int value)
{
    x = value;
}
