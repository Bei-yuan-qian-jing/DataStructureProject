#include "initworld.h"




bool checkBoard(int x, int y)
{
	/*
	Boundary check 
	*/ 
    if(x<0||x>=row||y<0||y>=column)
        return false;
    else
        return true;
}


int fourmax(int x_minus, int y_minus, int x, int y)
{
    x =( (x_minus)==x?(rand()%2==0?-x_minus:x):(x_minus>x?-x_minus:x));
    y = ((y_minus)==y?(rand()%2==0?-y_minus:y):(y_minus>y?-y_minus:y));
    if(abs(x)==abs(y)){
        if(x==0){
            return rand()%4;
        }
        else
            return rand()%2==1?(x>0?1:0):(y>0?3:2);
    }
    return (abs(x)>abs(y))?(x>0?1:0):(y>0?3:2);
}
