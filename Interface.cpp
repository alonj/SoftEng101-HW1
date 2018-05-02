#include "Interface.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "RobotDB.h"
#include "Map.h"
#include "Printer.h"

//
// Created by alonj on 18-Apr-18.
//
using namespace std;

void StartControl(){
    Robot_Count = 0;
    string CommandInput;
    vector<string> CommandParse;
    std::cout << "Start entering commands:" << std::endl;
    string CurrCommand;
    string RobotID, Direction;
    int x, y;
    while(!cin.eof()){
        cin>>CurrCommand;
        if(CurrCommand == "Move"){
            cin >> RobotID;
            cin >> Direction;
            if(DB_robot_in_map(RobotID)) {
                DB_Move(RobotID, Direction);
                PrintRobotPlace(RobotID, x, y);
            }
        }
        else if (CurrCommand == "AddDirt"){
            cin >> x;
            cin >> y;
            if(!DB_exist_in_coord(x, y) && inMapLimit(x, y))
                addDirt(x, y);
        }
        else if (CurrCommand == "Clean"){
            cin >> RobotID;
            if(DB_robot_in_map(RobotID)) DB_Clean(RobotID);
        }
        else if (CurrCommand == "Place"){
            cin >> RobotID;
            cin >> x;
            cin >> y;
            bool success = DB_Place(RobotID, x, y);
            if(success) PrintRobotPlace(RobotID, x, y);
        }
        else if (CurrCommand == "Delete"){
            cin >> RobotID;
            DB_Delete(RobotID);
        }
        else if (CurrCommand == "MoveMulti"){
            string nextWord;
            cin >> nextWord;
            while(nextWord != "end"){
                DB_Move(RobotID, nextWord);
                cin >> nextWord;
            }
        }
    }
}
