#ifndef LOGMESSAGECOMMAND_H
#define LOGMESSAGECOMMAND_H
#include "Command.h"

class LogMessageCommand : public Command {
public:
	LogMessageCommand(ChatRoom* room, ChatRoom::ChatMessage* message):Command(room, message) {}
	void execute();
};

#endif
