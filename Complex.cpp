#include "Complex.h"

Complex::Complex()
{
	_real = 0.0;
	_imag = 0.0;
}


// Constructors
Complex();

Complex::Complex(double re, double im)
{
	_real = re;
	_imag = im;
}

Complex::Complex(const Complex& z)
{
	_real = z.real();
	_imag = z.imag();
}

// access values
double Complex::real() const
{
	return _real;
}

double Complex::imag() const 
{
	return _imag;
}


	// Constructors
	Complex();
	Complex(double re, double im);
	Complex(const Complex& z);

	// access values
	double real() const;
	double imag() const;

	// assignment
	Complex& operator=(double r);
	Complex& operator=(const Complex& z);
	Complex& operator+=(const Complex& z);
	Complex& operator-=(const Complex& z);
	Complex& operator*=(const Complex& z);
	Complex& operator/=(const Complex& z);

	
// basic math operations
Complex operator+(const Complex& a, const Complex& b)
{
	double reals = a.real() + b.real();
	double imags = a.imag() + b.imag();

	Complex total(reals,imags);

	return total;
}

Complex operator-(const Complex& a, const Complex& b)
{
	double reals = a.real() - b.real();
        double imags = a.imag() - b.imag();

	Complex total(reals,imags);

	return total;
}

Complex operator*(const Complex& a, const Complex& b)
{
	double first = a.real() * b.real();
        double outside = a.real() * b.imag(); 
	double inside = b.real() * a.imag();
	double last  = -1 * a.imag() * b.imag();

	double imags = outside + inside;
	double reals = first + last;

	Complex total(reals,imags);

	return total;
}
/*
Complex operator/(const Complex& a, const Complex& b);
{
	
        
//	VERY BUGGY


	Complex total(reals,imags);

	return total;
}
*/
// norm returns the squared magnitude of z
double norm(const Complex& z)			//FOIL
{						//(8+i)(8+i)
	double first = z.real() * z.real();	//8*4
	double inNout = 2*z.real() * z.imag();	//(8*i + 8*i) = 2(8*i)
	double last = -1*z.imag() * z.imag();	//i*i = -1 

	double reals = first + last;		//inNout = inner + outer parts of FOIL
	double total = reals + inNout;

	return total;
}


// conj returns the complex conjugate of z
Complex conj(const Complex& z)
{							//(a + bi)(a - bi)
	double reals1 = z.real() * z.real();		//a * a = a^2
        double reals2 = -1*z.imag() * z.imag();		// bi * bi = b^2 i^2 => i^2 = -1 => -1*b^2

	double reals_tot = reals1 + reals2;		//no need to calculate inner and outer since they cancel each other out
	
	Complex total(reals_tot, 0);

	return total;
}


// comparison
bool operator==(const Complex& a, const Complex& b)
{
	if ((a.real() == b.real()) && (a.imag() == b.imag()))
		return true;
	else
		return false;	

}

bool operator==(const Complex& a, double r)
{
	if (a.real() == r)
		return true;
	else
		return false;

}

bool operator!=(const Complex& a, const Complex& b)
{
	if ((a.real() != b.real()) && (a.imag() != b.imag()))
		return true;
        else
		return false;


}

bool operator!=(const Complex& a, double r)
{	
	if (a.real() != r && a.imag() != 0)
		return true;
	else
		return false;
}

// write the complex number z to the output stream in the
// format "6+5i" or "6-5i"

std::ostream& operator<<(std::ostream& out, const Complex& z)
{
	out<< z.real() << (z.imag() < 0? "-": "+") << z.imag();

	return out;
}
