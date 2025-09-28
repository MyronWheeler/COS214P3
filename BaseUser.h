#ifndef COS214P3_NORMALUSER_H
#define COS214P3_NORMALUSER_H
#include "Users.h"
using namespace std;
class BaseUser: public Users {
    friend class UserDecorator;
protected:
    vector<ChatRoom*> chatRooms; // changed to be a vector
    string name;
    vector<Command*> commandQueue;
    int id;
public:
    BaseUser(string name, int id);
    virtual ~BaseUser();
    void addCommand(Command* command);
    int getId();

    void executeAll();
    void setChatRooms(ChatRoom* rooms);
    string getName() const;

    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room);
protected:
    virtual vector<ChatRoom*> getChatRooms();
};


#endif //COS214P3_NORMALUSER_H