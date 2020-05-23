#include "listtiger.h"
#include<iostream>


int Listtiger::getMovetimes() const
{
    return movetimes;
}

void Listtiger::setMovetimes(int value)
{
    movetimes = value;
}

Listtiger::Listtiger(int Size)
{
    size = Size;
    tlist.clear();
    setMovetimes(3);
}

bool Listtiger::traverse()
{
    /*
    a traverse of tiger
    */

    for(t1 = tlist.begin();t1!=tlist.end();){
		//std::cout << "T  health: " << t1->getHealth() << " star: " << t1->getStarvationValue() << " state: " << specie[t1->getX()][t1->getY()] << " size: " << size << std::endl;
        if(!t1->live()){
			t1 = tlist.erase(t1);
			setSize(getSize() - 1);
			if (tlist.empty())return false;
			continue;
        }
        for(int i =0;i<=1;i++){
            if(t1->kidlive(i)){
                int e = t1->leave(i);
                if(e==-1)
                    continue;
                Tiger c(checkBoard(t1->getX()+move1[e][0]),checkBoard(t1->getY()+move1[e][1]),rand()%2);
                tlist.push_back(c);
                setSize(getSize()+1);
                specie[c.getX()][c.getY()]=8-c.getSex();
            }
        }
        if(t1->checkHungry()){
            if(t1->getHealth()<=50)
            {
                t1->update();
                break;
            }
            for(int i = 0;i<getMovetimes();i++){
                if(t1->update())
                    break;
            }
        }
        else if(!t1->checkkid()){
            t1->reproduction();
        }
        else{

            for(int i = 0;i<getMovetimes();i++){
                t1->moveTiger(rand()%4);
            }

		}
		++t1;
	}
	return true;
}

bool Listtiger::checkempty()
{
    return tlist.empty();
}

void Listtiger::cleartiger()
{
    setSize(0);
    tlist.clear();
}

void Listtiger::append(Tiger t)
{
    tlist.push_back(t);
}



int Listtiger::getSize() const
{
    return size;
}

void Listtiger::setSize(int value)
{
    size = value;
}
