
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {

	vector<vector<int>> result; //vector of vectors (main object)

	vector<vector<int>>::iterator it;
	vector<vector<int>>::iterator it2; //iterators to insert like pythons ways.extend
	vector<vector<int>>::iterator it3; //source: http://www.cplusplus.com/reference/vector/vector/insert/

	if(num_stairs == 0){
		result.push_back(vector<int>()); //adds on an empty vector like [] in python
	}
	else{
		for(int i = 1; i <= 3; i++){ // for i in range(1,4) - 1,2 or 3 steps at a time
			if(num_stairs < i){
				break;
			}
			else{
				vector<vector<int>>temp = get_ways(num_stairs - i);

				for(string::size_type j = 0; j < temp.size(); j ++){ // for j in range(len(temp))
					temp.at(j).push_back(i); //temp[j] = [i] + result[j]
				}

				it = result.end();
				it2 = temp.begin();
				it3 = temp.end();
				result.insert(it, it2, it3); //ways.extend(temp).  Source: https://stackoverflow.com/questions/313432/c-extend-a-vector-with-another-vector
			}
		}
	}
	return result;
}

void display_ways(const vector< vector<int> > &ways) {

	//just like in sieve, I used a while loop and division to find the maximum amount of spaces used for listing the sets of ways to walk up.
	int x = 1;
	int num = ways.size();
	while(num > 9){
		num = num/10;
		x+=1;
	}
	for(string::size_type i = 0; i < ways.size(); i++){ //iterates through the vector of vector
		cout << setw(x)<< i+1 <<". [";
		for(string::size_type j = ways[i].size() - 1; j > 0; --j){ //iterates over the objects in index i of ways. Iterating from 0 up to ways[i].size() does not work. ways[i].size() is amount of objects in the ith index of ways.
			cout << ways[i][j] << ", ";
		}
			cout << ways[i][0] << "]" <<endl; //case for last number
	}
}

int main(int argc, char * const argv[]) {

	istringstream inp;
	int x;

	if(argc != 2){ //if there aren't exactly 2 arguments (stairclimber and the amount of stairs)
		cerr << "Usage: " <<argv[0] <<" <number of stairs>" <<endl;
		return 1;
	}

	inp.str(argv[1]);

	if(!(inp >> x) || x<=0){ //if the parameter is not a number or if it is a number that's less than 0
		cerr << "Error: Number of stairs must be a positive integer." <<endl;
		return 1;
	}
	else{
		inp.str(argv[1]);
		inp >> x;

		vector<vector<int>> gwx = get_ways(x);

	    //used for formatting, way vs ways
		if(gwx.size() > 1){
			cout << gwx.size() <<" ways to climb " << x <<" stairs." << endl;
		}
		else{
			cout << "1 way to climb 1 stair." <<endl;
		}

		display_ways(gwx);
		return 0;
	}
}
