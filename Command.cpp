#include "Command.h"

Command::~Command() {
    delete room;
    delete fromUser;
}
