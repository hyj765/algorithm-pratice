#include<iostream>
/*
	Amdahls_law 
	St = improve_percentage   = (1.xx - 1) *100;
	P = Function_Running_Time;
	Sp = Improved_Function_Running Time;
*/

float Amdahls_law(float p,float Sp) {
	float St = 1 / ((1 - p) + (p / Sp));
	return St;
}//Optimized Function Time Calculating Algorithm

int main() {
	std::cout << Amdahls_law(0.8, 1.3);
}
