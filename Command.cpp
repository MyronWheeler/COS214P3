#include "Command.h"

Command::~Command() {
    delete message;
}
