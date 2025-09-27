#ifndef COS214P3_NORMALUSER_H
#define COS214P3_NORMALUSER_H
#include "Users.h"
using namespace std;
class BaseUser: public Users {
protected:
    vector<ChatRoom*> chatRooms; // changed to be a vector
    string name;
    vector<Command*> commandQueue;
public:
    BaseUser(string name);
    virtual ~BaseUser();
    void addCommand(Command* command);

    void executeAll();
    void setChatRooms(ChatRoom* rooms);
    string getName() const;

    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room);
};


#endif //COS214P3_NORMALUSER_H