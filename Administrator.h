#ifndef COS214P3_ADMINISTRATOR_H
#define COS214P3_ADMINISTRATOR_H
#include "UserDecorator.h"


class Administrator: public UserDecorator {
public:
    Administrator(Users* user);
    ~Administrator();
    void banUserAccount(Users* user, string reason);
    void removeUserFromChatRoom(Users* user, ChatRoom* cRoom);
    Users* elevateUserPrivileges(Users* user, int type);

};


#endif //COS214P3_ADMINISTRATOR_H