#include<iostream>
#include<math.h>
using namespace std;
int main(){
	double a,b,c;
	int p,n,m;
	cin>>a>>b;
	c=a+b;
	if(c<0){
		cout<<"-";
	}
	c=fabs(c);
	if(c<1000){
		cout<<c;
	}
	else if(c<1000000){
		n=c/1000;
		cout<<n<<",";	
		
		m=c-n*1000;	//	m=fmod(c,1000);
		if(m>100){
			cout<<m;
		}
		else if(m>10){
			cout<<"0"<<m;
		}
		else if(m>0){
			cout<<"00"<<m;
		}
		else if(m==0){
			cout<<"000";
		}
	}
	else if(c<=2000000){
		p=c/1000000;
		cout<<p<<",";	
		
		n=(c-p*1000000)/1000;
		if(n>100){
			cout<<n<<",";
		}
		else if(n>10){
			cout<<"0"<<n<<",";
		}
		else if(n>0){
			cout<<"00"<<n<<",";
		}
		else if(n==0){
			cout<<"000,";
		}
		m=fmod(c,1000);
		if(m>100){
			cout<<m;
		}
		else if(m>10){
			cout<<"0"<<m;
		}
		else if(m>0){
			cout<<"00"<<m;
		}
		else if(m==0){
			cout<<"000";
		}

	}
	return 0;
}



