#ifndef _VIRTUAL_DESTRUCTOR_TEST_
#define _VIRTUAL_DESTRUCTOR_TEST_

#include "ITest.h"

class VirtualDestructorTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif