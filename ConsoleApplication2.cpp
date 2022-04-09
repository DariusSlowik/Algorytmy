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

void sort(node*&H, int x) {
	if (H == NULL) {
		Add(H, x);
	}
	else {
		if (H->val > x) {
			node* p = H;
			while (p->next != NULL&&p->next->val < x) {
				p = p->next;
			}
			Add(p->next, x);
		}
	}
}

void swapFL(node*&H) {
	if (H != NULL&&H->next != NULL) {
		if (H->next->next == NULL) {
			node *e = H->next;
			H->next = NULL;
			e->next = H;
			H = e;
		}
		else {
			node *p = H;
			while (p->next->next != NULL) {
				p = p->next;
			}
			node*e = H;
			H = p->next;
			p->next->next = e->next;
			p->next = e;
			e->next = NULL;
		}
	}
}

int countEL(node*H) {
	int a=0;
	node*p = H;
	while (p != NULL) {
		p = p->next;
		a++;
	}
	return a;
}

void SplitList(node*&H, node*&H1, node*&H2) {
	if (H != NULL) {
		if (H->next == NULL) {
			H1 = H;
			H = NULL;
		}
		else {
			int c = countEL(H);
			node* p = H;
			for (int i = 0; i < (c/2)-1; i++) {
				p = p->next;
			}
			H2 = p->next;
			p->next = NULL;
			H1 = H;
			H = NULL;
		}
	}
}

void Merge(node*&H, node*&H1, node*&H2) {

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
