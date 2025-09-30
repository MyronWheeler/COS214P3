#include "Sender.h"
#include "LogMessageCommand.h"
#include "SendMessageCommand.h"
void Sender::send(string message, ChatRoom *room) {
    // ChatRoom::ChatMessage* msg = new ChatRoom::ChatMessage();
    // msg->message = message;
    // msg->sender = this;
    // msg->timestamp = time(NULL);
    // // Chnaged to we make the command here and add it to the queue
    // user->addCommand(new SendMessageCommand(room, msg));
    // user->addCommand(new LogMessageCommand(room, msg)); // I say it should save as well when the user says send or not?

    ChatRoom::ChatMessage* msg1 = new ChatRoom::ChatMessage();
    msg1->message = message;
    msg1->sender = this;
    msg1->timestamp = time(NULL);

    // create second message for logging (separate allocation to avoid double-free)
    ChatRoom::ChatMessage* msg2 = new ChatRoom::ChatMessage();
    msg2->message = message;
    msg2->sender = this;
    msg2->timestamp = msg1->timestamp;

    // push commands that now own distinct message pointers
    user->addCommand(new SendMessageCommand(room, msg1));
    user->addCommand(new LogMessageCommand(room, msg2));

}



