#include<iostream>
#include<string>

// 연산자는 +=를 사용할 것
// 미리 기억공간을 확보할 것. = 기억공간 재할당을 줄일 것.
// 복사 생성자를 최대한 줄일 것

std::string remove_ctrl(std::string s) {  // unoptimized function
	std::string answer;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 0x20) answer = answer + s[i];
	}

	return answer;
}

std::string remove_ctrl_op1(std::string s) {  // 연산자 변환
	std::string answer;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 0x20) answer += s[i];
	}

	return answer;
}

std::string remove_ctrl_op2(std::string s) {  // 기억공간 미리 확보하여 재할당 감소 	
	std::string answer;
	answer.reserve(s.length());
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 0x20) answer += s[i];
	}

	return answer;
}

std::string remove_ctrl_op3(std::string const& s) {  //  	
	std::string answer;
	answer.reserve(s.length());
	for (auto i = s.begin(), end = s.end(); i != end; ++i) {
		if (*i >= 0x20) answer += *i;
	}

	return answer;
}

void remove_ctrl_op4(std::string& answer,std::string const& s) {  // 매개변수용 변수인자		
	answer.clear();
	answer.reserve(s.length());
	for (auto i = s.begin(), end = s.end(); i != end; ++i) {
		if (*i >= 0x20) answer += *i;
	}
}

void remove_ctrl_cstrings(char* destp, char const* srcp, size_t size) { // cache locality를 이용 
	for (size_t i = 0; i < size; ++i) {
		if (srcp[i] >= 0x20) *destp++ = srcp[i];
	}
	*destp = 0;
}//최적화 안된 함수보다 약 170배 정도 향상.

std::string remove_ctrl_op5(std::string const& s) {  //조금 더 좋은 알고리즘으로 변경  	
	std::string r;
	r.reserve(s.length());
	for (size_t b = 0, i = b; b < s.length(); b = i+1) {
		for (i = b; i < s.length(); ++i) {
			if (s[i] < 0x20) break;
		}
		r.append(s, b, i - b);
	}
	return r;
}
