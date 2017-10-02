#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin,fout,fstd;
ofstream fscore,freport;

/*
 * argv[1]：输入文件
 *
 * argv[2]：选手输出文件
 *
 * argv[3]：标准输出文件
 *
 * argv[4]：单个测试点分值
 *
 * argv[5]：输出最终得分的文件
 *
 * argv[6]：输出错误报告的文件
 *
 */
double Judge() {
	double score = 0.0;
	int stdn, outn;
	fstd >> stdn;
	fout >> outn;
	if(stdn != outn) return score;
	else score += 0.5;
	vector<int> require, fact;
	int n;
	fin >> n;
	for(int i = 1; i <= n; i++) {
		int v;
		fin >> v;
		require.push_back(v);
	}
	for(int i = 1; i <= outn; i++) {
		string s;
		fout >> s;
		if(s.size() != outn) return score;
		int cnt = 0;
		for(int j = 0; j < s.size(); j++) {
			if(j + 1 == i) {
				if(s[j] == '1') return score;
			} else {
				cnt += s[j] == '1';
			}
		}
		fact.push_back(cnt);
	}
	sort(require.begin(), require.end());
	require.erase(unique(require.begin(),require.end()),require.end());
	sort(fact.begin(), fact.end());
	fact.erase(unique(fact.begin(),fact.end()), fact.end());
	if(fact == require) {
		score += 0.5;
	} 
	return score;
}
int main(int argc,char *argv[]){
	fin.open(argv[1]);
	fout.open(argv[2]);
	fstd.open(argv[3]);
	fscore.open(argv[5]);
	freport.open(argv[6]);

	int score=atoi(argv[4]);
	fscore<<score*Judge()<<endl;

	fin.close();
	fout.close();
	fstd.close();
	fscore.close();
	freport.close();
	return 0;
}

