#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define ll long long
#define rep(i,n) for (ll i = 0; i < n; i++)
#define frev(i, x, y) for (ll i = x - 1; i >= y; i--)
#define feach(x, y) for (auto &x : y)
#define fsq(i, x, y) for (ll i = x; i*i<=y; i++)
#define vl vector<ll>
#define vp vector<pair<ll,ll>>
#define all(v) v.begin(), v.end()
#define backk(v) v.rbegin(), v.rend()
#define pb push_back
#define pf push_front
#define fr first
#define sc second
#define maxv(v) *max_element(v.begin(), v.end())
#define minv(v) *min_element(v.begin(), v.end())
#define endl '\n'
void build(int ind ,int low,int high,int arr[],int seg[]){
  if(low==high){
    seg[ind]=arr[low];
    return;
  }
  int mid=(low+high)/2;
  build(2*ind+1,low,mid,arr,seg);
   build(2*ind+2,mid+1,high,arr,seg);
   seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind,int low,int high,int l,int r,int seg[]){
     if(r<low||l>high) return 0;
     if(low>=l&&high<=r) return seg[ind];
     int mid=(low+high)/2;
     int left=query(2*ind+1,low,mid,l,r,seg);
     int right=query(2*ind+2,mid+1,high,l,r,seg);
     return left+right;
}
void update(int ind,int low,int high,int i,int val,int seg[]){
if(low==high){
  seg[ind]+=val;
  return;
}
int mid=(low+high)/2;
if(i<=mid) update(2*ind+1,low,mid,i,val,seg);
else update(2*ind+2,mid+1,high,i,val,seg);
seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int par[26];
int ranks[26];



void makeset(){
  for(int i=0;i<=25;i++){
    par[i]=i;
    ranks[i]=0;
  }
}
int findpar(int node){

  if(node==par[node]){
    return node;
  }
  return par[node]=findpar(par[node]);
}
void Union(int u,int v){
 
  u=findpar(u);
  v=findpar(v);

  if(ranks[u]<ranks[v]){
     par[u]=v;
  }
  else if(ranks[v]<ranks[u]){
    par[v]=u;

  }
  else{
    par[v]=u;
    ranks[u]++;

  }
}




void solve(){
 makeset();
map<char,int>mpused1;
map<char,int>mpused2;
map<char,char>mpreq;
for(char ch='a';ch<='z';ch++){
  mpused1[ch]=1;
}
for(char ch='a';ch<='z';ch++){
  mpused2[ch]=1;
}
for(char ch='a';ch<='z';ch++){
  mpreq[ch]='1';
}
int n;
cin>>n;
string s;
cin>>s;
string t;
for(int i=0;i<n;i++){
  if(mpreq[s[i]]!='1'){
     t.pb(mpreq[s[i]]);
  }
  else{
    char ch;
     for( ch='a';ch<='z';ch++){
      int val1=s[i]-97;
      int val2=ch-97;
      while(par[val1]!=val1){
        val1=par[val1];
        par[s[i]-97]=val1;
      }
    while(par[val2]!=val2){
        val2=par[val2];
        par[ch-97]=val2;
      }

      if(val2!=val1&&mpused2[ch]==1){ 
             Union(s[i]-97,ch-97);
             t.pb(ch);
             mpused1[s[i]]=0;
             mpused2[ch]=0;
             mpreq[s[i]]=ch;
             break;
      }
     }
     if(ch=='z'+1){
      char ch3;
      char ch4;
      for(char ch2='a';ch2<='z';ch2++){
           if(mpused1[ch2]==1){
            ch3=ch2;
            break;
           }
      }
      for(char ch2='a';ch2<='z';ch2++){
           if(mpused2[ch2]==1){
            ch4=ch2;
            break;
           }
      }
             mpreq[ch3]=ch4;
             t.pb(ch4);
             mpused1[ch3]=0;
             mpused2[ch4]=0;
            
     }

  }
}

cout<<t<<endl;

}

signed main(){
 ios_base::sync_with_stdio(false);
   cin.tie(NULL);
int t;
cin>>t;
while(t--){
solve();
}
return 0;
}