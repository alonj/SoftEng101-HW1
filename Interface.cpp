#include "Interface.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "RobotDB.h"
#include "Map.h"

//
// Created by alonj on 18-Apr-18.
//
using namespace std;

void StartControl(){
    RobotDB main_db;
    string CommandInput;
    vector<string> CommandParse;
    std::cout << "Start entering commands:" << std::endl;
    while(!cin.eof()){
        getline(cin, CommandInput);
        string CurrentWord;
        for(string::iterator sit=CommandInput.begin(); sit != CommandInput.end(); sit++){
            if(*sit != ' '){
                CurrentWord.push_back(*sit);
            }
            else{
                CommandParse.push_back(CurrentWord);
                CurrentWord.clear();
            }
        }
        CommandParse.push_back(CurrentWord);
    }
    string CurrentCommand = *CommandParse.begin();
    CommandParse.erase(CommandParse.begin());
    if(CurrentCommand == "Move"){
        vector<string>::iterator it = CommandParse.begin();
        string RobotID = *it;
        string Direction = *++it;
        CommandParse.erase(CommandParse.begin(), it);
        main_db.Move(RobotID, Direction);
    }
    else if (CurrentCommand == "AddDirt"){
        vector<string>::iterator it = CommandParse.begin();
        unsigned x, y;
        stringstream ss;
        ss << *it;
        ss >> x;
        ss << *++it;
        ss >> y;
        CommandParse.erase(CommandParse.begin(), it);
        addDirt(x, y);
    }
    else if (CurrentCommand == "Clean"){
        vector<string>::iterator it = CommandParse.begin();
        string RobotID = *it;
        CommandParse.erase(it);
        main_db.Clean(RobotID);
    }
    else if (CurrentCommand == "Place"){
        vector<string>::iterator it = CommandParse.begin();
        string RobotID = *it;
        int x, y;
        stringstream ss;
        ss << *++it;
        ss >> x;
        ss << *++it;
        ss >> y;
        CommandParse.erase(CommandParse.begin(), it);
        main_db.Place(RobotID, x, y);
    }
    else if (CurrentCommand == "Delete"){
        vector<string>::iterator it = CommandParse.begin();
        string RobotID = *it;
        CommandParse.erase(it);
        main_db.Delete(RobotID);
    }
    else if (CurrentCommand == "MoveMulti"){
        vector<string>::iterator it = CommandParse.begin();
        string RobotID = *it;
        while(*++it != "end"){
            main_db.Move(RobotID, *it);
        }
        CommandParse.erase(CommandParse.begin(), it);
    }
}
