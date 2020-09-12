#ifndef TEST_MESSAGE_H
#define TEST_MESSAGE_H

#include "../message/message.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>

void runMessageTests();
bool is_serializedProperlyToken();
bool is_serializedProperlyRequest();
bool is_deserializedProperlyToken();
bool is_deserializedProperlyRequest();

#endif