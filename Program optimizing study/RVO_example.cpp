#include<iostream>
#include<vector>

std::vector<int> scalar_product(std::vector<int> const& v, int c) { // �� ������ �ʿ� ���� �ÿ��� const&�� ���Ͽ� ���簡 �Ͼ�� �ʵ��� ����
	std::vector<int> rt;
	rt.reserve(v.size()); // �׻� ���Ҵ��� �ּ�ȭ�ϱ� ���Ͽ� reserve ��ɾ ���Ͽ� �޸� �̸� �Ҵ�
	for (auto val : v) {
		rt.push_back(val * c);
	}
	return rt;
}

void scalar_product_op(std::vector<int> const& v, int c, std::vector<int>& rt) { // 1������ ȣ�⿡ ���� ���� �����ߴٸ� ��ȯ�� ���� ���� ����
	rt.clear();
	rt.reserve(v.size());
	for (auto val : v) {
		rt.push_back(val * c);
	}
} /*
	���� ��ȯ���� ��ȯ ���� ���� ���縦 ���� �� ����.
	RVO(return value optimization)���
	�� ����� ��ü�� ��ȯ���� ���� Ÿ���̿��� ������.
	�Լ��� ������ �� �����Ϸ��� RVO�� ������ ���ɼ��� ����
	�� ����� ����ϸ� �ش� �Լ��� ��ȯ�� ���ϰ� �ϰų� �������� ������ �ߴ� ���� ���� Ȯ�� ���� ��ȯ����
	����� �� ����.
	�� ������ �Լ����� ���� X
  */

