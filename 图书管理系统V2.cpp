#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>//字符分类函数 
#include <cstdlib>
#include <cstdio>
#include <fstream>
using namespace std;
typedef long long ll;
ll n,i;

struct Library
{
		char name[50];
		char publish[50];
		ll ISBN;
		char author[50];
		ll amount;
		char price[20];
}book[2000];

bool cmp1(Library a,Library b)
{
	return strcmp(a.price,b.price)>0;
}

bool cmp2(Library a,Library b)
{
	return a.amount>b.amount;
}

bool cmp3(Library a,Library b)
{
	return strcmp(a.author,b.author)>0;
}

bool cmp4(Library a,Library b)
{
	return strcmp(a.publish,b.publish)>0;
}

void read()//读取文件内容 

{
	memset(book,0,2000); 
	FILE *fp;
	ll k=0;
	fp=fopen("text.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%lld %s %s %s %s %lld\n",&book[k].ISBN,&book[k].name,&book[k].author,&book[k].publish,&book[k].price,&book[k].amount);
		cout<<"\t-----------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\tISBN号："<<book[k].ISBN<<" |书名："<<book[k].name<<" |作者："<<book[k].author;
		cout<<" |出版社："<<book[k].publish<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<"\t"<<endl;k++;
	}
	cout<<"\t-----------------------------------------------------------------------------------------------\t"<<endl;
	i=k;
	n=k;
}

void menu()//菜单
{
	system("cls");
	system("color 2f");
	cout<<endl;
	cout<<"       \t     +-------------------------------------欢迎进入图书管理系统V2-------------------------------+"<<endl;
	cout<<"       \t     |                                                                                          |"<<endl;
	cout<<"       \t     +----------------------------------------------------By-李康 & QQ:123456789----------------+"<<endl;
	cout<<"       \t     *                                                                                          *"<<endl;
	cout<<"       \t     *\t\t\t\t        按1，图书销售系统                                       *"<<endl;
	cout<<"       \t     *\t\t\t\t                                                                *"<<endl;
	cout<<"       \t     *\t\t\t\t        按2，图书管理系统                                       *"<<endl;
	cout<<"       \t     *\t\t\t\t                                                                *"<<endl;
	cout<<"       \t     *\t\t\t\t        按3，图书信息统计                                       *"<<endl;
	cout<<"       \t     *\t\t\t\t                                                                *"<<endl;
	cout<<"       \t     *\t\t\t\t        按0，退出系统                                           *"<<endl;
	cout<<"       \t     --------------------------------------------------------------------------------------------"<<endl<<endl;
	cout<<"       \t     ==================================目前已存在的信息如下表所示================================="<<endl<<endl; 
	read();
	cout<<"\t\t请选择（0-3）:";
}

void sell()//销售系统 
{
	ll newISBN,t,k;
	cout<<"请输入购买图书的ISBN号：";
	cin>>newISBN;
	for(k=0;k<n;k++)
	{
		if(book[k].ISBN==newISBN)
		{
			cout<<"查询到的结果如下所示"<<endl; 
			cout<<"ISBN号："<<book[k].ISBN<<" 书名："<<book[k].name;
			cout<<" 作者："<<book[k].author<<" 出版社："<<book[k].publish;
			cout<<" 该图书数量为："<<book[k].amount<<"本，";
			cout<<" 单价为："<<book[k].price<<"元。"<<endl;
			break;
		}	
	}
	if(k==n) cout<<"查无此书，请重新输入ISBN号！"<<endl;
	else
	{
		cout<<"请输入购买数量：";
		cin>>t;
		book[k].amount-=t;
		cout<<"购买成功，该图书现剩余"<<book[k].amount<<"本"<<endl; 
		FILE *fp;
		fp=fopen("text.txt","w");
		for(int t=0;t<n;t++)
		{
			fprintf(fp,"%lld %s %s %s %s %lld\n",book[t].ISBN,book[t].name,book[t].author,book[t].publish,book[t].price,book[t].amount);
		}
		fclose(fp);
	}
}

void add()//添加 
{
	ll a,k,q,t,m;
	cout<<"请输入要添加图书的种类数量：";
	cin>>t;
	q=1;
	for(k=i;k<i+t;k++)
	{
		a=0;
		m=0;
		cout<<"请输入第"<<q++<<"种图书的ISBN号：";
		cin>>book[k].ISBN; 
		if(k!=i)
		{
			for(ll m=0;m<k;m++)
			{
				if(book[k].ISBN==book[m].ISBN)
				{
					cout<<"您已经添加过该图书了，请重新输入ISBN编号！"<<endl;
					a=1;
					k-=1;
					break;
				}
			}
		}
		if(a==1) continue;
		cout<<"请输入书名：";
		cin>>book[k].name;
		cout<<"请输入作者：";
		cin>>book[k].author;
		cout<<"请输入出版社：";
		cin>>book[k].publish;
		cout<<"请输入价格：";
		loop:cin>>book[k].price;
		for(int j=0;j<strlen(book[k].price);j++)//若输入的不是数字则给出提示并重新输入 
		{
			if(isdigit(book[k].price[j]))
			continue;
			else 
			{
				cout<<"输入格式错误！"<<endl;
				m=100; 
				break;
			}
		}
		if(m==100) 
		{
			cout<<"请重新输入价格："; 
			m=0;
			goto loop;
		}
		cout<<"请输入要添加该种图书的数量：";
		cin>>book[k].amount;
	}
	n+=t; 
	cout<<"添加完毕！"<<endl;
	FILE *fp;
	fp=fopen("text.txt","w");
	if(fp==NULL)
	{
		cout<<"文件打开失败！"<<endl;
		exit(0);
	}
	else
	{
		for(k=0;k<i+t;k++)
		fprintf(fp,"%lld %s %s %s %s %lld\n",book[k].ISBN,book[k].name,book[k].author,book[k].publish,book[k].price,book[k].amount);
		fclose(fp);	
	}
	
}

