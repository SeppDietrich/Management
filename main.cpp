#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "inventar.h"
using namespace std;
fstream f;
fstream o;
int main(){
	inventar produs[100];int n;
	int op;
	char d;
	citire(produs, n);
	cout<<"Informatia a fost citita din date.in"<<endl;

	do{
        cout<<"Ce dorit sa faceti?"<<endl;
	cout<<"	1 -Afisarea informatiei."<<endl;
	cout<<"	2 -Adaugarea informatiai."<<endl;
	cout<<"	3 -Sortarea informatiei."<<endl;
	cout<<"	4 -Filtrarea informatiei."<<endl;
	cout<<"	6 -Excluderea informatiei."<<endl;
	cout<<"	7 -Salvarea informatiei."<<endl;
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
				"1 -Sortare dupa pret."<<endl<<
				"2 -Sortare dupa disponibilitate."<<endl<<
				"3 -Sortare alfabetic dupa marca."
				<<endl;
			int s;
			cin>>s;
			switch(s){
				case 1:
					cout<<"Doriti sa filtrati iteme crescator?"
					<<endl<<"da sau nu(d & n)";
					cin>>d;
					if(d=='d'){SortarePret(produs, n, true);}
					else{SortarePret(produs, n, false);}
				break;
				case 2:
					SortareDispon(produs, n);
				break;
				case 3:
					cout<<"Doriti sa filtrati alfabetic crescator?"
					<<endl<<"da sau nu(d & n)";
					cin>>d;
					if(d=='d'){SortareMarca(produs, n, true);}
					else{SortareMarca(produs, n, false);}
				break;
			}
		
		break;
		case 4:
			cout<<"Alegeti tipul de filtrare:"<<endl<<
				"1 -Filtrare dupa disponibilitate."<<endl<<
				"2 -Filtrare dupa pret."<<endl<<
				"3 -Filtrare dupa marca"<<endl
				<<endl;
			int f;
			cin>>f;
			switch(f){
				case 1:
					cout<<"Doriti sa filtrati iteme disponibile?"
					<<endl<<"da sau nu(d & n)";
					cin>>d;
					if(d == 'd'){filtrare(produs, n, true);}
					else {filtrare(produs, n, false);}
				break;
				case 2:
					cout<<"Introduceti pretul min si maxim:"
					<<endl;
					double min,max;
					cin>>min>>max;
					filtrare(produs, n, min, max);
				break;
				case 3:
					cout<<"Introduceti ce marca doriti"<<endl;
					char comp[15];
					cin>>comp;
					filtrare(produs, n, comp);
				break;
			
		}

		break;
		case 5:

		break;
		case 6:{	
			afisare(produs ,n);
			cout<<"Cite elemente doriti sa stergeti?"<<endl;
			int ids;
			cin>>ids;
			int e[ids];
			cout<<"Ce elemene doriti sa stergeti(nr din tabel)"<<endl;
			for (int i=0;i<ids;i++){
				cin>>e[i];
			}	
			sterge(produs, n, e, ids);
		       }
		break;
		case 7:
			cout<<"Alegeti cum va fi numit fisierul in care for fi salvate datele despre stoc:"<<endl;
			char numeout[20];
			cin>>numeout;
			salvare(produs, n, numeout);
		break;
		case 0:
	  		cout<<"Multumim ca esti alauri de noi"<<endl;
		break;
		default:
			cout<<"Optiune invalida"<<endl;
		break;
	}
	}while(op!=0);

	return 0;

}
