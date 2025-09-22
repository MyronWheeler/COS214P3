#ifndef CHATROOM_H
#define CHATROOM_H
#include "Users.h"
#include <string>
#include <vector>
using namespace std;
class ChatRoom {

private:
	// Im gonna have a vector of users in the chat room
	// Hear me out what about a vector of Messages for the history (we make a new class called Message) or just a vecotr of strings
	vector<Users*> users;
	vector<string> chatHistory;

public:
// I changed all the parameters to be pointers cause I think its better that way
	virtual void registerUser(Users* User) = 0;

	virtual void sendMessage(string message, Users* fromUser) = 0;

	virtual void saveMessage(string message, Users* fromUser) = 0;

	virtual void removeUser(Users* user) = 0;
};

#endif
