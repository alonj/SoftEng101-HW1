#include "Interface.h"
#include <vector>
#include <sstream>
#include <queue>
#include "RobotDB.h"
#include "Map.h"
#include "Printer.h"

//
// Created by alonj on 18-Apr-18.
//

extern vector<string> Robot_ID;
extern vector<int> Score;
extern vector<int> Bin_Status;
extern int Robot_Count;

using namespace std;

void CommandRoutine(){
    string CurrCommand;
    string RobotID, Direction;
    int x, y;
    cin >> CurrCommand;
    while(!cin.eof()){
        if(CurrCommand == "Move"){
            cin >> RobotID;
            cin >> Direction;
            if(DB_robot_in_map(RobotID)) {
                DB_Move(RobotID, Direction);
                PrintRobotPlace(RobotID, DB_get_robot_pos(RobotID,'x'), DB_get_robot_pos(RobotID,'y'));
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
            if(DB_robot_in_map(RobotID)) {
                DB_Clean(RobotID);
                PrintClean(RobotID, DB_get_robot_pos(RobotID,'x'), DB_get_robot_pos(RobotID,'y'));
            }
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
            std::queue<int> printQueue;
            string nextDirection;
            cin >> RobotID;
            cin >> nextDirection;
            while(nextDirection != "end"){
                if(DB_robot_in_map(RobotID)) {
                    DB_Move(RobotID, nextDirection);
                    printQueue.push(DB_get_robot_pos(RobotID, 'x'));
                    printQueue.push(DB_get_robot_pos(RobotID, 'y'));
                }
                cin >> nextDirection;
            }
            while(!printQueue.empty()){
                int a = printQueue.front();
                printQueue.pop();
                int b = printQueue.front();
                printQueue.pop();
                PrintRobotPlace(RobotID, a, b);
            }
        }
        printMap();
        cin >> CurrCommand;
    }
}

void StartControl(){
    Robot_Count = 0;
    cout << "Start entering commands:" << endl;
    CommandRoutine();
    PrintTable(Robot_ID, Score, Bin_Status);
}
