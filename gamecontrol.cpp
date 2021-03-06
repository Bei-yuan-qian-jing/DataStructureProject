#include "gamecontrol.h"

gameControl::gameControl(QObject *parent) : QObject(parent)
{

}


void gameControl::initGrass(int GrassNumber)
{

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            grassList[i][j] =new Grass(i, j);
        }
    }
    /*
    randomly initialize the grass, the size of the map can be changed
    */
    for (int i = 0; i < GrassNumber; i++)
    {
        int a = rand() % 100;
        int b = rand() % 100;
        if (grassa[a][b] != 0)continue;
        grassa[a][b] = 10;
    }
}

void gameControl::initTiger(int tigerNumber)
{
    /*
    randomly initialize the tiger, and check whether there are not other tigers in its vision
    */

    tigerlist.setSize(tigerNumber);
    int temp = tigerNumber;
    srand(time(NULL));
    while (temp)
    {
        int a = rand() % 100;
        int b = rand() % 100;
        if (specie[a][b] != 0)continue;

        int check = 0;
        for (int i =  (a - tigerView >= 0) ? (a - tigerView) : 0 ; i < ((a + tigerView < 100) ? (a + tigerView) : 99); i++)
        {
            for (int j = ((b - tigerView >= 0) ? (b - tigerView) : 0 ); j < ((b + tigerView < 100) ? (b + tigerView) :99); j++)
            {
                if (specie[i][j] == 7 || specie[i][j] == 8) {
                    check=1;
                    break;
                }
            }
            if (check == 1)break;
        }
        if (check==0) {
            int sex = rand() % 2;
            tigerlist.append(Tiger(a, b, sex));
            temp--;
        }

    }
    //cout << "----------------";
}

void gameControl::initCow(int CowherdNumber)
{
    /*
    randomly initialize the cow, and check whether there are not other tigers in its vision
    */
    int temp = CowherdNumber;
    int cnt = 0;
    while (temp)
    {
        int a = rand() % 100 ;
        int b = rand() % 100 ;
        if (specie[a][b] != 0)continue;
        int check = 0;
        for (int i =  ((a - herdView >= 0) ? (a - herdView) : 0) ; i < ((a + herdView < 100) ? (a + herdView) :99); i++)
        {
            for (int j =  ((b - herdView >= 0) ? (b - herdView) : 0) ; j < ((b + herdView < 100) ? (b + herdView) : 99)
        ; j++)
            {

                if (specie[i][j] == 7 || specie[i][j] == 8)
                {
                    check = 1;
                    break;
                }

            }
            if (check == 1) break;
        }
        if (check == 0) {
            cowlist.push_back(Listcow(a, b));
            cnt++;

            temp--;

        }
    }

}

void gameControl::initsheep(int SheepherdNumber)
{
    /*
    randomly initialize the sheep, and check whether there are not other tigers in its vision
    */
    int temp = SheepherdNumber;
    int cnt = 0;
    while (temp)
    {
        int a = rand() % 100;
        int b = rand() % 100;
        int check = 0;
        if (specie[a][b] != 0)continue;
        for (int i = ((a - herdView >= 0) ? (a - herdView) : 0); i < ((a + herdView < 100) ? (a + herdView) : 99)
            ; i++)
        {
            for (int j = ((b - herdView >= 0) ? (b - herdView) : 0); j < ((b + herdView < 100) ? (b + herdView) : 99)
                ; j++)
            {

                if (specie[i][j] == 7 || specie[i][j] == 8)
                {
                    check = 1;
                    break;
                }

            }
            if (check == 1) break;
        }
        if (check == 0) {
            sheeplist.push_back( Listsheep(a, b));
            cnt++;
            temp--;

        }
    }

}

void gameControl::init(int GrassNumber, int CowherdNumber, int SheepHerdNumber, int TigerNumber)
{
    memset(specie,0,sizeof(specie));
    memset(grassa,0,sizeof(specie));
    cowlist.clear();
    sheeplist.clear();
    tigerlist.cleartiger();
    grassNum = GrassNumber;
    cowherdNum = CowherdNumber;
    sheepherdNum = SheepHerdNumber;
    tigerNum = TigerNumber;
    srand(time(NULL));
    initGrass(GrassNumber);
    initTiger(TigerNumber);
    initCow(CowherdNumber);
    initsheep(SheepHerdNumber);
}

void gameControl::nextTurn()
{

    for (int i = 0; i <100; i++)
    {
        for (int j = 0; j < 100; j++) {
            grassList[i][j]->live();

        }
    }
   // std::cout << count<<std::endl;

    if (!tigerlist.checkempty()) {
        if (!tigerlist.traverse());
           // std::cout << "All Tigers died!!!";
       // std::cout <<"tiger: "<< tigerlist.getSize() << std::endl;
    }
    if (!cowlist.empty()) {
        for (lc = cowlist.begin(); lc != cowlist.end();) {
            int i = lc->traverse();
            if(i==0){
                cowlist.erase(lc++);
                continue;
            }
            if(i==2){
                cowlist.push_back(Listcow(lc->branchCow()));
            }

            lc++;
        }
    }
    if (!sheeplist.empty()) {
        for (ls = sheeplist.begin(); ls != sheeplist.end(); ) {
            int i = ls->traverse();
            if(i==0){
                sheeplist.erase(ls++);
                continue;
            }
            if(i==2){
                sheeplist.push_back(Listsheep(ls->branchSheep()));
            }

            ls++;
        }
    }
}

//int main()
//{
//    init(2000,200,200,10);
//    for(int i = 1;i <= 20;i++){
//        nextTurn();
//        cout << std::setw(2);
//        for(int j = 0;j < 20;j++){
//            for(int k = 0;k < 20;k++){
//                cout << specie[j][k] << std::setw(2);
//            }
//            printf("\n");
//        }
//    }
//}


