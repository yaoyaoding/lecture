#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
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
	int n, m, q;
	fin >> n >> m >> q;
	while(q--) {
		double qstd, qout = 1e10;
		fstd >> qstd;
		fout >> qout;
		if(fabs(qstd-qout) / max(1.0, fabs(qstd)) > 1e-6) return 0.0;
	}
	return 1.0;
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

