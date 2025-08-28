#include <iostream>
#include <vector>


int	main() {
	std::vector<std::pair<int, int> >	p1;
//	std::vector<std::pair<int, int> >	p2;

	p1.push_back(std::make_pair(1, 2));
	p1.push_back(std::make_pair(4, 2));
	p1.push_back(std::make_pair(3, 2));
	p1.push_back(std::make_pair(2, 2));
	p1.push_back(std::make_pair(5, 2));
	p1.push_back(std::make_pair(6, 2));
    for (int i = 0; i < p1.size(); i++)
    	std::cout << p1[i].first << " " << p1[i].second << std::endl;


	return 0;
}