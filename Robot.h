//
// Created by alonj on 23-Apr-18.
//

#ifndef HW1ATTACHEDCODEFILES_ROBOT_H
#define HW1ATTACHEDCODEFILES_ROBOT_H

#import "string"
#import "Map.h"
using namespace std;

class Robot {
private:
    int _score;
    int _pos_x;
    int _pos_y;
    int _bin_status;
    static string _name;
public:
    Robot(string name, int pos_x, int pos_y){
        _name = name;
        _pos_x = pos_x;
        _pos_y = pos_y;
        _score = 0;
        _bin_status = 0;
    }
    void set_position(int new_pos_x, int new_pos_y){
        if (!inMapLimit(new_pos_x, new_pos_y)) return;
        _pos_x = new_pos_x;
        _pos_y = new_pos_y;
    };
    string get_name(){return _name;};
    int get_score(){return _score;};
    int get_pos(char t){
        if(t=='x') return _pos_x;
        else return _pos_y;
    }
    void inc_score(){_score++;};
    void inc_bin(){_bin_status++;};
    void reset_bin(){_bin_status = 0;};
    int get_bin_status(){return _bin_status;};
};


#endif //HW1ATTACHEDCODEFILES_ROBOT_H
