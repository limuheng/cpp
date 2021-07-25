#include <iostream>
#include "InheritanceTest.h"
#include "VirtualDestructorTest.h"
#include "TemplateTest.h"
#include "OperatorOverloadingTest.h"
#include "FunctionPointerTest.h"
#include "FunctionObjectTest.h"
#include "LambdaExpressionTest.h"
#include "SmartPointerTest.h"
#include "ContainerTest.h"

using namespace std;

int main() {
    ITest *test = nullptr;

    // test = new InheritanceTest();
    // test->start();
    // test->stop();
    // delete test;

    // test = new VirtualDestructorTest();
    // test->start();
    // test->stop();
    // delete test;

    // test = new TemplateTest();
    // test->start();
    // test->stop();
    // delete test;

    // test = new OperatorOverloadingTest();
    // test->start();
    // test->stop();
    // delete test;

    // test = new FunctionPointerTest();
    // test->start();
    // test->stop();
    // delete test;

    // test = new FunctionObjectTest();
    // test->start();
    // test->stop();
    // delete test;

    // test = new LambdaExpressionTest();
    // test->start();
    // test->stop();
    // delete test;
 
    // test = new SmartPointerTest();
    // test->start();
    // test->stop();
    // delete test;

    test = new ContainerTest();
    test->start();
    test->stop();
    delete test;

    return 0;
}
