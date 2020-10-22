#include <reg51.h>
#include <math.h>

unsigned char fixedPoint(unsigned char x, int accuracy) {
	int result;
	int i;
	for(i = 1; i < accuracy; i++) {
		result -=  pow(x, accuracy) / i; 
	}
	return result;
}

void fixedPointWrapper() {
	unsigned char x;
	for(x = -100; x <= 100; x++) {
		P3 = fixedPoint(x, 6) + 100;
	}
}

void main() {
	while(1) {
		fixedPointWrapper();
	}
}