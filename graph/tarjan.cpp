//Position this line where user code will be pasted.
class Solution {
  public:
    int tarjan(vector<vector<int>> &adj) {
        // code here
        
        // so this is going to be tarjans algorithm         // lets see what are thing we need to code  this
        // low link / in stack / stack / timer 
        
        
        // the basic logic is visit node push stack return the min time from child
        // if min time from children which is commming back is min time of current node 
        // cur node is cnenter of scc
        
        // stack help us to sepearte the current scc from going into other scc
        
        int inf = 1e8;
        int n = adj.size();
        vector<int> low,instack,entry;
        deque<int> stack;
        low.assign(n+1,inf);
        entry.assign(n+1,-1);
        instack.assign(n+1,0);
        int tmr =0;
        vector<vector<int>>scc;
        
        function <void(int)> dfs = [&](int cur)
        {
            if(low[cur]!=inf)
            {
                 return;
            }
            entry[cur]=low[cur]=tmr++;
            instack[cur]=1;
            stack.push_back(cur);
            
            for(int child:adj[cur])
            {
                if(low[child]==inf)
                {
                    dfs(child);
                    low[cur]=min(low[cur],low[child]);
                }else if (instack[child]==1)
                {
                    low[cur]=min(low[cur],low[child]);
                }
               
            }
            
            if(low[cur]==entry[cur])
            {
               
                vector<int> comp;
                {
                    int node = stack.back();
                    comp.push_back(node);
                    stack.pop_back();
                    instack[node]=0;
                    
                    if(node == cur)break;
                }
                scc.push_back(comp);
            }
            
            return ;
        };
        
        for(int i=0;i<n;i++)
        {
            dfs(i);
        }
        
        return scc.size();
            
        }
        
        
        
    
};
   /*
         the key idea is that when a ssc is found the low value of first visited node will be 
         transferred back 
         if low value comming from child matched the entry value 
         we can say this node is center of scc
         we will push value from stack till this node
         
         need vairable 
         low link = to propate lowest value back 
         entry = to compare low link value
         instack = to know if the element in current stack [path]
         stack =  stop cur scc to take min value from other scc
         tmr = to initialize entry 
        */
        
        