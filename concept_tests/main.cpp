#include <iostream>
#include <unordered_map>

#include "InheritanceTest.h"
#include "VirtualDestructorTest.h"
#include "TemplateTest.h"
#include "OperatorOverloadingTest.h"
#include "FunctionPointerTest.h"
#include "FunctionObjectTest.h"
#include "LambdaExpressionTest.h"
#include "SmartPointerTest.h"
#include "ContainerTest.h"
#include "MapTest.h"
#include "SizeOfTest.h"
#include "QueueTest.h"

using namespace std;

enum class Test {
    INHERITANCE,
    VIRTUAL_DESTRUCTOR,
    TEMPLATE,
    OPERATOR_OVERLOADING,
    FUNCTION_POINTER,
    FUNCTION_OBJECT,
    LAMBDA_EXPRESSION,
    SMART_POINTER,
    CONTAINER,
    SIZE_OF,
    MAP,
    QUEUE
};

int main() {
    unordered_map<Test, ITest *> tests;

    tests.insert(make_pair(Test::INHERITANCE, new InheritanceTest()));
    tests.insert(make_pair(Test::VIRTUAL_DESTRUCTOR, new VirtualDestructorTest()));
    tests.insert(make_pair(Test::TEMPLATE, new TemplateTest()));
    tests.insert(make_pair(Test::OPERATOR_OVERLOADING, new OperatorOverloadingTest()));
    tests.insert(make_pair(Test::FUNCTION_POINTER, new FunctionPointerTest()));
    tests.insert(make_pair(Test::FUNCTION_OBJECT, new FunctionObjectTest()));
    tests.insert(make_pair(Test::LAMBDA_EXPRESSION, new LambdaExpressionTest()));
    tests.insert(make_pair(Test::SMART_POINTER, new SmartPointerTest()));
    tests.insert(make_pair(Test::CONTAINER, new ContainerTest()));
    tests.insert(make_pair(Test::SIZE_OF, new SizeOfTest()));
    tests.insert(make_pair(Test::MAP, new MapTest()));
    tests.insert(make_pair(Test::QUEUE, new QueueTest()));

    auto test = tests.find(Test::QUEUE);
    if (test != tests.cend()) {
        test->second->start();
        test->second->stop();
    }

    return 0;
}
