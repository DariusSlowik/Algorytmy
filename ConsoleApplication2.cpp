#include "stdafx.h"
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

int main() {
	node *H = NULL;
	H = new node;
	H->val = 10;
	H->next = NULL;
	cout << H->val << endl;
	node *p = new node;
	p->val = 5;
	p->next = H;
	H = p;
	Add(H, 15);
	Show(H);
	Del(H);
	Show(H);
	Copy(H);
	Show(H);
	Delete(H);
	Show(H);
	Del_x(H, 10);
	Show(H);
	system("pause");
	return 0;
}
