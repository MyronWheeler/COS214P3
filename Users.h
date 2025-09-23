#ifndef USERS_H
#define USERS_H
#include "ChatRoom.h"
#include "Command.h"
#include <string>
using namespace std;

class Users {// Should have a setMediator function?
	// added getters and setters for name and chatRooms

protected:
	vector<ChatRoom*> chatRooms; // changed to be a vecctor
	string name;
	vector<Command*> commandQueue;

public:
	Users(string name);
    void send(string message, ChatRoom* room);

    void receive(string message, Users* fromUser, ChatRoom* room);

	void addCommand(Command* command);

	void executeAll();
	void setChatRooms(ChatRoom* rooms);
	string getName() const;
	
};

#endif
