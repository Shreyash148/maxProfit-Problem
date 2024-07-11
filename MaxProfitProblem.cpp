#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<ll>> solution;
ll findMaxEarnings(ll timeleft, vector<vector<ll>> &dp, ll sum)
{
  if (timeleft < 4)
  {
    return sum * timeleft;
  }
  if (dp[timeleft][sum] != -1)
    return dp[timeleft][sum];
  ll earnings = 0;
  if (timeleft >= 5)
    earnings = max(earnings, findMaxEarnings(timeleft - 5, dp, sum + 3) + 5 * sum);
  if (timeleft >= 4)
    earnings = max(earnings, findMaxEarnings(timeleft - 4, dp, sum + 2) + 4 * sum);
  if (timeleft >= 10)
    earnings = max(earnings, findMaxEarnings(timeleft - 10, dp, sum + 6) + 10 * sum);
  return dp[timeleft][sum] = earnings;
}
void getAllPossibleSolutions(ll theatre, ll pub, ll commPark, ll timePeriod, ll earnings)
{
  ll timeUsed = theatre * 5 + pub * 4 + commPark * 10;
  ll sum = theatre * 3 + pub * 2 + commPark * 6;
  if (timePeriod - timeUsed < 4)
  {
    if (earnings == sum * (timePeriod - timeUsed))
    {
      solution.push_back({theatre, pub, commPark});
    }
    return;
  }
  if (timePeriod - timeUsed >= 5)
    getAllPossibleSolutions(theatre + 1, pub, commPark, timePeriod, earnings - 5 * sum);
  if (timePeriod - timeUsed >= 4)
    getAllPossibleSolutions(theatre, pub + 1, commPark, timePeriod, earnings - 4 * sum);
  if (timePeriod - timeUsed >= 10)
    getAllPossibleSolutions(theatre, pub, commPark + 1, timePeriod, earnings - 10 * sum);
  return;
}
int main()
{
  ll n;
  cout << "Enter the number of Time Units: ";
  cin >> n;
  vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, -1));
  ll maxEarnings = findMaxEarnings(n, dp, 0);
  cout << "Earnings : " << maxEarnings * 500 << endl;
  ll theatre = 0, pub = 0, commPark = 0;
  getAllPossibleSolutions(theatre, pub, commPark, n, maxEarnings);
  cout << "Solutions : " << endl;

  for (ll i = 0; i < solution.size(); i++)
  {
    cout << "T: " << solution[i][0] << " P: " << solution[i][1] << " C: " << solution[i][2] << endl;
  }
  return 0;
}