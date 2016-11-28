#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

#define tableSize 10

int HashF(string key){
	int hash=0;

	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
		// cout<<"hash : "<<hash<<endl;
	}
	return hash % tableSize;
}


string String_vector(string s){
	string x;
	istringstream iss(s);
	iss >> x;
	return x;
}

class Palavras
{
private:
	string palavra;
public:
	Palavras()=default;
	Palavras(string p){
		palavra = p;
	}
	void setPalavras(string p){
		palavra = p;
	}
	string getPalavras(){
		return palavra;
	}

};

string lerPalavras(){
	string palavra;
	fstream in;
	in.open("palavras.txt");
	while(!in.eof()){
		getline (in,palavra);
		// cout<<palavra<<endl;
		return palavra;
	}
}
int main(){
	vector<Palavras> v;
	

	for (int i = 0; i < tableSize; i++)
	{
		Palavras p;
		string s1 = String_vector(lerPalavras());
		p.setPalavras(s1);
		v[i]=p;

	}

	cout<<v[1].getPalavras();

	system("PAUSE");
}