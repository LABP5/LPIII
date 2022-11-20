// C++ program to solve fractional Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

// Structure for an item which stores weight and
// corresponding value of Item
struct Item {
	int value, weight;

	// Constructor
	Item(int value, int weight)
	{
		this->value = value;
		this->weight = weight;
	}
};

// Comparison function to sort Item
// according to val/weight ratio
bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	// Sorting Item on basis of ratio
	sort(arr, arr + N, cmp);

	double finalvalue = 0.0;

	// Looping through all items
	for (int i = 0; i < N; i++) {
		
		// If adding Item won't overflow,
		// add it completely
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].value;
		}

		// If we can't add current Item,
		// add fractional part of it
		else {
			finalvalue
				+= arr[i].value
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}

	// Returning final value
	return finalvalue;
}

// Driver code
int main()
{
	int W = 50;
	Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };

	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << fractionalKnapsack(W, arr, N);
	return 0;
}




/*# Structure for an item which stores weight and
# corresponding value of Item
class Item:
	def __init__(self, value, weight):
		self.value = value
		self.weight = weight

# Main greedy function to solve problem
def fractionalKnapsack(W, arr):

	# Sorting Item on basis of ratio
	arr.sort(key=lambda x: (x.value/x.weight), reverse=True)

	# Result(value in Knapsack)
	finalvalue = 0.0

	# Looping through all Items
	for item in arr:

		# If adding Item won't overflow,
		# add it completely
		if item.weight <= W:
			W -= item.weight
			finalvalue += item.value

		# If we can't add current Item,
		# add fractional part of it
		else:
			finalvalue += item.value * W / item.weight
			break
	
	# Returning final value
	return finalvalue


# Driver Code
if __name__ == "__main__":

	W = 50
	arr = [Item(60, 10), Item(100, 20), Item(120, 30)]

	# Function call
	max_val = fractionalKnapsack(W, arr)
	print(max_val)
*/ 
