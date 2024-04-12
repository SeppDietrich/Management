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
void afisare(inventar p[],int n){
	cout << setfill('-') << setw(84) << '\n';
cout << setfill(' ');
cout << "| " << setw(20) << "Tip" << " | "
     << setw(11) << "Marca" << " | "
     << setw(10) << "Culoare" << " | "
     << setw(10) << "Pret" << " | "
     << setw(5) << "Cant" << " | "
     << setw(8) << "Dispon" << " |" << endl;
cout << setfill('-') << setw(84) << '\n';
cout << setfill(' ');

for (int i = 0; i < n; i++) {
    cout << "| " << setw(20) << p[i].tip << " | "
         << setw(11) << p[i].marca << " | "
         << setw(10) << p[i].culoare << " | "
         << setw(10) << p[i].pret << " | "
         << setw(5) << p[i].cant << " | "
         << setw(8) << p[i].dispon << " |" << endl;
}

cout << setfill('-') << setw(84) << '\n';

}
