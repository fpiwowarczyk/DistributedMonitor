# DistributedMonitor 
A distributed monitor project with implementation of Suzuki Kasami Algorithm and using ZMQ to communicate between processes.

## How to use
Add Monitor object into your code. Use Monitor.enter() and Monitor.exit() to mark ciritical section inside your code. Now that piece of code is protected and other processes cannot use that part of code inside their code. Also you can use Monitor.wait() if you want thread to wait some amout of time. 

## Functions
* Monitor Object{yourPort,otherPorts,hasToken} - musisz podać kolejno port którego używasz, vektor portów innych procesów oraz czy dany proces jest zainicjalizowany z tokenem[UWAGA!!! Tylko jeden proces może posiadać token !!!]

* Object.enter() - program will go inside ciritical section (code below Object.enter()) or will wait until he gets Token from other proces.

* Object.exit() - program will exit critical section and send token to other process in queue.

* Object.wait() - program will wait while wait is constantly being called.

## Test Program
My code include example use of Monitor inside test_Program.cpp. To run it:
* Compile whole project *make*
Run program: 
- [console1] -./a.out auto 1 
- [console2] -./a.out auto 2
- [console3] -./a.out auto 3

# Algorithm 
### Data Structures
Each process maintains one data structure:

* an array RN[n] (for request Number) where RNi[j] stores the last Request Number receivedd from j.

The token contains two data structures

* an array LN[n] (for last reques Number), where LN[j] stores the most recent Request Number of process j for which the token was successfully granted

* a quque Q, storing the ID of processes waiting for the token 

### Algorithm

#### Requesting the critical section (CS)

When process i wants to enter the CS, it if does not have the token, it:

* increments its sequence number RNn[i]
* sends a request message containg new sequence number to all processes in the system

#### Releasing the CS
When process i leaves the CS, it:
* sets LN[i] of the token equal to RNi[i]. This indicates that its request RNi[i] has been executed
* for every process k not in the token queue Q, it appends k to Q if RNi[k] = LN[k] +1. This indicates that process k has an outstanding request
* if the token queue Q is not emplty after this update, it pops a process ID j from Q and sends the token to j
* otherwise, it keeps the token

#### Receiving a request 
When process j receives a request from i with sequence number s, it:
* sets RNj[i] to max (RNj[i],s)(if s<RNj[i], the message is outdated)
* if process j has the token and is not in CS, and if RNj[i] == LN[i] +1 (indicating an outstanding request), it sends the oken to process i

### EXecuting the CS
A process enters the CS when it has acquired the token

### Performance 
* Either 0 or N messages for CS invocation(no messages if process holds the token; otherwise N-1 requests and 1 reply)
* Synchronization delay is 0 or N(N01 requests and reply 1)