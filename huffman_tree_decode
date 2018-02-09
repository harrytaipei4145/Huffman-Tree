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

	
	unsigned char letter;
	huff* right;
	huff* left;
};

huff::huff(){
	right=NULL;
	left = NULL;
	letter = NULL;
}
huff::~huff(){

}


int main()
{
	unsigned char ans;
	fstream file;
	string s;
	string input_s;
	huff* head=new huff();
	file.open("Reader.txt", ios::in);
	int input;
	if (!file)    
	{

		cerr << "Can't open file!\n";

		exit(1);     

	}
	
     huff* root =new huff();
	 huff* temp = root;
	for (int i = 0; i < 256;i++)

	{
		file >> s;
		
		temp = root;
		for (int j = 0; j < s.size(); j++)
		{
			
			if (s[j] == '1')
			{
				if (temp->right == NULL)
				{
					huff* one = new huff();
					temp->right = one;
					temp = one;

					
				}
				else
				{
					
					temp = temp->right;
				}
			}
			else
			{
				if (temp->left == NULL)
				{
					huff* one = new huff();
					temp->left = one;
					temp = one;

				}
				else
				{
					temp = temp->left;
				}
			}
			if (j == s.size()-1)
			{
				temp->letter=i;
			}
		}
		
	}
	file >> input_s;
	
	temp = root;
	for (int i = 0; i <input_s.size(); i++)
	{
		
		if (input_s[i] == '0')
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
		if (temp->letter != NULL)
		{
			cout << temp->letter;
			temp = root;
		}
	}

	
	
	system("pause");
	return 0;
}
