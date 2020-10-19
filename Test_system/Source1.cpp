class DigPow
{
public:
	static int digPow(int n, int p);
};
int DigPow::digPow(int n, int p)
{
	int res;
	int tres;
	int nt;
	int j;
	int k;
	int div_d;
	res = 0;
	tres = 0;
	j = 0;
	nt = n;
	while (1)
	{
		div_d = nt;
		nt = nt / 10;
		div_d = div_d - nt * 10;
		for (int i = 0; i < p + j; i++)
			tres *= div_d;
		res += tres;
		tres = 1;
		j++;	
	}
	k = res / n;
	if (res%n == 0) return k;
	else return -1;
}