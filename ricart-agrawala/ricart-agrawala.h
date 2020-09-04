#ifndef RICART_AGRAWALA_H
#define RICART_AGRAWALA_H

#include "../common/common.h"
#include "../message/message.h"
#include "../utils/utils.h"

#include <zmq.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <thread>

class RicartAgrawala {

    public:
    RicartAgrawala(int port);
    ~RicartAgrawala();
    void addNewPortNumber(int port);
    void displayPortNumbers() {Utils::displayVector(portNumbers);}
    private:

    std::vector<int> portNumbers;
    std::vector<std::pair<long,Message>> requestQueue;
    std::map<std::string, std::vector<int>> replyReceived;


    void *ctx;
    int port;
    int requestId;
};

#endif