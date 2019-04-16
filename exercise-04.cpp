/*
Nama program			: Exercise
Nama					: Fadlan Mulya Priatna
NPM						: 140810180041
Tanggal pembuatan		: 15 April 2019
Deskripsi progrram		: program ini berisikan kodingan exercise 4 
*/

#include<iostream>

using namespace std;

struct contact{
    char nama[10];
    char nomor[12];
    contact* nextcontact;
};

struct index{
    char info[5];
    contact* Firstcontact;
    index* next;
};
typedef struct index* pointerIndex;
typedef contact* pointercontact;
typedef pointerIndex list;

void createList(list& First){
    First=NULL;
}

void createElmtIndex(pointerIndex& pBaru){
    pBaru = new struct index;
    cout << "Input index : ";
    cin >> pBaru->info;
    pBaru->next=NULL;
    pBaru->Firstcontact=NULL;
    
}

void createElmtcontact(pointercontact& pBaru){
    pBaru= new contact;
    cout << "Input nama kontak : ";
    cin >> pBaru->nama;
    cout << "Input nomor : ";
    cin >> pBaru->nomor;
    pBaru->nextcontact=NULL;
}

void insertFirstIndex(list& First,pointerIndex pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void traversalIndex(list First){
    pointerIndex pBantu;
    pBantu=First;
    while(pBantu!=NULL){
        cout << "Index : "<<pBantu->info<<",";
        pBantu=pBantu->next;
    }
}

void linearSearch(list First,char key[5],int& status,pointerIndex& pCari){
    status=0;
    pCari=First;
    while(status==0 && pCari!=NULL){
        if(strcmp(pCari->info,key)==0){
            status=1;
        }
        else{
            pCari=pCari->next;
        }
    }
}

void insertFirstKontak(list& First,char key[5],pointercontact pBaru){
    pointerIndex pIn;
    int ketemu;
    cout << "Input index yang di cari : ";
    cin >> key;
    linearSearch(First,key,ketemu,pIn);
    if(ketemu){
        cout << "Ditemukan dengan index :" << pIn->info << endl;
        if(pIn->Firstcontact==NULL){
            pIn->Firstcontact=pBaru;
        }
        else{
            pBaru->nextcontact=pIn->Firstcontact;
            pIn->Firstcontact=pBaru;
        }
    }
    else{
        cout << "Index  tidak di temukan" << endl;
    }
}

void deleteFirstcontact(list& First,char key[5],pointercontact& pHapus ){
    int ketemu;
    pointerIndex pIn;
    cout << "Input index yang di cari : ";
    cin >> key;
    linearSearch(First,key,ketemu,pIn);
    if(ketemu){
        cout << "Ditemukan dengan index : " << pIn->info;
        if(pIn->Firstcontact==NULL){
            cout << "Tidak ada yang di hapus" << endl;
        }
        else if(pIn->Firstcontact->nextcontact==NULL){
            pHapus=pIn->Firstcontact;
            pIn->Firstcontact=NULL;
        }
        else{
            pHapus=pIn->Firstcontact;
            pIn->Firstcontact=pIn->Firstcontact->nextcontact;
            pHapus->nextcontact=NULL;
        }
    }
    else{
        cout << "Index tidak di temukan" << endl;
    }
}

void traversalIndexKontak(list First){
    pointerIndex pBantuIndex;
    pointercontact pBantuKontak;
    cout << "Traversal divisi" << endl;
    pBantuIndex=First;
    while (pBantuIndex!=NULL){
        cout << "Index = " << pBantuIndex->info << endl;
        pBantuKontak=pBantuIndex->Firstcontact;
        while (pBantuKontak!=NULL) {
            cout << pBantuKontak->nama << " / " << pBantuKontak->nomor << endl;
            pBantuKontak=pBantuKontak->nextcontact;
        }
        pBantuIndex=pBantuIndex->next;
    }
}

void updateKontak(list First,char key[10],int& status,pointerIndex& pIndex){
    status=0;
    pointercontact pK;
    pIndex=First;
    pK=pIndex->Firstcontact;
    cout<<"Masukan nama contact :"; cin>>key;
    while(pIndex!=NULL){
        while(status== 0 && pK!=NULL){
            if(strcmp(pK->nama,key)==0){
                cout << "Input Nama : ";
                cin >> pK->nama;
                cout << "Input Nomor : ";
                cin >> pK->nomor;
                status=1;
            }
            else if(pK->nextcontact==NULL){
                status=1;
            }
            else {
                pK=pK->nextcontact;
            }
        }
        pIndex=pIndex->next;
    }
}

int main(){
    pointerIndex pI;
    pointercontact pK;
    list q;
    char key[5],nama[10];
    int ni,nk,ketemu;
    createList(q);
    cout << "Input banyak index : ";
    cin >> ni;
    for(int i=0;i<ni;i++){
        createElmtIndex(pI);
        insertFirstIndex(q,pI);
    }
    cout << "Input banyak kontak : ";
    cin >> nk;
    for(int i=0;i<nk;i++){
        createElmtcontact(pK);
        insertFirstKontak(q,key,pK);
    }
    traversalIndexKontak(q);
    updateKontak(q,nama,ketemu,pI);
    traversalIndexKontak(q);
}
