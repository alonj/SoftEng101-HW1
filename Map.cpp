#include <iostream>
#include "Map.h"
#include <string>
#include "RobotDB.h"

#define S_HIGH (7) // define the numbers of rows
#define S_WIDTH (7) // define the numbers of columns

using std::string;

int gmap [S_HIGH][S_WIDTH] =
{
{ 0 , 1 , 1 , 1 , 1 , 1 , 1},
{ 1 , 0 , 0 , 0 , 1 , 0 , 1},
{ 0 , 0 , 1 , 1 , 1 , 0 , 1},
{ 1 , 0 , 0 , 0 , 0 , 0 , 1},
{ 1 , 1 , 1 , 0 , 1 , 0 , 1},
{ 1 , 0 , 0 , 0 , 0 , 0 , 1},
{ 1 , 0 , 1 , 1 , 1 , 1 , 1}
} ;

/**
 * ###################### Module functions ######################
 */

void addDirt(const int x, const int y)
{
    if (inMapLimit(x,y))
        gmap[x][y]=1;
}

void cleanDirt(const int x, const int y)
{
    if (inMapLimit(x,y))
    {
        gmap[x][y]=0;
    }

}

//####################################################################################################

bool inMapLimit (const int x, const int y)
{
	if (x>=0 && x<S_HIGH && y>=0 && y<S_WIDTH)
		return true;
	else
		return false;
}

int get_cell_status(int x, int y){return gmap[x][y];}

void printMap(){
    std::cout<<"Current Map Status:"<<std::endl;
    for(int i = 0; i < S_HIGH; i ++){
        for(int j = 0; j < S_WIDTH ; j++){
            if(DB_exist_in_coord(i,j) && gmap[i][j] == 1) std::cout<<'d';
            else if(DB_exist_in_coord(i,j)) std::cout<<'c';
            else std::cout<<gmap[i][j];
        }
        std::cout<<std::endl;
    }
}