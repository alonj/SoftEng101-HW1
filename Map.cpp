#include <iostream>
#include "Map.h"
#include <string>

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
    if (!inMapLimit(x,y))
        gmap[x][y]=0;
}

//####################################################################################################

bool inMapLimit (const int x, const int y)
{
	if (x>=0 && x<S_HIGH && y>=0 && y<S_WIDTH)
		return true;
	else
		return false;
}