#include "Administrator.h"

#include "Sender.h"

Administrator::Administrator(Users* user): UserDecorator(user) {
}

Administrator::~Administrator() {
}

void Administrator::banUserAccount(Users *user, string reason) {
    vector<ChatRoom*> chatRooms = getChatRooms();
    cout<<user->getName()<<" has been banned. "<<reason<<endl;
    for (ChatRoom* room: chatRooms) {
        room->removeUser(user);
    }
}

void Administrator::removeUserFromChatRoom(Users *user, ChatRoom *cRoom) {
    cRoom->removeUser(user);
}

Users * Administrator::elevateUserPrivileges(Users *user, int type) {
    if (type==1) {
        return new Sender(user);
    }
    return new Administrator(user);
}
