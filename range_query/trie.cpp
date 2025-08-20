// trie
#include <bits/stdc++.h>
using namespace std;
/*

add additional information in node
how many string ended here
how many string have pref with this pref




*/
class trie
{ 
  public:
  // node will act as basic unit of trie
  // every thing depends on node
  struct node{
   // link refers to valid char present in this node
   // nullptr means no char present in this node
   // end means any string has endded here
   
   vector<node*> link;
   bool end=false;
   
    node()
    {
       // assigning for 26 char
       link.assign(26,nullptr);
       end=0;
    }
    
    node* get(char c)
    {
      // return link acoording to charecter
      return link[c-'a'];
    }
    
    bool have(char c)
    {
      // find if node have char c 
       return nullptr!=link[c-'a'];
    }
    
    void put(char c)
    {
       // add char in node link
       if(link[c-'a']==nullptr)link[c-'a']=new node;
    }
  };
  
  node* root;
  
  trie()
  {
    root = new node;
  }
  
  void insert(string s)
  {
    node* cur = root;
    
    /*
    
    iterate the string put every char link in node 
    move forward in that link
    at end assign true
    
    
    */
    for(char c:s)
    {
      if(!cur->have(c))cur->put(c);
      cur = cur->get(c);
    }
    
    cur->end= true;
  }
  
  bool check(string s)
  {
  
   /*
   
   check the char move forward 
   if not found any char return false
   
   at last check if the string ended here
   
   return it
   
   */
   node* cur = root;
   
   for(char c :s)
   {
     if(!cur->have(c))return 0;
     cur = cur->get(c);
   }
   
   return cur->end;
  }
  
  bool pref(string s)
  {
  
  /*
  
  same as before just but dont check the 
  end vairable 
  if you are bale to iterate string completery 
  its prefix of some string 
  
  
  
  */
  node* cur = root;
   
   for(char c :s)
   {
     if(!cur->have(c))return 0;
     cur = cur->get(c);
   }
   
   return 1;
  
  
  }
  
  
  
};

int main() {
    trie t;
    t.insert("apple");
    t.insert("app");

    cout << t.check("apple") << "\n";  // 1
    cout << t.check("appl") << "\n";   // 0
    cout << t.pref("app") << "\n";     // 1
    cout << t.pref("ap") << "\n";     // 0

    return 0; // destructor auto-called, all memory freed
}

