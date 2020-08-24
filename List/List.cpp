#include <iostream>
#include <ctime>
using namespace std;

struct data {
	int numb;
	int age;
};

struct list {
	struct data file;
	list *next;
};

void init(int &);
void init(list *&);
void display(list *&);
void search_date(list *&);
void add_elem(list *&);
void erase_elem(list *&);

int main() {

	int size;
	list *head = NULL;

	init(size);

	for (int i = 0; i < size; i++) {
		add_elem(head);
	}

	init(head);

	display(head);

	search_date(head);

	erase_elem(head);

	display(head);

	system("pause");
	return 0;
}

void init(int &size) {
	do {
		cout << "Enter size of list = ";
		cin >> size;
	} while (size < 1);
}


void init(list *&head) {
	srand(time(0));
	list *ptr = head;

	while (ptr) {
		ptr->file.age = rand() % 21 - 10;
		ptr->file.numb = rand() % 21 - 10;
		ptr = ptr->next; // i++
	}
}

void display(list *&head) {
	list *ptr = head;

	while (ptr) {
		cout << ptr->file.age << "\t" << ptr->file.numb << endl;
		ptr = ptr->next;
	}
}

void search_date(list *&head) {

	int ind = 0;
	int numb;
	int counter = 0;

	cout << "Enter number = ";
	cin >> numb;

	list *ptr = head;
	while (ptr && ind == 0) {
		counter++;
		if (numb == ptr->file.numb) {
			ind = 1;
		}
		ptr = ptr->next;
	}

	if (ind == 0) {
		cout << "There are not this date" << endl;
	}
	else {
		cout << "Position is: " << counter << endl;
	}
}

void add_elem(list *&head) {
	list *p = new list;
	p->next = NULL;

	if (head == NULL) {
		head = p;
		return;
	}

	list *ptr = head;
	while (ptr->next) {
		ptr = ptr->next;
	}

	ptr->next = p;
	return;
}

void erase_elem(list *&head) {
	list *q = NULL;
	int numb;

	cout << "Enter number = ";
	cin >> numb;

	list *ptr = head;
	while (ptr) {
		if (numb == ptr->file.numb) {
			q = ptr;
		}
		ptr = ptr->next;
	}

	if (q == head) {
		head = q->next;
		delete q;
		return;
	}

	ptr = head;

	while (ptr->next != q) {
		ptr = ptr->next;
	}

	if (q->next == NULL) {
		ptr->next = NULL;
		delete q;
		return;
	}

	ptr->next = q->next;
	delete q;
	return;
}


/*
void make_list(list *&head) {

	int size;
	do {
		cout << "Enter size of list = ";
		cin >> size;
	} while(size < 1);

	list *ptr = head;
	for (int i = 0; i < size - 1; i++) {
		ptr->next = new list;
		ptr = ptr->next;
		ptr->next = NULL;
	}
}
*/
