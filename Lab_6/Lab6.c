#include <reg51.h>

#define Div (0x10000- 20000) / 512;
#define Mod (0x10000- 20000) % 512;

void signal() interrupt 0 {
	unsigned int x = (TL1 + (TH1 << 8)) * 2;
	TL1 = 0;
	TH1 = 0;
}

void time() interrupt 1 {
	TL0 = Mod;
	TH0 = Div;
	P3 ^= 0x6F;
}


int main() {
	TMOD = 0x91;
	TR1 = 1;
	IT0 = 1;
	
	TR0 = 1;
	ET0 = 1;
	EX0 = 1;
	
	EA = 1;
	while(1);
}