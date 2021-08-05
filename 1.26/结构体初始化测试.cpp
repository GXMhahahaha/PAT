//拓扑排序
#include <iostream>
#include <queue>
using namespace std;


struct Node{
	int id;
	int indegree = 6;//这是高级标准才能运行的，尽量不要使用 
//	Node(){
//		indegree = 5;
//	}
//	Node(int _id,int _in){
//		id = _id;
//		indegree = _in;
//	} 
}node[5];



int main(){

	for(int i=0;i<5;i++){
		cout<<node[i].indegree;
	}
	cout<<endl;
//	Node temp = Node(3,2);
//	cout<<temp.id<<" "<<temp.indegree;
	
	return 0;
} 
