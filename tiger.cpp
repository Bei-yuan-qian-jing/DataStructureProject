#include "tiger.h"
#include<iostream>
Tiger::Tiger(int x, int y, bool sex)
{
    setX(x);
    setY(y);
    setSex(sex);
    setHealth(kidhealth);
	setStarvationValue(0);
    set_kidheal(0,0);
    set_kidheal(0,1);
    set_kidstar(0,0);//set the default condition of starvation is full
    set_kidstar(0,1);
	specie[x][y] = 8 - sex;
}

bool Tiger::eat()
{
	/*
	tiger's eating
	*/ 
    int target=-1;
    int newx,newy;
    int type;
    for(int i = 0;i<4;i++){
        newx = getX()+move1[i][0];
        newy = getY()+move1[i][1];
        if(checkBoard(newx,newy)){
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
        }
    }
    if(target != -1&&(rand()%10)<=successRate[type]){
        specie[getX()+move1[target][0]][getY()+move1[target][1]]=-1;//if ate, become-1
        setStarvationValue(getStarvationValue()-10);
		set_kidstar(get_kidstar(0) - 10, 0);
		set_kidstar(get_kidstar(1) - 10, 1);
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
    for (int i = 4;i<12;i++)
	{
        newx = getX()+move2[i][0];
        newy = getY()+move2[i][1];
        if(checkBoard(newx,newy))
		{
            if(specie[newx][newy]==4||specie[newx][newy]==6||specie[newx][newy]==1||specie[newx][newy]==3)
			{
                target = i;
                break;
            }
            else if(specie[newx][newy]==5||specie[newx][newy]==2)
			{
                target = i;
            }
        }
    }
       if(target<0)
	   {
	   	/*
	    not found
		*/ 
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
    int newx = getX()+move1[i][0];
    int newy = getY()+move1[i][1];
    if(checkBoard(newx,newy)){
        if(specie[newx][newy]==0)
		{
            specie[newx][newy]=8-getSex();
            specie[getX()][getY()]=0;
            setX(newx);
            setY(newy);

		}
    }
    else return;

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
    if(get_kidstar(no)==20){
        set_kidheal(0,no);
        set_kidstar(0,no);
        return false;
    }
    if(get_kidheal(no) <= adulthealth){
        return true;
    }
    return false;
}

bool Tiger::checkkid()
{
    return get_kidheal(0)||get_kidheal(1)||getSex();
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
        int newx = x + move1[i][0];
        int newy = y + move1[i][1];
		if (checkBoard(newx, newy)) {
			if (specie[newx][newy] == 0)
			{
				set_kidheal(0, no);
				return i;
			}
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
