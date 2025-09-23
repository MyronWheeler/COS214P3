#include "ChatRoom.h"

ChatRoom::ChatRoom() {
    users = vector<Users*>();
    chatHistory = vector<chatMessage>();
}

ChatRoom::~ChatRoom() {
}
