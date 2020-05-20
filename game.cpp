#include "game.h"
#include <bits/stdc++.h>

Game::Game(QObject *parent) : QObject(parent)
{

}

void Game::init(int gs, int cs, int ss, int ts){
    std::cout << "init the game";
    this->grass_num = gs;
    this->cow_num = cs;
    this->sheep_num = ss;
    this->tiger_num = ts;
    for(int i = 0; i < maxn; i++)
        for(int j = 0; j < maxn; j++)
            this->board[i][j] = 0;
}

void Game::nexterm(){
    std::cout << "nextern" << std::endl;
    std::cout << "init the grass" << std::endl;
    int cnt = 0;
    srand((unsigned)time(NULL));
    while(cnt < this->grass_num) {
         int x = rand() % maxn;
         int y = rand() % maxn;
         this->board[x][y] = 1;
         cnt++;

    }

    std::cout << "init the cow" << std::endl;
    cnt = 0;
    while(cnt < this->cow_num) {
         int x = rand() % maxn;
         int y = rand() % maxn;
         this->board[x][y] = 2;
         cnt++;
    }

    std::cout << "init the sheep" << std::endl;
    cnt = 0;
    while(cnt < this->sheep_num) {
         int x = rand() % maxn;
         int y = rand() % maxn;
         this->board[x][y] = 3;
         cnt++;
    }

   std::cout << "init the tiger" << std::endl;
    cnt = 0;
    while(cnt < this->tiger_num) {
         int x = rand() % maxn;
         int y = rand() % maxn;
         this->board[x][y] = 4;
         cnt++;
    }
}

void Game::show() {
    int cnt = 0;
    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < maxn; j++) {
            std::cout << this->board[i][j] << " ";
            if(this->board[i][j])
                cnt++;
        }
        std::cout << std::endl;
    }
    std::cout << cnt << std::endl;
}
