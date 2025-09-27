#ifndef USERS_H
#define USERS_H
#include "ChatRoom.h"
#include <string>
#include <iostream>
using namespace std;
class Command;
#include "Command.h"
class Users {// Should have a setMediator function?
	// added getters and setters for name and chatRooms
public:
	Users();
	virtual ~Users();
    virtual void send(ChatRoom::ChatMessage* message, ChatRoom* room)=0;

    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room)=0;
	virtual string getName() const;
};

#endif
