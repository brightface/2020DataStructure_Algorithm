/*

maxRow = 0
def dfs(triangle,row,col,arr):
	if row>=maxRow:
		return
	else:
		arr[(row+1)*2+col] += arr[row][col]
		arr[(row+1)*2+col+1] += arr[row][col]
		dfs(triangle,row+1,col,arr)


def solution(triangle):
	answer = 0
	maxRow = len(triangle)
	arr = [0]*(maxRow*(maxRow+1)//2)
	for i in range(maxRow):
		dfs(triangle,0,0,arr)
	print(arr)

	#print(size)

	return answer
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
int maxRow;
int arr[
int solution(vector<vector<int>> triangle) {
	int answer = 0;
	maxRow = triangle.size();
	cout << maxRow;
	return answer;
}