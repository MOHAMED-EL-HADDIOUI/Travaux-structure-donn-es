#include <iostream>
#include <string>
using namespace std;
class Contact{
	public:
		string name,phone,email;
		Contact(string,string,string="");
		Contact(const Contact&);
		~Contact(){}
		string toString()const;
		bool compare(const Contact &)const;
		bool operator<(const Contact &)const;
		void print()const;
	};

	class Node{
	public:
		Contact *contact;
		Node *previous,*next;
		Node(string,string,string="");
		Node(const Contact &);
		~Node();
		string toString()const;
	};

	class List{
	private:
		Node *head;
		int size;
	public:
		List();
		~List();
		void add(string,string,string);
		void Delete(string,string);
		Node* search(string,string)const;
		string toString()const;
		void print()const;
	};
//=> class contact
Contact ::Contact(string name, string email, string phone)
{

    this->name = name;
    this->email = email;
    this->phone = phone;
}

Contact ::Contact(const Contact &v)
{

    this->name = v.name;
    this->email = v.email;
    this->phone = v.phone;
}

string Contact ::toString() const
{

    return "Name : " + this->name + "\t phone : " + this->phone + "\t email : " + this->email + "\n";
}

bool Contact ::compare(const Contact &v) const
{ 
    return name < v.name; 
}
bool Contact ::operator<(const Contact &v) const
{

    return name < v.name;
}
void Contact ::print()const
{
	cout<<toString();
}

//=> class Node

Node ::Node(string name, string email, string phone)
{

    this->contact = new Contact(name, email, phone);
    this->next = NULL;
    this->previous = NULL;
}

Node ::Node(const Contact &C)
{
    this->contact = new Contact(C);  
    this->next = NULL;
    this->previous = NULL;
}

Node ::~Node()
{

    delete contact;
    delete next;
    delete previous;
}
string Node ::toString() const
{

    return this->contact->toString();
}
//=>List

List ::List()
{

    this->head = NULL;
    this->size = 0;
}

List ::~List()
{

    Node *current = head;
    while (current != NULL)
    {

        head = head->next;
        delete current;
        current = head;
    }
}

void List ::add(string name, string email, string phone)
{
	Node *tmp,*tm;
	tmp=tm=this->head;
	Node *nv=new Node(name,email,phone);
	if(size==0)
	{
		this->head=nv;size++;
		return;
		
	}
	if(name<=tmp->contact->name)
	{
	    nv->next=head;
	    head->previous=nv;
	    head=nv;
	    size++;
	}
	else
	{
	 while(tmp!=NULL)
	   {
	   	if(name>tmp->contact->name)
	   	{
	   		tm=tmp;
	   		tmp=tmp->next;
		}
		else
		{
			break;
		}
       }
	if(tm->next!=NULL)
	{
		nv->next=tm->next;
		tm->next->previous=nv;
		nv->previous=tm;
	    tm->next=nv;
	    size++;
			
	}
	else
	{
	    tm->next=nv;
	    nv->previous=tm;
		size++;
	}
		
	}
}

void List ::Delete(string name, string email)
{
	if(name!=this->head->contact->name)
	{
		Node *P=head;
		while(P->contact->name!=name)
			  P=P->next;
		Node *tmp=P->next;
		P->next=tmp->next;
		tmp->previous=P;
		size--;
		delete tmp;
	}
	else
	{
	    if(head!=NULL)
	    {
		    Node *p=head;
		    head=p->next;
		    head->previous=NULL;
		    delete p;
		    size--;
	    }
	}
}

Node *List ::search(string name, string email) const
{
	Node *c = head;
    while (c!=NULL)
	{
        if(c->contact->name==name&&c->contact->email==email)
        {
            	return c;
		}
		c=c->next;
	}   
}
void List ::print() const
{
	Node *c = head;
	while (c!=NULL)
	{
        c->contact->print();
        c=c->next;
	}  
}
main()
{
	List l;
	l.add("MOHAMED","mohamedelhddioui99@gmail.com","0624389378");
	l.add("ZANIB","zanibelhddioui99@gmail.com","0604413008");
	l.add("AHMAED","ahmedelhddioui99@gmail.com","0623383098");
	l.add("ILYSE","ilyseelhddioui99@gmail.com","0620383228");
    l.print();
	l.Delete("AHMAED","ahmedelhddioui99@gmail.com");
    l.print();
}

