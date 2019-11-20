#include <iostream>

int fibo(int n){
	if(n <= 1){return n;}
	return fibo(n-1) + fibo(n-2);
}


int main(){
	for(int i = 0; i <= 20; i++)
	{
		int val = fibo(i);
		std::cout << val << std::endl;
	}
	return 0;
}
