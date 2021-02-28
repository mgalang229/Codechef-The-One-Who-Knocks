#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long x, y;
		cin >> x >> y;
		long long moves = 0;
		if (x > y) {
			long long diff = x - y;
			if (diff % 2 == 0) {
				// In this case we have to decrease the value of X. We can only 
				// subtract the even value. So, if the difference is even then in one 
				// round we can reach Y.
				moves = 1;
			} else {
				// Now for odd differences, the observation here is that the difference 
				// of an even and odd number is always odd. So we can add any odd number 
				// and now subtract the difference as it will be an even number.
				moves = 2;
			}
		} else if (x < y) {
			long long diff = y - x;
			if (diff % 2 == 1) {
				// In this case we have to increase the value of X. We can add the odd value. 
				// So, if our difference is odd then in one round we can reach Y.
				moves = 1;
			} else if (diff % 2 == 0 && diff % 4 != 0) {
				// When our difference is even then we have to perform at least two operations. 
				// We can add the odd number twice as the sum of two odd numbers will give an 
				// even number but this even number will not be divisible by 4. In such cases 
				// where our difference is even and not divisible by 4 it will take 2 operations.
				moves = 2;
			} else {
				// Now our last case, when we have difference as even and divisible by 4, 
				// we can achieve Y by adding two odd numbers giving sum greater than difference 
				// and then subtract the even number in order to achieve Y. In this case it will 
				// take 3 operations.
				moves = 3;
			}
		}
		cout << moves << '\n';
	}
	return 0;
}
