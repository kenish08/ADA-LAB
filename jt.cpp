include <iostream>
#include <vector>
//DONT 
//FORK
//:/
using namespace std;
 
vector<int> till(int n, int offset = 0)
{
	vector<int> baka(n);
	for (int i= 0; i < n; ++i)
		baka[i] = i + offset;
	return baka;
}
 
struct jt
{
	vector<int> val;
	vector<int> pos;	
	vector<bool> dir; //its a diff "dir" ->direction
	int sign;
 
	jt(int n) : val(till(n, 1)), pos(till(n + 1, -1)), dir(n + 1, false), sign(1) {} //constructor fo the structure
 
	int LargestMobile() const //so that it doesnt erase the prev values 	
	{
		for (int r = val.size(); r > 0; --r)
		{
			const int loc = pos[r] + (dir[r] ? 1 : -1);
			if (loc >= 0 && loc < val.size() && val[loc] < r)
				return r;
		}
		return 0;
	}
 
	bool comp() const { return LargestMobile() == 0; } //checking is the limit has been reached
 
	void operator++() //operator modifiction....the way ++ works in the incrementation	
	{
		const int r = LargestMobile();
		const int rloc = pos[r];
		const int lloc = rloc + (dir[r] ? 1 : -1);
		const int l = val[lloc];
		swap(val[lloc], val[rloc]);// swapping ....moving the numbers around
		swap(pos[l], pos[r]);
		sign = -sign;// change directions...the direction of the largest number
		for (auto pd = dir.begin() + r + 1; pd != dir.end(); ++pd)
			*pd = !*pd;
	}
};
 
int main(void)
{
	auto n=0;
	cout<<"Enter the length of the permutation\n";
	cin>>n;
	jt state(n);
	do
	{
		for (auto v : state.val)
			cout << v << " ";
		cout << "\n";
		++state;
	} while (!state.comp());
}
