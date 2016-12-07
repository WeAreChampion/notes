#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
struct Book {
	string name;
	string year;
	string price;
};
/**
	根据名称，年份，价格排序
*/
bool compName(const Book b1, const Book b2)
{
	if(b1.name != b2.name) {
		return b1.name < b2.name;
	} else if(b1.year != b2.year) {
		return b1.year < b2.year;
	}
	return b1.price < b2.price;
}
/**
	根据年份，名称，价格排序
*/
bool compYear(const Book b1, const Book b2)
{
	if(b1.year != b2.year) {
		return b1.year < b2.year;
	} else if(b1.name != b2.name) {
		return b1.name < b2.name;
	}
	return b1.price < b2.price;
}
/**
	根据价格，名称，年份排序
*/
bool compPrice(const Book b1, const Book b2)
{
	if(b1.price != b2.price) {
		b1.price < b2.price;
	} else if(b1.name != b2.name) {
		return b1.name < b2.name;
	}
	return b1.year < b2.year;
}
int main()
{
	vector<Book> v;
	string sortring;
	Book book;
	int n, i, line = 0;
	while(cin >> n && n) {
		line++;
		v.clear();
		for(i = 0; i < n; i++) {
			cin >> book.name >> book.year >> book.price;
			v.push_back(book);
		}
		cin >> sortring;
		if(sortring == "Name") {
			sort(v.begin(), v.end(), compName);
		} else if(sortring == "Year") {
			sort(v.begin(), v.end(), compYear);
		} else if(sortring == "Price") {
			sort(v.begin(), v.end(), compPrice);
		}
		if(line != 1) {
			cout << endl;
		}
		for(i = 0; i < v.size(); i++) {
			cout << v[i].name << " " << v[i].year << " " << v[i].price << endl;
		}
	}
	return 0;
}
/*
3
LearningGNUEmaces 2003 68
TheC++StandardLibrary 2002 108
ArtificialIntelligence 2005 78
Year
0
*/