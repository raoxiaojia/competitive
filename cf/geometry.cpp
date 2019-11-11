#include "bits/stdc++.h"

using namespace std;

double INF = 1e100;
double EPS = 1e-12;
struct PT
{
	double x,y;
	PT() {}
	PT (double x,double y): x(x),y(y) {}
	PT (const PT &p) : x.(p.x), y.(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x,y+p.y);}
	PT operator - (const PT &p) const { return PT(x-p.x,y-p.y);}
	PT operator * (double c)    const { return PT(x*c,y*c);}
	PT operator / (double c)    const { return PT(x/c,y/c);}
};

inline double dot(PT p,PT q)	{ return p.x*q.x+p.y*q.y; }
inline double dist2(PT p,PT q)	{ return dot(p-q,p-q); }
inline double cross(PT p,PT q)	{ return p.x*q.y-p.y*q.x; }
