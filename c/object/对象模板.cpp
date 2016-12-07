#include<iostream>
using namespace std;
#include<string>
template<class KeyType, class OtherType>
class RecordType
{
private:
	KeyType key;
	OtherType otherData;
public:
	RecordType();
	RecordType(KeyType key, OtherType otherData);
	void setKey(KeyType key);
	KeyType getKey();
	void setOtherData(OtherType otherData);
	OtherType getOtherData();
	string toString();
};
template<class KeyType, class OtherType>
RecordType<KeyType, OtherType>::RecordType()
{
	//has nothing
}
template<class KeyType, class OtherType>
RecordType<KeyType, OtherType>::RecordType(KeyType key, OtherType otherData){
	this->key = key;
	this->otherData = otherData;
}

template<class KeyType, class OtherType>
void RecordType<KeyType, OtherType>::setKey(KeyType key)
{
	this->key = key;
}
template<class KeyType, class OtherType>
KeyType RecordType<KeyType, OtherType>::getKey()
{
	return key;
}
template<class KeyType, class OtherType>
void RecordType<KeyType, OtherType>::setOtherData(OtherType otherData)
{
	this->otherData = otherData;
}
template<class KeyType, class OtherType>
OtherType RecordType<KeyType, OtherType>::getOtherData()
{
	return otherData;
}
template<class KeyType, class OtherType>
string RecordType<KeyType, OtherType>::toString()
{
	string s = "";
	s += "Key is : ";
	s += key + '0';
	s += "\n";
	s += "OtherData is : ";
	s += otherData;
	s += "\n";
	return s;
}
void test()
{
	RecordType<int, char> *recordType = new RecordType<int, char>(1, 'a');
	cout << recordType->toString();
}
int main()
{
	test();
	return 0;
}