#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
	int answer = 0;
	queue<pair<int, int>> que;//temp
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); i++) {
		que.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}
	//따로 놓고 시작한다.
	while (!que.empty())
	{
		int i = que.front().first;
		int priority = que.front().second;
		que.pop();
		//이게 굉장히 신기하다.
		//que가 이상의 우선순위 일떄 인쇄를 하기 위해 뺀다. 만약 미만이라면 다시 맨끝으로 넣는다. (큐 구조)
		if (priority == pq.top()) { 
			pq.pop();
			answer++;
			if (location == i) break;
			//else { //이럴때는 같이 뺀다. 
			//	que.push(make_pair(i, priority));
			//}
		}
		else { //인쇄를 안한다. 근데 이게 우선순위 큐에서는 빠지지 않는다. 그냥 큐에서만 빠져서 뒤로간다.
			que.push(make_pair(i, priority));
			/*answer++;*/ //인쇄를 안하고 큐끝에로 다시 넣는다.
		}
		return answer;
	}
}