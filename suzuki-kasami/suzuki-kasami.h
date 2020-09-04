#ifndef SUZUKI_KASAMI_H
#define SUZUKI_KASAMI_H
#include "../message/message.h"
#include "../common/common.h"
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <zmq.h>

class SuzukiKasami{

    public:
    SuzukiKasami();
    ~SuzukiKasami();
    private:
    std::vector<int> ports;
    std::vector<std::pair<long,Message>> requestQueue;



};


#endif 