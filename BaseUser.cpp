#include "BaseUser.h"

BaseUser::BaseUser(string name) {
    chatRooms = vector<ChatRoom*>();
    this->name = name;
    commandQueue = vector<Command*>();
    // I dont know how you assign user IDs
    this->id = 0;//just for testing
}

BaseUser::~BaseUser() {
    for(Command* command : commandQueue){
        delete command; //free the memory
    }
    commandQueue.clear(); // Clear the vector
}

string BaseUser::getName() {
    return name;
}

void BaseUser::addCommand(Command *command) {
    commandQueue.push_back(command);
}

void BaseUser::receive(ChatRoom::ChatMessage* message, ChatRoom* room){
    cout << "[" << room << "] " << message->sender->getName() << ": " << message->message << endl;
}

void BaseUser::executeAll() {
    for(Command* command : commandQueue){
        command->execute();
        delete command; //free the memory
    }
    commandQueue.clear(); // Clear the vector
}

void BaseUser::setChatRooms(ChatRoom *rooms) {
    chatRooms.push_back(rooms);
}

int BaseUser::getId(){
    return id;
}
