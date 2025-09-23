#include "ChatRoom.h"

ChatRoom::ChatRoom() {
    users = vector<Users*>();
    chatHistory = vector<ChatMessage>();
}

ChatRoom::~ChatRoom() {
    //Users exist after a chatroom is destroyed.
}
