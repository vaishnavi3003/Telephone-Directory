#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
using namespace std;

void clrscr()
{
   system("cls");
}

#define ALPHABET_SIZE (26)

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isWordEnd;
};

struct TrieNode *getNode(void)
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isWordEnd = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

void insert(struct TrieNode *root, const string key)
{
	struct TrieNode *pCrawl = root;

	for (int level = 0; level < key.length(); level++)
	{
		int index = CHAR_TO_INDEX(key[level]);

		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}
	pCrawl->isWordEnd = true;
}

bool search(struct TrieNode *root, const string key)
{
	int length = key.length();

	struct TrieNode *pCrawl = root;

	for (int level = 0; level < length; level++)
	{
		int index = CHAR_TO_INDEX(key[level])

		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isWordEnd);
}
bool isLastNode(struct TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return 0;
	return 1;
}

void suggestionsRec(struct TrieNode* root, string currPrefix)
{
	if (root->isWordEnd)
	{
		cout << currPrefix;
		cout << endl;
	}


	if (isLastNode(root))
		return;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			currPrefix.push_back(97 + i);

			suggestionsRec(root->children[i], currPrefix);
		}
	}
}


int printAutoSuggestions(TrieNode* root, const string query)
{
	struct TrieNode* pCrawl = root;

	int level;

	int n = query.length();

	for (level = 0; level < n; level++)
	{
		int index = CHAR_TO_INDEX(query[level]);
		if (!pCrawl->children[index])
			return 0;

		pCrawl = pCrawl->children[index];
	}
	bool isWord = (pCrawl->isWordEnd == true);

	bool isLast = isLastNode(pCrawl);

	if (isWord && isLast)
	{
		cout << query << endl;
		return -1;
	}
	if (!isLast)
	{
		string prefix = query;
		suggestionsRec(pCrawl, prefix);
		return 1;
	}
}


void display()
 {
   fstream ip ("newnewnew.csv");

    if(!ip.is_open()) std::cout<<"Error"<<endl;

    int i=0;
    vector<string>alphaf;
    vector<string>alphal;
    vector<string>numb;
    string fname,lname;
    string number;

    cout<<"Name"<<"\t\t\t"<<"Number"<<endl;
    while(ip.good())
   {
    getline(ip,fname,',');
    getline(ip,lname,',');
    getline(ip,number,'\n');
    alphaf.push_back(fname);
    alphal.push_back(lname);
    numb.push_back(number);
    cout<<fname<<" "<<lname<<"\t\t"<<number<<endl;

   }
   ip.close();
}
void insert_rec()
{

  int choice1=0;
 fstream ip ("newnewnew.csv");
    if(!ip.is_open()) std::cout<<"Error"<<endl;
    string w,x,y,z;
   do
   {
    cout<<"Enter the details for new record "<<endl;
    cout<<"Enter First Name "<<endl;
    cin>>x;
    cout<<"Enter Last name"<<endl;
    cin>>y;
    cout<<"enter number"<<endl;
    cin>>z;

    w=x+","+y+","+z;

    ip<<w<<endl;
    cout<<"Do you want to enter more records "<<endl;
    cout<<"1. Yes  "<<"2. No  "<<endl;
    cin>>choice1;
    if(choice1!=1){
            clrscr();
            cout<<"THANKS ";

                _getch();}
                clrscr();
   } while(choice1==1);
  ip.close();
}
void delete_rec()
{
    string delfname,dellname,fname,lname,numb,x;
    vector<string>abc;
    vector<string>def;
    vector<string>number;
    fstream F1 ("newnewnew.csv");
    if(!F1.is_open()) std::cout<<"Error"<<endl;
    fstream F2 ("temp.csv");
    if(!F2.is_open()) std::cout<<"Error"<<endl;

  int del=0,i=0,j=0,k=0,l=0,m=0;
  cout<<"Enter the first name of the record you want to enter";
  cin>>delfname;

  cout<<"Enter the last name of the record you want to enter";
  cin>>dellname;

  while(F1.good())
  {
        getline(F1,fname,',');
        getline(F1,lname,',');
        getline(F1,numb,'\n');

        abc.push_back(fname);
        def.push_back(lname);
        number.push_back(numb);
    {
      if(abc[i++]==delfname&&def[j++]==dellname)
	{

	  del++;
	}
       else
       {
        x=abc[k++]+","+def[l++]+","+number[m++];
        F2<<x<<endl;
       }
    }
	 if(del)
	 cout<<"The record has been deleted";

	 F1.close();
	 F2.close();

	 remove(" ");

	 rename("temp.csv","newnewnew.csv");

 }
}

