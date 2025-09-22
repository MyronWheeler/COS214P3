#ifndef CTRLCAT_H
#define CTRLCAT_H
#include "ChatRoom.h"

class CtrlCat : public ChatRoom {
// If we create a chat room, should we already have users for it (as in we have in the constructor)?
// I am gonna have a vector of users in the chat room
private:
    vector<Users*> users;
    vector<string> chatHistory;
public:
    CtrlCat();
    void registerUser(Users* User) override;
    void sendMessage(string message, Users* fromUser) override;
    void saveMessage(string message, Users* fromUser) override;
    void removeUser(Users* user) override;




};

#endif
