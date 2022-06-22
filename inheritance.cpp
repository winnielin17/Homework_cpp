#include <iostream>
#include <cstring>
using namespace std;

class Stnode
{
	protected:
		int no;
		char name[21];
		int math;
		Stnode *ptr;
	public:
		Stnode() { no = 0; math = 0; }
		void writeno(int t)
		{
			no = t;
		}
		int readno()
		{
			return no;
		}
		void writename(char t[])
		{
			strcpy(name, t);
		}
		char *readname()
		{
			return name;
		}
		void writemath(int t)
		{
			math = t;
		}
		int readmath()
		{
			return math;
		}
		void writeptr(Stnode *t)
		{
			ptr = t;
		}
		Stnode *readptr()
		{
			return ptr;
		}
};

class CS : public Stnode
{
	private:
		int cs;
		int oo;
		CS *cptr;
	public:
		void writecs(int t)
		{
			cs = t;
		}
		int readcs()
		{
			return cs;
		}
		void writeoo(int t)
		{
			oo = t;
		}
		int readoo()
		{
			return oo;
		}
		void writecptr(CS *t)
		{
			cptr = t;
		}
		CS *readcptr()
		{
			return cptr;
		}
};

class PE : public Stnode
{
	private:
		int pe;
		PE *pptr;
	public:
		void writepe(int t)
		{
			pe = t;
		}
		int readpe()
		{
			return pe;
		}
		void writepptr(PE *t)
		{
			pptr = t;
		}
		PE *readpptr()
		{
			return pptr;
		}
};

class MENU
{
	public:
		void menu()
		{
			cout<<"(1).新增學生資料"<<endl;
			cout<<"(2).刪除學生資料"<<endl;
			cout<<"(3).列印串列資料"<<endl;
			cout<<"(4).離開"<<endl; 
			cout<<"請輸入選擇項目: ";
		}
};

int main()
{
	CS *head, *q, *f, *p;
	int tno;
	char tname[21];
	int tmath, tcs, too, tpe;
	MENU m;
	int n,x;
	head = NULL;
	while(true)
	{
		m.menu();
		cin>>n;
		cout<<endl;
		if(n < 1 || n > 4)
		{
			cout<<"輸入錯誤!!"<<endl;
			cout<<"請重新選擇"<<endl;
			cout<<endl;
		}
		int t = 1;
		if(n == 1)
		{
			cout<<"新增學生資料執行中"<<endl;
			cout<<endl;
			if(head == NULL)
			{
				head = new CS;
				cout<<"請輸入學生座號: ";
				cin>>tno;
				while(tno <= 0)
				{
					cout<<"輸入的座號要>0!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>tno;
				}
				head->writeno(tno);
				cout<<"請輸入學生姓名: ";
				cin.get();
				cin.getline(tname, 21);
				head->writename(tname);
				cout<<"請輸入學生數學成績: ";
				cin>>tmath;
				while(tmath < 0 || tmath > 100)
				{
					cout<<"輸入的成績要在0~100之間!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>tmath;
				}
				head->writemath(tmath);
				cout<<"請輸入學生計概成績: ";
				cin>>tcs;
				while(tcs < 0 || tcs > 100)
				{
					cout<<"輸入的成績要在0~100之間!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>tcs;
				}
				head->writecs(tcs);
				cout<<"請輸入學生物件導向成績: ";
				cin>>too;
				while(too < 0 || too > 100)
				{
					cout<<"輸入的成績要在0~100之間!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>too;
				}
				head->writeoo(too);
				head->writecptr(NULL);
				cout<<endl;
			}
			else
			{
				q = new CS;
				cout<<"請輸入學生座號: ";
				cin>>tno;
				while(tno <= 0)
				{
					cout<<"輸入的座號要>0!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>tno;
				}
				q->writeno(tno);
				cout<<"請輸入學生姓名: ";
				cin.get();
				cin.getline(tname, 21);
				q->writename(tname);
				cout<<"請輸入學生數學成績: ";
				cin>>tmath;
				while(tmath < 0 || tmath > 100)
				{
					cout<<"輸入的成績要在0~100之間!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>tmath;
				}
				q->writemath(tmath);
				cout<<"請輸入學生計概成績: ";
				cin>>tcs;
				while(tcs < 0 || tcs > 100)
				{
					cout<<"輸入的成績要在0~100之間!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>tcs;
				}
				q->writecs(tcs);
				cout<<"請輸入學生物件導向成績: ";
				cin>>too;
				while(too < 0 || too > 100)
				{
					cout<<"輸入的成績要在0~100之間!!"<<endl;
					cout<<"請重新輸入: ";
					cin>>too;
				}
				q->writeoo(too);
				cout<<endl;
				f = NULL;
				p = head;
				while(p != NULL && p->readno() <= q->readno())
				{
					if(p->readno() == q->readno())
					{
						cout<<"輸入的座號已經存在!!"<<endl;
						cout<<"請重新選擇"<<endl;
						t = 0;
						cout<<endl;
						break;
					}
					f = p; //f跑到p的位置 
					p = p->readcptr(); //p跑到下一個 
				}
				if(t == 1)
				{
					if(f == NULL) //q最小  
					{
						q->writecptr(head);
						head = q;
					}
					else //q在中間或最大
					{
						f->writecptr(q);
						q->writecptr(p);
					}
				}
			}
		}
		if(n == 2)
		{
			cout<<"刪除學生資料執行中"<<endl;
			cout<<endl;
			if(head == NULL)
			{
				cout<<"沒有資料可供刪除!!"<<endl;
				cout<<"請重新選擇"<<endl;
				cout<<endl; 
			}
			else
			{
				cout<<"請輸入要刪除的學生座號: ";
				cin>>x;
				cout<<endl;
				f = NULL;
				p = head;
				while(p != NULL && p->readno() != x) //沒有符合的話會跳到最後一個 
				{
					f = p; //f跑到p的位置 
					p = p->readcptr(); //p跑到下一個 
				}
				if(p == NULL)
				{
					cout<<"該筆資料不存在，無法刪除"<<endl;
					cout<<"請重新選擇"<<endl;
					cout<<endl; 
				}
				else if(x == head->readno())
				{
					head = head->readcptr(); //刪掉第一個 
					cout<<"該筆資料已刪除"<<endl;
					cout<<endl;
				}
				else
				{
					f->writecptr(p->readcptr()); //刪掉中間或最大的 
					cout<<"該筆資料已刪除"<<endl; 
					cout<<endl;
				}
			}
		} 
		if(n == 3)
		{
			cout<<"列印串列資料執行中"<<endl;
			cout<<endl;
			if(head == NULL)
			{
				cout<<"head -> ||"<<endl;
				cout<<endl;
			}
			else
			{
				p = head;
				cout<<"head -> ";
				while(p != 0)
				{
					cout<<p->readno()<<" -> ";
					p = p->readcptr(); //往後一個 
				}
				cout<<"||"<<endl;
				cout<<endl;
			}
		}
		if(n == 4)
		{
			cout<<"謝謝使用~";
			break;
		}
	}
}