void search1()
{
    fstream ip ("newnewnew.csv");

    if(!ip.is_open()) std::cout<<"Error"<<endl;
    int i=0;
    vector<string>alpha;
    vector<string>alpha1;
    vector<string>alpha3;

    string fname,lname;
    string number,x;

    int found=0;

    while(ip.good())
    {
        getline(ip,fname,',');
        getline(ip,lname,',');
        getline(ip,number,'\n');

        alpha.push_back(fname);
        alpha1.push_back(lname);
        alpha3.push_back(number);
    }
    ip.close();
    int a,n = alpha.size();
    string asdf;

    struct TrieNode* root = getNode();

	for (int i=0; i<n; i++)
    {

		insert(root, alpha[i]);

    }
    cout<<"if you know the name enter 1 else enter 0"<<endl;
    cin>>a;

    if(a==0)
    {
    cout<<"enter the First name (or first 3-4 letter)"<<endl;
    cin>>x;

	int comp1 = printAutoSuggestions(root,x);

	if (comp1 == -1)
		cout << "No other strings found with this prefix\n";

	else if (comp1 == 0)
		cout << "No string found with this prefix\n";

    }

        cout<<"Enter the first name"<<endl;
        cin>>asdf;

        for(int i=0;i<n;i++)
        {
            if(asdf==alpha[i])
            {

                cout<<alpha[i]<<" "<<alpha1[i]<<"\t\t"<<alpha3[i]<<endl;
                found++;
            }
        }

            if(!found)
            {
                cout<<"No match found!!!!"<<endl;
            }


}


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];

    do
{

    cout<<"\n  **************************  LOGIN FORM  **************************  ";
    cout<<" \n                       ENTER USERNAME:-";
	cin>>uname;
	cout<<" \n                       ENTER PASSWORD:-";

	while(i<4)
	{
	    pword[i]=_getch();
	    c=pword[i];
	    cout<<"*";
	    i++;
	}
	_getch();
	pword[i]='\0';

	i=0;
		if((strcmpi(uname,"user")==0) && (strcmpi(pword,"pass")==0) )
	{
	cout<<"  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL";
	cout<<"\n\n\n\t\t\t\tPress any key to continue...";

	break;
	}

	else
	{
		cout<<"\n        SORRY    !!!!  LOGIN IS UNSUCESSFUL";
		a++;
		_getch();
		clrscr();
	}
}
	while(a<=3);

	if (a>3)
	{
		cout<<"\nSorry you have entered the wrong username and password for two times!!!";
		}
		system("cls");
}

 main()
{

clrscr();
int choice;
int t;

int opt;

    	time_t time_;

	time(&time_);
    system("COLOR B");
    startmenu:
   cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *      WELCOME TO     *     ::";
       cout<<"\n\t\t\t\t\t::     *       ANMOL'S       *     ::";
       cout<<"\n\t\t\t\t\t::     *      DIRECTORY      *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

cout<<"\t\t\t\t\t\tSELECT YOUR IDENTITY"<<endl;
cout<<"\t\t\t\t\t\t1.USER"<<endl;
cout<<"\t\t\t\t\t\t2.ADMINISTRATOR"<<endl;

cout<<"\t\t\t\t\t\tCHOICE - ";
cin>>opt;

clrscr();

switch(opt)
{
    case 1:
        up1:

           cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *      WELCOME TO     *     ::";
       cout<<"\n\t\t\t\t\t::     *       ANMOL'S       *     ::";
       cout<<"\n\t\t\t\t\t::     *      DIRECTORY      *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

       cout<<endl<<endl;

    cout<<"\t\t\t\t\t\tWhat would you like to do - "<<endl;
    cout<<"\t\t\t\t\t\t1.Search record"<<endl;
	cout<<"\t\t\t\t\t\t2.Display record"<<endl;
	cout<<"\t\t\t\t\t\t3.Exit"<<endl;

    cout<<"\t\t\t\t\t\tEnter choice - ";
    cin>>t;

    clrscr();
     switch(t)
      {
	case 1: clrscr();
            search1();
            _getch();
            clrscr();
	goto up1;

	break;

	case 2: display();
        cout<<endl<<endl<<endl;
        _getch();
        clrscr();
	goto up1;

	break;

	case 3: clrscr();
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\t Thank You";
            _getch();
            clrscr();
        goto startmenu;

        break;

    default :   clrscr();
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\t wrong choice";
                _getch();
                clrscr();
    goto up1;


 }
    case 2:
            login();
            up2:
            cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
            cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
            cout<<"\n\t\t\t\t\t::                                 ::";
            cout<<"\n\t\t\t\t\t::     ***********************     ::";
            cout<<"\n\t\t\t\t\t::     *                     *     ::";
            cout<<"\n\t\t\t\t\t::     *      WELCOME TO     *     ::";
            cout<<"\n\t\t\t\t\t::     *       ANMOL'S       *     ::";
            cout<<"\n\t\t\t\t\t::     *      DIRECTORY      *     ::";
            cout<<"\n\t\t\t\t\t::     *                     *     ::";
            cout<<"\n\t\t\t\t\t::     ***********************     ::";
            cout<<"\n\t\t\t\t\t::                                 ::";
            cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

            cout<<endl<<endl;

            cout<<"\t\t\t\t\t\tWhat would you like to do - "<<endl;
            cout<<"\t\t\t\t\t\t1.Add"<<endl;
            cout<<"\t\t\t\t\t\t2.Delete"<<endl;
            cout<<"\t\t\t\t\t\t3.Search"<<endl;
            cout<<"\t\t\t\t\t\t4.Display"<<endl;
            cout<<"\t\t\t\t\t\t5.Exit"<<endl;

            cout<<"\t\t\t\t\t\tEnter choice - ";
            cin>>choice;

            clrscr();
     switch(choice)
      {

	case 1: insert_rec();
            goto up2;

	break;

	case 2: delete_rec();
            cout<<endl<<endl<<endl;

	break;

	case 3: clrscr();
            search1();
            _getch();
            clrscr();
	goto up2;

	break;

	case 4: display();
            cout<<endl<<endl<<endl;
            _getch();
            clrscr();
	goto up2;

	break;

	case 5: clrscr();
            cout<<"\n\n\n\n\n\n\t\t\t\t\t\tThank You"<<endl;
            _getch();
            clrscr();
	goto startmenu;

	break;

	default:    clrscr();
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\ttwrong choice";
                _getch();
                clrscr();
            goto up2;
       }

    default:    clrscr();
                cout<<"\n\n\n\n\n\n\t\t\t\t\t\twrong choice"<<endl;
                _getch();
                clrscr();
            goto startmenu;
}

}

