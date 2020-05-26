#include "sheep.h"
#include<iostream>

bool Sheep::getFindEnemy() const
{
    return findEnemy;
}

void Sheep::setFindEnemy(bool value)
{
    findEnemy = value;
}

Sheep::Sheep(int x,int y){

    setHealth(kidhealth);
    setStarvationValue(0);
    setSheepDirection(0,0,0,0);
    setX(x);
    setY(y);
	specie[x][y] = 1;
	setFindEnemy(0);
}


bool Sheep::live() {
	/*
	check whether the sheep is alive
	*/
	setHealth(getHealth() - 1);
	setStarvationValue(getStarvationValue() + 1);
	if (specie[getX()][getY()] == -1){
		specie[getX()][getY()] = 0;
        std::cout<<"eats"<<std::endl;
		return false;
	}
    if(getHealth()<=0||getStarvationValue()>extreStar){
        specie[getX()][getY()]=0;
        std::cout<<"hungs"<<std::endl;
        return false;
    }
    if(getHealth()<=oldhealth){
        specie[getX()][getY()]=3;

    }
    else if(getHealth()<=adulthealth){
        specie[getX()][getY()]=2;
    }
    else {
        specie[getX()][getY()]=1;
    }
    return true;
}

int Sheep::update(){
        /*
        update the dirction of sheep
        return the dirction having the bigger value
        */
    int newx,newy;
    setSheepDirection(0,0,0,0);
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

        i = (i+1)%12;
        if(i==temp)
            break;
    }

        return fourmax(sheepDirection[0],sheepDirection[1],sheepDirection[2],sheepDirection[3]);
}

void Sheep::addx(int x)
{
    if(x>0)
        sheepDirection[1]+=x;
    if(x<0)
        sheepDirection[0]-=x;
}

void Sheep::addy(int y)
{
    if(y>0)
        sheepDirection[3]+=y;
    if(y<0)
        sheepDirection[2]-=y;
}

int Sheep::eat(){
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

bool Sheep::add(){
        /*
        process the grass
        */
    if(grassa[getX()][getY()]>0){
        grassa[getX()][getY()]=0;
        return true;
    }
    return false;
}

void Sheep::moveSheep(int i) {
	/*
	move towards the direction of i
	*/
    int newx = checkBoard(x+move2[i][0]);
    int newy = checkBoard(y+move2[i][1]);

    specie[newx][newy] = specie[getX()][getY()];
    specie[getX()][getY()] = 0;
    setX(newx);
    setY(newy);

}

int Sheep::reproduction(){
        /*
        check whether the nearby block is available
        */
    int temp = rand()%4;
    for (int i = temp;; ) {
        int newx = checkBoard(x+move2[i][0]);
        int newy = checkBoard(y+move2[i][1]);
        if (specie[newx][newy] == 0)
            return i;

        i=(i+1)%4;
        if(i==temp)
            break;
	}
    return -1;
}


int Sheep::getStarvationValue() const
{
    return starvationValue;
}

void Sheep::setStarvationValue(int value)
{
    starvationValue = value;
}

int Sheep::getHealth() const
{
    return health;
}

void Sheep::setHealth(int value)
{
    health = value;
}

int Sheep::getX() const
{
    return x;
}

void Sheep::setX(int value)
{
    x = value;
}

int Sheep::getY() const
{
    return y;
}

void Sheep::setY(int value)
{
    y = value;
}

void Sheep::setSheepDirection(int minus_x, int minus_y,int x, int y)
{
    sheepDirection[0] = minus_x;
    sheepDirection[1] = minus_y;
    sheepDirection[2] = x;
    sheepDirection[3] = y;
}
