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
	cout<<"	1 -Afisarea informatiei."<<endl;
	cout<<"	2 -Adaugarea informatiai."<<endl;
	cout<<"	3 -Sortarea informatiei."<<endl;
	cout<<"	4 -Filtrarea informatiei."<<endl;
	cout<<" 	0 -Oprirea programului"<<endl<<"	";
	cin>>op;
	switch(op){
		case 1:
			afisare(produs, n);
		  break;
		case 2:
		  	adaugare(produs, n);
		  break;
		case 3:
		  	cout<<"Alegeti tipul de sortare:"<<endl<<
				"1 -Sortare dupa pret."
				<<endl;
			int s;
			cin>>s;
			switch(s){
				case 1:
					Sortare(produs, n);
				break;
			
			}
		
		break;
		case 4:
			cout<<"Alegeti tipul de filtrare:"<<endl<<
				"1 -Filtrare dupa disponibilitate"
				
				<<endl;
			int f;
			cin>>f;
			switch(f){
				case 1:
					cout<<"Doriti sa filtrati iteme disponibile?"
					<<endl<<"da sau nu(d & n)";
					char d;
					cin>>d;
					if(d == 'd'){filtrare(produs, n, true);}
					else {filtrare(produs, n, false);}

				break;
			
			}

		break;
		
		case 0:
	  		cout<<"Multumim ca esti alauri de noi"<<endl;
		  break;
	}
	}while(op!=0);

	return 0;

}
