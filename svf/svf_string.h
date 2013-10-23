/*
 * svf_string.h
 *
 *  Created on: Oct 15, 2013
 *      Author: ballance
 */

#ifndef SVF_STRING_H_
#define SVF_STRING_H_

class svf_string {

	public:
		svf_string();

		svf_string(const char *str);

		virtual ~svf_string();

		void operator = (const char *str);

		void operator = (const svf_string &str);

		void append(const char *str);

	private:

		char				*m_str;

};

#endif /* SVF_STRING_H_ */
