/*
 * svf_string.cpp
 *
 *  Created on: Oct 15, 2013
 *      Author: ballance
 */

#include "svf_string.h"
#include <string.h>

svf_string::svf_string() {
	m_str = new char[1];
	m_str[0] = 0;
}

svf_string::svf_string(const char *str) {
	int len = strlen(str);
	m_str = new char[len+1];
	memcpy(m_str, str, len+1);
}

svf_string::~svf_string() {
	// TODO Auto-generated destructor stub
}

void svf_string::operator = (const char *str) {
	int len = strlen(str);
	if (m_str) {
		delete [] m_str;
	}
	m_str = new char[len+1];
	memcpy(m_str, str, len+1);
}

void svf_string::operator = (const svf_string &str) {
	int len = strlen(str.m_str);
	if (m_str) {
		delete [] m_str;
	}
	m_str = new char[len+1];
	memcpy(m_str, str.m_str, len+1);
}

void svf_string::append(const char *str) {
	int len = strlen(str);
	int str_len = strlen(m_str);
	char *tmp = m_str;

	m_str = new char[len+str_len+1];

	memcpy(m_str, tmp, str_len);
	memcpy(&m_str[str_len], str, len+1);

	if (tmp) {
		delete [] tmp;
	}
}
