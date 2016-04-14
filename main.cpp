#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

using namespace std;


string slownik(int liczba){
	string wyjscie;
	string setki[] ={"","sto ", "dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ", "osiemset ", "dziewiecset "};
	string dziesiatki[] = {"", "", "dwadziescia ", "trzydziesci ", "czterdziesci ", "piecdziesiat ", "szescdziesiat ", "siedemdziesiat ", "osiemdziesiat ", "dziewiecdziesiat "};
	string jedynki[]={"", "", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem", "dziewiec ", "dziesiec ", "jedenascie ", "dwanascie ", "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ", "siedemnascie ", "osiemnascie ", "dziewietnascie "};
	wyjscie.append(setki[(liczba/100000)%10]);
	if(((liczba/10000)%10)>1)
	wyjscie.append(dziesiatki[(liczba/10000)%10]);
	wyjscie.append(jedynki[(liczba/10000)%10==1?(liczba/1000)%10+10:(liczba/1000)%10]);
	if(((liczba/10000)%10==1?(liczba/1000)%10+10:(liczba/1000)%10)==1)
		wyjscie.append("tysiac ");
	else if(((liczba/10000)%10==1?(liczba/1000)%10+10:(liczba/1000)%10)>1&&((liczba/10000)%10==1?(liczba/1000)%10+10:(liczba/1000)%10)<5)
		wyjscie.append("tysiace ");
	else if(((liczba/10000)%10==1?(liczba/1000)%10+10:(liczba/1000)%10)>4)
		wyjscie.append("tysiecy ");
	wyjscie.append(setki[(liczba/100)%10]);
	if(((liczba/10)%10)>1)
	wyjscie.append(dziesiatki[(liczba/10)%10]);
	jedynki[1]="jeden ";
	jedynki[0]="zero";
	wyjscie.append(jedynki[((liczba/10)%10==1?liczba%10+10:liczba%10)]);
	return wyjscie;

}
int main(int argc, char const *argv[]){
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int n = rand() % 1000000;
		cout<<n<<" = "<<slownik(n)<<endl;
	}
//	cout<<slownik(atoi(argv[1]))<<endl;
}
