#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"

class CtrlCat : public ChatRoom {
public:
    CtrlCat();
    void registerUser(Users* User) override;
    void sendMessage(string message, Users* fromUser) override;
    void saveMessage(string message, Users* fromUser) override;
    void removeUser(Users* user) override;
};

#endif
