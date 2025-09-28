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
    void addCommand(Command* command);

    void executeAll();
    void setChatRooms(ChatRoom* rooms);
    virtual string getName();
    virtual void send(string message, ChatRoom* room)=0;
    virtual int getId();
    virtual vector<ChatRoom*> getChatRooms();
friend class Administrator;//to access the getChatRooms securely
};

#endif //COS214P3_USERDECORATOR_H