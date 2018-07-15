#include <boost/learning.hpp>
#include <boost/function.hpp>

#define BOOST_TEST_MODULE GradTest
#include <boost/test/unit_test.hpp>

using namespace learning;

boost::function<float (int x)> f;

struct two_x_squared { 
  float operator()(int x) const { return ((float)2*x*x); }; 
};

BOOST_AUTO_TEST_CASE(grad_test)
{
    f = two_x_squared();
	
    std::function<void(float)> f_prime = learning::grad(f)

	BOOST_CHECK_EQUAL( f_prime(2), 8 );
} 
