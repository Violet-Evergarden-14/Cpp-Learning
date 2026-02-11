#ifndef _MARITX_H
#define _MARITX_H

class Matrix
{
private:
	int size;
	double* elements;
public:
	Matrix(int _size = 2);
	~Matrix();
	void set_matrix(const double* values);
	void print_matrix() const;
	int get_size() const {return size;}
	double& element(int i, int j) {return elements[i * size + j];}
	double element(int i, int j) const {return elements[i * size + j];}
};

#endif