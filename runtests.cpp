#include <iostream>
#include <cstdlib>
// change the value below to 1 to run tests against your Complex class.
// change the value below to 0 to run tests against the built in std::complex.

#if 0
#include "Complex.h"
#else
#include <complex>
typedef std::complex<double> Complex;
#endif

bool Approx(double val1, double val2, double eps)
{
        return abs(val1 - val2) < eps;

}

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	Complex z1(4, 3);

	Assert(z1.real() == 4, "real constructor");
	Assert(z1.imag() == 3, "real constructor");
	//Assert(norm(z1) == 25, "complex norm");

	
	// TODO:
	// Write *at least* 20 more tests to fully test
	// your Complex class.

	Complex num1(18, 23);
	Complex num2(3, 9);
	Complex add_result, sub1_result, sub2_result;
        Complex	mult_result, div1_result, div2_result, conjugate1;
	add_result = num1+num2;
	sub1_result = num1-num2;
	sub2_result = num2-num1;
	mult_result = num1*num2;
	div1_result = num1/num2;
	div2_result = num2/num1;
	conjugate1 = conj(num1);

	Assert(add_result.real() == 21 && add_result.imag() ==32,
		"(18 + 23i) + (3 + 9i)");
	Assert(sub1_result.real() == 15 && sub1_result.imag() ==14,
                "(18 + 23i) - (3 + 9i)");
       	Assert(sub2_result.real() == -15 && sub2_result.imag() == -14,
                "(3 + 9i) - (18 + 23i)");
        Assert(mult_result.real() == -153 && mult_result.imag() == 231,
                "(18 + 23i) * (3 + 9i)");
        Assert(div1_result.real() == (87./30.) && div1_result.imag() ==
			(-31./30.), "(18 + 23i) / (3 + 9i)");
        Assert(div2_result.real() == (261./853.) && div2_result.imag() ==
			(93./853), "(3 + 9i) / (18 + 23i)");
        Assert(conjugate1.real() == 18 && conjugate1.imag() == -23,
               "conj(18 + 23i)");

	Complex num3(-20, -8);
	Complex num4(-3, -8);	
	Complex add_result2, sub1_result2, sub2_result2;
        Complex mult_result2, div1_result2, div2_result2;
	add_result2 = num3+num4;
        sub1_result2 = num3-num4;
        sub2_result2 = num4-num3;
	mult_result2 = num3*num4;
	div1_result2 = num3/num4;
	div2_result2 = num4/num3;

        Assert(add_result2.real() == -23 && add_result2.imag() ==-16,
                "(-20 - 8i) + (-3 - 8i)");
        Assert(sub1_result2.real() == -17 && sub1_result2.imag() ==0,
                "(-20 - 8i) - (-3 - 8i)");
        Assert(sub2_result2.real() == 17 && sub2_result2.imag() == 0,
                "(-3 - 8i) - (-20 - 8i)");
	Assert(Approx(norm(num3), 464.0, 0.00000001), "norm(-20-8i)");

	Assert(mult_result2.real() == -4 && mult_result2.imag() == 184,
                "(-20 - 8i) * (-3 - 8i)");
        Assert(div1_result2.real() == (124./73.) && div1_result2.imag() ==
		-(136./73.), "(-20 - 8i) / (-3 - 8i)");

	num3 = 5;
	Assert(num3.real() == 5 && num3.imag() == 0, "Complex = double r");
	num3 = num4;
	Assert(num3.real() == -3 && num3.imag() == -8, "Complex = Complex");

	Complex num5(54.93, 85.32);
	Complex num6(62.125, 9.175);
	
	Assert(Approx(norm(num6), 3943.69625, 0.00000001), "norm((62.125+9.175i))");
        Assert(conj(num6).real()==62.125 && conj(num6).imag() == -9.175,
		       	"conj((62.125+9.175i))");

	Assert(!(num5==num6), "(54.93+85.32i)==(62.125+9.175i)");
	Assert(!(num5==140.25), "! (54.93+85.32i)==140.25");
	Assert(num5!=num6, "(54.93+85.32i)!=(62.125+9.175i)");
	Assert(num5!=120.2, "(54.93+85.32i)!=120.2");
	Assert(!(num5==120.2), "! (54.93+85.32i)==120.2");
       	Assert(num5!=140.25, "(54.93+85.32i)!=140.25");
        
	Complex num9(10, -2);
	Complex num10(5, 3);
	num9 += num10;
	Assert(num9.real() == 15 &&  num9.imag() == 1, "num9+=num10");
	num9 -= num10;
        Assert(num9.real() == 10 && num9.imag() == -2, "num9-=num10");

	Complex num7(-9, 12);
	Complex num8(12, -9);

	num7*=num8;
	Assert(num7.real() == 0 && num7.imag() == 225.0,
		       	"num7*=num8");
	num7/=num8;
	Assert(num7.real() == -9 &&
		       	num7.imag() == 12, "num7/=num8");

	std::cout << num8 << std::endl;
	std::cout << num7 << std::endl;
	return 0;
}


