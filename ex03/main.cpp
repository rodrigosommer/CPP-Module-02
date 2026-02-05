#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);
	
	Point inside(5.0f, 3.0f);
	Point outside(15.0f, 5.0f);
	Point onEdge(5.0f, 0.0f);
	Point vertex(0.0f, 0.0f);
	
	std::cout << "Testing BSP function:" << std::endl;
	std::cout << "Triangle vertices: A(0,0), B(10,0), C(5,10)" << std::endl;
	
	std::cout << "Point (5,3) inside triangle: " << (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
	std::cout << "Point (15,5) outside triangle: " << (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
	std::cout << "Point (5,0) on edge: " << (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
	std::cout << "Point (0,0) on vertex: " << (bsp(a, b, c, vertex) ? "true" : "false") << std::endl;
	
	return 0;
}