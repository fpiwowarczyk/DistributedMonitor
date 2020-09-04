#include "ricart-agrawala.h"


RicartAgrawala::RicartAgrawala(int port) :port {port} {
    ctx = zmq_ctx_new();
    requestId=0;
}

RicartAgrawala::~RicartAgrawala(){
    zmq_ctx_destroy(ctx);
}

void RicartAgrawala::addNewPortNumber(int port) {portNumbers.push_back(port);}

void RicartAgrawala::displayPortNumbers(){Utils::displayVector(portNumbers);}