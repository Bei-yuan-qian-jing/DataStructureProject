#ifndef INITWORLD_H
#define INITWORLD_H

#include<cstdlib>


//this file is used to store the global varible and function


//the world capacity
int row= 100;
int column = 100;


/* specie
 * used for store the coordinates of cow, tiger and sheep
 * 0 represent no animal
 * 1,2,3 represent sheep's three states: kid, adult, old
 * 4,5,6 represent cow's three states
 * 7, 8 represent tiger's male and female
 */
int specie[100][100]={{0}};


/* grassa
 * used for store the cooridinates of grass because it allows one position to hold a grass and an animal
 * 1-10 represent the health state of a grass, with time goes by, the health state of the grass will decrease
 * 0 represent death or no gress
 */
int grassa[100][100]={{0}};


/* move1
 * represent the four directions :left right down up
 */
int move1[4][2]={{-1,0},{1,0},{0,-1},{0,1}};


/* move2
 * represent the 12 possible locations two move can reach
 */
int move2[12][2]={{-1,0},{1,0},{0,-1},{0,1},{-2,0},{2,0},{0,-2},{0,2},
                  {-1,-1},{1,-1},{-1,1},{1,1}};


/* move3
 * 24 locations three moves can reach
 */
int move3[24][2]={{-1,0},{1,0},{0,-1},{0,1},{-2,0},{2,0},{0,-2},{0,2},
                   {-1,-1},{1,-1},{-1,1},{1,1},{0,3},{0,-3},{3,0},{-3,0},
                  {2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};


/* checkBoard
 * used for check if the new cooridinate(x, y) is exceed the range of world
 */
bool checkBoard(int x,int y);

int fourmax(int x_minus, int y_minus, int x, int y);
/*
    return the largest one of 4 directions. */

#endif // INITWORLD_H
