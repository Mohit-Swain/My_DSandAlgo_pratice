#include"iostream"
using namespace std;

class Account{
	private:
		int balance;
		static float roi;
	public:
		void setBalance(int b){
			balance =b;
		}

		static void getBalance();
};
float Account :: roi =3.0f;
void Account :: getBalance(){
			cout<<roi<<endl;
		}
int main(){
	Account a;
	a.getBalance();
	
}