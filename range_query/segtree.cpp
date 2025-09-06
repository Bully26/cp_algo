//implementing segement tree
#include <bits/stdc++.h>
using namespace std;
class seg{
public:
vector<int> t,v;

seg(vector<int> vec)
{
  int n = vec.size();
  v=vec;
  // assign the vairables
  t.assign(4*n,0);
  build(1,0,n-1);
}

void build(int ind, int l , int r)
{
  // if lowest point base case arrived assign and return
  if(l==r)
  {
    t[ind]=v[r];
    return;
  }
  int md = (l+r)/2;
  // build left
  build(ind*2,l,md);
  //build right
  build(ind*2+1,md+1,r);
  
  // build parent from right and left
  t[ind] = t[ind*2]+t[ind*2+1];
}

int query(int ind,int tl,int tr, int l ,int r)
{
  // if l>r return out side range
  if(l>r)return 0;
  
  // if perfect point arrived return fast
  if(tl == l and tr == r) return t[ind];
  
  int md = (tl+tr)/2;
  
  // query left and query right
  // the one one which doest match return 0 
  return query(ind*2,tl,md,l,min(md,r))+query(ind*2+1,md+1,tr,max(l,md+1),r);
}
void update(int ind,int tl , int tr, int pos, int val)
{ 
  if(tl == tr and tl == pos)
  {
   t[ind]=val;
   return;
  }
  int md = (tl+tr)/2;
  
  if(pos<=md)
  {
    update(ind*2,tl,md,pos,val);
  }else
  {
    update(ind*2+1,md+1,tr,pos,val);
  }
  
  t[ind] = t[ind*2] + t[ind*2+1];
  
  
  
}

void upd(int pos,int val)
{ 
  update(1,0,v.size()-1,pos,val);
}



int qry(int l , int r)
{ 
  return query (1,0,v.size()-1,l,r);
}
};

int main()
{ 
  int n;
  cin>>n;
  int q;
  cin>>q;
  vector<int> vec(n);
  
  for(auto &i:vec)cin>>i;
  
  seg my(vec);
  
  while(q--)
  {
    int l,r;
    cin>>l>>r;
    cout<<my.qry(l,r)<<endl;
  }
  
  
  
  
  return 0;
}

///////////
// now coding segment tree

#include <bits/stdc++.h>
using namespace std;

class seg{
	public:
	vector<int> tbl,from;
	
	// assigning the value
	seg(vector<int>vec)
	{
		int n = vec.size();
		tbl.assign(4*n,-1);
		from = vec;
		build(1,0,n-1);
	}
	
	// building the the tbl
	
	void build(int ind , int l , int r)
	{
		if(l==r)
		{
			tbl[ind] =from[l];
			return;
		}
		int md = (l+r)/2;
		
		build(ind*2,l , md);
		
		build(ind*2+1,md+1, r);
		
		tbl[ind]= tbl[ind*2]+tbl[ind*2+1];
		return ;
	}
	
	void update(int ind , int l , int r , int pos, int val)
	{
		
		if(l==r and l==pos)
		{
			tbl[ind]=val;
			return ;
		}
		
		int md = (l+r)>>1;
		
		if(md>=pos)
		{
			update(ind*2,l,md,pos,val);
		}else
		{
			update(ind*2+1,md+1,r , pos , val);
		}
		
		tbl[ind]= tbl[ind*2]+tbl[ind*2+1];
		return;
	}
	void upd(int pos , int val)
	{
		update(1,0,from.size()-1,pos,val);
	}
	int query(int ind , int tl, int tr , int l , int r)
	{
		
		// if(l>r)
		// {
			// return 0;
		// }
		// if(tl==l and tr ==r )
		// {
			// return tbl[ind];
		// }
		// int md = (tl + tr)>>1;
// 		
		// return query(ind*2,tl ,md, l , min(r,md))+ query(ind*2+1,md+1, tr , max(l,md+1) , r);
		
		if(tr< l or tl >r)return 0;
		
		if(tl >= l and tr<= r)
		{
			return tbl[ind];
		}
		
		int md = (tl+tr)>>1;
		
		return query(ind*2,tl,md , l,r )+ query(ind*2+1,md+1, tr, l , r);
		
	};
	int qry(int l,int r)
	{
		return query(1,0,from.size()-1,l,r);
	}
	
	
	
	
	
};

void ans(int x)
{
	cout<<"__"<<x<<endl;
	return;
}





int main()
{
	vector<int>vec{1,5,4,7,89,45,3,7,86,4,3,3,7};
	seg  tree = seg(vec);
	
	ans(tree.qry(2,4));
	tree.upd(2,0);
	ans(tree.qry(2,4));
	ans(tree.qry(4,4));
	
	
	return 0;
}
