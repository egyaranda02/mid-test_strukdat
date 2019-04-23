#include<iostream>
using namespace std;
struct ElementList{
	int nomor;
	string tim;
	string daerah;
	int gol;
	ElementList* next;
};
typedef ElementList* pointer;
typedef pointer List;

void createList(List& First)
{
	First=NULL;
}

void createElement(pointer& pBaru, int y)
{
	pBaru=new ElementList;
	pBaru->nomor=y;
	cout<<"Masukkan Nama	: ";cin>>pBaru->tim;
	cout<<"Masukkan Daerah	: ";cin>>pBaru->daerah;
	cout<<endl;
	pBaru->gol=0;
	pBaru->next=NULL;
}

void insertLast(List& First, pointer pBaru)
{
	pointer last;
	if(First==NULL)
	{
		First=pBaru;
	}
	else
	{
		last=First;
		while(last->next!=NULL)
		{
			last=last->next;
		}
		last->next=pBaru;
	}
}

void inputGol(List& First)
{
	pointer pBantu;
	pBantu=First;
	while(pBantu!=NULL)
	{
		cout<<"TIM "<<pBantu->tim<<endl;
		cout<<"Masukkan Jumlah Gol	: ";cin>>pBantu->gol;
		pBantu=pBantu->next;
	}
}

void tukar(pointer& pBantu,pointer& pBantu2)
{
  	int temp=pBantu->gol;
	pBantu->gol=pBantu2->gol;
    pBantu2->gol=temp;
    
    string temp2=pBantu->tim;
    pBantu->tim=pBantu2->tim;
    pBantu2->tim=temp;
    
    temp=pBantu->nomor;
    pBantu->nomor=pBantu2->nomor;
    pBantu2->nomor=temp;
    
    temp2=pBantu->daerah;
    pBantu->daerah=pBantu2->daerah;
    pBantu2->daerah=temp;
}

void sorting(List& First)
{
    int swapped, i;
    pointer pBantu;
    pointer pBantu2 = NULL;

    if (First == NULL)
        return;

    do{
        swapped = 0;
       	pBantu = First;

        while(pBantu->next!=pBantu2){
            if (pBantu->gol<pBantu->next->gol){
                tukar(pBantu,pBantu->next);
                swapped = 1;
            }
            pBantu = pBantu->next;
        }
        pBantu2 = pBantu;
    } while(swapped);
}


void traversal(List First)
{
	pointer pBantu;
	pBantu=First;
	cout<<"No. Daftar| Tim		| Asal Daerah	| Gol"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	while(pBantu!=NULL)
	{
		cout<<pBantu->nomor<<"	   "<<pBantu->tim<<"		"<<" "<<pBantu->daerah<<"	  	 "<<pBantu->gol<<endl;
		pBantu=pBantu->next;
	}
}

int main()
{
	List First;
	int x,y;
	y=1;
	pointer p;
	createList(First);
	cout<<"Masukkan Jumlah Tim	: ";cin>>x;
	for(int i=0;i<x;i++)
	{
		createElement(p,y);
		insertLast(First,p);
		y++;
	}
	traversal(First);
	inputGol(First);
	sorting(First);
	traversal(First);
}
