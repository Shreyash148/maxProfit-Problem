#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


void getAllPossibleSolutions(ll timePeriod, ll &earnings, set<vector<ll>> &solution, vector<pair<ll, ll>> buildingType, ll seqeunce)
{
  ll time1 = buildingType[0].first, time2 = buildingType[1].first, time3 = buildingType[2].first;
  ll buildEarn1 = buildingType[0].second, buildEarn2 = buildingType[1].second, buildEarn3 = buildingType[2].second;
  ll maxBuilding = timePeriod / time1;
  ll earn1 = 0;

  for (ll building1 = 0; building1 <= maxBuilding; building1++){
    ll leftTime = timePeriod - building1 * time1;
    if (building1 > 0){
      earn1 += buildEarn1 * leftTime;
    }
    ll earn2 = earn1;
    for (ll building2 = 0; building2 <= leftTime / time2; building2++){
      ll remTime = leftTime - building2 * time2;
      if (building2 > 0){
        earn2 += buildEarn2 * remTime;
      }
      ll building3 = remTime / time3;
      remTime -= building3 * time3;
      ll earn3 = earn2;
      if (building3 > 0){
        earn3 += (((building3 - 1) * building3 / 2) * time3 + remTime) * buildEarn3;
      }
      if (earn3 > earnings){
        solution.clear();
        earnings = earn3;
      }
      if (earn3 == earnings){
        if (seqeunce == 1)
          solution.insert({building1, building2, building3});
        if (seqeunce == 2)
          solution.insert({building1, building3, building2});
        if (seqeunce == 3)
          solution.insert({building2, building1, building3});
        if (seqeunce == 4)
          solution.insert({building3, building1, building2});
        if (seqeunce == 5)
          solution.insert({building2, building3, building1});
        if (seqeunce == 6)
          solution.insert({building3, building2, building1});
      }
    }
  }
}

int main()
{
  ll n;
  cout << "Enter the number of Time Units: ";
  cin >> n;

  set<vector<ll>> solution;
  ll maxEarnings = 0;
  pair<ll, ll> theatre = {5, 1500}, pub = {4, 1000}, commPark = {10, 3000};

  getAllPossibleSolutions(n, maxEarnings, solution, {theatre, pub, commPark}, 1);
  getAllPossibleSolutions(n, maxEarnings, solution, {theatre, commPark, pub}, 2);
  getAllPossibleSolutions(n, maxEarnings, solution, {pub, theatre, commPark}, 3);
  getAllPossibleSolutions(n, maxEarnings, solution, {pub, commPark, theatre}, 4);
  getAllPossibleSolutions(n, maxEarnings, solution, {commPark, theatre, pub}, 5);
  getAllPossibleSolutions(n, maxEarnings, solution, {commPark, pub, theatre}, 6);

  cout << "Earnings : " << maxEarnings << endl;
  cout << "Solutions : " << endl;

  for (auto sol:solution)
  {
    cout << "T: " << sol[0] << " P: " << sol[1] << " C: " << sol[2] << endl;
  }
  return 0;
}