#include <iostream>
using namespace std;

struct node
{
	int val;
	node * next;
};
void Add(node* &H, int x) {
	node*p = new node;
	p->val = x;
	p->next = H;
	H = p;
}
void Show(node*H) {
	cout << "H->";
	node*p = H;
	while (p != NULL) {
		cout << p->val << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
void Del(node* &H) {
	if (H != NULL) {
		node* p = H;
		H = H->next;
		delete p;
	}
}
void Copy(node* &H) {
	node*p = H;
	while (p != NULL) {
		Add(p->next, p->val);
		p = p->next->next;
	}
}
void Delete(node* &H) {
	node*p = H;
	while (p != NULL) {
		Del(p->next);
		p = p->next;
	}
}
void Del_x(node* &H, int x) {
	if (H != NULL) {
		Del(H);
	}
	else {
		node* p = H;
		while (p->next!=NULL && p->next->val!=x) {
			p = p->next;
		}
		if (p->next != NULL) {
			Del(p->next);
		}
	}
}
void Multiply(node* &H){
    node* p=H;
    while(p!=NULL){
        for(int i=1;i<p->val;i++){
            Add(p->next, p->val);
            p=p->next;
        }
        p=p->next;
    }
}
void Backwards(node* &H){
    node* p=H;
    int i=1;
    while(p!=NULL){
        for(int i=0;i<1;i++){
            Add(p->next, p->val-1);
            p=p->next;
        }
        p=p->next;
    }
}

int main() {
	node *H = NULL;
	H = new node;
	/*H->val = 1;
	H->next = NULL;
	cout << H->val << endl;*/
	
	/*node *p = new node;
	p->val = 5;
	p->next = H;
	H = p;*/
	
	//     Zadanie 1
	cout<<"Zad1"<<endl;
	H->val=4;
	H->next=NULL;
	Add(H,2);
	Show(H);
	Multiply(H);
	Show(H);
	
	//     Zadanie 2
	node* H2 = NULL;
	H2 = new node;
	cout<<"Zad2"<<endl;
	for(unsigned int i=4;i>0;--i){
	    Add(H2,i);
	}
	Show(H2);
	Backwards(H2->next->next->next);
	Show(H2);
	
	//     Zadanie 3 
	node* H3 = NULL;
	H3 = new node;
	cout<<"Zad3"<<endl;
	for(unsigned int i=4;i>0;--i){
	    Add(H3,i);
	}
	Show(H3);
	Copy(H3);
	Show(H3);
	//     Zadanie 4
	
	//     Zadanie 5 
	
	//     Zadanie 6
	
	
	/*Add(H, 15);
	Show(H);
	Del(H);
	Show(H);
	Copy(H);
	Show(H);
	Delete(H);
	Show(H);
	Del_x(H, 10);
	Show(H);*/
	system("pause");
	return 0;
}
