#include "UserDecorator.h"

UserDecorator::UserDecorator(Users *user):Users() {
    this->user = user;
}

UserDecorator::~UserDecorator() {
    delete user;
}

void UserDecorator::receive(ChatRoom::ChatMessage *message, ChatRoom *room) {
    user->receive(message, room);
}

void UserDecorator::addCommand(Command *command) {
    user->addCommand(command);
}

void UserDecorator::executeAll() {
    user->executeAll();
}

void UserDecorator::setChatRooms(ChatRoom *rooms) {
    user->setChatRooms(rooms);
}

string UserDecorator::getName() {
    return user->getName();
}

void UserDecorator::send(string message, ChatRoom *room) {
    user->send(message, room);
}

int UserDecorator::getId() {
    return user->getId();
}

vector<ChatRoom *> UserDecorator::getChatRooms() {
    return user->getChatRooms();
}
void UserDecorator::removeChatRoom(ChatRoom* room) {
    user->removeChatRoom(room);
}
