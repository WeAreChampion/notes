#include<iostream>
#include<string>
#include<map>
using namespace std;
#define LENGTH 11
string array[LENGTH] = {
	"Hello",
	"Name",
	"Good morning",
	"Good afternoon",
	"Good evening",
	"Good morning",
	"Good morning",
	"Hello",
	"Hello",
	"Hello",
	"Good afternoon"
};
map<string, int> stringMap;
void dispStringArray()
{
	for(int i = 0; i < LENGTH; i++) {
		cout << array[i] <<endl;
	}
}
void initMap()
{
	stringMap.clear();
	for(int i = 0; i < LENGTH; i++) {
		stringMap[array[i]]++;
	}
}
void dispMap()
{
	map<string, int>::iterator it;
	for(it = stringMap.begin(); it != stringMap.end(); it++) {
		cout << it->first << " " << it->second << endl;
	}
}
int main()
{
	initMap();
	dispMap();
	return 0;
}