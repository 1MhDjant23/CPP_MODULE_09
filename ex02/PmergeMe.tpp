
template <typename LIST, typename PAIR>
void	PmergeMe::pairSort(LIST& list, PAIR& pair, TimeTracker& chrono) {
	size_t	i = 0;
	if (list.size() % 2 != 0)
		_unpair = list[list.size() - 1];
	chrono.start();
	while (i < list.size() - 1) {
		pair.push_back(std::make_pair(list[i], list[i + 1]));
		i += 2;
	}
	list.clear();
	for (size_t i = 0; i < pair.size(); i++) {
		if (pair[i].first > pair[i].second) {
			int	tmp = pair[i].first;
			pair[i].first = pair[i].second;
			pair[i].second = tmp;
		}
	}
}

template <typename CHAIN, typename PAIR>
void	PmergeMe::setMainChain(CHAIN& mainChain, PAIR& pair) {
	for (size_t i = 0; i < pair.size(); i++)
		mainChain.push_back(pair[i].second);

	//sort mainChain using mergeInserionSort algorithm
	PmergeMe::mergeInserionSort(mainChain, 0, mainChain.size() - 1);
}

template <typename T>
void	PmergeMe::insertionSort(T& arr, int start, size_t end) {
	for (size_t i = start + 1; i <= end; i++)
	{
		int	key = arr[i];
		int	j = i - 1;
		while (j >= start && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

template <typename T>
void	PmergeMe::mergeInserionSort(T& arr, size_t start, size_t end) {
	if (end - start + 1 <= PmergeMe::seuil) {
		PmergeMe::insertionSort(arr, start, end);
		return ;
	}
	size_t		midll = start + (end - start) / 2;
	mergeInserionSort(arr, start, midll);
	mergeInserionSort(arr, midll + 1, end);
	T	tmp(end - start + 1);
	size_t	i = start;
	size_t	j = midll + 1;
	size_t	k = 0;
	while (i <= midll && j <= end)
		tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	while (i <= midll) tmp[k++] = arr[i++];
	while (j <= end) tmp[k++] = arr[j++];
	for (k = 0; k < tmp.size(); k++)
		arr[start + k] = tmp[k];
}

template <typename CHAIN, typename PAIR>
void	PmergeMe::insertSmallJacobsthal(CHAIN& mainChain, PAIR& _pair, TimeTracker& chrono) {
	const std::vector<size_t>	jacobIndex = PmergeMe::getJacobsthalOrder(_pair.size());
	typename CHAIN::iterator pos;
	for (size_t i = 0; i < jacobIndex.size(); i++)
	{
		int	small = _pair[jacobIndex[i]].first;
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), small);
		mainChain.insert(pos, small);
	}
	if (_unpair != -1)
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), _unpair);
		mainChain.insert(pos, _unpair);
	}
	chrono.stop();
	chrono.setElapsedTime();
}
