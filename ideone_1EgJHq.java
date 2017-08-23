#include <iostream>
using namespace std;
 
int main() {
	double vel=0.0;
	double a=0.0;
	double pinit=413685.437;
	double p=0;
	double circle=0.00114;
	double x=0;
	double ep=0.00001;
	double voli=.0006;
	double vol=0;
 
	while(x<1.676){
		x+=vel*ep+0.5*a*ep*ep;
		vol=circle*x+voli;
		p=(pinit*voli)/vol;
		a=(p*circle)/.129;
		vel+=a*ep;
	}

	cout << vel << endl;
	return 0;
}