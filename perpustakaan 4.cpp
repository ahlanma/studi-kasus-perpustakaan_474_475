#include <iostream>  
using namespace std; 

struct data{
  	string nama;
  	string id;
  	string judul;
  	int stok;
  	int Tb;
  	data *next, *prev;
  };
  data *awal=NULL,*akhir=NULL,*bantu,*baru,*hapus;
  
class Perpustakaan {
public:


  void input();
  void output();
  void hapusdata();
  
};


void Perpustakaan::input() {
  int jml;
  cout<<"Masukan Jumlah buku : ";
  cin>>jml;  
  for (int i=0; i<jml; i++) {
  	baru = new data;
	  baru->next = NULL;
    baru->prev = NULL;
    cout << "Data ke-" << i+1 << endl;
    cout << "Masukkan Id\t : ";
    cin >> baru->id;
    cout << "Masukkan Nama\t : ";
    cin >> baru->nama;
    cout << "Masukkan Judul\t : ";
    cin >> baru->judul;
    cout << "Tahun terbit\t : ";
    cin >> baru->Tb;
    cout << "Masukkan stok buku: ";
    cin >> baru->stok;
    cout << endl;
    if (awal == NULL){
	        awal = akhir = baru;
	}
    else {
	        baru->next = awal;
	        awal->prev = baru;
	        awal = baru;
    }
  } 
}

void Perpustakaan::output() {
	bantu=awal;
	int i=0;
    while (bantu!=NULL) {
    cout << endl;
    cout << "Id buku \t: " << bantu->id << endl;
    cout << "Judul buku \t: " << bantu->judul << endl;
    cout << "Nama pengarang \t: " << bantu->nama << endl;
    cout << "Tahun terbit\t: " << bantu->Tb << endl;
    cout << "Stok buku \t: " << bantu->stok << endl;
    bantu = bantu->next;  
  };
}

void Perpustakaan::hapusdata(){
    if(awal->next == NULL){
        awal=akhir=NULL;
        cout << "Data sudah kosong";
    }else{
        hapus = akhir;
        akhir = akhir->prev;
        akhir->next = NULL;
        delete hapus;
    }
}

int main() {
	Perpustakaan x;
  int pilih;

  do{
	cout << "+----------------------------+" << endl;
	cout << "| PROGRAM PERPUSTAKAAN CERIA |" << endl;
	cout << "+----------------------------+" << endl;
	cout << endl;
  	cout << "Pilih menu : \n";
  	cout << "1. Input data \n";
  	cout << "2. Hapus data \n";
  	cout << "3. Output data\n";
  	cout << "4. Exit\n";
  	cout << "Lain-lain >> EXIT\n";
  	cout << endl;
  	cout << "Pilih   : ";
  	cin>>pilih;

  switch(pilih){
    case 1:
      system("cls");
      x.input();
      break;
      case 2:
      system("cls");
      x.hapusdata();
      break;
      case 3:
      system("cls");
      x.output();
      break;
      
      default :
    system("cls");
      cout << "---------EXIT---------";
      exit(1);
      break;
  }
  
}
  while(pilih<=3);
}
