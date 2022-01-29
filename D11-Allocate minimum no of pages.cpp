
/*
You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. 
In each permutation, one of the M students will be allocated the maximum number of pages. 
Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages 
allocated to a student is minimum of those in all the other permutations and print this minimum value. 
Each book will be allocated to exactly one student. Each student has to be allocated at least one book.
Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order.
*/

/*
Time: O(n * lg n)
Space: O(1)
Binary Search.
*/

bool isPossible(int arr[], int n, int pages, int students) {
	int count = 1, allocated = 0;

	for (int i = 0; i < n; ++i) {
		if (allocated + arr[i] > pages) {
			++count;
			allocated = arr[i];

			if (arr[i] > pages)
				return false;
		}
		else
			allocated += arr[i];
	}

	if (count > students)
		return false;

	return true;
}

int findPages(int arr[], int n, int m) {
	if (m > n)
		return -1;

	int lo = arr[0], hi = 0;
	for (int i = 0; i < n; ++i)
		hi += arr[i];

	int res = -1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;

		if (isPossible(arr, n, mid, m)) {
			res = mid;
			hi = mid - 1;
		}
		else
			lo = mid + 1;
	}

	return res;
}