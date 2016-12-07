#include<iostream>
using namespace std;
#include<ctime>
#include<cstdlib>
int main()
{
	//current date/time based on current system
	time_t now = time(0);

	//convert now to tm struct for local timezone
	tm* localtm = localtime(&now);
	cout<<"the local date and time is: "<<asctime(localtm)<<endl;

	//convert now to tm struct for UTC
	tm* gmtm = gmtime(&now);
	if(gmtm != NULL) {
		cout << "The UTC date and time is: " << asctime(gmtm);
	} else {
		cout << "Failed to get the UTC date and time" << endl;
		return EXIT_FAILURE;
	}
	return 0;
}