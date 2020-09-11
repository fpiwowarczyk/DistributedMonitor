#ifndef TEST_MESSAGE_H
#define TEST_MESSAGE_H

#include "../message/message.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>

void runMessageTests();
void is_serializedProperlyToken();
void is_serializedProperlyRequest();
void is_deserializedProperlyToken();
void is_deserializedProperlyRequest();

#endif