#include <iostream>
#include <algorithm>
#include <cstring>
#include <cctype>//�ַ����ຯ�� 
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

void read()//��ȡ�ļ����� 

{
	memset(book,0,2000); 
	FILE *fp;
	ll k=0;
	fp=fopen("text.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%lld %s %s %s %s %lld\n",&book[k].ISBN,&book[k].name,&book[k].author,&book[k].publish,&book[k].price,&book[k].amount);
		cout<<"\t-----------------------------------------------------------------------------------------------\t"<<endl;
		cout<<"\tISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name<<" |���ߣ�"<<book[k].author;
		cout<<" |�����磺"<<book[k].publish<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<"\t"<<endl;k++;
	}
	cout<<"\t-----------------------------------------------------------------------------------------------\t"<<endl;
	i=k;
	n=k;
}

void menu()//�˵�
{
	system("cls");
	system("color 2f");
	cout<<endl;
	cout<<"       \t     +-------------------------------------��ӭ����ͼ�����ϵͳV2-------------------------------+"<<endl;
	cout<<"       \t     |                                                                                          |"<<endl;
	cout<<"       \t     +----------------------------------------------------By-� & QQ:123456789----------------+"<<endl;
	cout<<"       \t     *                                                                                          *"<<endl;
	cout<<"       \t     *\t\t\t\t        ��1��ͼ������ϵͳ                                       *"<<endl;
	cout<<"       \t     *\t\t\t\t                                                                *"<<endl;
	cout<<"       \t     *\t\t\t\t        ��2��ͼ�����ϵͳ                                       *"<<endl;
	cout<<"       \t     *\t\t\t\t                                                                *"<<endl;
	cout<<"       \t     *\t\t\t\t        ��3��ͼ����Ϣͳ��                                       *"<<endl;
	cout<<"       \t     *\t\t\t\t                                                                *"<<endl;
	cout<<"       \t     *\t\t\t\t        ��0���˳�ϵͳ                                           *"<<endl;
	cout<<"       \t     --------------------------------------------------------------------------------------------"<<endl<<endl;
	cout<<"       \t     ==================================Ŀǰ�Ѵ��ڵ���Ϣ���±���ʾ================================="<<endl<<endl; 
	read();
	cout<<"\t\t��ѡ��0-3��:";
}

void sell()//����ϵͳ 
{
	ll newISBN,t,k;
	cout<<"�����빺��ͼ���ISBN�ţ�";
	cin>>newISBN;
	for(k=0;k<n;k++)
	{
		if(book[k].ISBN==newISBN)
		{
			cout<<"��ѯ���Ľ��������ʾ"<<endl; 
			cout<<"ISBN�ţ�"<<book[k].ISBN<<" ������"<<book[k].name;
			cout<<" ���ߣ�"<<book[k].author<<" �����磺"<<book[k].publish;
			cout<<" ��ͼ������Ϊ��"<<book[k].amount<<"����";
			cout<<" ����Ϊ��"<<book[k].price<<"Ԫ��"<<endl;
			break;
		}	
	}
	if(k==n) cout<<"���޴��飬����������ISBN�ţ�"<<endl;
	else
	{
		cout<<"�����빺��������";
		cin>>t;
		book[k].amount-=t;
		cout<<"����ɹ�����ͼ����ʣ��"<<book[k].amount<<"��"<<endl; 
		FILE *fp;
		fp=fopen("text.txt","w");
		for(int t=0;t<n;t++)
		{
			fprintf(fp,"%lld %s %s %s %s %lld\n",book[t].ISBN,book[t].name,book[t].author,book[t].publish,book[t].price,book[t].amount);
		}
		fclose(fp);
	}
}

void add()//��� 
{
	ll a,k,q,t,m;
	cout<<"������Ҫ���ͼ�������������";
	cin>>t;
	q=1;
	for(k=i;k<i+t;k++)
	{
		a=0;
		m=0;
		cout<<"�������"<<q++<<"��ͼ���ISBN�ţ�";
		cin>>book[k].ISBN; 
		if(k!=i)
		{
			for(ll m=0;m<k;m++)
			{
				if(book[k].ISBN==book[m].ISBN)
				{
					cout<<"���Ѿ���ӹ���ͼ���ˣ�����������ISBN��ţ�"<<endl;
					a=1;
					k-=1;
					break;
				}
			}
		}
		if(a==1) continue;
		cout<<"������������";
		cin>>book[k].name;
		cout<<"���������ߣ�";
		cin>>book[k].author;
		cout<<"����������磺";
		cin>>book[k].publish;
		cout<<"������۸�";
		loop:cin>>book[k].price;
		for(int j=0;j<strlen(book[k].price);j++)//������Ĳ��������������ʾ���������� 
		{
			if(isdigit(book[k].price[j]))
			continue;
			else 
			{
				cout<<"�����ʽ����"<<endl;
				m=100; 
				break;
			}
		}
		if(m==100) 
		{
			cout<<"����������۸�"; 
			m=0;
			goto loop;
		}
		cout<<"������Ҫ��Ӹ���ͼ���������";
		cin>>book[k].amount;
	}
	n+=t; 
	cout<<"�����ϣ�"<<endl;
	FILE *fp;
	fp=fopen("text.txt","w");
	if(fp==NULL)
	{
		cout<<"�ļ���ʧ�ܣ�"<<endl;
		exit(0);
	}
	else
	{
		for(k=0;k<i+t;k++)
		fprintf(fp,"%lld %s %s %s %s %lld\n",book[k].ISBN,book[k].name,book[k].author,book[k].publish,book[k].price,book[k].amount);
		fclose(fp);	
	}
	
}

