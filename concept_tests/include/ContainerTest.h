#ifndef _CONTAINER_TEST_
#define _CONTAINER_TEST_

#include "ITest.h"

class ContainerTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif