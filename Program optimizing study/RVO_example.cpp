#include<iostream>
#include<vector>

std::vector<int> scalar_product(std::vector<int> const& v, int c) { // 값 변경이 필요 없을 시에는 const&를 통하여 복사가 일어나지 않도록 방지
	std::vector<int> rt;
	rt.reserve(v.size()); // 항상 재할당을 최소화하기 위하여 reserve 명령어를 통하여 메모리 미리 할당
	for (auto val : v) {
		rt.push_back(val * c);
	}
	return rt;
}

void scalar_product_op(std::vector<int> const& v, int c, std::vector<int>& rt) { // 1번에서 호출에 대한 복사 제거했다면 반환에 대한 복사 제거
	rt.clear();
	rt.reserve(v.size());
	for (auto val : v) {
		rt.push_back(val * c);
	}
} /*
	참조 반환으로 반환 값에 대한 복사를 피할 수 있음.
	RVO(return value optimization)방법
	이 방법은 객체가 반환형과 같은 타입이여만 가능함.
	함수가 간단할 시 컴파일러가 RVO를 수행할 가능성이 높음
	이 방법을 사용하면 해당 함수가 반환을 안하게 하거나 성공적인 수행을 했는 지에 대한 확인 값의 반환으로
	사용할 수 있음.
	단 연산자 함수에는 구현 X
	C++ 11 이상부터는 RVO를 자동으로 최적화해주기 때문에 이상 버전에서는 return 값을 사용해도 상관 없음.
  */

