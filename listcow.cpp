#include "listcow.h"
#include<iostream>
#include<cstring>

int Listcow::getProReproNeeded() const
{
    return ProReproNeeded;
}

void Listcow::setProReproNeeded(int value)
{
    ProReproNeeded = value;
}

std::list<Cow> Listcow::branchCow()
{
    c1=clist.begin();

    for(int i = 1;i<6;i++){
        c1++;
    }
    std::list<Cow>temp;
    temp.insert(temp.begin(),c1,clist.end());
    clist.erase(c1,clist.end());
    setSize(7);
    return temp;
}

Listcow::Listcow(int x,int y)
{
    Cow h(x,y);
    clist.push_back(h);
    setSize(1);
    setProductivity(5);
    setGrassContent(5);
    setProReproNeeded(getProReproNeeded()+rand()%20-10);
    setBirth(init_birth);
    memset(enemy,0,sizeof (enemy));
    memset(direction,0,sizeof(direction));
}

Listcow::Listcow(std::list<Cow>l1)
{
    c1=clist.begin();
    clist.splice(c1,l1);
    setSize(7);
    setProductivity(5);
    setGrassContent(20);
    setProReproNeeded(getProReproNeeded()+rand()%20-10);
    setBirth(0);
    memset(enemy,0,sizeof (enemy));
    memset(direction,0,sizeof(direction));
}


void Listcow::appendList(Cow c){

    clist.push_back(c);

}

void Listcow::removeList(std::list<Cow>::iterator a){
    clist.erase(a);
}

int Listcow::traverse()
{
	/*
	one traverse of a herd of cow
	*/

    int dir = updatedir();
    clearDirection(dir);

	c1 = clist.begin();
    while(c1!=clist.end())
	{

		// std::cout << "C   health: " << c1->getHealth() << " star:" << c1->getStarvationValue() << "state: " << specie[c1->getX()][c1->getY()] << " content: " << getGrassContent() << std::endl;
		if (!c1->live()) {
			c1 = clist.erase(c1);
			setSize(getSize() - 1);
            if (clist.empty())return 0;
			if (c1 == clist.end())break;
            setProductivity(getProductivity()+5);
			continue;
		}
        if(getBirth()>0){
            int i = c1->reproduction(dir);
            if(i>=0){
            Cow c(checkBoard(c1->getX()+move1[i][0]),checkBoard(c1->getY()+move1[i][1]));
            clist.insert(c1,c);
            setSize(getSize()+1);
            specie[c.getX()][c.getY()]=4;
            setBirth(getBirth() - 1);
            }
        }
		if (specie[c1->getX()][c1->getY()] == 5)
			setProductivity(getProductivity() + 1);
        c1->moveCow(dir);
        if(getGrassContent()<getSize()*5){
            if(c1->add())
                setGrassContent(getGrassContent()+addGrassEachTime);
        }
		if (getGrassContent() > 0)
			setGrassContent(getGrassContent() - c1->eat());
        int j= c1->update();

        if(c1->getFindEnemy()){
            addx(sentivityToTiger*move1[j][0]);
            addy(sentivityToTiger*move1[j][1]);
            c1->setFindEnemy(0);
            enemy[j]+=enemy_plus;
        }
        else
		{
            addx(move1[j][0]);
            addy(move1[j][1]);
        }



		++c1;
    }

    if(getSize()>=14)
        return 2;
    return 1;
}

int Listcow::updatedir()
{
	/*
	update the dirction of a herd of cow
	*/
    if (productivity >= (ProReproNeeded +getSize()*10)&& getGrassContent() >= getSize()*2+ContentReproNeeded) {
		birth++;
        productivity -= ProReproNeeded;
        grassContent -= ContentReproNeeded;

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
        direction[1]+=x;
    if(x<0)
        direction[0]-=x;
    return;
}

void Listcow::addy(int y)
{
    if(y>0)
        direction[3]+=y;
    if(y<0)
        direction[2]-=y;
    return;
}

void Listcow::clearDirection(int dir){
    memset(direction,0,sizeof (direction));
    direction[dir] = 1;
    for(int i = 0;i<4;i++){
        if(enemy[i]>0){
        direction[i]-=alert*enemy[i];
        enemy[i]--;
        }
    }
}
