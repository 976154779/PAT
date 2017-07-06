#include<iostream>
#include<math.h> 
#define size 10000
using namespace std;

int cross[3];
int result[3];
int left_result[3];
int right_result[3];
int cross_result[3];


int* FIND_MAX_CROSSING_SUBARRAY(int a[],int low,int mid,int high){
//	int cross[3];
	int left_sum=-10000;
	int sum=0;
	for(int i=mid;i>=low;i--){
		sum+=a[i];
		if(sum>left_sum){
			left_sum=sum;
			cross[0]=i;
		}
	}
	int right_sum=-10000;
	sum=0;
	for(int j=mid+1;j<=high;j++){
		sum+=a[j];
		if(sum>right_sum){
			right_sum=sum;
			cross[1]=j;
		}
	}
	cross[2]=left_sum+right_sum;
	return cross;
} 

int* FIND_MAXIMUM_SUBARRAY(int a[],int low,int high){
	
	if(high==low){
//		int result[3];
		result[0]=low;
		result[1]=high;
		result[2]=a[low]; 
		return result;
	}
	else{
		int mid=floor((low+high)/2);
		
//		int left_result[3];
		int *left;
		left=FIND_MAXIMUM_SUBARRAY(a,low,mid);
		for(int i=0;i<3;i++){
			left_result[i]=*left;
			left++;
		} 
		
//		int right_result[3];
		int *right;
		right=FIND_MAXIMUM_SUBARRAY(a,mid+1,high);
		for(int i=0;i<3;i++){
			right_result[i]=*right;
			right++;
		} 
//		int cross_result[3];
		int *cross;
		cross=FIND_MAX_CROSSING_SUBARRAY(a,low,mid,high);
		for(int i=0;i<3;i++){
			cross_result[i]=*cross;
			cross++;
		} 
		
		if(left_result[2]>=right_result[2]&&left_result[2]>=cross_result[2]){
			return left_result;
		}
		else if(right_result[2]>=left_result[2]&&right_result[2]>=cross_result[2]){
			return right_result;
		}
		else{
			return cross_result;
		}		
	}	
}

int main(){
	int a[size];
	int a_length;
	cin>>a_length;
	for(int i=1;i<=a_length;i++)
		cin>>a[i];
		
	int flags=false;
	for(int i=1;i<=a_length;i++){
		if(a[i]>=0){
			flags=true;
			break;
		}
	}
	if(flags==false){
		cout<<0<<" "<<a[1]<<" "<<a[a_length];
		return 0;
	}
		
	int result[3];
	int *pointer;
	pointer=FIND_MAXIMUM_SUBARRAY(a,1,a_length);
	for(int i=0;i<3;i++){
			result[i]=*pointer;
			pointer++;
		} 
	cout<<result[2]<<" "<<a[result[0]]<<" "<<a[result[1]];
	return 0;
}
