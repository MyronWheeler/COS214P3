#ifndef DOGORITHM_H
#define DOGORITHM_H
#include "ChatRoom.h"
#include <iostream>
#include <string>
using namespace std;
#include "Users.h"
class Dogorithm : public ChatRoom {
public:
    Dogorithm();
    void registerUser(Users* User) override;
    void sendMessage(ChatMessage* message) override;
    void saveMessage(ChatMessage* message) override;
    void removeUser(Users* user) override;
    CHIterator* createIterator() override;
};

#endif
