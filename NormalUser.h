#ifndef COS214P3_NORMALUSER_H
#define COS214P3_NORMALUSER_H
#include "Users.h"
using namespace std;
class NormalUser: public Users {
public:
    NormalUser(string name): Users(name){};
    void addCommand(Command* command);
    virtual void send(string message, ChatRoom* room);

    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room);
};


#endif //COS214P3_NORMALUSER_H