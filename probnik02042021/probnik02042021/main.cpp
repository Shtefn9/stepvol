#include <iostream>//26 пробник 02.04.2021
#include <fstream>
#include <algorithm>
using namespace std;
const int N=10000;
int binsearh(int *a, int n, int x) {
	int L, R, c;
	L=0; R=n;
	while (L<R-1) {
		c=L+(R-L)/2;
		if (x<a[c]) R=c;
		else L=c;
	}
	if (a[L]==x) return L;
	else return -1;
}
bool comp(int a, int b) {
	return (a%2<b%2 || a%2==b%2 && a<b);
}
int main() {
	int i, j, a[N], b[N], c, cnt=0, n, qchet=0, minsr=1e9+1;
	ifstream in;
	in.open("in.txt");
	in >> n;
	for (i=0; i<n; i++) {
		in >> a[i];
		b[i]=a[i];
	}
	sort(a, a+n, comp);
	sort(b, b+n);
	while(a[qchet]%2==0)
		qchet++;
	for (i=0; i<qchet-1; i++)
		for (j=i+1; j<qchet; j++){
			c=(a[i]+a[j])/2;
			if (binsearh(b, n, c)>=0) {
				cnt++;
				minsr=min(minsr, c);
			}
		}
	cout << cnt << " " << minsr;
	cin >> c;
	return 0;
}

//#include <iostream>//25 пробник 02.04.2021
//#include <cmath>
//using namespace std;
//bool isprime(int a) {
//	int i;
//	for (i=2; i*i<=a; i++)
//		if (a%i==0)
//			return false;
//	return true;
//}
//int main() {
//	int i, j, a, b, cnt=0;
//	for (i=63000000; i<=75000000; i++) {
//		a=i;
//		while (a%2==0)
//			a/=2;
//		if (a==1)
//			continue;
//		b=pow(a, 1.0/4);
//		if (isprime(b) && b*b*b*b==a) {
//			cout << i << " " << a << endl;
//		}
//	}
//	return 0;
//}

//#include <iostream>//23 пробник 02.04.2021
//using namespace std;
//const int N=400;
//int main() {
//	int a[N]={0}, b[N], i, j, cnt=0;
//	a[10]=1;
//	for (i=0; i<5; i++) {
//		for (j=0; j<N; j++)
//			b[j]=0;
//		for (j=0; j<N; j++)
//			if (a[j]>0) {
//				b[j+2]=1;
//				b[j+3]=1;
//				b[2*j]=1;
//			}
//		for (j=0; j<N; j++)
//			a[j]=b[j];
//	}
//	for (j=0; j<N; j++)
//		cnt+=a[j];
//	cout << cnt;
//	cin >> i;
//	return 0;
//}

//#include <algorithm>
//#include <iostream>
//const int N=400, K=18;
//using namespace std;
//int main() {
//	int pos[N][N], i, j, rez19, rez20, rez21 ;
//	for (i=0; i<N; i++)
//		for (j=0; j<N; j++)
//			pos[i][j]=0;
//	for (j=K+1; j<N; j++) 
//		if (pos[0][j-1]>0 && pos[0][j/2]>0)
//			pos[0][j]=-max(pos[0][j-1], pos[0][j/2]);
//		else {
//			pos[0][j]=-1000;
//			if (pos[0][j-1]<=0)
//				pos[0][j]=max(pos[0][j-1], pos[0][j]);
//			if (pos[0][j/2]<=0)
//				pos[0][j]=max(pos[0][j/2], pos[0][j]);
//			pos[0][j]=-pos[0][j]+1;
//		}
//	for (j=K+1; j<N; j++) 
//		pos[j][0]=pos[0][j];
//	for (i=1; i<N; i++)
//		for (j=max(K+1-i,1); j<N; j++) {
//			if (pos[i][j-1]>0 && pos[i][j/2]>0 && pos[i-1][j]>0 && pos[i/2][j]>0) {
//				pos[i][j]=-max(max(pos[i][j-1],pos[i][j/2] ), max(pos[i-1][j],pos[i/2][j]));
//			}
//			else {
//				pos[i][j]=-1000;
//				if (pos[i][j-1]<=0)
//					pos[i][j]=max(pos[i][j], pos[i][j-1]);
//				if (pos[i][j/2]<=0)
//					pos[i][j]=max(pos[i][j], pos[i][j/2]);
//				if (pos[i-1][j]<=0)
//					pos[i][j]=max(pos[i][j], pos[i-1][j]);
//				if (pos[i/2][j]<=0)
//					pos[i][j]=max(pos[i][j], pos[i/2][j]);
//				pos[i][j]=-pos[i][j]+1;
//			}
//		}
//	/*printf("   ");
//	for (i=0; i<50; i++)
//		printf("%3d", i);
//	for (i=0; i<50; i++){
//		printf("\n%3d", i);
//		for (j=0; j<50; j++)
//			printf("%3d", pos[i][j]);
//	}*/
//	//19
//	rez19=0;
//	while(pos[rez19][rez19]!=-1)
//		rez19++;
//	cout << rez19 << endl;
//	//20
//	rez20=0; 
//	while(pos[13][rez20]!=2)
//		rez20++;
//	cout << rez20<< " ";
//	rez20=N-1; 
//	while(pos[13][rez20]!=2)
//		rez20--;
//	cout << rez20<< endl;
//	rez19=0;
//	while(pos[rez19][rez19]!=-2)
//		rez19++;
//	cout << rez19 << endl;
//	cin >> i;
//	return 0;
//}
//#include <algorithm>
//#include <iostream>
//bool f(int a) {
//	int cnt=0, q=0;
//	while (a>0) {
//		cnt++;
//		q+=a%2;
//		a/=2;
//	}
//	return (2*q==cnt);
//}
//using namespace std;
//int main() {
//	int i, count=0;
//	for (i=15; i<=528; i++)
//		if (f(i))
//			count++;
//	cout << count;
//	cin >> i;
//	return 0;
//}