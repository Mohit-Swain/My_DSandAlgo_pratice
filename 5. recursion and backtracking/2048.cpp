#include"iostream"
using namespace std;
void digitprint(int x){
	switch(x){
		case 0:
			cout<<"zero ";
			break;
		case 1:
			cout<<"one ";
			break;
		case 2:
			cout<<"two ";
			break;
		case 3:
			cout<<"three ";
			break;
		case 4:
			cout<<"four ";
			break;
		case 5:
			cout<<"five ";
			break;
		case 6:
			cout<<"six ";
			break;
		case 7:
			cout<<"seven ";
			break;
		case 8:
			cout<<"eight ";
			break;
		case 9:
			cout<<"nine ";
			break;
	}
}
void words(int n){
	if(n==0){
		return;
	}
	int x = n%10;
	words(n/10);
	digitprint(x);
}

int main(){
	int n;
	cin>>n;
	words(n);
}