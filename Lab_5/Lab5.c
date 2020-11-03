#include <reg51.h> 
 
char bdata mem;
sbit y1 = mem^0; 
sbit y2 = mem^1; 
sbit y3 = mem^2;
sbit y4 = mem^3;
sbit z = P1^0; 
 
main() {    
	for(mem=0;mem<8;mem++) {
		P1 <<= 1;
		z = (!y1 | !y2 & y3) &(!y2 |y4); 
	}
	return 0;
} 