#include "listsheep.h"
#include<iostream>
#include<cstring>
int Listsheep::getProReproNeeded() const
{
    return ProReproNeeded;
}

void Listsheep::setProReproNeeded(int value)
{
    ProReproNeeded = value;
}

std::list<Sheep> Listsheep::branchSheep()
{
    s1=slist.begin();

    for(int i = 1;i<7;i++){
        s1++;
    }
    std::list<Sheep>temp;
    temp.insert(temp.begin(),s1,slist.end());
    slist.erase(s1,slist.end());
    setSize(8);
    return temp;
}

Listsheep::Listsheep(int x,int y)
{
    Sheep h(x,y);
    slist.push_back(h);
    setSize(1);
    setProductivity(5);
    setGrassContent(5);
    setProReproNeeded(getProReproNeeded()+rand()%20-10);
    setBirth(init_birth);
    memset(direction,0,sizeof(direction));
    memset(enemy,0,sizeof (enemy));
}

Listsheep::Listsheep(std::list<Sheep>l1)
{
    s1=slist.begin();
    slist.splice(s1,l1);
    setSize(8);
    setProductivity(5);
    setGrassContent(24);
    setProReproNeeded(getProReproNeeded()+rand()%20-10);
    setBirth(0);
    memset(enemy,0,sizeof (enemy));
    memset(direction,0,sizeof(direction));
}

void Listsheep::appendList(Sheep c){

    slist.push_back(c);

}

void Listsheep::removeList(std::list<Sheep>::iterator a){
    slist.erase(a);
}

int Listsheep::traverse()
{
        /*
        one traverse of a herd of sheep
        */
    int dir = updatedir();
    clearDirection(dir);
	s1 = slist.begin();
    while(s1!=slist.end()){
		// std::cout << "S  health: " << s1->getHealth() << " star: " << s1->getStarvationValue() << " state: " << specie[s1->getX()][s1->getY()] <<" content: "<<getGrassContent()<< std::endl;
        if(!s1->live()){
			s1 = slist.erase(s1);
			setSize(getSize() - 1);
            if (slist.empty())return 0;
            if (s1 == slist.end())break;
            setProductivity(getProductivity()+5);
			continue;
        }
        if(getBirth()>0){
            int i = s1->reproduction(dir);
            if(i>=0){
            Sheep c(checkBoard(s1->getX()+move1[i][0]),checkBoard(s1->getY()+move1[i][1]));
            appendList(c);
            setSize(getSize()+1);
            specie[c.getX()][c.getY()]=1;
            setBirth(getBirth() - 1);
            }
        }
        if(specie[s1->getX()][s1->getY()]==2)
            productivity++;
        s1->moveSheep(dir);
        if(getGrassContent()<getSize()*4){
            if(s1->add())
                setGrassContent(getGrassContent()+addGrassEachTime);
        }
        if(getGrassContent()>0)
            grassContent-=s1->eat();
        int j= s1->update();
        if(s1->getFindEnemy()){
            addx(-sentivityToTiger*move1[j][0]);
            addy(-sentivityToTiger*move1[j][1]);
            s1->setFindEnemy(0);
        }
        else
        {
            addx(move1[j][0]);
            addy(move1[j][1]);
        }


		++s1;
    }
    if(getSize()>=16)
        return 2;
    return 1;
}


int Listsheep::updatedir()
{
        /*
        update the dirction of a herd of sheep
        */
    if((productivity>=(ProReproNeeded +getSize()*8))&&getGrassContent()>=ContentReproNeeded){
        birth++;
        productivity-=ProReproNeeded;
        ContentReproNeeded -= ContentReproNeeded;
    }

    return fourmax(direction[0],direction[1],direction[2],direction[3]);
}


int Listsheep::getBirth() const
{
    return birth;
}

void Listsheep::setBirth(int value)
{
    birth = value;
}

int Listsheep::getSize() const
{
    return size;
}

void Listsheep::setSize(int value)
{
    size = value;
}

int Listsheep::getProductivity() const
{
    return productivity;
}

void Listsheep::setProductivity(int value)
{
    productivity = value;
}


void Listsheep::setDirection(int i, int j){
    direction[i]=j;
}


int Listsheep::getGrassContent() const
{
    return grassContent;
}

void Listsheep::setGrassContent(int value)
{
    grassContent = value;
}
void Listsheep::addx(int x)
{
    if(x>0)
        direction[1]+=x;
    if(x<0)
        direction[0]-=x;
}

void Listsheep::addy(int y)
{
    if(y>0)
        direction[3]+=y;
    if(y<0)
        direction[2]-=y;
}
void Listsheep::clearDirection(int dir){
    memset(direction,0,sizeof(direction));
    direction[dir]=1;
    for(int i = 0;i<4;i++){

        if(enemy[i]>0){
        direction[i]-=alert*enemy[i];
        enemy[i]--;
        }

    }
}
