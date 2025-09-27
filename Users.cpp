#include "Users.h"

Users::Users(string name){
    chatRooms = vector<ChatRoom*>();
    this->name = name;
    commandQueue = vector<Command*>();
}

Users::~Users() {
    for(Command* command : commandQueue){
        delete command; //free the memory
    }
    commandQueue.clear(); // Clear the vector
}

string Users::getName() const {
    return name;
}
void Users::setChatRooms(ChatRoom* rooms){
    chatRooms.push_back(rooms);
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