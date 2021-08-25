#ifndef _SIZEOF_TEST_
#define _SIZEOF_TEST_

#include "ITest.h"

class SizeOfTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif