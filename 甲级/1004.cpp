#include<stdio.h>
#include<stdlib.h>

struct Node{
	int ID;
	int K=0;//默认无孩子节点
	int child[100]={0};//孩子节点全为0
	Node *parent=NULL;//默认无父节点
};

Node node[100];


int find_floor(int id){//找到当前编号为id的节点所在的层数
	int count=1;
	while(node[id].parent!=NULL){
		count++;
		id=node[id].parent->ID;
	}
	return count;
}

int main(){

	int N,M;//总结点数，非叶子节点数
	int i,j;
	
	int id;//当前节点的编号
	int max_floor=1,floor;//整棵树的层数(至少为1），当前节点所在的层数

	int a[100];//表示树的每一层中叶子节点的个数
	for(i=0;i<100;i++){
		a[i]=0;//全部初始化为0
	}
	
	for(i=1;i<100;i++){
		node[i].ID=i;//所有节点的id编号赋值 
	}

	scanf("%d%d",&N,&M);

	for(i=0;i<M;i++){
		scanf("%d",&id);//非叶子节点的编号id 
		scanf("%d",&node[id].K);//对应非叶子节点的孩子数
		for(j=0;j<node[id].K;j++){
			scanf("%d",&node[id].child[j]);//填充对应节点的孩子编号
			node[node[id].child[j]].parent=&node[id];//填充对应孩子节点的父亲节点地址
		}
	}

	for(i=1;i<=N;i++){
		if(node[i].K==0){//是叶子节点
			floor=find_floor(node[i].ID);//找到当前叶子节点位于的层数
			if(floor>max_floor){
				max_floor=floor;
			}
			a[floor]++;//这一层上的叶子节点数加一			
		}
	}

	for(i=1;i<=max_floor-1;i++){ 
		printf("%d ",a[i]);
	}
	printf("%d",a[max_floor]);

	return 0;
}
