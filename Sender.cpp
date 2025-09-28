#include "Sender.h"
#include "LogMessageCommand.h"
#include "SendMessageCommand.h"
void Sender::send(string message, ChatRoom *room) {
    ChatRoom::ChatMessage* msg = new ChatRoom::ChatMessage();
    msg->message = message;
    msg->sender = this;
    msg->timestamp = time(NULL);
    // Chnaged to we make the command here and add it to the queue
    user->addCommand(new SendMessageCommand(room, msg));
    user->addCommand(new LogMessageCommand(room, msg)); // I say it should save as well when the user says send or not?
}



