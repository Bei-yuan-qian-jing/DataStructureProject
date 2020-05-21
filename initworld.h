#ifndef INITWORLD_H
#define INITWORLD_H

#include<cstdlib>
//this file is used to store the global varible and function


int row= 100;
int column = 100;//the world capacity
int specie[100][100]={{0}};

/*
used for store the coordinates of cow, tiger and sheep
0 represent no animal
1,2,3 represent sheep's three states: kid, adult, old
4,5,6 represent cow's three states
7, 8 represent tiger's male and female

*/

int grassa[100][100]={{0}};
/*
used for store the cooridinates of grass because it allows collision between grass and animal
1-10 represent the health state of a grass
0 represent death or no gress
*/

int move1[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//represent the four directions :left right down up

int move2[12][2]={{-1,0},{1,0},{0,-1},{0,1},{-2,0},{2,0},{0,-2},{0,2},
                  {-1,-1},{1,-1},{-1,1},{1,1}};
//represent the 12 possible locations two move can reach

int move3[24][2]={{-1,0},{1,0},{0,-1},{0,1},{-2,0},{2,0},{0,-2},{0,2},
                   {-1,-1},{1,-1},{-1,1},{1,1},{0,3},{0,-3},{3,0},{-3,0},
                  {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
//24 locations three moves can reach

bool checkBoard(int x,int y);
//used for check if the new cooridinate(x, y) is exceed the range of world

int fourmax(int x, int y);
/*x,y represent 4 values(x == -1 represent left 1) in x,y dirsction,
    return the largest one of 4 directions. */

#endif // INITWORLD_H
