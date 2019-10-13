// use 32bit data to reperesent 64bit data
#include <iostream>

int main()
{
	int x ,y;
	int xFront, yFront;
	int xBack, yBack;
	//input x, y
	std::cin >> x >> y;
	long long int result;
  
  //divide half bit
	xFront = (x & 0xffff0000)>>16;
	xBack = x & 0xffff;
	yFront = (y & 0xffff0000)>>16;
	yBack = y & 0xffff;
	
	printf("%x %x\n", xFront, xBack);
	printf("%x %x\n", yFront, yBack);

	int front;
	int last;

	/
	front = (xFront * yFront) + (((yFront * xBack + xFront * yBack) & 0xffff0000) >> 16);
	
	last = (xBack * yBack) + (((xFront * yBack + xBack * yFront) & 0xffff) << 16);
	
	printf("(int)A * (int)B = %#X", front);
	printf("%X\n\n", last);
	result = (long long int)x * (long long int)y;
	//-----------------------------//
	printf("%#016I64X\n\n\n", result);
	printf("%lld\n\n\n", result);
	
}