void inquiry()//��ѯ 
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
    	cout<<"\t\t\t\t\t|             ��1--��������ѯ              |\t\t\t\t\t"<<endl;
    	cout<<"\t\t\t\t\t|             ��2--���������ѯ            |\t\t\t\t\t"<<endl;
    	cout<<"\t\t\t\t\t|             ��3--�����߲�ѯ              |\t\t\t\t\t"<<endl;
   	   	cout<<"\t\t\t\t\t|             ��4--��ISBN�Ų�ѯ            |\t\t\t\t\t"<<endl;
   		cout<<"\t\t\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\t\t\t\t\t"<<endl;
    	cout<<"��ѡ�� 1-4:";
    	cin>>j;
    	if(j==1)
    	{
    		cout<<"������������";
    		cin>>newname;
    		for(k=0;k<n;k++)
    		{
    			if(strcmp(book[k].name,newname)==0)
    			{
    				cout<<"��ѯ���Ľ��Ϊ������ʾ#"<<endl;
					cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
					cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
					cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"���޴��飡"<<endl;
		}
		else if(j==2)
    	{
    		cout<<"����������磺";
    		cin>>newpublish;
    		for(k=0;k<n;k++)
    		{
    			if(strcmp(book[k].publish,newpublish)==0)
    			{
    				cout<<"��ѯ���Ľ��Ϊ������ʾ#"<<endl;
					cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
					cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
					cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"���޴��飡"<<endl;
		}
		else if(j==3)
    	{
    		cout<<"���������ߣ�";
    		cin>>newauthor;
    		for(k=0;k<n;k++)
    		{
    			if(strcmp(book[k].author,newauthor)==0)
    			{
    				cout<<"��ѯ���Ľ��Ϊ������ʾ#"<<endl;
					cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
					cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
					cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"���޴��飡"<<endl;
		}
		else if(j==4)
    	{
    		cout<<"������ISBN�ţ�";
    		cin>>newISBN;
    		for(k=0;k<n;k++)
    		{
    			if(book[k].ISBN==newISBN)
    			{
    				cout<<"��ѯ���Ľ��Ϊ������ʾ#"<<endl;
					cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
					cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
					cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<endl;
					break; 
				}
			}
			if(k==n) cout<<"���޴��飡"<<endl;
		}
		else cout<<"������1-4�����֣�"<<endl;
		cout<<"�Ƿ������ѯ����YES����NO�������룺";
		cin>>st;
	}while(strcmp(st,"YES")==0);
	cout<<"��ѯ��ϣ����ع���ϵͳ"<<endl; 
}

void rewrite()//�޸� 
{
	ll newISBN,k,t,m;
	char s[4];
	char st[4]; 
	do
	{
		m=0;
		memset(s,0,4);
		memset(st,0,4);
		cout<<"������Ҫ�޸���Ϣ��ͼ���ISBN��:";
		cin>>newISBN;
		for(k=0;k<n;k++)
		{
			if(book[k].ISBN==newISBN) 
			{
				cout<<"��ѯ���Ľ������"<<endl;
				break;
			}
		}
		if(k==n) 
		{
			cout<<"���޴��飡�����²�ѯ��"<<endl;
			continue;
		}
		else
		{
			cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
			cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
			cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<"|"<<endl;
		}
		cout<<"�Ƿ��޸���������YES,��NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"��������ĺ��������";
			cin>>book[k].name;	
		}
		memset(st,0,4); 
		cout<<"�Ƿ��޸����ߣ���YES,��NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"��������ĺ�����ߣ�";
			cin>>book[k].author;	
		}
		memset(st,0,4);
		cout<<"�Ƿ��޸ĳ����磿��YES,��NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"��������ĺ�ĳ����磺";
			cin>>book[k].publish;	
		}
		memset(st,0,4);
		cout<<"�Ƿ��޸���������YES,��NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"��������ĺ��������";
			cin>>book[k].amount;	
		}
		memset(st,0,4);
		cout<<"�Ƿ��޸ļ۸���YES����NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			cout<<"�������޸ĺ�ļ۸�";
			loop:cin>>book[k].price;
			for(int j=0;j<strlen(book[k].price);j++)//������Ĳ��������������ʾ���������� 
			{
				if(isdigit(book[k].price[j]))
				continue;
				else 
				{
					cout<<"�����ʽ����"<<endl;
					m=100; 
					break;
				}
			}
			if(m==100)
			{
				cout<<"����������۸�";
				m=0;
				goto loop;
			}
		}
		cout<<"�޸���ϣ����Ĺ�����Ϣ����"<<endl; 
		cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
		cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
		cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<"|"<<endl;
		cout<<"�Ƿ�����޸���Ϣ��YES or NO"<<endl;
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

void delect()//ɾ�� 
{
	ll newISBN,k,m,t;
	char s[4];
	char st[4];
	do
	{
		memset(s,0,4);
		memset(st,0,4);
		cout<<"������Ҫɾ��ͼ���ISBN�ţ�";
		cin>>newISBN; 
		for(k=0;k<n;k++)
		{
			if(book[k].ISBN==newISBN)
			{
				cout<<"��ѯ���Ľ������^-^"<<endl;
				cout<<"ISBN�ţ�"<<book[k].ISBN<<" |������"<<book[k].name;
				cout<<" |���ߣ�"<<book[k].author<<" |�����磺"<<book[k].publish;
				cout<<" |�۸�"<<book[k].price<<" |������"<<book[k].amount<<"|"<<endl;
				break; 
			}
		}
		if(k==n) cout<<"�ñ�Ų����ڣ�"<<endl;
		cout<<"ȷ��Ҫɾ����ͼ����Ϣ����YES����NO"<<endl;
		cin>>st;
		if(strcmp(st,"YES")==0)
		{
			for(m=k;m<n-1;m++)
			{
				book[m]=book[m+1];	
			}	
			n--;
		}
		cout<<"��ͼ����Ϣ�Ѿ��ɹ�����ɾ����"<<endl;
		cout<<"�Ƿ����ִ����һ�ε�ɾ�����ܣ�YES or NO"<<endl;
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

void manage()//����ϵͳ 
{
	int m,j;
    do
    {
    	j=1;
        system("cls");
        system("color B0");
        cout<<"\t\t\t\t\t+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          ��1--���ͼ����Ϣ           |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          ��2--��ѯ��Ϣ               |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          ��3--�޸�ͼ����Ϣ           |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          ��4--ɾ��ͼ����Ϣ           |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t|          ��0--�������˵�             |\t\t\t\t\t"<<endl;
        cout<<"\t\t\t\t\t=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\t\t\t\t\t"<<endl;
        cout<<"��ѡ�� 0-4:";
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
            	cout<<"������0-4������"<<endl; 
        }
        if(j!=0) cout<<"�������������"<<endl;
    }while(j!=0);
}

void count()//ͳ��ϵͳ 
{
	int a;
	ll k;
	cout<<"\t\t---------��ӭ����ͼ����Ϣͳ��ϵͳ---------\t\t"<<endl; 
	cout<<"\t\t��1�����ռ۸�ͳ��\t\t"<<endl;
	cout<<"\t\t��2�����տ����ͳ��\t\t"<<endl;	
	cout<<"\t\t��3����������ͳ��\t\t"<<endl;	
	cout<<"\t\t��4�����ճ�����ͳ��\t\t"<<endl;
	cout<<"\t\t�����룺";
	cin>>a;
	if(a==1)
	{
		sort(book,book+n,cmp1);
		for(k=0;k<n;k++)
		{
			cout<<"�۸�"<<book[k].price<<" ������"<<book[k].name;
			cout<<" ���ߣ�"<<book[k].author<<" �����磺"<<book[k].publish;
			cout<<" �������"<<book[k].amount<<endl;
		}
	}
	else if(a==2)
	{
		sort(book,book+n,cmp2);
		for(k=0;k<n;k++)
		{
			cout<<" �������"<<book[k].amount<<" ������"<<book[k].name;
			cout<<" ���ߣ�"<<book[k].author<<" �����磺"<<book[k].publish;
			cout<<" �۸�"<<book[k].price<<endl;
		}	
	}
	else if(a==3)
	{
		sort(book,book+n,cmp3);
		for(k=0;k<n;k++)
		{
			cout<<" ���ߣ�"<<book[k].author<<" ������"<<book[k].name;
			cout<<" �����磺"<<book[k].publish<<" �������"<<book[k].amount;
			cout<<" �۸�"<<book[k].price<<endl;		
		}	
	}
	else if(a==4)
	{
		sort(book,book+n,cmp4);
		for(k=0;k<n;k++)
		{
			cout<<" �����磺"<<book[k].publish<<" ������"<<book[k].name;
			cout<<" ISBN�ţ�"<<book[k].ISBN<<" �������"<<book[k].amount;
			cout<<" �۸�"<<book[k].price<<endl;
		}
	}
	else cout<<"������1-4�����֣�"<<endl; 
}

int main()//������ 
{
	n=i=0;
	void manage();//����ϵͳ
	void sell();//����ϵͳ
	void count();//ͳ��ϵͳ
	void menu();//�˵�
	void add();//���
	void inquiry();//��ѯ
	void rewrite();//�޸�
	void delect();//ɾ��
	void read();//��ȡ�ļ� 
	int choice,quit;
	while(1)
	{
		quit=0;
		menu();//�˵�
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
				cout<<"������0-3�����֣�"<<endl;
		}
		if(quit==1) break;
		printf("��������������˵�!\n");
		getchar();
		getchar();
	}
	printf("�������!\n");
	return 0;
}
