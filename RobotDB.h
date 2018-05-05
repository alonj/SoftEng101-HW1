//
// Created by alonj on 18-Apr-18.
//

#ifndef HW1ATTACHEDCODEFILES_ROBOTDB_H
#define HW1ATTACHEDCODEFILES_ROBOTDB_H

#include <vector>
#include <string>

using namespace std;

void DB_Move(string &RobotID, string &Direction);
bool DB_Place(string &RobotID, int &pos_x, int &pos_y);
void DB_Clean(string &RobotID);
void DB_Delete(string &RobotID);
bool DB_exist_in_coord(int &pos_x, int &pos_y);
bool DB_robot_in_map(string &RobotID);
int DB_get_robot_pos(string &RobotID, char type);

#endif //HW1ATTACHEDCODEFILES_ROBOTDB_H
