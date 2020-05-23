#include "cow.h"
#include<cstdio>


Cow::Cow(int x,int y){

    setHealth(kidhealth);
    setStarvationValue(0);
    setCowDirection(0,0,0,0);
	setFindEnemy(0);
    setX(x);
    setY(y);
	specie[x][y] = 4;
}


bool Cow::live(){
	/*
        execute every round, change the state of the cow and judge whether the cow is alive.
	*/

    // every round, the cow will get older and its health value will decrease
    setHealth(getHealth()-1);
    // the cow need energy to move, so every round it will get more hungry
    setStarvationValue(getStarvationValue()+1);
    if (specie[getX()][getY()] == -1) {//-1 represents that it has been aten by the tiger
		specie[getX()][getY()] = 0;
		return false;
	}
    // the condition that the cow dies of oldness or hunger
    if(getHealth()<=0||getStarvationValue()>extreStar){
        specie[getX()][getY()]=0;
        return false;
    }
    if(getHealth()<=oldhealth){
        specie[getX()][getY()]=6;

    }
    else if(getHealth()<=adulthealth){
        specie[getX()][getY()]=5;
    }
    else {
        specie[getX()][getY()]=4;
    }
    return true;
}


int Cow::update(){
        /*
        update the dirction of cow
        return the dirction having the bigger value
        */
    int newx,newy;
    setCowDirection(0,0,0,0);
    for(int i = 0;i <= 11 ; i++){
        newx = x+move2[i][0];
        newy = y+move2[i][1];
        if(checkBoard(newx, newy))
        {
            if(grassa[newx][newy]>0)
                        {
                //find the grass
                addx(weigh[move2[i][0]+2]);
                addy(weigh[move2[i][1]+2]);
            }
            if(specie[newx][newy]==7||specie[newx][newy]==8)
            {
                //find the tiger
                addx(-3*weigh[move2[i][0]+2]);
                addy(-3*weigh[move2[i][1]+2]);
                setFindEnemy(1);
            }
        }
    }
    return fourmax(cowDirection[0],cowDirection[1],cowDirection[2],cowDirection[3]);
}

void Cow::addx(int x)
{
    if(x>0)
        cowDirection[2]+=x;
    if(x<0)
        cowDirection[0]-=x;
}

void Cow::addy(int y)
{
    if(y>0)
        cowDirection[3]+=y;
    if(y<0)
        cowDirection[1]-=y;
}


int Cow::eat(){
	/*
	update the StarvationValue after eating
	*/
    if(getStarvationValue()>hungryStar){
        setStarvationValue(getStarvationValue()-2);
        return 2;
    }
    else if(getStarvationValue()>fullStar){
        setStarvationValue(getStarvationValue()-1);
        return 1;
    }
    else
        return 0;
}

bool Cow::add(){
	/*
	process the grass
	*/
    if(grassa[getX()][getY()]>0){
        grassa[getX()][getY()]=0;
        return true;
    }
    return false;
}

void Cow::moveCow(int i) {
	/*
	move towards the direction of i
	*/
	int newx = getX() + move1[i][0];
	int newy = getY() + move1[i][1];
	if (checkBoard(newx, newy)) {
		specie[getX() + move1[i][0]][getY() + move1[i][1]] = specie[getX()][getY()];
		specie[getX()][getY()] = 0;
		setX(getX() + move1[i][0]);
		setY(getY() + move1[i][1]);
	}
}

int Cow::reproduction(){
	/*
	check whether the nearby block is available
	*/
	for (int i = 0; i <= 3; i++) {
		int newx = x + move1[i][0];
		int newy = y + move1[i][1];
		if (checkBoard(newx, newy)) {
			if (specie[newx][newy] == 0 )
				return i;
		}
	}
    return -1;
}

bool Cow::getFindEnemy() const
{
    return findEnemy;
}

void Cow::setFindEnemy(bool value)
{
    findEnemy = value;
}

int Cow::getStarvationValue() const
{
    return starvationValue;
}

void Cow::setStarvationValue(int value)
{
    starvationValue = value;
}

int Cow::getHealth() const
{
    return health;
}

void Cow::setHealth(int value)
{
    health = value;
}

int Cow::getX() const
{
    return x;
}

void Cow::setX(int value)
{
    x = value;
}

int Cow::getY() const
{
    return y;
}

void Cow::setY(int value)
{
    y = value;
}

void Cow::setCowDirection(int minus_x, int minus_y,int x, int y)
{
    cowDirection[0] = minus_x;
    cowDirection[1] = minus_y;
    cowDirection[2] = x;
    cowDirection[3] = y;
}
