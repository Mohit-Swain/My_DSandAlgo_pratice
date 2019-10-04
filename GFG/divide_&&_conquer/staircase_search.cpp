#include"iostream"
using namespace std;

int search(int key ,int mat[][10] ,int sx ,int sy ,int ex ,int ey){
	if(sx>ex || sy>ey){
		return 0;
	}

	int midx = (sx + ex)/2 ,midy = (sy + ey)/2;

	if(mat[midx][midy]==key){
		return 1;
	}
	else if(mat[midx][midy] < key){
		return (search(key,mat,midx , sy , ex , midy) || search(key ,mat ,sx ,midy  ,ex ,ey));
	}
	else{
		return (search(key ,mat ,sx ,sy ,midx  ,ey) || search(key ,mat ,midx ,sy ,ex ,midy));
	}
}

int main(){
	int mat[][10] = {{10, 20, 30, 40},  
					{15, 25, 35, 45}, 
                    {27, 29, 37, 48}, 
                    {32, 33, 39, 50}};
    cout<<search(23,mat,0,0,3,3);
}