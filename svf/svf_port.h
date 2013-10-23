/*
 * svf_port.h
 *
 *  Created on: Oct 16, 2013
 *      Author: ballance
 */

#ifndef SVF_PORT_H_
#define SVF_PORT_H_

template <class T> class svf_export;

template <class T> class svf_port {

	public:

		void connect(svf_export<T> exp);

		T *operator ->();

};




#endif /* SVF_PORT_H_ */
