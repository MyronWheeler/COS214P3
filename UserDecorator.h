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
    virtual void addCommand(Command* command) override;

    virtual void executeAll() override;
    virtual void setChatRooms(ChatRoom* rooms) override;
    virtual string getName() override;
    virtual void send(string message, ChatRoom* room)=0;
    virtual int getId()override;

    virtual vector<ChatRoom*> getChatRooms();
friend class Administrator;//to access the getChatRooms securely
};

#endif //COS214P3_USERDECORATOR_H