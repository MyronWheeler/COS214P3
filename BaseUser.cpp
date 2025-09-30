#include "BaseUser.h"

BaseUser::BaseUser(string name, int id) {
    chatRooms = vector<ChatRoom*>();
    this->name = name;
    commandQueue = vector<Command*>();
    this->id = id;
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
    cout << "[" << room->getRoomName() << "@" << message->timestamp << "] " << message->sender->getName() << ": " << message->message << endl;
}

void BaseUser::executeAll() {
    for(Command* command : commandQueue){
        command->execute();
        delete command; //free the memory
        // cout << "HERE" << endl;
        
    }
    commandQueue.clear(); // Clear the vector
    
}

void BaseUser::setChatRooms(ChatRoom *rooms) {
    chatRooms.push_back(rooms);
}

int BaseUser::getId() {
    return id;
}

vector<ChatRoom *> BaseUser::getChatRooms() {
    return chatRooms;
}
void BaseUser::removeChatRoom(ChatRoom* room) {
    vector<ChatRoom*> newList;
    for (ChatRoom* r : chatRooms) {
        if (r != room) newList.push_back(r);
    }
    chatRooms = std::move(newList);
}

void BaseUser::send(string message, ChatRoom *room) {
    cout << "You do not have permission to send a message" << endl;
}