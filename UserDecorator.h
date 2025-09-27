#ifndef COS214P3_USERDECORATOR_H
#define COS214P3_USERDECORATOR_H
#include "Users.h"


class UserDecorator: public Users {
protected:
    Users* user;
public:
    UserDecorator(Users* user) {};

};


#endif //COS214P3_USERDECORATOR_H