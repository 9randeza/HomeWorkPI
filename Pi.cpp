#include <iostream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>
#include <iomanip>


using s_float = boost::multiprecision::cpp_dec_float_100;

s_float power(const s_float& index, int degree){
    s_float result = 1.0;

    for (int i = 0; i < degree; ++i){
        result *= index;
    }

    return result;
}

s_float boost_factorial(int num){
    s_float fact = 1;

    for (int i = num; i > 1; --i){
        fact *= i;
    }

    return fact;
}


s_float MyPi(int k){
	 s_float sum = 0; 
    s_float z = 2.0*sqrt(2.0) / 9801.0;

    for (int i = 0; i < k; ++i){
        s_float result1 = power(396.0, 4 * i);
        s_float result2 = power(boost_factorial(i), 4);

        s_float n = boost_factorial(4 * i) * (1103 + (26390 * i));
        s_float m = result1 * result2;

       sum +=  n / m;
    }
    
    sum =  1.0 / (sum * z);
    
    return sum;
	
}
int main() {
	int n;
	std::cin >> n;
	
    std::cout << "my_Pi: 	  " << std::setprecision(std::numeric_limits<s_float>::digits10) << MyPi(n) << "\n";
    
    s_float pi_boost = boost::math::constants::pi<s_float>();
     std::cout << "boost_Pi: " << std::setprecision(std::numeric_limits<s_float>::digits10) << pi_boost << "\n";

    s_float diff = fabs(MyPi(n) - pi_boost);
    std::cout << "difference: " << std::setprecision(std::numeric_limits<s_float>::digits10) << diff << "\n";

    return 0;
}
