#include <iostream>
#include <fstream>
using namespace std;

class hashClass
{
private:
	static const int tableSize = 10;
	struct item
	{
		string name="empty";
		string drink="empty";
		item* next = NULL;
	};

	item HashTable[tableSize];
public:
	hashClass(){
/*		for (int i = 0; i < tableSize; i++)
		{
			HashTable[i] = new item;
			HashTable[i]->name = "empty";
			HashTable[i]->drink = "empty";
			HashTable[i]->next = NULL;
		}*/
	}

	int HashF(string key){
		int hash=0;
	
		for (int i = 0; i < key.length(); i++)
		{
			hash = hash + (int)key[i];
			// cout<<"hash : "<<hash<<endl;
		}
		return hash % tableSize;
	}
/*	void AddItem(string name, string drink){
		int index = HashF(name);
		if(HashTable[index].name == "empty"){
			HashTable[index].name = name;
			HashTable[index].drink = drink;
		}
		else{
			item& Ptr = HashTable[index]; //usei &, invés de *... ver no que dá depois
			item* n = new item;
			n->name = name;
			n->drink = drink;
			n->next = NULL;
			while(Ptr->next !=NULL){
				Prt = Prt->next;
			}

		}
	}*/

};

string lerPalavras(){
	string palavras;
	fstream in;
	in.open("palavras.txt");
	while(!in.eof()){
		getline (in,palavras);
		//cout<<palavras<<endl;
		return palavras;
	}
}

int main(){
	string palavras = lerPalavras();
	cout<<palavras;
	
	hashClass obj;
	cout<<obj.HashF("Renan Kimura")<<endl;
	
	system("PAUSE");
}