void inquiry()//查询 
{
	int j;
	ll k;
	char newname[50];
	char newauthor[50];
	char newpublish[50];
	char st[5];
	ll newISBN;
	do
	{
		system("cls");
		system("color 5e");
		cout<<"\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\t\t\t\t\t"<<endl;
    	cout<<"\t\t\t\t\t|             按1--按书名查询              |\t\t\t\t\t"<<endl;
    	cout<<"\t\t\t\t\t|             按2--按出版社查询            |\t\t\t\t\t"<<endl;
    	cout<<"\t\t\t\t\t|             按3--按作者查询              |\t\t\t\t\t"<<endl;
   	   	cout<<"\t\t\t\t\t|             按4--按ISBN号查询            |\t\t\t\t\t"<<endl;
   		cout<<"\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\t\t\t\t\t"<<endl;
    	cout<<"请选择 1-4:";
    	cin>>j;
    	if(j==1)
    	{
    		cout<<"请输入书名：";
    		cin>>newname;
    		for(k=0;k<n;k++)
    		{
    			if(strcmp(book[k].name,newname)==0)
    			{
    				cout<<"查询到的结果为如下所示#"<<endl;
					cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
					cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
					cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"查无此书！"<<endl;
		}
		else if(j==2)
    	{
    		cout<<"请输入出版社：";
    		cin>>newpublish;
    		for(k=0;k<n;k++)
    		{
    			if(strcmp(book[k].publish,newpublish)==0)
    			{
    				cout<<"查询到的结果为如下所示#"<<endl;
					cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
					cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
					cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"查无此书！"<<endl;
		}
		else if(j==3)
    	{
    		cout<<"请输入作者：";
    		cin>>newauthor;
    		for(k=0;k<n;k++)
    		{
    			if(strcmp(book[k].author,newauthor)==0)
    			{
    				cout<<"查询到的结果为如下所示#"<<endl;
					cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
					cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
					cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"查无此书！"<<endl;
		}
		else if(j==4)
    	{
    		cout<<"请输入ISBN号：";
    		cin>>newISBN;
    		for(k=0;k<n;k++)
    		{
    			if(book[k].ISBN==newISBN)
    			{
    				cout<<"查询到的结果为如下所示#"<<endl;
					cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
					cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
					cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"查无此书！"<<endl;
		}
		else cout<<"请输入1-4的数字！"<<endl;
		cout<<"是否继续查询？是YES，否NO。请输入：";
		cin>>st;
	}while(strcmp(st,"YES")==0);
	cout<<"查询完毕，返回管理系统"<<endl; 
}

void rewrite()//修改 
{
	ll newISBN,k,t,m;
	char s[4];
	char st[4]; 
	do
	{
		m=0;
		memset(s,0,4);
		memset(st,0,4);
		cout<<"请输入要修改信息的图书的ISBN号:";
		cin>>newISBN;
		for(k=0;k<n;k++)
		{
			if(book[k].ISBN==newISBN) 
			{
				cout<<"查询到的结果如下"<<endl;
				break;
			}
		}
		if(k==n) 
		{
			cout<<"查无此书！请重新查询！"<<endl;
			continue;
		}
		else
		{
			cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
			cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
			cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<"|"<<endl;
		}
		cout<<"是否修改书名？是YES,否NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"请输入更改后的书名：";
			cin>>book[k].name;	
		}
		memset(st,0,4); 
		cout<<"是否修改作者？是YES,否NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"请输入更改后的作者：";
			cin>>book[k].author;	
		}
		memset(st,0,4);
		cout<<"是否修改出版社？是YES,否NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"请输入更改后的出版社：";
			cin>>book[k].publish;	
		}
		memset(st,0,4);
		cout<<"是否修改数量？是YES,否NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"请输入更改后的数量：";
			cin>>book[k].amount;	
		}
		memset(st,0,4);
		cout<<"是否修改价格？是YES，否NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"请输入修改后的价格：";
			loop:cin>>book[k].price;
			for(int j=0;j<strlen(book[k].price);j++)//若输入的不是数字则给出提示并重新输入 
			{
				if(isdigit(book[k].price[j]))
				continue;
				else 
				{
					cout<<"输入格式错误！"<<endl;
					m=100; 
					break;
				}
			}
			if(m==100)
			{
				cout<<"请重新输入价格：";
				m=0;
				goto loop;
			}
		}
		cout<<"修改完毕！更改过的信息如下"<<endl; 
		cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
		cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
		cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<"|"<<endl;
		cout<<"是否继续修改信息？YES or NO"<<endl;
		cin>>s;
	}while(strcmp(s,"YES")==0);
	FILE *fp;
	fp=fopen("text.txt","w");
	for(int t=0;t<n;t++)
	{
		fprintf(fp,"%lld %s %s %s %s %lld\n",book[t].ISBN,book[t].name,book[t].author,book[t].publish,book[t].price,book[t].amount);
	}
	fclose(fp);
}

void delect()//删除 
{
	ll newISBN,k,m,t;
	char s[4];
	char st[4];
	do
	{
		memset(s,0,4);
		memset(st,0,4);
		cout<<"请输入要删除图书的ISBN号：";
		cin>>newISBN; 
		for(k=0;k<n;k++)
		{
			if(book[k].ISBN==newISBN)
			{
				cout<<"查询到的结果如下^-^"<<endl;
				cout<<"ISBN号："<<book[k].ISBN<<" |书名："<<book[k].name;
				cout<<" |作者："<<book[k].author<<" |出版社："<<book[k].publish;
				cout<<" |价格："<<book[k].price<<" |数量："<<book[k].amount<<"|"<<endl;
				break; 
			}
		}
		if(k==n) cout<<"该编号不存在！"<<endl;
		cout<<"确定要删除该图书信息吗？是YES，否NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			for(m=k;m<n-1;m++)
			{
				book[m]=book[m+1];	
			}	
			n--;
		}
		cout<<"该图书信息已经成功被您删除！"<<endl;
		cout<<"是否继续执行下一次的删除功能？YES or NO"<<endl;
		cin>>s;
	}while(strcmp(s,"YES")==0);
	FILE *fp;
	fp=fopen("text.txt","w");
	for(int t=0;t<n;t++)
	{
		fprintf(fp,"%lld %s %s %s %s %lld\n",book[t].ISBN,book[t].name,book[t].author,book[t].publish,book[t].price,book[t].amount);
	}
	fclose(fp);
}

void manage()//管理系统 
{
	int m,j;
    do
    {
    	j=1;
        system("cls");
        system("color B0");
        cout<<"\t\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          按1--添加图书信息           |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          按2--查询信息               |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          按3--修改图书信息           |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          按4--删除图书信息           |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          按0--返回主菜单             |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\t\t\t\t\t"<<endl;
        cout<<"请选择 0-4:";
        cin>>m;
        switch(m)
        {
            case 1:
                add();break;
            case 2:
            	inquiry();break;
            case 3:
            	rewrite();break;
            case 4:
            	delect();;break;
            case 0:
            	j=0;break;
            default:
            	cout<<"请输入0-4的数字"<<endl; 
        }
        if(j!=0) cout<<"按任意键继续！"<<endl;
    }while(j!=0);
}

void count()//统计系统 
{
	int a;
	ll k;
	cout<<"\t\t---------欢迎进入图书信息统计系统---------\t\t"<<endl; 
	cout<<"\t\t按1，按照价格统计\t\t"<<endl;
	cout<<"\t\t按2，按照库存量统计\t\t"<<endl;	
	cout<<"\t\t按3，按照作者统计\t\t"<<endl;	
	cout<<"\t\t按4，按照出版社统计\t\t"<<endl;
	cout<<"\t\t请输入：";
	cin>>a;
	if(a==1)
	{
		sort(book,book+n,cmp1);
		for(k=0;k<n;k++)
		{
			cout<<"价格："<<book[k].price<<" 书名："<<book[k].name;
			cout<<" 作者："<<book[k].author<<" 出版社："<<book[k].publish;
			cout<<" 库存量："<<book[k].amount<<endl;
		}
	}
	else if(a==2)
	{
		sort(book,book+n,cmp2);
		for(k=0;k<n;k++)
		{
			cout<<" 库存量："<<book[k].amount<<" 书名："<<book[k].name;
			cout<<" 作者："<<book[k].author<<" 出版社："<<book[k].publish;
			cout<<" 价格："<<book[k].price<<endl;
		}	
	}
	else if(a==3)
	{
		sort(book,book+n,cmp3);
		for(k=0;k<n;k++)
		{
			cout<<" 作者："<<book[k].author<<" 书名："<<book[k].name;
			cout<<" 出版社："<<book[k].publish<<" 库存量："<<book[k].amount;
			cout<<" 价格："<<book[k].price<<endl;		
		}	
	}
	else if(a==4)
	{
		sort(book,book+n,cmp4);
		for(k=0;k<n;k++)
		{
			cout<<" 出版社："<<book[k].publish<<" 书名："<<book[k].name;
			cout<<" ISBN号："<<book[k].ISBN<<" 库存量："<<book[k].amount;
			cout<<" 价格："<<book[k].price<<endl;
		}
	}
	else cout<<"请输入1-4的数字！"<<endl; 
}

int main()//主函数 
{
	n=i=0;
	void manage();//管理系统
	void sell();//销售系统
	void count();//统计系统
	void menu();//菜单
	void add();//添加
	void inquiry();//查询
	void rewrite();//修改
	void delect();//删除
	void read();//读取文件 
	int choice,quit;
	while(1)
	{
		quit=0;
		menu();//菜单
		//read(); 
		cin>>choice;
		switch(choice)
		{
			case 1:
				sell();break;
			case 2:
				manage();break;
			case 3:
				count();break;
			case 0:
				quit=1;break;
			default:
				cout<<"请输入0-3的数字！"<<endl;
		}
		if(quit==1) break;
		printf("按任意键返回主菜单!\n");
		getchar();
		getchar();
	}
	printf("程序结束!\n");
	return 0;
}
