#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <sstream>

class TestRunner
{
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const std::string& test_name)
    {
        try
        {
            func();
            std::cerr << test_name << " OK" << std::endl;
        }
        catch (const std::runtime_error& e)
        {
            ++fail_count;
            std::cerr << test_name << " fail: " << e.what() << std::endl;
        }
        catch (...)
        {
            ++fail_count;
            std::cerr << "Unknown exception caught" << std::endl;
        }
    }

    ~TestRunner()
    {
        if (fail_count > 0)
        {
            std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {})
{
    if (t != u)
    {
        std::ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty())
        {
            os << " hint: " << hint;
        }
        throw std::runtime_error(os.str());
    }
}

