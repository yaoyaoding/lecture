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
const int N = 33;
int board[N][N];

double Judge() {
	double score = 0.0;
	int n, m, q, type;
	fin >> n >> m >> q >> type;
	for(int i = 1; i <= q; i++) {
		int x, y;
		fin >> x >> y;
		board[x][y] = 1;
	}
	if(type == 0) {
		int usrans = -1, stdans = -1;
		fstd >> stdans;
		fout >> usrans;
		if(stdans != usrans) {
			score = 0.0;
			freport << "Wrong Answer, Your answer is " << usrans << " and std answer is " << stdans << endl;
		} else {
			score = 1.0;
			freport << "Accepted." << endl;
		}
	} else {
		int usrans = -1, stdans = -1;
		fstd >> stdans;
		fout >> usrans;
		if(stdans != usrans) {
			score = 0.0;
			freport << "Wrong Answer, Your answer is " << usrans << " and std answer is " << stdans << endl;
		} else {
			int succ = 0;
			for(int i = 1; i <= stdans; i++) {
				int x, y;
				fout >> x >> y;
				if(x < 1 || x > n || y < 1 || y > m) {
					freport << "Wrong Answer, you place a horse on an invalid position" << endl;
					break;
				} else if(board[x][y] == 1) {
					freport << "Wrong Answer, you place a horse on a bad block" << endl;
					break;
				} else if(board[x][y] == 2) {
					freport << "Wrong Answer, you place two horses into one block" << endl;
					break;
				} else {
					board[x][y] = 2;
					succ++;
				}
			}
			if(succ == stdans) {
				score = 1.0;
				for(int x = 1; x <= n; x++)
					for(int y = 1; y <= m; y++) {
						if(board[x][y] != 2) continue;
						int dx[] = { -1, -1, -2, -2, 1, 1, 2, 2 };
						int dy[] = { -2,  2, -1, 1, -2, 2,-1, 1 };
						for(int d = 0; d < 8; d++) {
							int xx = x + dx[d];
							int yy = y + dy[d];
							if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
							if(board[xx][yy] != 2) continue;
							freport << "Wrong Answer, your horse can fight each other." << endl;
							freport << x << " " << y << endl;
							freport << xx << " " << yy << endl;
							score = 0.0;
							goto END;
						}
					}
END:;
				if(score > 0.5) {
					freport << "Accepted." << endl;
				} 
			} else {
				score = 0.0;
			}
		}
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
	double got = Judge();
	fscore<<score*got<<endl;
	cout << score * got << endl;

	fin.close();
	fout.close();
	fstd.close();
	fscore.close();
	freport.close();
	return 0;
}

