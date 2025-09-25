#ifndef COMMAND_H
#define COMMAND_H
#include "ChatRoom.h"
#include <string>
class Users;
#include "Users.h"
using namespace std;
class Command {

protected:
	ChatRoom* room;
	ChatRoom::ChatMessage message;
	Users* fromUser;

public:
	Command(ChatRoom* room, ChatRoom::ChatMessage message, Users* fromUser) {
		this->room = room;
		this->message = message;
		this->fromUser = fromUser;
	}
	virtual ~Command();
	virtual void execute() = 0;
};

#endif
