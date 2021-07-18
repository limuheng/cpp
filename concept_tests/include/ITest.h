#ifndef _TEST_INTERFACE_
#define _TEST_INTERFACE_

class ITest {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

#endif