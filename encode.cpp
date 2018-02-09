#include<iostream>
#include<string.h>
#include <sstream>
#include <fstream>
#include <stdlib.h> 
using namespace std;

int number = 0;
class huff{
public:
	huff();
	~huff();

	int weight;
	int letter;
	huff* left;
	huff* right;
	huff* father;
	huff* sib;
	huff* pre;
	huff* next;
	int arr[50];
	int n;
};

huff::huff(){
	left = next = right = father = sib = pre = NULL;
	letter = NULL;
	weight = 1;
	n = 0;
	arr[50] = NULL;
}
huff::~huff(){

}
void swap(huff* a, huff*b)
{
	huff* temp = a;
	b->pre = temp->pre;

	a->sib = b->sib;
	a->pre = b;
	b->sib = temp;
	if (b->pre != NULL)
		b->pre->sib = b;
	if (a->sib != NULL)
		a->sib->pre = a;
}
void sort(huff* head)
{
	huff* temp = head;



	for (int i = 0; i < number - 1; i++)
	{
		temp = head;
		for (int j = 0; j < number - 1 - i; j++)
		{

			if (temp != NULL && temp->sib != NULL && temp->weight > temp->sib->weight)
			{
				swap(temp, temp->sib);
				temp = temp->pre;
			}
			if (temp->sib != NULL)
				temp = temp->sib;

		}


	}


}

int main()
{
	fstream file;
	
	string s;
	getline(cin, s, '\n');
	
	huff *head = new huff();
	huff *tail = new huff();
	huff *temp;

	file.open("Reader.txt", ios::out | ios::trunc);
	if (!file) 

	{

		cerr << "Can't open file!\n";

		exit(1);     

	}

	for (int i = 0; i < s.size(); i++)
	{
		if (head->letter == NULL)
		{
			head->letter = s[i];
			head->weight = 2;
			number++;
		}
		else
		{
			temp = head;
			while (true)
			{
				if (s[i] == temp->letter)
				{
					temp->weight = temp->weight + 1;
					break;
				}
				else
				{
					if (temp->sib == NULL)
					{
						huff* one = new huff();
						one->letter = s[i];
						one->weight = 2;
						one->pre = temp;
						temp->sib = one;
						number++;
						break;
					}
					else
					{
						temp = temp->sib;
						continue;
					}
				}
			}
		}
	}
	for (int k = 0; k < 256; k++)
	{
		int x;
		huff* check = head;
		x = k;
		while (true)
		{
			if (x == check->letter)
			{
				break;
			}
			else if (check->sib == NULL)
			{
				huff* ins = new huff();
				ins->letter = x;
				ins->weight = 1;
				ins->pre = check;
				check->sib = ins;
				number++;
				break;
			}
			else
			{

				check = check->sib;
				continue;
			}
		}
	}
	sort(head);


	while (head->pre != NULL)
	{
		head = head->pre;
	}

	huff* old_head = head;
	while (old_head->sib != NULL)
	{
		old_head = old_head->sib;
	}
	tail = old_head;
	while (old_head->pre != NULL)
	{
		old_head->next = old_head->pre;
		old_head = old_head->pre;
	}
	old_head = head;
	while (true)
	{

		huff* root = new huff();
		if (head->sib == NULL)
			break;
		root->right = head->sib;
		root->left = head;
		root->weight = head->weight + head->sib->weight;
		if (head->sib->sib != NULL)
		{
			root->sib = head->sib->sib;
			root->sib->pre = root;
		}
		head->father = root;
		head->sib->father = root;
		head = root;
		sort(head);
		while (head->pre != NULL)
		{
			head = head->pre;
		}


	}

	huff *use = tail;


	while (true)
	{

		huff *use_father = use;
		use->n = 0;
		while (use_father->father != NULL)
		{
			if (use_father == use_father->father->right)
				use->arr[use->n] = 1;
			else
				use->arr[use->n] = 0;
			use->n++;
			use_father = use_father->father;
		}

		if (use->next != NULL)
		{
			use = use->next;
			continue;
		}
		else
			break;
	}
	for (int i = 0; i < 256;i++)
	{
		use = tail;
		while (true)
		{
			if (use->letter == i)
			{
				for (int i = use->n - 1; i >= 0; i--)
				{
					file << use->arr[i];
				}
				file<< endl;
				break;
			}
			else
			{
				use = use->next;
				continue;
			}
		}
	}
	for (int i = 0; i < s.size(); i++)
	{
		huff* print = tail;
		while (true)
		{
			if (s[i] == print->letter)
		{
				for (int i = print->n - 1; i >= 0; i--)
				{
					file << print->arr[i];
				}
				break;
			}
			else
			{
				print = print->next;
			}
		}

	}

	system("pause");
	return 0;
}
