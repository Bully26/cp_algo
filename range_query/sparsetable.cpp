#include <bits/stdc++.h>
using namespace std;

class spr{
  public:
  vector<vector<int>> tbl;
  
  spr(vector<int> vec)
  {
  	int n = vec.size();
    int p2 = log2(n)+1;
    
    
    tbl.assign(p2 ,vector<int> (n , 1e7));
    
    for(int i=0;i<n;i++)
    {
    	tbl[0][i] = vec[i]; 
    }
    
    for(int p = 1; p < p2 ;p++)
    {
    	for(int i=0;i + (1<<p) <n; i++ )
    	{
    		tbl[p][i] = min(tbl[p-1][i] , tbl[p-1][i+ (1<<(p-1))]);
    	}
    }
    
  }
  
  int query(int l , int r)
  {
  	
  	int len  = r - l +1 ;
  	int p = log2(len);
  	
  	return min(tbl[p][l] , tbl[p][r - (1<<p) +1]);
  
  }
	
	
};

#define shw(x)   cout<<x<<endl;


int main()
{
   vector<int> vec{12,3245,457,234,12,345,4567,112,12,42346,4231,4,5,2,1};
   
   spr m = spr(vec);
   
   
   shw(m.query(0,4));
   shw(m.query(2,4));
   shw(m.query(5,6));
   shw(m.query(6,7));
   shw(m.query(6,6));
   shw(m.query(6,7));
   shw(m.query(8,8));
   
   
   
}
