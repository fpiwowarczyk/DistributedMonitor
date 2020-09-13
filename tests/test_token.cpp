#include "test_token.h"

void runTokenTests(){
    testQueuePrinting();
}

void testQueuePrinting(){
    Token token;

    token.addToQueue(12);
    token.addToQueue(13);
    token.addToQueue(14);
    token.addToQueue(15);
    token.addToQueue(16);
    token.addToQueue(17);
    token.addToQueue(18);

    token.printQueue();
}