#include "grass.h"
#include<iostream>
Grass::Grass(int X , int Y )
{
	x = X;
	y = Y;
}

Grass::Grass()
{
	x = 0;
	y = 0;
}

void Grass::live()
{
	/*
	check whether the grass can reproduction
	*/
    if(grassa[x][y]>0){
        grassa[x][y]--;
        reproduction();

    }

}

void Grass::reproduction()
{
	/*
	the reproduction of grass
	*/
    int newx,newy;
    int temp = rand()%4;
    for (int i = temp; ; ) {

        newx = checkBoard(x+move1[i][0]);
        newy = checkBoard(y+move1[i][1]);

        if (grassa[newx][newy] == 0) {
            if (rand() % 20 < prob) {
                grassa[newx][newy] = 15+rand()%4-2;

            }
        }
        i=(i+1)%4;
        if(i==temp)
            break;

}
}



int Grass::getY() const
{
    return y;
}

void Grass::setY(int value)
{
    y = value;
}

int Grass::getX() const
{
    return x;
}

void Grass::setX(int value)
{
    x = value;
}
