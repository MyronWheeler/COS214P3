#ifndef COS214P3_USERDECORATOR_H
#define COS214P3_USERDECORATOR_H
#include "Users.h"

class UserDecorator: public Users {
protected:
    Users* user;
public:
    UserDecorator(Users* user);
    virtual ~UserDecorator() override;
    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room)override;
    void addCommand(Command* command);

    void executeAll();
    void setChatRooms(ChatRoom* rooms);
    string getName() const;
    virtual void send(string message, ChatRoom* room)=0;
    virtual int getId()override;

};

#endif //COS214P3_USERDECORATOR_H