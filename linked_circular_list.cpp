#include<iostream>
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
			next=NULL;
		}
	friend class list_single_circular;
	};
	class list_single_circular
	{
	private:
		node *head;
		int count;
	public:
		list_single_circular()
		{
			head=NULL;
			count=0;
		}
		bool is_list_empty()
		{
			return this->head==NULL;
		}

		void insert_at_first(int data)
		{
			node *element=new node(data);
			if(is_list_empty())
			{
				element->next=element;
				head=element;
			}
			else
			{
				node *trav=head;
				while(trav->next!=head)
				{
					trav=trav->next;
					//cout<<"hi";
				}
				trav->next=element;
				element->next=head;
				head=element;
			}
			this->count++;
			//delete element;
			//element=NULL;
		}
		void insert_at_last(int data)
		{
			node *element=new node(data);
			if(is_list_empty())
			{
				element->next=element;
				head=element;
			}
			else
			{
				node *trav=head;
				while(trav->next!=head)
				{
					trav=trav->next;
				}
				trav->next=element;
				element->next=head;

			}
			this->count++;
		}
		void insert_at_middle(int data,int pos)
		{
			node *element=new node(data);
			if(pos==1)
				insert_at_first(data);
			else if(pos==count)
				insert_at_last(data);
			else if(pos>count)
				cout<<"invalid position"<<endl;
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
				trav->next=element;
				element->next=temp;
				this->count++;
			}
		}
		void delete_at_first()
		{
			if(is_list_empty())
				cout<<"list is empty\n";
			else if(this->head->next==head)
			{
				delete head;
				this->head=NULL;
				this->count=0;
			}
			else
			{
				node *trav=head;
				while(trav->next!=head)
				{
					trav=trav->next;
				}
				node *temp=head;
				trav->next=head->next;
				head=head->next;
				delete temp;
				temp=NULL;
				this->count--;
			}
		}

		void delete_at_last()
		{
			if(is_list_empty())
				cout<<"list is empty\n";
			else if(this->head->next==head)
			{
				delete head;
				head=NULL;
				this->count=0;
			}
			else
			{
				node *trav=head;
				while(trav->next->next!=head)
				{
					trav=trav->next;
				}
				node *temp=trav->next;
				trav->next=head;
				delete temp;
				temp=NULL;
				this->count--;
			}
		}

		void print_list()
		{
			if(is_list_empty())
			{
				cout<<"list is empty\n";
				return; 
			}
			node *trav=head;
			do
			{
				cout<<"->"<<trav->data;
				trav=trav->next;
			}while(trav!=head);
			cout<<"count is"<<this->count<<endl;
		}
		~list_single_circular()
		{
			node *temp;
			while(head!=NULL)
			{
				delete_at_last();
				//print_list();
			}
		}
				
	};
}
using namespace linked_list;
int main()
{
	list_single_circular list1;
	//list1.print_list();
	list1.insert_at_first(10);
	list1.insert_at_first(20);
	list1.insert_at_first(30);
	list1.insert_at_first(40);

//	list_single_circular list2;
/*	list2.insert_at_last(10);
	list2.insert_at_last(20);
	list2.insert_at_last(30);
	list2.insert_at_last(40);
*/	
	//list_single_circular list3;
//	list1.insert_at_middle(55,5);
	list1.print_list();
	list1.delete_at_last();
	list1.print_list();
	//list3.print_list();
}
