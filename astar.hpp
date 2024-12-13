#include<iostream>
#include<queue>
#include<math.h>
#include<functional>

int dx[] = { 0,1,0,-1 };

int dy[] = { 1,0,-1,0 };

class astar
{
public:
	astar(std::pair<int, int> _src, std::pair<int, int> _dst, std::function<int(std::pair<int, int>, std::pair<int, int>)> _huristicFunction): heuristicFunc(_huristicFunction)
	{
		src.SetNode(_src.first,_src.second);
		dst.SetNode(_dst.first, _dst.second);
	}

	int GetRoute(const std::vector<std::vector<int>>& grid, const std::vector<std::vector<double>>& cost)
	{
        int rows = grid.size();
        int cols = grid[0].size();

        // �����¿� Ž�� ����
        int dx[] = { 0, 0, -1, 1 };
        int dy[] = { -1, 1, 0, 0 };

        // �켱���� ť (f���� ���� ��尡 �켱)
        std::priority_queue<std::vector<double>> pq;

        // g���� �湮 ���θ� ����
        std::vector<std::vector<double>> g_cost(rows, std::vector<double>(cols, 1e9));
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

        // ���� ��� �ʱ�ȭ
        pq.push({ static_cast<double>(src.GetNode().first), static_cast<double>(src.GetNode().second), 0, 0 });
        g_cost[src.GetNode().first][src.GetNode().second] = 0;

        while (!pq.empty()) {
            std::vector<double> current = pq.top();
            pq.pop();

            int x = current[0];
            int y = current[1];

            // ��ǥ ������ ������ ���
            if (x == dst.GetNode().first && y == dst.GetNode().second) {
                return g_cost[x][y];
            }

            // �̹� �湮�� ���� ��ŵ
            if (visited[x][y]) continue;
            visited[x][y] = true;

            // ���� ��� Ž��
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // ��ȿ�� ��ġ���� Ȯ��
                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 0) {
                    double new_g = g_cost[x][y] + cost[nx][ny];
                    double new_f = new_g + GetWeight({ nx, ny }, { dst.GetNode().first, dst.GetNode().second});

                    if (new_g < g_cost[nx][ny]) {
                        g_cost[nx][ny] = new_g;
                        pq.push({ static_cast<double>(nx), static_cast<double>(ny), new_f, new_g });
                    }
                }
            }
        }

        return -1; // ��ǥ ������ ������ �� ���� ���

	}

	void setHeuristicFunction(std::function<int(std::pair<int, int>, std::pair<int, int>)> _huristicfunction)
	{
		heuristicFunc = _huristicfunction;
	}


private:
	
	class Node
	{
	public:
		Node() {};
		~Node() {};
		Node(int _x, int _y) : x(_x), y(_y) {};
		std::pair<int, int> GetNode() noexcept { return { x, y }; }
		void SetNode(int _x, int _y) noexcept { x = _x; y = _y; }
	private:
		int x = 0;
		int y = 0;
	};

	int GetWeight(std::pair<int,int> _src, std::pair<int,int> _dst)
	{
		if (heuristicFunc == NULL)
		{
			return -1;
		}

		return heuristicFunc(_src, _dst);
	}
	

	Node src;
	
    Node dst;
	
    std::vector<int> costTable;

	std::function<int(std::pair<int, int>, std::pair<int, int>)> heuristicFunc = NULL;
};