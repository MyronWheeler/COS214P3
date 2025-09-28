#ifndef COS214P3_SENDER_H
#define COS214P3_SENDER_H
#include "UserDecorator.h"


class Sender: public UserDecorator {
    public:
    Sender(Users* user): UserDecorator(user){};
    virtual ~Sender(){};
    virtual void send(string message, ChatRoom* room) override;
};


#endif //COS214P3_SENDER_H