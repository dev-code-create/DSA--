#include <bits/stdc++.h>
using namespace std;

struct Item
{
  int value, weight;
};

bool compare(Item a, Item b)
{
  double r1 = (double)a.value / a.weight;
  double r2 = (double)b.value / b.weight;
  return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> items)
{
  sort(items.begin(), items.end(), compare);
  double totalValue = 0.0;

  for (auto item : items)
  {
    if (W >= item.weight)
    {
      totalValue += item.value;
      W -= item.weight;
    }
    else
    {
      totalValue += item.value * ((double)W / item.weight);
      break;
    }
  }

  return totalValue;
}

int main()
{
  vector<Item> items = {{
                            60,
                            10,
                        },
                        {
                            100,
                            20,
                        },
                        {120, 30}};
  int capacity = 50;
  cout << "Maximum value in knapsack = " << fractionalKnapsack(capacity, items) << endl;
  return 0;
};