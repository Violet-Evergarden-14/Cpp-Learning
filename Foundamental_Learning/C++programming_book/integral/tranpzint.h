#ifndef __TRANPZINT_H__
#define __TRANPZINT_H__

class Function {
public:
	virtual double operator()(double x) const = 0;
	virtual ~Function() {};
};

class MyFunction: public Function {
public:
	virtual double operator()(double x) const;
};

class Integration {
public:
	virtual double operator()(double a, double b, double eps) const = 0;
	virtual ~Integration() {};
};

class Tranz: public Integration {
private:
	const Function &f;
public:
	Tranz(const Function& _f): f(_f) {};
	virtual double operator()(double a, double b, double eps) const;
};

#endif