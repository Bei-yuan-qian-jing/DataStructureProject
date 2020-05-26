#include "cow.h"
#include<cstdio>
#include<iostream>

Cow::Cow(int x,int y){

    setHealth(kidhealth+rand()%100-50);
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
    int temp = rand()%12;
    for(int i = temp;;){
        newx = checkBoard(x+move2[i][0]);
        newy = checkBoard(y+move2[i][1]);
            if(grassa[newx][newy]>0)
                        {
                //find the grass
                addx(weigh[move2[i][0]+2]);
                addy(weigh[move2[i][1]+2]);
            }
            if(specie[newx][newy]==7||specie[newx][newy]==8)
            {
                //find the tiger
                addx(-5*weigh[move2[i][0]+2]);
                addy(-5*weigh[move2[i][1]+2]);
                setFindEnemy(1);
            }

        i=(i+1)%12;
        if(i==temp)
            break;
    }
    return fourmax(cowDirection[0],cowDirection[1],cowDirection[2],cowDirection[3]);
}

void Cow::addx(int x)
{
    if(x>0)
        cowDirection[1]+=x;
    if(x<0)
        cowDirection[0]-=x;
}

void Cow::addy(int y)
{
    if(y>0)
        cowDirection[3]+=y;
    if(y<0)
        cowDirection[2]-=y;
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
    int newx = checkBoard(x+move2[i][0]);
    int newy = checkBoard(y+move2[i][1]);
    if(specie[newx][newy]==0){
    specie[newx][newy] = specie[getX()][getY()];
    specie[getX()][getY()] = 0;
    setX(newx);
    setY(newy);
}
}

int Cow::reproduction(int dir){
	/*
	check whether the nearby block is available
	*/
    int temp = rand()%4;
    for (int i = temp; ; ) {

        int newx = checkBoard(x+move1[i][0]);
        int newy = checkBoard(y+move1[i][1]);
        if ((specie[newx][newy] == 0) && (specie[newx+move1[dir][0]][newy+move1[dir][1]]==0))
            return i;
        i=(i+1)%4;
        if(i==temp)
            break;
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
