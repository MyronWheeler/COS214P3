#ifndef COS214P3_USERDECORATOR_H
#define COS214P3_USERDECORATOR_H
#include "Users.h"


class UserDecorator: public Users {
protected:
    Users* user;
public:
    UserDecorator(Users* user);
    virtual ~UserDecorator();
    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room);

};

//virtual void send(ChatRoom::ChatMessage* message, ChatRoom* room)=0;
#endif //COS214P3_USERDECORATOR_H