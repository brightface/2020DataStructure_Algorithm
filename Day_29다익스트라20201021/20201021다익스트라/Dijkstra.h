#pragma once

/*
±æÃ£´Â ¾Ë°í¸®Áò

´ÙÀÍ½ºÆ®¶ó ¾Ë°í¸®Áò

À½ÀÇ °¡ÁßÄ¡°¡ ¾ø´Â ±×·¡ÇÁ¿¡¼­ ÇÑ ³ëµå¿¡¼­ ´Ù¸¥ ¸ğµç ³ëµå±îÁöÀÇ ­C³ª°Å¸®¸¦ ±¸ÇÏ´Â ¾Ë°í¸®Áò
(Çö½Ç¼¼°è)

º§¸¸ Æ÷µå ¾Ë°í¸®Áò <- À½ÀÇ °¡ÁßÄ¡°¡ ÀÖ´Â ±×·¡ÇÁ¿¡¼­ ÃÖ´Ü°æ·Î¸¦ Ã£´Â ¾Ë°í¸®Áò
Çö¾÷¿¡¼­ ¾²´Â  A* ¾´´Ù. ±Ùµ¥ ³×ºñ°ÔÀÌ¼Ç ¸Ş½Ã ¾´´Ù.
Çì´õµµ ÀÖ´Ù. ³×ºñ°ÔÀÌ¼Ç ¸Ş½Ã
 ½º½º·Î °øºÎ¸¦ ÇØº¸°í 
 ±æÃ£±â ¾Ë°í¸®ÁòÀÇ Å¬·¡½Ä

 ±×·¡ÇÁÀÌ·Ğ¿¡¼­ Á¤Á¡³¢¸®ÀÇ ÃÖ´Ü°æ·Î¸¦ ±¸ÇÏ´Â°Í.
 ±×·¡ÇÁ¿¡¼­ Á¤Á¡³¢¸®ÀÇ ÃÖ´Ü °æ·Î¸¦ ±¸ÇÏ´Â ¹®Á¦ÀÇ Á¾·ù
 1. ÇÏ³ªÀÇ Á¤Á¡¿¡¼­ ´Ù¸¥ ÇÏ³ªÀÇ Á¤Á¡±îÁöÀÇ ÃÖ´Ü°æ·Î¸¦ ±¸ÇÏ´Â ¹®Á¦.(single source and single destination shortest path problem) : ±íÀÌ¿ì¼±
 2. ÇÏ³ªÀÇ Á¤Á¡¿¡¼­ ´Ù¸¥ ¸ğµç Á¤Á¡±îÁöÀÇ ÃÖ´Ü°æ·Î¸¦ ±¸ÇÏ´Â ¹®Á¦. (single sorce shortest path problem) : ³ĞÀÌ ¿ì¼± Å½»ö <´ÙÀÍ½ºÆ®¶ó> : 
 3. A* °Å±â¿¡¼­ ´ÙÀ½±îÁö °¡´Â °Å¸®¸¦ °è»êÇÑ´Ù.
 3. ÇÏ³ªÀÇ ¸ñÀûÁö·Î °¡´Â ¸ğµç ÃÖ´Ü °æ·Î¸¦ ±¸ÇÏ´Â ¹®Á¦(single destination path problem) : ±íÀÌ¿ì¼± È®Àå. ³×ÀÌ¹ö Áöµµ. ¸»ÀÌ µÇ´Â °æ·Î
 4. ¸ğµç ÃÖ´Ü°æ·Î¸¦ ±¸ÇÏ´Â ¹®Á¦. ¸ğµç ÄÉÀÌ½º¸¦ ´Ù °Ë»ç(All pairs shortest path problem)

 °æ·Î¸¦ Ã£´Â´Ù. ´ÙÀÍ½ºÆ®¶ó´Â ½ÃÀÛÁ¡ÀÌ ÀÖ´Ù.

 ´ÙÀÍ½ºÆ®¶ó ·ÎÁ÷
 Ã¹ Á¤Á¡À» ±âÁØÀ¸·Î ¿¬°áµÇ¾î ÀÖ´Â Á¤Á¡µéÀ» Ãß°¡ÇØ °¡¸ç ÃÖ´Ü°Å¸®¸¦ °»½ÅÇÏ´Â ¹æ½Ä.
 Á¤Á¡À» ¿¬°áÇÏ±â Àü±îÁö´Â ½ÃÀÛÁ¡À» Á¦¿ÜÇÑ Á¤Á¡(°Å±â±îÁö °¡´Âµ¥ µå´Â ºñ¿ë)µéÀº ¸ğµÎ ¹«ÇÑ´ë °ªÀ» °¡Áø´Ù.

 Á¤Á¡ A¿¡¼­ Á¤Á¡B·Î ÀÌ¾îÁö¸é, Á¤Á¡B°¡ °¡Áö´Â ÃÖ´Ü°Å¸®´Â ½ÃÀÛÁ¡À¸·Î ºÎÅÍ Á¤Á¡ A±îÁöÀÇ ÃÖ´Ü°Å¸® + Á¤Á¡A, Á¤Á¡B°£¼±ÀÇ °¡ÁßÄ¡¿Í, ±âÁ¸¿¡ °¡Áö°í ÀÖ´ø
 Á¤Á¡ BÀÇ ÃÖ´Ü°Å¸®Áß ÀÛÀº°ªÀÌ BÀÇ ÃÖ´Ü°Å¸®°¡ µÈ´Ù.
 B±îÁöÀÇ °ªÀÌ °è¼Ó °»½ÅÀÌµÈ´Ù.
*/

