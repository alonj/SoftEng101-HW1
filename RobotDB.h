//
// Created by alonj on 18-Apr-18.
//

#ifndef HW1ATTACHEDCODEFILES_ROBOTDB_H
#define HW1ATTACHEDCODEFILES_ROBOTDB_H

#include <vector>
#include <string>

using namespace std;

static vector<int> Score;
static vector<int> Pos_x;
static vector<int> Pos_y;
static vector<int> Bin_Status;
static vector<string> Robot_ID;
static int Robot_Count;

void DB_Move(string &RobotID, string &Direction);
bool DB_Place(string &RobotID, int &pos_x, int &pos_y);
void DB_Clean(string &RobotID);
void DB_Delete(string &RobotID);
bool DB_exist_in_coord(int &pos_x, int &pos_y);
bool DB_robot_in_map(string &RobotID);

#endif //HW1ATTACHEDCODEFILES_ROBOTDB_H
