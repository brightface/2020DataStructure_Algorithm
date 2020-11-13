/*
	Greedy(탐욕 알고리즘)
	어떻게 하는게 좋을까.
	신호등 교통상황 한다음에 계산을 한다음에 그다음에 출발.
	아침에 어찌저찌하면서 출발을 하는거야.

	지금 상황에 도착하는 상황.
	출발은 한다음에 갈림길에 마다 
	생각하는시간을 줄일수가 있다. 출발하기 전에 다 계산하는것 다 동적계획법
	a* 알고리즘 = 탐욕알고리즘 : 가면서 짧은 알고리즘
	계산하는것 자체가 오래걸릴수 있고. 

	탐욕 알고리즘을 사용하는 경우
		1. 탐욕 알고리즘으로 최적의 해답을 찾아도 되는 경우.
			최적의 케이스가 아닐수도 있잖아. 그렇게 해도 상관은 없는 게 있어. 예를들어 길찾는 알고리즘. 
			학문적으로 알고리즘 분야에서 인간이 아직 풀지 못한 문제를 풀때 정확한 해답을 찾기 보다는 근사해를 찾는 경우
			근사값을 찾을려고 하는거야. 
			그런것을 찾을떄 탐욕알고리즘을 찾을려고 하는거야.

			탐욕을 할때 만족해야하는 조건
			1. 탐욕스러운 선택 조건(greedy choice property)
			2. 최적 부분 구조조건(optimal substructure)
			의 조건들이 성립되어야 잘 작동한다.

			탐욕스러운 선택조건
			앞 이전에 선택한 갈림길이 현재 상황에 영향을 주지 않는 조건.(주면 안돼)

			최적 부분 구조 조건
			문제에 대한 최종 해결방법이 부분 문제에서도 또한 최적 문제 해결방법이라는 조건

			우리가 한 최적해에서도 벗어날수 있다.
			탐욕알고리즘의 가장 큰장점. 현재 상황에서 가장 좋은 선택을 하면 돼.
			아까도 이야기 했다시피 최선의 해결책이 되지 않는다.
			아쪳든 빠르게가 중요한거잖아.

*/

#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int p[1005];
int result = 0;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			result += p[j];

	printf("%d", result);
	return 0;
}

/*
탐욕 알고리즘을 쓰는 문제는 뭔가를 가장 빨리~, 가장 큰~  이라는 단어가 많이 들어간다.
정렬을 잘 알아두면 문제를 푸는데 도움이 된다.
A*도 정렬을 시켜가지고 하는게 빠르겠지.여러가지 길이 있을거 아냐.
문제를 보고 완전탐색으로 풀기에는 경우의 수가 너무 큰데,
뒷일을 생각하지 않고 각 단계에서 최선을 택해도 정답을 구할 수 있을 것 같을때 탐욕알고리즘을 사용하면 된다.
*/