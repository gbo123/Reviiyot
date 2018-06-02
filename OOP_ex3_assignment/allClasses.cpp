#include "allClasses.h"
#include <typeinfo>

int Shape::_totalNumOfShapes = 0;

int Point::getX() const {

	return _x;

}

int Point::getY() const {

	return _y;

}


void Point::setX(int x) {
	_x = x;
}
void Point::setY(int y) {
	_y = y;
}

void Point::setPoint(int x, int y) {

	_x = x;
	_y = y;
}

void Point::setPoint(const Point & other) {

	_x = other._x;
	_y = other._y;



}

bool Point::operator==(const Point & other) const {

	return (_x == other._x  && _y == other._y);
}

bool Point::operator!=(const Point & other) const {

	return (_x != other._x && _y != other._y);

}
Point Point::operator+(int num) const {

	return  Point(_x + num, _y + num);



}

Point & Point:: operator+=(int num) {

	setX(_x + num);
	setY(_y + num);
	return *this;
}

Point::operator int() const
{
	return _x + _y;

}

Point Point::operator+(const Point & other) const
{
	return Point(_x+other._x,_y+other._y);
}

Point Point::operator++(int)
{
	Point TempVector = *this;
	(*this) += 1;
	return TempVector;
}

Point & Point::operator++()
{
	(*this) += 1;
	return *this;
}


/*
Point operator+(const Point & other) const;//adds cordinats (x,y) and returns a new point
Point operator++(int);//adds 1 to x and y and returns the updated point - postfix
Point & operator++();//adds 1 to x and y and returns the updated point - prefix
*/

Point operator*(int num, const Point & other)
{
	return Point(other._x*num,other._y*num);
}

Circle operator+(int r, const Circle & other)
{
	return Circle(other._radius+r,other.getName());
}

Shape::~Shape()
{
	
	Shape::_totalNumOfShapes -= 1;
	


}


Shape::Shape(string sn):_shapeName(sn.c_str()),_centerPoint(0,0)
{
	
	Shape::_totalNumOfShapes += 1;

}

Shape::Shape(const Shape & other):_shapeName(other._shapeName.c_str()),_centerPoint(other._centerPoint)
{
	Shape::_totalNumOfShapes += 1;

}

void Shape::setName(string name)
{

	_shapeName = name.c_str();
}

void Shape::setCenter(const Point & p)
{
	_centerPoint.setPoint(p);
}

string Shape::getName() const
{
	return _shapeName;
}

Point Shape::getCenter() const
{
	return _centerPoint;
}

void Shape::setShape(string sn, const Point & other)
{

	_shapeName = sn.c_str();
	_centerPoint.setPoint(other);

}

int Shape::numOfShapes()
{
	return _totalNumOfShapes;
}

Circle::Circle(double r, string sn):_radius(r), Shape(sn)
{
	 
}

Circle::Circle(const Circle & other):_radius(other._radius),Shape(other)
{
	


}

Circle::~Circle()
{
}

double Circle::getRadius() const
{
	return _radius;
	

}

void Circle::setRadius(double r)
{
	_radius = r;

}

int Circle::calcArea() const
{

	return (int)(_radius*_radius * PI);

}

int Circle::calcPerimeter() const
{
	return (int)(2 * PI * _radius);
}

Circle & Circle::operator=(string name)
{
	this->setName(name);
	return *this;
}

Quad::Quad(double up, double down, double right, double left, string sn):_up(up),_down(down),_right(right),_left(left),Shape(sn)
{

}

Quad::Quad(const Quad & other):_up(other._up), _down(other._down),_right(other._right), _left(other._left),Shape(other)
{


}
Quad::~Quad()
{
}



int Quad::calcArea() const
{
	return (int)(_right*_up);
}

int Quad::calcPerimeter() const
{
	return (int)(_up + _down + _right + _left);
}

Square::Square(double up, double down, double right, double left, string sn) :Quad(up, down, right, left,sn)
{
}

Square::~Square()
{
}

void Square::shiftX(int x)
{
	int x1 = _centerPoint.getX();//returns the x
	int y = _centerPoint.getY();//returns the y
	 _centerPoint.setX(x1+x);//sets the x
	
}

void Square::shiftY(int y)
{

	int x1 = _centerPoint.getY();//returns the x

	_centerPoint.setY(x1 + y);//sets the x
	

}

int allShapes::getSize() const
{
	return _size;
}

allShapes::allShapes() :_size(0)
{
	
	
	_arr = new Shape*[0];

}

allShapes::~allShapes()
{
	/*for (int i = 0; i < _size; i++) {
		delete _arr[i];
}
*/
	delete[] _arr;

}

void allShapes::addShape(Shape * newShape)
{
	Shape** tmp = new Shape*[_size + 1];
	for (int i = 0; i < _size; i++) {

		tmp[i] = _arr[i];

		}
	tmp[_size] = newShape;
	_arr = tmp;
	
	_size += 1;
	
	

	
}

void allShapes::removeShape(int index){

	delete _arr[index];
	
	Shape** tmp = _arr;
	_size -= 1;

	_arr = new Shape*[_size];
	
	int i = 0;
	while (i != index) {	
	_arr[i] = tmp[i];
		i++;
	}
	int j = i;
	
	while (j<_size){
		_arr[j] = tmp[j + 1];
		j++;
		}
	


	
		
}

int allShapes::totalArea() const
{
	
	int area = 0;
	
	for (int i = 0; i < _size; i++) {
		area += _arr[i]->calcArea();

	}
	
	return area;

}

int allShapes::totalPerimeter() const
{
	int perimeter = 0;
	
	
	for (int i = 0; i < _size; i++) {
		perimeter += _arr[i]->calcPerimeter();

	}
	
	return perimeter;

}

int allShapes::totalCircleArea() const
{
	
	
		int area = 0;
		
		for (int i = 0; i < _size; i++) {
			if (typeid(*_arr[i]) == typeid(Circle)) {// false
				area += _arr[i]->calcArea();

				}

			
			}
			

return area;
}

int allShapes::totalSquarePerimeter() const
{
	int perimeter = 0;
	
	for (int i = 0; i < _size; i++) {
		if (typeid(*_arr[i]) == typeid(Square)) {// false
			perimeter += _arr[i]->calcPerimeter();

		}
	}
	return perimeter;
	
	
	}

allShapes & allShapes::operator+=(Shape * newS)
{
	addShape(newS);
	return *this;
}

Shape * allShapes::operator[](int ind) const
{
	return _arr[ind];
}

allShapes allShapes::operator+(const allShapes & other) const
	{
	
	

	
	allShapes all= allShapes();
	for (int i = 0; i < _size; i++) {

		all.addShape(_arr[i]);
	}
	int size2 = other._size;
	for (int j = 0; j < size2; j++) {

		all.addShape(other._arr[j]);
	}

	return all;
	
	}

allShapes::operator int() const
{
	return _size;

}
