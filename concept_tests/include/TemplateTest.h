#ifndef _TEMPLATE_TEST_
#define _TEMPLATE_TEST_

#include "ITest.h"

class TemplateTest : public ITest {
public:
    void start() override;
    void stop() override;
};

#endif