  int n = words1.size();
  int m = words1[0].size();
  
  vector<vector<int>> adj(n,vector<int>()); //adj[i] -> vector of all the strings that i can go to from the current string.
  map<string,int> store; //string -> index
  for(int i=0;i<n;i++)
  {
    store[words1[i]] = i;
  }
  unordered_set<string> st;
  int start = -1;
  int end = -1;
  for(int i=0;i<n;i++) 
  {
    if(words1[i]==source) start = i;
    else if(words1[i]==target) end = i;
  }
  if(end==-1) return(0);
  for(string s : words1) st.insert(s);
  for(int i=0;i<n;i++)
  {
    string curr = words1[i];
    for(int j=0;j<m;j++)
    {
      string change = curr;
      for(int k=0;k<26;k++)
      {
        change[j] = k + 'a';
        if(st.count(change) && change!=curr)
        {
          adj[i].push_back(store[change]);
        }
      } 
    }
  }
  vector<bool> vis(n,false);
