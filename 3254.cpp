#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define MAXROWS 12
using namespace std;

map<vector<int>,int> spacereq;
vector<int> limits;
vector<int>::iterator it;

int getnum(vector<int> current){
  if (spacereq.find(current)!=spacereq.end()){
    return spacereq[current];
  }
  int mn=limits[MAXROWS+1];
  for (int i=0;i<current.size();i++){
    if (current[i]>0){
      current[i]--;
      int tmp=getnum(current);
      if (tmp==limits[MAXROWS+1]) continue;
      current[i]++;
      it = upper_bound(limits.begin()+i+1,limits.end(),tmp);
      if (*it-tmp>i+1){
	tmp=max(tmp,*(it-1));
	mn=min(mn,tmp+i+2);
      }
      else{
	mn=min(mn,*it+i+2);
      }
    }
  }
  /* save for later and return */
  spacereq[current]=mn;
  return mn;
}
int main(){
  /* initialize table of the last seat in each row (including ghost
     seats) */
  limits.resize(MAXROWS+2);
  limits[0]=0;
  for (int i=1;i<MAXROWS+2;i++){
    limits[i]=limits[i-1]+i+1;
  }
  /* read input on format: N [number of different group sizes]
     x_1, ..., x_n [number in each group] */
  int N;
  cin>>N;
  vector<int> nums(N,0);
  int totalpersons=0;
  /* base case for memoization */
  spacereq[nums]=0;
  for (int i=0;i<N;i++){
    cin>>nums[i];
    totalpersons+=nums[i]*(i+1);
  }
  if (totalpersons>limits[MAXROWS+1])
    cout<<"impossible"<<endl;
  else{
    it = upper_bound(limits.begin(),limits.end(),getnum(nums)-1);
    int totalrows = int(it-limits.begin());
    if (totalrows>MAXROWS)
      cout<<"impossible"<<endl;
    else
      cout<<totalrows<<endl;
  }
}