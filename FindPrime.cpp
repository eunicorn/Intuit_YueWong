#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int findPrime(int n);
bool isPrime(int x);


int main()
{
	
	int a = findPrime(3); //5 
	cout << "The 3rd prime number is: " << a << endl;
    
	int b = findPrime(58); //271
	cout << "The 58th prime number is: " << b << endl;

	int c = findPrime(10001); //104743
	cout << "The 10,001th prime number is: " <<c << endl;
	

	return 0;
}

int findPrime(int n)
{
	if (n<=0) return -1;
	if (n==1) return 2; //first prime number is 2

	vector<int> prime;

	for(int i = 2, j = 0;  j<n; i++)
	{
		if (isPrime(i)) 
		{
			prime.push_back(i);
			j++;
		}	
	}

	return prime.back();
}

bool isPrime(int x)
{
	if(x<=1){
		return false;
	}
	// 2 and 3 are prime numbers
	else if (x==2 || x== 3 ){
		return true;
	}
	// numbers that are divisible by 2 or 3 are not prime
	else if (x % 2 == 0 || x % 3 == 0) {
        return false;
    }
	else {
        for (int i = 5; i*i <= x; i += 2) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

}
