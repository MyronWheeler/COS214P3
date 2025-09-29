/**
 * @file Administrator.h
 * @brief Declares the Administrator decorator for user accounts with admin privileges.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef COS214P3_ADMINISTRATOR_H
#define COS214P3_ADMINISTRATOR_H
#include "UserDecorator.h"

/**
 * @class Administrator
 * @brief Decorator that adds administrative capabilities to a user.
 */
class Administrator: public UserDecorator {
public:
    /**
     * @brief Constructor.
     * @param user Pointer to the user being decorated.
     */
    Administrator(Users* user);

    /**
     * @brief Destructor.
     */
    ~Administrator();

    /**
     * @brief Ban a user account from all chat rooms.
     * @param user The user to ban.
     * @param reason Reason for banning.
     */
    void banUserAccount(Users* user, string reason);

    /**
     * @brief Remove a user from a specific chat room.
     * @param user The user to remove.
     * @param cRoom The chat room to remove the user from.
     */
    void removeUserFromChatRoom(Users* user, ChatRoom* cRoom);

    /**
     * @brief Elevate a user's privileges.
     * @param user The user to elevate.
     * @param type The type of privilege (1 = Sender, else Administrator).
     * @return Pointer to the elevated user.
     */
    Users* elevateUserPrivileges(Users* user, int type);

};

#endif //COS214P3_ADMINISTRATOR_H