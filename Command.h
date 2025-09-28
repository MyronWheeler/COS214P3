#ifndef COMMAND_H
#define COMMAND_H
#include "ChatRoom.h"
#include <string>
class Users;
#include "Users.h"
using namespace std;
class Command {

protected:
	ChatRoom::ChatMessage* message;
	ChatRoom* room;

public:
	Command(ChatRoom* room, ChatRoom::ChatMessage* message) {
		this->room = room;
		this->message = message;
	}
	virtual ~Command();
	virtual void execute() = 0;
};

#endif
