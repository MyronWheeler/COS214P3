#include "Administrator.h"

Administrator::Administrator(Users* user): UserDecorator(user) {
}

Administrator::~Administrator() {
}

void Administrator::banUserAccount(Users *user, string reason) {
}

void Administrator::removeUserFromChatRoom(Users *user, ChatRoom *cRoom) {
}

Users * Administrator::elevateUserPrivileges(Users *user) {
}
