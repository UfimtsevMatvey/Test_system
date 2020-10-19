#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
unsigned int countBits(unsigned long long n);
std::string DNAStrand(const std::string& dna);
std::string reverse_words(std::string str);
std::vector<int> convert(string n);
std::string duplicate_encoder(const std::string& word);
long sumTwoSmallestNumbers(std::vector<int> numbers);
bool comp(std::vector<int>&a, std::vector<int>&b);
int digPow(int n, int p);

int main()
{
	unsigned long long n = 123124;
	countBits(n);

	string S = "GCAAA";
	DNAStrand(S);
	S = "GCAAA oweofi oefijsfds";
	//cout << reverse_words(S);
	//vector<int> result;
	//result = convert(string("1001"));
	//duplicate_encoder(string("CodeWarrior"));

	//digPow(89, 1);

	std::vector<int> a = { 121, 144, 19, 161, 19, 144, 19, 11 };
	std::vector<int> b = { 14641, 20736, 361, 25921, 361, 20736, 361, 121 };
	a = { 121, 144, 19, 161, 19, 144, 19, 11 };
	b = { 14641, 20736, 361, 25921, 361, 20736, 362, 121 };
	comp(a, b);
	return 0;
}

unsigned int countBits(unsigned long long n) {
	//your code here
	int r = 0;
	unsigned long long mask = 1;
	int N = sizeof(unsigned long long) * 8;
	for (int i = 0; i < N; i++)
	{
		if ((mask & n) != 0) r++;
		mask << 1;
	}
	return r;
}

std::string DNAStrand(const std::string& dna)
{
	//your code here
	std::string res = "";
	for (int i = 0; dna[i] != 0; i++)
	{
		if (dna[i] == 'A') res += 'T';
		if (dna[i] == 'T') res += 'A';
		if (dna[i] == 'C') res += 'G';
		if (dna[i] == 'G') res += 'C';
	}
	return res;
}
/*Function not insert space between rewersed words*/
std::string reverse_words(std::string str)
{
	std::string::iterator ptr_space_c;
	std::string::iterator ptr_space_n;
	std::string::iterator riter;
	std::string::iterator iter;
	std::string res = "";
	ptr_space_c = str.begin();
	ptr_space_n = find(str.begin(), str.end(), ' ');
	while (ptr_space_c != str.end())
	{
		//ptr_space_c = find(++ptr_space_c,str.end(),' ');
		for (riter = ptr_space_c; riter != ptr_space_n + 1; riter++)
		{
			res.insert(res.begin(), *riter);
		}
		ptr_space_c = ++ptr_space_n;
		ptr_space_n = find(ptr_space_c, str.end(), ' ');
	}
	return res;
}
//Convert decimal number to i-number: A_n*i^n + A_(n-1)*i^(n-1) + ..... + A_0*i^0 = a + i*b
vector<int> convert(string n)
{
	vector<int> cV = { 0,0 };
	int sign = 1;
	int rep = 0;
	int imp = 0;
	int temp = 0;
	int r = 0;
	int slen = n.length();
	r = slen % 4;
	if (r != 0)
	{
		for (int i = 0; i < 4 - r; i++)
			n.push_back('0');
		slen = slen + 4 - r;
	}
	for (int i = 0; i < slen/4; i++)
	{
		rep += (n[slen - 1 - 4 * i] - '0') - (n[slen - 1 - 4*i - 2] - '0');
		imp += (n[slen - 1 - 4 * i - 1] - '0') - (n[slen - 1 - 4*i - 3] - '0');
	}
	r = (4 - r) & 3;
	temp = rep;
	sign = (r % 2 == 0) ? 1 : -1;
	if (r != 0) {
		if (r == 2) {
			rep = -rep;
			imp = -imp;
		}
		else {
			if (r == 1) {
				rep = -imp;
				imp = temp;
			}
			else
			{
				rep = imp;
				imp = -temp;
			}
		}
	}
	cV[0] = rep * sign;
	cV[1] = imp * sign;
	return cV;
}
/*std::string duplicate_encoder(const std::string& word)
{
	char ch = '0';
	int length = word.length();
	string res;
	map<char, int, less<char>> mapDupl;
	//filling in map duplicates
	for (int i = 0; i < length; i++)
	{
		ch = word[i];
		if (ch >= 'A' && ch <= 'Z') ch = ch + ('z' - 'Z');
		mapDupl[ch] += 1;
	}
	//filling resulting string
	for (int i = 0; i < length; i++)
	{ 
		ch = word[i];
		if (mapDupl[(ch >= 'A' && ch <= 'Z') ? ch + ('z' - 'Z') : ch] == 1)//symbol is duplicate
			res.push_back('(');
		else
			res.push_back(')');// symbol is not duplicate 
	}
	return res;
}*/
std::string duplicate_encoder(const std::string& word)
{
	string res;
	map<char, int, less<char>> mapDupl;
	//filling in map duplicates
	for (auto ch : word)
		mapDupl[tolower(ch)] += 1;
	//filling resulting string
	for (auto ch : word) 
		res += (mapDupl[tolower(ch)] == 1) ? '(' : ')';
	return res;
}
int digPow(int n, int p)
{
	int res;
	int tres;
	int nt;
	int j;
	int k;
	int div_d;
	vector<int> Num;
	vector<int>::reverse_iterator riNum;
	res = 0;
	tres = 1;
	j = 0;
	nt = n;
	while (nt != 0)
	{
		div_d = nt;
		nt = nt / 10;
		div_d = div_d - nt * 10;
		Num.push_back(div_d);
	}
	for (riNum = Num.rbegin(); riNum != Num.rend(); riNum++)
	{
		k = *riNum;
		for (int i = 0; i < p + j; i++)
			tres *= k;
		res += tres;
		tres = 1;
		j++;
	}
	k = res / n;
	if (res%n == 0) return k;
	else return -1;
}

long sumTwoSmallestNumbers(std::vector<int> numbers)
{
	vector<int>::iterator itr;
	long min_c = numeric_limits<long>::max();
	long min_p = min_c;
	int cur;
	for (itr = numbers.begin(); itr != numbers.end(); itr++) 
	{
		cur = *itr;
		if (cur < min_c) 
		{
			min_p = min_c;
			min_c = cur;
		}
		else if (cur < min_p)	
			min_p = cur;
	}
	return min_c + min_p;
}

bool comp(std::vector<int>&a, std::vector<int>&b) {
	bool res = true;
	int al = a.size();
	int bl = b.size();
	for (int i = 0; i < al; i++)
		a[i] = a[i] * a[i];
	sort(b.begin(), b.end());
	sort(a.begin(), a.end());
	if (al == bl)
		for (int j = 0; j < al; j++) 
			res = res && (a[j] == b[j]);
	else res = false;
	return res;
}