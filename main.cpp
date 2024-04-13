#include <iostream>
#include <fstream>
#include <iomanip>
#include "inventar.h"
using namespace std;
fstream f;
int main(){
	inventar produs[100];int n;
	int op;
	citire(produs, n);
	cout<<"Informatia a fost citita din date.in"<<endl;

	do{
        cout<<"Ce dorit sa faceti?"<<endl;
	cout<<"		1 -Afisarea informatiei."<<endl;
	cout<<"		2 -Adaugarea informatiai."<<endl;
	cout<<"		3 -Sortarea informatiei."<<endl;
	cout<<" 	0 -Oprirea programului"<<endl;
	cin>>op;
	switch(op){
		case 1:
			afisare(produs, n);
		  break;
		case 2:
		  	adaugare(produs, n);
		  break;
		case 3:
		  	SortarePret(produs, n);
		break;
		
		case 0:
	  		cout<<"Multumim ca esti alauri de noi"<<endl;
		  break;
	}
	}while(op!=0);

	return 0;

}
