#include "monitor.h"

Monitor::Monitor(int port, std::vector<int> otherPorts) {
    ctx  = zmq_ctx_new();
    receiveSocket = zmq_socket(ctx,ZMQ_REP);

    std::string host = "tcp://127.0.0.1:"+std::to_string(port);
    zmq_bind(receiveSocket,host.c_str());
    std::cout <<"Initialized with address: " << host << std::endl;
    for(const int &otherPort : otherPorts) {
        ricartAgrawala.addNewPortNumber(otherPort);
    }
}