#ifndef COS214P3_NORMALUSER_H
#define COS214P3_NORMALUSER_H
#include "Users.h"
using namespace std;
class BaseUser: public Users {
protected:
    vector<ChatRoom*> chatRooms; // changed to be a vector
    string name;
    vector<Command*> commandQueue;
    int id;
public:
    BaseUser(string name, int id);
    virtual ~BaseUser() override;
    virtual void addCommand(Command* command) override;
    virtual int getId() override;

    virtual void executeAll() override;
    virtual void setChatRooms(ChatRoom* rooms) override;
    virtual string getName() override;

    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room) override;
};


#endif //COS214P3_NORMALUSER_H