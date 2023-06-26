#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
	int weight, usefulness;
};

bool cmp(Item a, Item b) {
	return (double)a.usefulness/a.weight > (double)b.usefulness/b.weight;
}

int main() {
	int n;
	cin >> n;

	vector<Item> items(n);
	for (int i = 0; i < n; i++) {
		cin >> items[i].weight >> items[i].usefulness;
	}

	sort(items.begin(), items.end(), cmp);

	int max_usefulness = 0;
	int current_weight = 0;
	for (int i = 0; i < n; i++) {
		if (current_weight + items[i].weight <= INT_MAX) { 
			current_weight += items[i].weight;
			max_usefulness += items[i].usefulness;
		} else {
			int remaining_weight = INT_MAX - current_weight;
			max_usefulness += (double)remaining_weight/items[i].weight * items[i].usefulness;
			break;
		}
	}

	cout << max_usefulness << endl;

	return 0;
}
