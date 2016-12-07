#include<iostream>
using namespace std;
#define ARRAY_A_LENGTH 6
#define ARRAY_B_LENGTH 6
int mergeSort(int arrayA[], int lengthA, int arrayB[], int lengthB,int array[])
{
	int count = 0;
	int iA = 0;
	int iB = 0;
	while(iA < lengthA && iB < lengthB) {
		if(arrayA[iA] < arrayB[iB]) {
			array[count++] = arrayA[iA++];
		} else if(arrayA[iA] == arrayB[iB]) {
			array[count++] = arrayA[iA++];
			iB++;
		} else {
			array[count++] = arrayB[iB++];
		}
	}
	while(iA < lengthA) {
		array[count++] = arrayA[iA++];
	}
	while(iB < lengthB){
		array[count++] = arrayB[iB++];
	}
	return count;
}
void dispArray(int array[], int length) {
	for(int i =0; i <length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}
void testMergeSort()
{
	int arrayA[] = {
		1, 3, 5, 7, 9, 11
	};
	int arrayB[] = {
		2, 4, 6, 8, 10, 12
	};
	int array[ARRAY_A_LENGTH + ARRAY_B_LENGTH];
	int count = mergeSort(arrayA, ARRAY_A_LENGTH, arrayB, ARRAY_B_LENGTH, array);
	dispArray(array, count);
	cout << "The mid element is : " << array[(count - 1) / 2];
	if(count % 2 == 0) {
		cout << " , " << array[(count + 1) / 2];
	}
	cout << endl;
}
int getMid(int arrayA[], int arrayB[], int length)
{
	int midA, midB;
	//The start pos in the array arrayA
	int startA = 0;
	//The end pos in the array arrayA
	int endA = length - 1;
	//The start pos in the array arrayB
	int startB = 0;
	//The end pos in the array arrayB
	int endB = length - 1;
	while(startA != endA || startB != endB) {
		midA = (startA + endA) / 2;
		midB = (startB + endB) / 2;
	
//		cout << "midA = " << midA << endl;
//		cout << "midB = " << midB << endl;
		//����A�е���λ����B�е���λ����� 
		if(arrayA[midA] == arrayB[midB]) {
			return arrayA[midA];
		}
		//����A�е���λ�� < B�е���λ�����
		//������λ��Ӧ��λ��arrayA[midA-endA]��arrayB[startB-midB]�� 
		if(arrayA[midA] < arrayB[midB]) {
			if((startA + endA) % 2 == 0) {
				startA = midA;//��ȥ����A����λ��֮ǰ�������ұ����е� 
			} else {
				startA = midA + 1;//��ȥ����A����λ��֮ǰ����
			}
			endB = midB;//��ȥ����B����λ��֮�����
		} else {
			//����A�е���λ�� > B�е���λ�����
			//������λ��Ӧ��λ��arrayA[startA-midA]��arrayB[midB-endB]�� 
			if((startA + endA) % 2 == 0) {
				startB = midB;//��ȥ����B����λ��֮ǰ�������ұ����е�
			} else {
				startB = midB + 1;//��ȥ����B����λ��֮ǰ����
			}
			endA = midA;
		}
//		cout << "startA = " << startA << ", endA = " << endA << endl;
//		cout << "startB = " << startB << ", endB = " << endB << endl;
	}
	//To return the min value
	return arrayA[startA] < arrayB[startB] ? arrayA[startA] : arrayB[startB];
}
int getMid(int arrayA[], int arrayB[], int lengthA, int lengthB)
{
	int midA, midB;
	//The start pos in the array arrayA
	int startA = 0;
	//The end pos in the array arrayA
	int endA = lengthA - 1;
	//The start pos in the array arrayB
	int startB = 0;
	//The end pos in the array arrayB
	int endB = lengthB - 1;
	int dataA;
	int dataB;
	while(startA != endA || startB != endB) {
		midA = (startA + endA) / 2;
		midB = (startB + endB) / 2;
	
//		cout << "midA = " << midA << endl;
//		cout << "midB = " << midB << endl;
		//����A�е���λ����B�е���λ����� 
		if(arrayA[midA] == arrayB[midB]) {
			return arrayA[midA];
		}
		//����A�е���λ�� < B�е���λ�����
		//������λ��Ӧ��λ��arrayA[midA-endA]��arrayB[startB-midB]�� 
		if(arrayA[midA] < arrayB[midB]) {
			//��֮��������������� 
			if((startA + endA) % 2 == 0) {
				startA = midA;//��ȥ����A����λ��֮ǰ�������ұ����е� 
			} else {//��֮���������ż����
				startA = midA + 1;//��ȥ����A����λ��֮ǰ����
			}
			endB = midB;//��ȥ����B����λ��֮�����
		} else {
			//����A�е���λ�� > B�е���λ�����
			//������λ��Ӧ��λ��arrayA[startA-midA]��arrayB[midB-endB]��
			
			//��֮��������������� 
			if((startA + endA) % 2 == 0) {
				startB = midB;//��ȥ����B����λ��֮ǰ�������ұ����е�
			} else {
				startB = midB + 1;//��ȥ����B����λ��֮ǰ����
			}
			endA = midA;
		}
//		cout << "startA = " << startA << ", endA = " << endA << endl;
//		cout << "startB = " << startB << ", endB = " << endB << endl;
	}
	//To return the min value
	return arrayA[startA] < arrayB[startB] ? arrayA[startA] : arrayB[startB];
}
void testGetMid()
{
	int arrayA[] = {
		1, 3, 5, 7, 9, 11
	};
	int arrayB[] = {
		2, 4, 6, 8, 10, 12
	};
	cout << getMid(arrayA, arrayB, ARRAY_A_LENGTH) << endl;
}
void testGetMid2()
{
	int arrayA[] = {
		1, 3, 5, 7, 9, 11, 13, 15, 17
	};
	int arrayB[] = {
		2, 4, 6, 8, 10, 12, 14
	};
	cout << getMid(arrayA, arrayB, 9, 7) << endl;
}
int main()
{
	testMergeSort();
	testGetMid();
	testGetMid2();
	return 0;
}