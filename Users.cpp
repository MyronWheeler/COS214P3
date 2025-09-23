#include "Users.h"
#include <iostream>
#include <string>
using namespace std;

Users::Users(string name){
    chatRooms = vector<ChatRoom*>();
    this->name = name;
    commandQueue = vector<Command*>();
}

Users::~Users() {
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
void Users::addCommand(Command* command){
    commandQueue.push_back(command);
}
void Users::executeAll(){
    for(Command* command : commandQueue){
        command->execute();
        delete command; //free the memory
    }
    commandQueue.clear(); // Clear the vector
}