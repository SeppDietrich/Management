#include <iostream>
#include <fstream>
#include <iomanip>
#include "inventar.h"
using namespace std;
fstream f;
int main(){
	inventar produs[100];int n;
	citire(produs, n);
	afisare(produs, n);
	
	return 0;

}
