#ifndef _STING_TEST_
#define _STING_TEST_

#include "ITest.h"

class StringTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif