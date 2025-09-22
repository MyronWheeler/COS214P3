#ifndef DOGORITHM_H
#define DOGORITHM_H
#include "ChatRoom.h"
class Dogorithm : public ChatRoom {
    //same shit as ctrlcat
    private:
    vector<Users*> users;
    vector<string> chatHistory;
public:
    Dogorithm();
    void registerUser(Users* User) override;
    void sendMessage(string message, Users* fromUser) override;
    void saveMessage(string message, Users* fromUser) override;
    void removeUser(Users* user) override;




};

#endif
