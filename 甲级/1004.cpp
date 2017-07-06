#include<stdio.h>
#include<stdlib.h>

struct Node{
	int ID;
	int K=0;//Ĭ���޺��ӽڵ�
	int child[100]={0};//���ӽڵ�ȫΪ0
	Node *parent=NULL;//Ĭ���޸��ڵ�
};

Node node[100];


int find_floor(int id){//�ҵ���ǰ���Ϊid�Ľڵ����ڵĲ���
	int count=1;
	while(node[id].parent!=NULL){
		count++;
		id=node[id].parent->ID;
	}
	return count;
}

int main(){

	int N,M;//�ܽ��������Ҷ�ӽڵ���
	int i,j;
	
	int id;//��ǰ�ڵ�ı��
	int max_floor=1,floor;//�������Ĳ���(����Ϊ1������ǰ�ڵ����ڵĲ���

	int a[100];//��ʾ����ÿһ����Ҷ�ӽڵ�ĸ���
	for(i=0;i<100;i++){
		a[i]=0;//ȫ����ʼ��Ϊ0
	}
	
	for(i=1;i<100;i++){
		node[i].ID=i;//���нڵ��id��Ÿ�ֵ 
	}

	scanf("%d%d",&N,&M);

	for(i=0;i<M;i++){
		scanf("%d",&id);//��Ҷ�ӽڵ�ı��id 
		scanf("%d",&node[id].K);//��Ӧ��Ҷ�ӽڵ�ĺ�����
		for(j=0;j<node[id].K;j++){
			scanf("%d",&node[id].child[j]);//����Ӧ�ڵ�ĺ��ӱ��
			node[node[id].child[j]].parent=&node[id];//����Ӧ���ӽڵ�ĸ��׽ڵ��ַ
		}
	}

	for(i=1;i<=N;i++){
		if(node[i].K==0){//��Ҷ�ӽڵ�
			floor=find_floor(node[i].ID);//�ҵ���ǰҶ�ӽڵ�λ�ڵĲ���
			if(floor>max_floor){
				max_floor=floor;
			}
			a[floor]++;//��һ���ϵ�Ҷ�ӽڵ�����һ			
		}
	}

	for(i=1;i<=max_floor-1;i++){ 
		printf("%d ",a[i]);
	}
	printf("%d",a[max_floor]);

	return 0;
}
