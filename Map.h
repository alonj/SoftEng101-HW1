#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>

using std::string;

/** Add a dirt to the map, meaning place 1 at x,y location
 * @param x: x coordinate
 * @param y: y coordinate
 */
void addDirt(const int x, const int y);

void cleanDirt(const int x, const int y);

/**
 * Check if x,y coordinates is valid. valid - if the coordinates in the map is in the map limits.
 * @param x: x coordinate
 * @param y: y coordinate
 * @return: True if the if coordinates are valid, false otherwise.
 */
bool inMapLimit (int x, int y);

#endif