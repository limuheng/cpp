#ifndef _INHERITANCE_TEST_
#define _INHERITANCE_TEST_

#include "ITest.h"

class InheritanceTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif