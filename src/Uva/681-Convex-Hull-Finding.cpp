//681 - Convex Hull Finding
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct point {
	int x, y;
	bool operator <(const struct point &p) const { return y < p.y || (y == p.y && x < p.x); }
}point;

int cross(const point &O, const point &A, const point &B){
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<point> convexHull(vector<point>P){

	sort(P.begin(),P.end()); 
	int n = P.size(),k=0;
	vector<point>H(2*n);
	for(int i=0; i<n; i++){ 
		while(k>=2 && cross(H[k-2],H[k-1],P[i]) <= 0) 
			k--;
		H[k++]=P[i]; 
	} 
	for(int i=n-2, t=k+1;i>=0; i--){ 
		while(k>=t && cross(H[k-2],H[k-1],P[i]) <= 0) 
			k--; 
		H[k++] = P[i]; 
	} 
	H.resize(k-1); 
	return H; 
}

int main()
{
	vector<point> vec;
	vector<point> sol;
	point p;
	int nc,np;
	
	scanf("%d", &nc);
	printf("%d\n", nc);
	while(nc--)
	{
		vec.clear(); sol.clear();
		scanf("%d", &np);
		while(np--)
		{
			scanf("%d%d", &p.x,&p.y);
			vec.push_back(p);
		}

		sol = convexHull(vec);
		printf("%d\n", (int) sol.size()+1);
		for(int i=0; i<sol.size(); i++)
			printf("%d %d\n", sol[i].x, sol[i].y);
		printf("%d %d\n", sol[0].x, sol[0].y);
		if(nc!=0)
			puts("-1");
		scanf("%d", &np);
	}
	
		
	return 0;
}
