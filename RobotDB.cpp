//
// Created by alonj on 18-Apr-18.
//

#include "RobotDB.h"
#include "Robot.h"

Robot* RobotDB::get_robot_ptr(string RobotID){
    vector<Robot>::iterator db_itr = _database.begin();
    bool found = false;
    while(db_itr != _database.end() && !found){
        if(db_itr->get_name() == RobotID){
            found = true;
        }
        else{
            db_itr++;
        }
    }
    return &(*db_itr);
}


Robot* RobotDB::Place(string RobotID, int &pos_x, int &pos_y) {
    Robot* newRobot = new Robot(RobotID, pos_x, pos_y);
    _total_count++;
    _database.push_back(*newRobot);
    return newRobot;
}

void RobotDB::Move(string RobotID, string Direction) {
    Robot* currentRobot = get_robot_ptr(RobotID);
    int curr_x = currentRobot->get_pos('x');
    int curr_y = currentRobot->get_pos('y');
    if(Direction == "L") {currentRobot->set_position(--curr_x,curr_y);}
    else if (Direction == "R") {currentRobot->set_position(++curr_x, curr_y);}
    else if (Direction == "U") {currentRobot->set_position(curr_x, --curr_y);}
    else if (Direction == "D") {currentRobot->set_position(curr_x, ++curr_y);}
    else if (Direction == "LU") {currentRobot->set_position(--curr_x, --curr_y);}
    else if (Direction == "LD") {currentRobot->set_position(--curr_x, ++curr_y);}
    else if (Direction == "RU") {currentRobot->set_position(++curr_x, --curr_y);}
    else if (Direction == "RD") {currentRobot->set_position(++curr_x, ++curr_y);}
}

void RobotDB::Clean(string RobotID) {
    Robot* currentRobot = get_robot_ptr(RobotID);
    if(currentRobot->get_bin_status() == 5){
        currentRobot->set_position(0,0);
        currentRobot->reset_bin();
        return;
    }
    currentRobot->inc_score();
    currentRobot->inc_bin();
    int curr_x = currentRobot->get_pos('x');
    int curr_y = currentRobot->get_pos('y');
    cleanDirt(curr_x, curr_y);
}

void RobotDB::Delete(string RobotID) {
    vector<Robot>::iterator db_itr = _database.begin();
    Robot *delRobot;
    while (db_itr != _database.end() && !found) {
        if (db_itr->get_name() == RobotID) {
            delRobot = &(*db_itr);
            _database.erase(db_itr);
        }
        delete delRobot;
        db_itr++;
    }
}