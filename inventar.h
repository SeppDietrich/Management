using namespace std;

struct inventar{

	char tip[21], marca[16], culoare[11];
	double pret;
	int cant;
	bool dispon;
};

void citire(inventar p[],int &n){
	fstream f("date.in");
	f>>n;
	for(int i=0;i<n;i++){
		f>>p[i].tip>>p[i].marca>>p[i].culoare>>p[i].pret>>p[i].cant>>p[i].dispon;
	}
	f.close();
	
}
void TableHead(){
	cout << setfill('-') << setw(87) << '\n';
	cout << setfill(' ');
	cout << "| " << setw(5) << "Nr." <<" | "
	     << setw(15) << "Tip" << " | "
	     << setw(11) << "Marca" << " | "
	     << setw(10) << "Culoare" << " | "
	     << setw(10) << "Pret" << " | "
	     << setw(5) << "Cant" << " | "
	     << setw(8) << "Dispon" << " |" << endl;
	cout << setfill('-') << setw(87) << '\n';
	cout << setfill(' ');
}
void afisare(inventar p, int &nr){
	 cout << "| " << setw(5) << nr <<" | " 
	 << setw(15) << p.tip << " | "
         << setw(11) << p.marca << " | "
         << setw(10) << p.culoare << " | "
         << setw(10) << p.pret << " | "
         << setw(5) << p.cant << " | "
         << setw(8) << p.dispon << " |" << endl;
    nr++;

}
void afisare(inventar p[],int n){
	int nr =1;
	TableHead();
	for (int i = 0; i < n; i++) {
		afisare(p[i], nr);
	}	
	cout << setfill('-') << setw(87) << '\n';

}
void adaugare(inventar p[],int &n){
	cout<<"Introduceti tipul: ";cin>>p[n].tip;
	cout<<"Itroduceti marca: ";cin>>p[n].marca;
	cout<<"Introduceti culoarea: ";cin>>p[n].culoare;
	cout<<"Introduceti pretul: ";cin>>p[n].pret;
	cout<<"Introduceti cantitatea:  ";cin>>p[n].cant;
	cout<<"Introduceti disponibilitatea (1/0): ";cin>>p[n].dispon;
	n++;
}
void schimb(inventar *p1,inventar *p2){
	inventar aux; 
	aux = *p1; 
	*p1=*p2;
	*p2=aux;
}
void Sortare(inventar p[], int n){
	int f;
	do{
		f=0;
		for(int i=0;i<n-1;i++){
			if(p[i].pret<p[i+1].pret){
				schimb(&p[i],&p[i+1]);
				f=1;
			}
		}
	}while(f!=0);


}
void filtrare(inventar p[], int n, bool s){
	TableHead();
	int nr=1;
	for(int i=0;i<n;i++){
		if(p[i].dispon==s)afisare(p[i],nr);
	}
	cout << setfill('-') << setw(87) << '\n';
}
void filtrare(inventar p[], int n, int min, int max){
	TableHead();
	int nr=1;
	for(int i=0;i<n;i++){
		if((p[i].pret>min)&&(p[i].pret<max))afisare(p[i],nr);
	}
	cout << setfill('-') << setw(87) << '\n';
}
void sterge(inventar p[], int &n, int v[], int sizev){
	for(int i=0;i<sizev;i++){
		if(v[i]!=n-1){
			for(int j=v[i]-1;j<n-1;j++){
				p[j]=p[j+1];	
			}
			for(int k=0;k<sizev;k++){
				--v[k];
			}
		}
		--n;
	}
	afisare(p, n);
}
