#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int main() {

	int term=0;

	cin >> term;

	while (term--) {

		int  x1, y1, x2, y2, r1, r2 =0;
		long xDistance=0;
		long yDistance=0;

		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;


		xDistance = pow(abs(x2-x1), 2);
		yDistance = pow(abs(y2-y1), 2);

		long pDistance = xDistance + yDistance;
		long rPlus = pow(abs(r1 + r2), 2);
		long rMinus = pow(abs(r1 - r2),2);






		if (pDistance == 0) {

			if( r1 == r2) cout << -1 << endl; // 일치한다.
			else cout << 0 << endl; // 만나지 않는다.(일치 하지 않는다.)

		}

		// 두 점에서 만난다.
		else if (pDistance <rPlus && pDistance > rMinus) cout << 2 << endl;

		// 한 점에서 만난다(접한다.)
		else if (pDistance == rPlus || pDistance ==rMinus) cout << 1 << endl;

		// 만나지 않는다.
		else if (pDistance > rPlus || pDistance < rMinus) cout << 0 << endl;

	}
}
