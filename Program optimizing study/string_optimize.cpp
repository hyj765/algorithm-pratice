#include<iostream>
#include<string>

// �����ڴ� +=�� ����� ��
// �̸� �������� Ȯ���� ��. = ������ ���Ҵ��� ���� ��.
// ���� �����ڸ� �ִ��� ���� ��

std::string remove_ctrl(std::string s) {  // unoptimized function
	std::string answer;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 0x20) answer = answer + s[i];
	}

	return answer;
}

std::string remove_ctrl_op1(std::string s) {  // ������ ��ȯ
	std::string answer;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] >= 0x20) answer += s[i];
	}

	return answer;
}

std::string remove_ctrl_op2(std::string s) {  // ������ �̸� Ȯ���Ͽ� ���Ҵ� ���� 	
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

void remove_ctrl_op4(std::string& answer,std::string const& s) {  // �Ű������� ��������		
	answer.clear();
	answer.reserve(s.length());
	for (auto i = s.begin(), end = s.end(); i != end; ++i) {
		if (*i >= 0x20) answer += *i;
	}
}

void remove_ctrl_cstrings(char* destp, char const* srcp, size_t size) { // cache locality�� �̿� 
	for (size_t i = 0; i < size; ++i) {
		if (srcp[i] >= 0x20) *destp++ = srcp[i];
	}
	*destp = 0;
}//����ȭ �ȵ� �Լ����� �� 170�� ���� ���.

std::string remove_ctrl_op5(std::string const& s) {  //���� �� ���� �˰������� ����  	
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
