#ifndef _CSTING_TEST_
#define _CSTING_TEST_

#include "ITest.h"

class CStringTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif