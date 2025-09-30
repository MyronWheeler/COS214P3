/**
 * @file Users.h
 * @brief Declares the Users abstract class for user accounts in the chat system.
 * @author u24574547_u24579565
 * @date 2025-09-27
 */

#ifndef USERS_H
#define USERS_H
#include "ChatRoom.h"
#include <string>
#include <iostream>
using namespace std;
class Command;
#include "Command.h"

/**
 * @class Users
 * @brief Abstract base class for users in the chat system.
 */
class Users {
public:
    /**
     * @brief Constructor.
     */
    Users();

    /**
     * @brief Virtual destructor.
     */
    virtual ~Users();

    /**
     * @brief Add a command to the user's queue.
     * @param command Pointer to the command.
     */
    virtual void addCommand(Command* command)=0;

    /**
     * @brief Execute all commands in the queue.
     */
    virtual void executeAll()=0;

    /**
     * @brief Add a chat room to the user's list.
     * @param rooms Pointer to the chat room.
     */
    virtual void setChatRooms(ChatRoom* rooms)=0;

    /**
     * @brief Get the user's ID.
     * @return User's ID.
     */
    virtual int getId()=0;

    /**
     * @brief Receive a message from a chat room.
     * @param message Pointer to the message.
     * @param room Pointer to the chat room.
     */
    virtual void receive(ChatRoom::ChatMessage* message, ChatRoom* room)=0;

    /**
     * @brief Get the user's name.
     * @return User's name.
     */
    virtual string getName()=0;

    /**
     * @brief Get the list of chat rooms.
     * @return Vector of chat room pointers.
     */
    virtual vector<ChatRoom *> getChatRooms()=0;
	//adding functionality to remove the user from the chat room

	/**
	 * @brief Send a message to a chat room.
	 * @param message The message content.
	 * @param room Pointer to the chat room.
	 */
	virtual void send(string message, ChatRoom *room)=0;

	/**
	 * @brief Leave a chat room.
	 * @param room Pointer to the chat room.
	 */
	virtual void removeChatRoom(ChatRoom* room)=0;
};

#endif
