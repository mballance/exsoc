/****************************************************************************
 * svf_env_primitives.h
 *
 * Functions that must be provided by the environment
 ****************************************************************************/
#ifndef INCLUDED_SVF_ENV_PRIMITIVES_H
#define INCLUDED_SVF_ENV_PRIMITIVES_H

#ifdef __cplusplus
extern "C" {
#endif
typedef void *svf_thread_hndl;
typedef void (*svf_thread_f)(void *);
typedef void *svf_mutex_hndl;
typedef void *svf_condition_hndl;



int svf_env_thread_create(
		svf_thread_hndl		*thread_h,
		svf_thread_f		thread_main,
		void 				*thread_ud);

int svf_env_mutex_create(
		svf_mutex_hndl		*mutex_h);

int svf_env_mutex_lock(
		svf_mutex_hndl		mutex_h);

int svf_env_mutex_unlock(
		svf_mutex_hndl		mutex_h);

#ifdef __cplusplus
}
#endif

#endif /* INCLUDED_SVF_ENV_PRIMITIVES_H */
