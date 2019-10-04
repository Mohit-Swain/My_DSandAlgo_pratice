#include"iostream"
#include"cstring"
using namespace std;
void reverse(char a[],int n){
	int i=0,j = n-1;
	while(i<j){
		swap(a[i],a[j]);
		i++;
		j--;
	}
}
int main(){
	char a[100] = "alok das likes cream";
	char *firstword = strtok(a," ");
	//reverse(firstword , strlen(firstword)); 
	char *otherwords = strtok(a," ");
	while(otherwords !=0){
		cout<<otherwords<<endl;
		int x =strcmp(firstword,otherwords);
		if(x==0){
			cout<<"alok $";
			//return 0;
		}
		otherwords = strtok(a," ");
	}
	cout<<"$";
}