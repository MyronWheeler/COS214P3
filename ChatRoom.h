#ifndef CHATROOM_H
#define CHATROOM_H
#include <string>
#include <vector>
using namespace std;
class Users;
class ChatRoom {

protected:
	struct chatMessage {
		long timestamp;
		string message;
		Users* sender;
	};
	vector<Users*> users;
	vector<chatMessage> chatHistory;

public:
	ChatRoom();
	virtual ~ChatRoom();

	virtual void registerUser(Users* User) = 0;

	virtual void sendMessage(string message, Users* fromUser) = 0;

	virtual void saveMessage(string message, Users* fromUser) = 0;

	virtual void removeUser(Users* user) = 0;
};

#endif
