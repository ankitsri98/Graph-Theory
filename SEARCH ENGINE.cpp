#include <bits/stdc++.h>
using namespace std;

class trienode{
public:
    trienode** children;
    int weight;

    trienode()
    {
        children =new trienode*[26];//every node has a array of pointer which store characters
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        weight=0;
    }
};
void insert(string s,int weight,trienode* root)
{
    trienode* current=root;//because root should not be disturbed
    for(int i=0;i<s.size();i++)
    {
        int index= s[i]-'a';
        if(!current->children[index])//if there is null further then make a child node
            current->children[index]=new trienode();//store in child to use it as a root next

        current=current->children[index];//moving to the next node
        if(current->weight<weight){//storing the grrater weight UPDATING
            current->weight=weight;
        }
        //cout<<"index:  "<<index<<" "<<"tep:: "<<current->children[index]<<" "<<current->weight<<endl;
    }

}
int searchbest(string s, trienode* root)
{
    int bestweight=-1;
    trienode* current= root;//root khali hai uske next se ele. store hone shuru hui hain
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        trienode* child=current->children[index];
        if(child)//check if present value NULL nhi  hai
        {
            current=current->children[index];
            bestweight=child->weight;
            //cout<<"sdvs:  "<<bestweight<<endl;
        }else{
            return -1;
        }
    }
    return bestweight;
}
int main()
{
    int n,q;
    cin>>n>>q;
    trienode* root=new trienode();//the  way class is defined ....in that way this trie with root is created
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int weight;
        cin>>weight;
        insert(s,weight,root);
    }
    while(q--)
    {
        string pre;
        cin>>pre;
        cout<<searchbest(pre,root)<<endl;
    }
    return 0;
    
}
