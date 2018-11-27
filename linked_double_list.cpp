#include<iostream>
using namespace std;
namespace list
{
	/*node for double linked list*/
	class node
	{
	private :
		int data;
		node *next;
		node *prev;
	public :
		node(int data)
		{
			this->data=data;
			this->next=NULL;
			this->prev=NULL;
		}
		friend class listdoublelink;
	};

	class listdoublelink
	{
	private:
		node *head;
		int count;
	public:
		listdoublelink()
		{
			this->head=NULL;
			count=0;
		}
		bool is_list_empty()
		{
			return head==NULL;
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
				head->prev=element;
				head=element;
			}
			this->count++;
		}
			
		void insert_at_last(int data)
		{
			node *element=new node(data);
			if(is_list_empty())
			{
				head=element;
			}
			else
			{
				node *trav=head;
				while(trav->next!=NULL)
				{
					trav=trav->next;
				}
				trav->next=element;
				element->prev=trav;
			}
			this->count++;
		}
		void delete_at_first()
		{
			if(is_list_empty())
				cout<<"list is empty\n";
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
				count=0;
			}
			else
			{
				node *temp=head;
				head=head->next;
				head->prev=NULL;
				delete temp;
				temp=NULL;
				count--;
			}
		}
		void delete_at_last()
		{
			if(is_list_empty())
				cout<<"list is empty\n";
			else if(head->next==NULL)
			{
				delete head;
				head=NULL;
				count=0;
			}
			else
			{
				node *trav=head;
				while(trav->next!=NULL)
				{
					trav=trav->next;
				}
				node *temp=trav;
				trav->prev->next=NULL;
				delete temp;
				temp=NULL;
				count--;
			}
		}
		void print_list()
		{
			node *temp=head;
			cout<<"forword\n";
			while(temp->next!=NULL)
			{
				cout<<temp->data<<" -> ";
				temp=temp->next;
			}
			cout<<temp->data<<endl;
			/*cout<<"Reverse:\n";
			while(temp!=NULL)
			{
				cout<<temp->data<<" <- ";
				temp=temp->prev;
			}*/
			cout<<"count is "<<this->count<<endl;
		}
		~listdoublelink()
		{
			while(head!=NULL)
				delete_at_last();
		}
	};
}
using namespace list;
int main()
{
	listdoublelink list1;
	cout<<"---------------------------------------------------------------------------first"<<endl;
	list1.insert_at_last(10);
	list1.insert_at_last(20);
	list1.insert_at_last(30);
	list1.insert_at_last(40);
	list1.insert_at_last(50);
	list1.insert_at_last(60);
	list1.print_list();
	list1.delete_at_first();
	list1.print_list();
	list1.delete_at_first();
	list1.print_list();

	listdoublelink list2;
	cout<<"---------------------------------------------------------------------------last"<<endl;
	list2.insert_at_first(10);
	list2.insert_at_first(20);
	list2.insert_at_first(30);
	list2.insert_at_first(40);
	list2.insert_at_first(50);
	list2.insert_at_first(60);
	list2.print_list();
	list2.delete_at_last();
	list2.print_list();
	list2.delete_at_last();
	list2.print_list();
}





