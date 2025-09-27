#include "UserDecorator.h"

UserDecorator::UserDecorator(Users *user) {
    this->user = user;
}

UserDecorator::~UserDecorator() {
    delete user;
}

void UserDecorator::receive(ChatRoom::ChatMessage *message, ChatRoom *room) {
    user->receive(message, room);
}
