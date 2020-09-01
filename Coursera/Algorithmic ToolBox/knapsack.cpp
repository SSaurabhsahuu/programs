#include <iostream>
#include <vector>

using std::vector;

int optimal_weight_greedy(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}
int optimal_weight(int W,const vector<int> &w)
{
    int n=w.size();
    vector<vector<int>> d(n+1,vector<int> (W+1));
    for(int i=0;i<=W;i++)
    {
        d[0][i]=0;
    }
      for(int i=0;i<=n;i++)
    {
        d[i][0]=0;
    }


    for(int i=1;i<n+1;i++)
    { for(int j=1;j<W+1;j++)
        { if(j>=w[i-1])
            { d[i][j]=std::max(w[i-1]+d[i-1][j-w[i-1]],d[i-1][j]); }
            else{
                d[i][j]=d[i-1][j];
            }

        }

    }

    return d[n][W];
}
int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
