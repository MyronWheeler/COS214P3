#include "Users.h"
#include <iostream>
#include <string>
using namespace std;

Users::Users(string name){
    this->name = name;
    commandQueue = NULL;
}

string Users::getName() const {
    return name;
}
void Users::setChatRooms(ChatRoom* rooms){
    chatRooms.push_back(rooms);
}

void Users::send(string message, ChatRoom* room){
    room->sendMessage(message, this);
}
void Users::receive(string message, Users* fromUser, ChatRoom* room){
    cout << "[" << room << "] " << fromUser->getName() << ": " << message << endl;
}