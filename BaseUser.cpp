#include "BaseUser.h"

BaseUser::BaseUser(string name) {
    chatRooms = vector<ChatRoom*>();
    this->name = name;
    commandQueue = vector<Command*>();
}

BaseUser::~BaseUser() {
    for(Command* command : commandQueue){
        delete command; //free the memory
    }
    commandQueue.clear(); // Clear the vector
}

string BaseUser::getName() const {
    return name;
}

void BaseUser::addCommand(Command *command) {
    commandQueue.push_back(command);
}

void BaseUser::send(string message, ChatRoom* room){
    /*ChatRoom::ChatMessage* msg = new ChatRoom::ChatMessage();
    msg->message = message;
    msg->sender = this;
    msg->timestamp = time(NULL);

    room->sendMessage(msg);*/
    cout << "You do not have permission to send messages." << endl;
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
