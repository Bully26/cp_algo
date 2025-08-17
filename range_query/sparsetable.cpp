class sptable{
   public:
  vector<vector<int>> sp;
  
  
  template<typename F>
  sptable(vector<int> &vec , F fun)
  {
    
     int n = vec.size();
     int p = log2(n)+1;
     
     sp.assign(p,vector<int> (n,-1));
     
     for(int i=0;i<n;i++)
     {
       sp[0][i]=vec[i];
     }
     
     for(int k = 1; k <= p ;k++)
     {
        for(int i =0 ; i+ pow(2,k) -1  < n ; i++)
        {
          sp[k][i] = fun(sp[k-1][i] , sp[k-1][i + pow(2,k-1)]);
        }
     }
  }
  template<typename F>
  int query(int l, int r,F fun)
  {
     int len = r - l + 1;
     int p = log2(len);
     
     int res = fun(sp[p][l], sp[p][l + (len - pow(2,p))]);
     
     return res;
  }
};