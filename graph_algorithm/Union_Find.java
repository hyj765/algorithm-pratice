
public class Union_Find {
	/*
	 유니온 
	 
	유니온 파인드는 그래프 알고리즘으로 두 노드가 같은 그래프에 속하는지 판별하는 알고리즘이다.
	서로소 집합, 상호 베타적 집합(Disjoint-Set)으로도 불린다.
	노드를 합치는 Union연산과 노드의 루트 노드를 찾는 Find연산으로 이루어진다.
	트리 구조로 이루어진 자료구조 중 한가지로 생각되기도 한다.
	 
	 */
	
	static int find(int [] parent, int x) {
		
		if(parent[x] == x) return x;
		return parent[x] = find(parent, parent[x]);
	}
	
	static void merge(int[] parent ,int x, int y) {
		x = find(parent,x); //x의 대표자 찾기
		y = find(parent,y); // y의 대표자 찾기
		if(x== y) return;
		parent[y] = x; // y의 값에 x의 대표자 값을 넣어주기.
	}

	
	
	
	static boolean isUnion(int[] parent,int x, int y) {
		x = find(parent,x);
		y = find(parent,y);
		if(x == y) return true;
		
		return false;
		
	}
	
	
	public static void main(String[] args) {
		
		int parent[] = new int[10];
		for(int i=1; i<=8; i++) {
			parent[i] = i;
		}
		merge(parent,1,2); // 각자 자기 자신이 대표자일 때 merge를 함으로써 2의 대표자는 1이 됨.
		merge(parent,4,5); // 5 -> 4
		merge(parent,5,6); // 6 -> 5 -> 4
		System.out.println(isUnion(parent,4,6));
		System.out.println(isUnion(parent,2,6));
		merge(parent,1,5); // 5 -> 4 -> 1
		System.out.println(isUnion(parent,2,6));
	}
}
