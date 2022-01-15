pair<int, int> repeatingAndMissing(vector<int> arr) {
	int repeating = -1;
	for (int i = 0; i < arr.size(); ++i) {
		if(arr[abs(arr[i]) - 1] < 0)
			repeating = abs(arr[i]);

		arr[abs(arr[i]) - 1] *= -1;
	}

	for (int i = 0; i < arr.size(); ++i)
		if (arr[i] > 0 && i + 1 != repeating)
			return {repeating, i + 1};

	return {-1, -1};
}