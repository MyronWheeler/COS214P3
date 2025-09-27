#include "ChatRoom.h"
#include "VectorCHIterator.h"

ChatRoom::ChatRoom() {
    users = vector<Users*>();
    chatHistory = vector<ChatMessage*>();
}

ChatRoom::~ChatRoom() {
    //Users exist after a chatroom is destroyed.
}
VectorCHIterator* ChatRoom::createIterator() {
    return new VectorCHIterator(chatHistory);
}
