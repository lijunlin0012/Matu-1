#include"CSet.h"
#include<algorithm>
#include<set>
//#include<cassert>

using namespace std;

bool Set::operator <=(const Set &s)const
{

	if (n > s.n)
		return false;
	sort(pS + 1, pS + n + 1);
	sort(s.pS + 1, s.pS + n + 1);
	for (int i = 1, j = 1; i <= n; j++)
	{
		if (pS[i] == s.pS[i])
			i++;
		else if (pS[i] < s.pS[i])
			return false;
		else if (j > s.n)
			return false;
		else;
	}
	return true;
};//this <= s判断当前集合是否包于集合s

bool Set::operator ==(const Set &s)const //判断集合是否相等
{
	if (n != s.n)
		return false;
	sort(pS + 1, pS + n + 1);
	sort(s.pS + 1, s.pS + n + 1);
	for (int i = 1; i <= n; i++)
		if (pS[i] != s.pS[i])
			return false;
	return true;
}

Set & Set::operator +=(int e)// 向集合中增减元素e
{
	int * newpS = new int[n + 2];
	for (int i = 1; i <= n; i++)
		newpS[i] = pS[i];
	newpS[++n] = e;
	delete[]pS;
	pS = newpS;
	return *this;
}
Set & Set::operator -=(int e)    //删除集合中的元素e
{
	bool found = false;
	for (int i = 1; i <= n; i++)
	{
		if (found)
			pS[n - 1] = pS[n];
		else if (pS[i] == e)
			found = true;
	}
	n--;
	return *this;
}

Set Set::operator |(const Set &s)const  //集合并
{
	set<int> stl_set;
	for (int i = 1; i <= n; i++)
		stl_set.insert(pS[i]);
	for (int i = 1; i <= s.n; i++)
		stl_set.insert(s.pS[i]);
	Set ans;
	ans.n = stl_set.size();
	ans.pS = new int[ans.n + 1];
	int i = 1;
	for (set<int>::iterator iter = stl_set.begin(); iter != stl_set.end(); iter++)
		ans.pS[i++] = *iter;
	return ans;
}

Set Set::operator &(const Set &s)const//集合交
{
	set<int> stl_set[2];
	for (int i = 1; i <= n; i++)
		stl_set[0].insert(pS[i]);
	for (int i = 1; i <= s.n; i++)
		if (stl_set[0].find(s.pS[i]) != stl_set[0].end())
			stl_set[1].insert(s.pS[i]);
	Set ans;
	ans.n = stl_set[1].size();
	ans.pS = new int[ans.n + 1];
	int i = 1;
	for (set<int>::iterator iter = stl_set[1].begin(); iter != stl_set[1].end(); iter++)
		ans.pS[i++] = *iter;
	return ans;
}

Set Set::operator -(const Set &s)const //集合差
{
	set<int> stl_set;
	for (int i = 1; i <= n; i++)
		stl_set.insert(pS[i]);
	for (int i = 1; i <= s.n; i++)
		stl_set.erase(s.pS[i]);
	Set ans;
	ans.n = stl_set.size();
	ans.pS = new int[ans.n + 1];
	int i = 1;
	for (set<int>::iterator iter = stl_set.begin(); iter != stl_set.end(); iter++)
		ans.pS[i++] = *iter;
	return ans;
}

/*
int main()
{
	//Set s;
	//s += 1;
	//s.ShowElement();//{1}

	//s += 2;
	//s.ShowElement();//{1,2}
	//s -= 1;
	//s.ShowElement();//{2}

	//Set s1, s2, s3;
	//s1 += 1; s2 += 1; s2 += 3; s3 += 2;
	//assert(s1 <= s2);//true
	//assert(!(s3 <= s2));//false
	
	//Set s1, s2;
	//s1 += 1; s1 += 3; s2 += 2; s2 += 1;
	//(s1 - s2).ShowElement();//{1,2}
}
*/