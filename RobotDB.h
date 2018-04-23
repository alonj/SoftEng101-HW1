//
// Created by alonj on 18-Apr-18.
//

#ifndef HW1ATTACHEDCODEFILES_ROBOTDB_H
#define HW1ATTACHEDCODEFILES_ROBOTDB_H

#include "Robot.h"
#include <vector>

using namespace std;

class RobotDB{
private:
    vector<Robot> _database;
    int _total_count;
    Robot* get_robot_ptr(string RobotID);
public:
    RobotDB(){_total_count = 0;};
    Robot* Place(string RobotID, int &pos_x, int &pos_y);
    void Move(string RobotID, string Direction);
    void Clean(string RobotID);
    void Delete(string RobotID);
};


#endif //HW1ATTACHEDCODEFILES_ROBOTDB_H
