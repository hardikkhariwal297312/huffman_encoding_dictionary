# include <iostream>
# include <string>
#include <fstream>
using namespace std;
struct Node
{
    char a;
    Node *arr[26];
    bool islast;

};
Node * createnew()
{
    Node *root=new(Node);
    root->a='%';
    for(int i=0;i<26;i++)
    root->arr[i]=NULL;
    root->islast=false;
    return root;
}
// Node *createnewTrie()
// {
//     Node *root=new(Node);
// }
int alphatoNum(char a)
{
    return (int(a)-97);
}
void insertword(string s,Node *root,int index)
{
    if(index==s.length())
    {
    root->islast=true;
    return;
    }
    if(root->arr[alphatoNum(s[index])]!=NULL)
    {
        insertword(s,root->arr[alphatoNum(s[index])],index+1);
    }
    else
    {
        Node *temp=createnew();
        temp->a=s[index];
        root->arr[alphatoNum(s[index])]=temp;
        insertword(s,root->arr[alphatoNum(s[index])],index+1);
    }
    


}
bool searchWord(string s,Node *root,int index)
{
    if(index==s.length())
    {
        cout<<"Return condition";
        if(root->islast==true)
        return true;
        else
        
            return false;
    }
    if(root->arr[alphatoNum(s[index])]!=NULL)
    {
        for(int i=0;i<26;i++)
        {
            cout<<root->arr[i]<<" ";
        }
        cout<<endl;
        cout<<"Exists"<<endl;
        return searchWord(s,root->arr[alphatoNum(s[index])],index+1);
    }
    else
    {
        cout<<"Does not exist";
        // Node *temp=createnew();
        // temp->a=s[index];
        // root->arr[alphatoNum(s[index])]=temp;
        // insertword(s,root->arr[alphatoNum(s[index])],index+1);
        return false;
    }
        
}
string searchlongestprefix(string s,Node *root,int index,string x)
{
    if(index==s.length())
    {
        return x;
    }
    if(root->arr[alphatoNum(s[index])]!=NULL)
    {
        // for(int i=0;i<26;i++)
        // {
        //     cout<<root->arr[i]<<" ";
        // }
        // cout<<endl;
        cout<<"Exists"<<endl;
        x.push_back(s[index]);
        return searchlongestprefix(s,root->arr[alphatoNum(s[index])],index+1,x);
    }
    else if(root->islast==true)
    {
        return x;
        // Node *temp=createnew();
        // temp->a=s[index];
        // root->arr[alphatoNum(s[index])]=temp;
        // insertword(s,root->arr[alphatoNum(s[index])],index+1);
        
    }
    else
    {
        return "$";
    }
    

}
void insertparagraph(string s,Node *root)
{
    string temp;
    for (int i=0;i<s.length();i++)
    {
        if((s[i]==' ')||(i==s.length()-1))
        {
        if(i==s.length()-1)
        temp.push_back(s[i]);
        cout<<temp<<endl;
        insertword(temp,root,0);
        temp.clear();
        }
        else
        {
            temp.push_back(s[i]);
        }
        

    }
}
void testread()
{
//     char data[1000];
//     ifstream infile; 
//     ofstream fout;
//     fout.open("uncompressed.txt");
 
//     // Execute a loop If file successfully opened
//     string line;
//     while (fout) {
 
//         // Read a Line from standard input
//         getline(cin, line);
 
//         // Press -1 to exit
//         if (line == "-1")
//             break;
 
//         // Write line in file
//         fout << line << endl;
//     }
//    infile.open("uncompressed.txt"); 
 
//    cout << "Reading from the file" << endl; 
//    infile >> data; 

//    // write the data at the screen.
//    cout << data << endl;
   fstream myfile;
   char c;
   string line;
   string p;
  myfile.open ("uncompressed.txt");
  if (myfile.is_open())
  {
    //cout<<"IN if";
    while ( myfile )
    {
        //cout<<"In while";
        myfile>>line;
      cout << line<<" ";
    }
    cout<<p;
    myfile.close();
  }
//   myfile >>c;
//   myfile.close();
}
void triefromtxt(string fileName)
{
    fstream myfile;
   char c;
   string line;
   string p;
  myfile.open (fileName);
  if (myfile.is_open())
  {
    //cout<<"IN if";
    while ( myfile )
    {
        //cout<<"In while";
        myfile>>line;
        p.append(line);
      //cout << line<<" ";
    }
    cout<<p;
    myfile.close();
  }

}