#include <vector>
using namespace std;

typedef pair<int, int> PII;


#define INF 1000000

class Dijkstra
{
public:
	//³ëµå °³¼ö
	Dijkstra(int nodeCount) : nodeCount(nodeCount)
	{
		ad.assign(nodeCount, vector<int>());
		selected.assign(nodeCount, false);
		dist.assign(nodeCount, INF);

	}

	void MakeEdge(int start, int weight) 
	{
		ad[start].push_back(weight);
	}
	//´ÙÀ½¿¡ ¹æ¹®ÇÒ ³ëµå¸¦ ¼±ÅÃÇÏ´Â°Å¾ß. ´Ü¼øÇÑ 2Â÷¿ø ¹è¿­Çü½ÄÀÌ±â ¶§¹®¿¡ ÀÎµ¦½º¹øÈ£ ³ëµå¹øÈ£°¡ ÀûÀº°ÍÀ» ¹İÈ¯À» ¹ŞÀ»°Å¾ß.
	//¿ì¼±¼øÀ§Å¥
	int GetSmallIndex()
	{
		int minDist = INF;
		int index = 0;
		for (int i = 0; i < nodeCount; i++) {
			if (dist[i] < minDist && selected[i] == false)
			{
				minDist = dist[i];
				index = i;
			}
		}
		return index;
	}
	void FindPath(int start)
	{
		for (int i = 0; i < nodeCount; i++)
		{
			dist[i] = ad[start][i];
		}
		selected[start] = true;
		for (int i = 0; i < nodeCount - 2; i++)
		{
			int current = GetSmallIndex();
			selected[current] = true;
			for (int j = 0; j < nodeCount; j++) {
				if (selected[j] == false)
				{
					if (dist[current] + ad[current][j] < dist[j]) 
					{
						//dist[j] = INT32_MAX
						//dist[current]
						//ad[current][j] = INT32_MAX 
						//ÀÎÆ® ¸Æ½º¸¦ ¾ÈÇÏ°í Àú°Å¸¦ ÇÑ°Å¾ß.
						dist[j] = dist[current] + ad[current][j];

					}
				}
			}
		}
	}


private:
	vector<vector<int>> ad; //°£¼±ÀÇ Á¤º¸¸¦ °¡Áö°í ÀÖ´Â ¹è¿­
	vector<bool> selected; //¹æ¹®Çß´ø ³ëµåÀÎÁö ¾Æ´ÑÁö
	vector<int> dist; //¿·¿¡ Àû¾îµÎ¾ú´ø ¹è¿­
	int nodeCount = 0;
};

#include <queue>
typedef pair<int, int> PII;
class Dijkstra2
{
public:
	Dijkstra2(int nodeCount) :nodeCount(nodeCount)
	{
		ad.assign(nodeCount, vector<PII>()); //°ø°£¸¸À» ÇÒ´çÇÑ´Ù. ¾ó¸¶¸¸Å­, 
		dist.assign(nodeCount, INF);
	}
	void MakeEdge(int N, int next, int weight)
	{
		ad[N].push_back(make_pair(next , weight));
	}
	//°¡ÁßÄ¡¸¦ ½á¼­ Á¤·ÄÇÏ·Á°í 
	//ÀÎÁ¢¸®½ºÆ® A* ºÙ¾îÀÖ´Â ¾Öµé¸¸ °è»êÇÑ´Ù.
	//¾ÈºÙ¾îÀÖ´Â¾Öµé °è»êÇØºÁ¾ß ÀÇ¹Ì°¡ ¾ø´Ù.

	void FindPath(int start)
	{
		dist[start] = 0;
		pq.push(PII(0, start));
		//°¡Àå À§¿¡ÀÖ´Â°Í¸¸ »©¸é µÇ´Ï±î. Å½»ö¼Óµµ°¡ ºü¸£´Ù. 
		//A* ¾Ë°í¸®Áòµµ ±æÃ£±â ¾Ë°í¸®Áò Àß ¾Ë¾Æ¾ß°Ú´Ù.
		while (pq.empty() == false)
		{
			int current = pq.top().second;
			int distance = pq.top().first;
			pq.pop();

			if (dist[current] < distance) continue;

			for (int i = 0; i < nodeCount; i++)
			{
				int next = ad[current][i].second;
				if (next == current) continue; // ÇöÀç ³ëµå¸é ³Ñ¾î°£´Ù.
					int nextDist = distance + ad[current][i].first;
					if (nextDist < dist[next])
					{
						dist[next] = nextDist;
						pq.push(PII(nextDist, next));
						parent.push_back(current);
					}
			}
		}
	}
private:
	vector<vector<PII>> ad;
	priority_queue<PII, vector<PII>, greater<PII>> pq; //°£¼±Áß ºñ¿ëÀÌ °¡Àå ÀÛÀº°ÍÀ» Ã£±âÀ§ÇÑ ¿ì¼±¼øÀ§Å¥
	vector<int> dist;
	int nodeCount = 0;
	vector<int> parent; //Ãâ·ÂÀßÇØºÁ. ±×¸®°í ºñ¿ëµµ Ãâ·ÂÇØ!
};