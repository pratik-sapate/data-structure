#include<iostream>
#include<stdlib.h>
using namespace std;
namespace linked_list
{
	class node
	{
		private:
			node *next;
			int data;
		public:

		node(int data)
		{
			this->data=data;
			this->next=NULL;
		}
		friend class single_list;

	};
	class single_list
	{	
		private:
			node *head;
			int count;
		public:

		single_list()
		{
			this->head=NULL;
			this->count=0;
		}

		bool is_list_empty()
		{
			if(this->head==NULL)
				return true;
			else 
				return false;
				
		}

		void insert_at_first(int data)
		{
			node *element=new node(data);
			if(is_list_empty())
			{
				head=element;
			}
			else
			{
				element->next=head;
				head=element;
			}
			this->count++;
		}
		void insert_at_last(int data)
		{
			node *element=new node(data);
			node *temp=this->head;
			if(is_list_empty())
			{
				this->head=element;
			}
			else
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=element;
			}
			count++;
			delete element ;
			element=NULL;
		}
		void insert_at_middle(int data,int pos)
		{
			if(is_list_empty())
			{
				insert_at_first(data);
			}
			else if(pos>this->count)
			{
				cout<<"invalid position"<<endl;
				return;
			}
			else if(pos==1)
			{
				insert_at_first(data);
			}
			else if(pos==this->count)
			{
				insert_at_last(data);
			}
			else
			{
				node *element=new node(data);
				int c=1;
				node *temp1=head;
				while(c!=pos-1)
				{
					temp1=temp1->next;
					c++;
				}
				node *temp2=temp1->next;
				temp1->next=element;
				element->next=temp2;
				//cout<<temp1->data<<" "<<temp2->data;
				this->count++;
				delete(element);
				element=NULL;
			}

		}
		void delete_first()
		{
			if(is_list_empty())
			{
				cout<<"list is empty\n";
			}
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
				count=0;
			}
			else
			{
				node *temp=head;
				temp=temp->next;
				head=temp;
			}
			count--;
				
		}
		void delete_last()
		{
			if(head==NULL || head->next==NULL)
			{	
				delete_first();
			}
			else
			{
				node *temp=head;
				while(temp->next->next!=NULL)
				{
					temp=temp->next;
				}
				delete temp->next;
				temp->next=NULL;
			}
			count--;
		}
		void delete_middle(int pos)
		{
			if(head==NULL || head->next==NULL)
			{	
				delete_first();
			}
			else if(pos==count)
			{
				delete_last();
			}
			else
			{
				int c=1;
				node *trav=head;
				while(c!=pos-1)
				{
					trav=trav->next;
					c++;
				}
				node *temp=trav->next;
				trav->next=trav->next->next;
				delete trav;
				trav=NULL;
			}
		}
		void search(int data)
		{
			int cnt=1;
			node *trav=head;
			while(trav!=NULL)
			{
				if(trav->data==data)
				{
					cout<<"data is found at position "<<cnt<<endl;
					return;
				}
				else
				{
					trav=trav->next;
					cnt++;
				}
			}
			cout<<"data element is not found\n";
		}
		void search_and_delete(int data)
		{
			int cnt=1;
			node *trav=head;
			while(trav!=NULL)
			{
				if(trav->data==data)
				{
					delete_middle(cnt);
					cout<<"data is found at position "<<cnt<<endl;
					cout<<"data is deleted sucessfully\n";
					return;
				}
				trav=trav->next;
				cnt++;
			}
			cout<<"data element is not found\n";
		}
		void print_list()
		{
			if(is_list_empty())
			{
				cout<<"there is no data in the list";
			}
			else
			{
				node *temp=head;
				while(temp->next!=NULL)
				{
					cout<<temp->data<<" -> ";
					temp=temp->next;
				}
				cout<<temp->data<<endl;
			}
		}
		void print_recursive(void)
		{
			if(is_list_empty())
			{
				cout<<"list is empty\n";
			}
			else
			{
				print_recursive(head);
			}
		}
		void print_recursive(node *temp)
		{
			if(temp->next!=NULL)
			{
				print_recursive(temp->next);
			}
			cout<<" "<<temp->data<<" ";
		}
		void free_me(node *temp)
		{
			node *n;
			while(temp!=NULL)
			{
				n=temp;
				temp=temp->next;
				delete n;
				n=NULL;
			}
			delete temp;
			temp=NULL;
		}
		~single_list()
		{
			free_me(this->head);
			cout<<"elements are freed"<<endl;
		}
	};
}
using namespace linked_list;
int main()
{
	single_list list;
	list.insert_at_first(10);
	list.insert_at_first(20);
	list.insert_at_first(30);
	list.insert_at_first(40);
	list.insert_at_first(50);
	
//	single_list list2;
/*	list2.insert_at_last(10);
	list2.insert_at_last(20);
	list2.insert_at_last(20);
	list2.insert_at_last(30);
	list2.insert_at_last(40);
*/

	list.print_list();

	//list.delete_middle(3);
	cout<<"enter data\n";
	int data;
	cin>>data;
	list.search(data);
	cout<<"data in recursive order is\n";
	list.print_recursive();
	list.print_list();
}


