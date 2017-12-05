/*
 * CallbackResponse.h
 *
 *  Created on: Jul 23, 2017
 *      Author: denizcan
 */

#ifndef ART_CALLBACKRESPONSE_H_
#define ART_CALLBACKRESPONSE_H_

#include <Art/Response.h>
#include <Art/Callback.h>
#include <Art/Thread.h>
#include <Art/Task.h>

namespace Art
{

	class CallbackResponse : public Response
	{
	public:
		CallbackResponse();
		virtual ~CallbackResponse();

		CallbackResponse(void(*function)(void*));
		CallbackResponse(void(*function)(void*), Thread* thread);

		template <class T>
		CallbackResponse(T* instance, void(T::*method)(void*));

		template <class T>
		CallbackResponse(T* instance, void(T::*method)(void*), Thread* thread);

		CallbackResponse(const Callback<void*>& callback);
		CallbackResponse(const Callback<void*>& callback, Thread* thread);


		template <class T>
		void setCallback(T* instance, void(T::*method)(void*));

		void setThread(Thread* value);
	private:
		virtual void clearTrigger();
		virtual void trigger();
		virtual void triggerSvc();

		class ThreadTask : public Task
		{
			void execute();
		};

		Thread*			m_thread;
		Callback<void*>	m_callback;
		ThreadTask		m_task;

	};

	template<class T>
	inline CallbackResponse::CallbackResponse(T* instance, void (T::*method)(void*),
			Thread* thread)
		: m_callback(instance, method)
	{
		 m_thread = thread;
	}

	template<class T>
	inline CallbackResponse::CallbackResponse(T* instance,
	        void (T::*method)(void*))
		: m_callback(instance, method)
	{
		m_thread = currentThread();
	}

	template<class T>
	inline void CallbackResponse::setCallback(T* instance,
	        void (T::*method)(void*))
	{
		m_callback.assign(instance, method);
	}

	inline void CallbackResponse::setThread(Thread* value)
	{
		m_thread = value;
	}

} /* namespace Art */



#endif /* SOURCE_ART_CALLBACKRESPONSE_H_ */
