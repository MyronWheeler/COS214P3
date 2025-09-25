#ifndef USERS_H
#define USERS_H
#include "ChatRoom.h"
#include <string>
using namespace std;
class Command;
#include "Command.h"
class Users {// Should have a setMediator function?
	// added getters and setters for name and chatRooms

protected:
	vector<ChatRoom*> chatRooms; // changed to be a vector
	string name;
	vector<Command*> commandQueue;

public:
	Users(string name);
	~Users();
    void send(ChatRoom::ChatMessage message, ChatRoom* room);

    void receive(ChatRoom::ChatMessage message, Users* fromUser, ChatRoom* room);

	void addCommand(Command* command);

	void executeAll();
	void setChatRooms(ChatRoom* rooms);
	string getName() const;
	
};

#endif
