#include "Sender.h"

void Sender::send(string message, ChatRoom *room) {
    ChatRoom::ChatMessage* msg = new ChatRoom::ChatMessage();
    msg->message = message;
    msg->sender = this;
    msg->timestamp = time(NULL);

    room->sendMessage(msg);
}
