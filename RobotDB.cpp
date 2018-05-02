//
// Created by alonj on 18-Apr-18.
//
#include "Map.h"
#include "RobotDB.h"


int get_robot_ptr(string &RobotID){
    int place = -1;
    for(vector<int>::size_type i=0; i<Robot_ID.size(); i++){
        if(Robot_ID[i] == RobotID){
            place = i;
        }
    }
    return place;
}


bool DB_robot_in_map(string &RobotID){
    int index = get_robot_ptr(RobotID);
    return inMapLimit(Pos_x[index],Pos_y[index]);
}

bool DB_Place(string &RobotID, int &pos_x, int &pos_y) { // TODO add case where Place func fails
    if(!inMapLimit(pos_x, pos_y)) return false;
    int Robot_ptr = get_robot_ptr(RobotID);
    if(Robot_ptr == -1){
        Robot_Count++;
        Robot_ID.push_back(RobotID);
        Pos_x.push_back(pos_x);
        Pos_y.push_back(pos_y);
        Score.push_back(0);
        Bin_Status.push_back(0);
    }
    else{
        Pos_x[Robot_ptr] = pos_x;
        Pos_y[Robot_ptr] = pos_y;
    }
    return true;
}

void DB_Move(string &RobotID, string &Direction) {
    int currentRobot = get_robot_ptr(RobotID);
    int curr_x = Pos_x[currentRobot];
    int curr_y = Pos_y[currentRobot];
    int new_x(curr_x), new_y(curr_y);
    if(Direction == "U" || Direction == "UL" || Direction == "UR") {new_x = --curr_x;}
    if(Direction == "D" || Direction == "DL" || Direction == "DR") {new_x = ++curr_x;}
    if(Direction == "L" || Direction == "UL" || Direction == "DL") {new_y = --curr_y;}
    if(Direction == "R" || Direction == "UR" || Direction == "DR") {new_y = ++curr_y;}
    if(inMapLimit(new_x, new_y)){
        Pos_x[currentRobot] = new_x;
        Pos_y[currentRobot] = new_y;
    }
}

void DB_Clean(string &RobotID) {
    int currentRobot = get_robot_ptr(RobotID);
    if(Bin_Status[currentRobot] == 5){
        Pos_x[currentRobot] = 0;
        Pos_y[currentRobot] = 0;
        Bin_Status[currentRobot] = 0;
        return;
    }
    Bin_Status[currentRobot]++;
    int curr_x = Pos_x[currentRobot];
    int curr_y = Pos_y[currentRobot];
    int current_cell_status = get_cell_status(curr_x, curr_y);
    cleanDirt(curr_x, curr_y);
    if (current_cell_status != get_cell_status(curr_x, curr_y)) Score[currentRobot]++;
}

void DB_Delete(string &RobotID) {
    int currentRobot = get_robot_ptr(RobotID);
    if(currentRobot == -1) return;
    Score.erase(Score.begin()+currentRobot-1);
    Pos_x.erase(Pos_x.begin()+currentRobot-1);
    Pos_y.erase(Pos_y.begin()+currentRobot-1);
    Bin_Status.erase(Bin_Status.begin()+currentRobot-1);
    Robot_ID.erase(Robot_ID.begin()+currentRobot-1);
    Robot_Count--;
}

bool DB_exist_in_coord(int &pos_x, int &pos_y){
    for(vector<int>::size_type i = 0; i < Robot_Count; i++) {
        if (Pos_y[i] == pos_y && Pos_x[i] == pos_x) {
            return true;
        }
    }
    return false;
}