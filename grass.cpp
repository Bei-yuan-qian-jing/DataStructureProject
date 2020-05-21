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
    for(int i = 0;i <= 3 ; i++){
        newx = x+move1[i][0];
        newy = y+move1[i][1];
        if(checkBoard(newx, newy)){
			if (grassa[newx][newy] == 0) {
                if (rand() % 10 < prob) {
					grassa[newx][newy] = 10;

				}
			}
    }

}}



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
