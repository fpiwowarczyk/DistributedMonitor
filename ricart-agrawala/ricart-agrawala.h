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
    RicartAgrawala();
    ~RicartAgrawala();
    void addNewPortNumber(int port);
    private:

    std::vector<int> portNumbers;

    void *context;
    int port;
    int requestId;
};

#endif