#include "listcow.h"
#include<iostream>

Listcow::Listcow(int x,int y)
{
    Cow h(x,y);
    clist.push_back(h);
    setSize(1);
    setBirth(0);
    setProductivity(5);
    setGrassContent(5);
	setDirection(0, 0);
	setDirection(1, 0);
}

void Listcow::appendList(Cow c){

    clist.push_back(c);

}

void Listcow::removeList(std::list<Cow>::iterator a){
    clist.erase(a);
}

bool Listcow::traverse()
{
	/*
	one traverse of a herd of cow
	*/
    int dir = updatedir();
    memset(direction,0,sizeof(direction));
	c1 = clist.begin();
    while(c1!=clist.end())
	{
		// std::cout << "C   health: " << c1->getHealth() << " star:" << c1->getStarvationValue() << "state: " << specie[c1->getX()][c1->getY()] << " content: " << getGrassContent() << std::endl;
		if (!c1->live()) {
			c1 = clist.erase(c1);
			setSize(getSize() - 1);
			if (clist.empty())return false;
			if (c1 == clist.end())break;
			continue;
		}

		if (specie[c1->getX()][c1->getY()] == 5)
			setProductivity(getProductivity() + 1);
        c1->moveCow(dir);
        if(c1->add())
            setGrassContent(getGrassContent()+addGrassEachTime);
		if (getGrassContent() > 0)
			setGrassContent(getGrassContent() - c1->eat());
        int j= c1->update();
        if(c1->getFindEnemy()){
            addx(-sentivityToTiger*move1[j][0]);
            addy(-sentivityToTiger*move1[j][1]);
            c1->setFindEnemy(0);
        }
        else
		{
            addx(move1[j][0]);
            addy(move1[j][1]);
        }

        if(getBirth()>0){
            int i = c1->reproduction();
            if(i>=0){
            Cow c(c1->getX()+move1[i][0],c1->getY()+move1[i][1]);
            appendList(c);
            setSize(getSize()+1);
            specie[c.getX()][c.getY()]=4;
			setBirth(getBirth() - 1);
			}
		}
		++c1;
    }
	return true;
}

int Listcow::updatedir()
{
	/*
	update the dirction of a herd of cow
	*/
	if (productivity >= ProReproNeeded && getGrassContent() >= ContentReproNeeded) {
		birth++;
		productivity -= ProReproNeeded;

	}
    return fourmax(direction[0],direction[1],direction[2],direction[3]);
}


int Listcow::getBirth() const
{
    return birth;
}

void Listcow::setBirth(int value)
{
    birth = value;
}

int Listcow::getSize() const
{
    return size;
}

void Listcow::setSize(int value)
{
    size = value;
}

int Listcow::getProductivity() const
{
    return productivity;
}

void Listcow::setProductivity(int value)
{
    productivity = value;
}



void Listcow::setDirection(int i, int j){
    direction[i]=j;
}


int Listcow::getGrassContent() const
{
    return grassContent;
}

void Listcow::setGrassContent(int value)
{
    grassContent = value;
}
void Listcow::addx(int x)
{
    if(x>0)
        direction[2]+=x;
    if(x<0)
        direction[0]-=x;
}

void Listcow::addy(int y)
{
    if(y>0)
        direction[3]+=y;
    if(y<0)
        direction[1]-=y;
}
