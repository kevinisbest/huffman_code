 #include<iostream>
 #include<string>
 #include<queue>
 #include<cstdlib> 
 using namespace std;

 
 class node
 {
	 public:
		node( float wht, node* left, node* right, string co )
		{
			weight=wht;
			leftchild=left;
			rightchild=right;
			code=co;
		}
		string content;
		float weight;
		node* leftchild;
		node* rightchild;
		string code;
};

 void create_tree( float* ,int ,node** );
 void insert_sort(node** , int , int );
 void create_code(node* );

 int main()
 {
 	 int n=0;
 	 cin>>n;
 	 node* array[n];
 	 float w[n];
 	 
 	 for(int i=1;i<=n;i++)
 	 {
 	 	cin>>w[i];
	  }
	 cout<<n<<endl;
	 create_tree(w,n,array);
	 create_code(array[n-1]);
	 
	 system("pause");
	 return 0;
	 
 }

void create_tree( float* w,int n,node** array)
{
	for(int i=0;i<n;i++)
	{
		array[i]=new node(w[i],NULL,NULL,"");
	}
	insert_sort(array,0,n);
	
	int p=0;
	while(p!=n-1)
	{
		node* min_1=array[p];
		node* min_2=array[p+1];
		node* new_node;
		if(min_1->weight > min_2->weight)
		{
//			
			new_node=new node(min_1->weight+min_2->weight,min_2,min_1,"");
		 } 
		 else
		{
			new_node=new node(min_1->weight+min_2->weight,min_1,min_2,"");//左子的權重加上右子的權重 
		}
		array[p+1]=new_node;
		p=p+1;
		insert_sort(array,p,n);
	}
	
}

void insert_sort(node** array, int small, int big)
{
	for(int i=small+1;i<big;i++)
	{
		node* temp=array[i];
		int j=i-1;
		while(array[j]->weight>temp->weight&&j>=small)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
}

	
void create_code(node* p)
{
	queue<node*> node_q;
	node_q.push(p);
	while(node_q.size()!=0)
	{
		node* cur=node_q.front();
		node_q.pop();
		
		node* l=cur->leftchild;
		if(l!=NULL)
		{
			l->code=cur->code+"0"; node_q.push(l);
		}
		
		node* r=cur->rightchild;
		if(r!=NULL)
		{
			r->code=cur->code+"1"; node_q.push(r);
		}
		
		if(l==NULL&&r==NULL)
		{
			cout<<cur->content<<cur->code<<" ";
		}
	}
}

