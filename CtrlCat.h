#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"
#include "Users.h"
#include <iostream>
#include <string>

class CtrlCat : public ChatRoom {
public:
    CtrlCat();
    void registerUser(Users* User) override;
    void sendMessage(ChatMessage* message) override;
    void saveMessage(ChatMessage* message) override;
    void removeUser(Users* user) override;
};

#endif
