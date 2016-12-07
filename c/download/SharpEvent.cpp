/*
 * SharpEvent.hpp
 *
 *  Created on: 2014-5-16
 *      Author: leoking
 *   Copyright: This file is published under BSD license.
 *
	Copyright (c) 2014, leoking
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
		* Redistributions of source code must retain the above copyright
		  notice, this list of conditions and the following disclaimer.
		* Redistributions in binary form must reproduce the above copyright
		  notice, this list of conditions and the following disclaimer in the
		  documentation and/or other materials provided with the distribution.
		* Neither the name of the <organization> nor the
		  names of its contributors may be used to endorse or promote products
		  derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#ifndef SHARPEVENT_HPP_
#define SHARPEVENT_HPP_

#include <list>

namespace SharpMM
{
	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, not for binding CDelegate type.
	 */
	template<typename Delegate, int ARGC = Delegate::ARGC, bool IsVoidDelegate = Delegate::IS_VOID_DELEGATE>
	class CEvent
	{
	public:
		enum { ERROR = "Illegal delegate type." /**< Illegal grammar to indicate illegal delegat binding. */ };
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 0 parameter and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 0, true>
	{
	public:
		typedef Delegate EventHandler; ///< The delegate type, called EventHandler.
		typedef typename EventHandler::ReturnType ReturnType; ///< The delegate's return type.

		/**
		 *	Default-constructor, do nothing.
		 */
		CEvent() {}

		/**
		 *	Bind an instance of EventHandler to the event.
		 *
		 *	\param handler, an instance of EventHandler.
		 */
		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }

		/**
		 *	Unbind an EventHandler from the event.
		 *
		 *	\param handler, an instance of EventHandler.
		 */
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		/**
		 *	Trigger of the event.
		 *	This function will invoke all the function bound with the delegates in order.
		 *	If functions bound with the delegates return, only the last one can be captured.
		 */
		void operator()() {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke();
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 0 parameter and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 0, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()() {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke();
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 1 parameter and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 1, true>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		void operator()(Arg0Type a0) {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke(a0);
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 1 parameter and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 1, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()(Arg0Type a0) {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke(a0);
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 2 parameters and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 2, true>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		void operator()(Arg0Type a0, Arg1Type a1) {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke(a0, a1);
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 2 parameters and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 2, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1) {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke(a0, a1);
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 3 parameters and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 3, true>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2) {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke(a0, a1, a2);
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 3 parameters and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 3, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2) {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke(a0, a1, a2);
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 4 parameters and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 4, true>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;
		typedef typename EventHandler::Arg3Type Arg3Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke(a0, a1, a2, a3);
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 4 parameters and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 4, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;
		typedef typename EventHandler::Arg3Type Arg3Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke(a0, a1, a2, a3);
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 5 parameters and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 5, true>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;
		typedef typename EventHandler::Arg3Type Arg3Type;
		typedef typename EventHandler::Arg4Type Arg4Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke(a0, a1, a2, a3, a4);
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 5 parameters and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 5, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;
		typedef typename EventHandler::Arg3Type Arg3Type;
		typedef typename EventHandler::Arg4Type Arg4Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke(a0, a1, a2, a3, a4);
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 6 parameters and returns void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 6, true>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;
		typedef typename EventHandler::Arg3Type Arg3Type;
		typedef typename EventHandler::Arg4Type Arg4Type;
		typedef typename EventHandler::Arg5Type Arg5Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) {
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				handler.Invoke(a0, a1, a2, a3, a4, a5);
			}
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};

	/**
	 *	Class template CEvent to immitate event grammar in C#.
	 *	To use this, you must bind a CDelegate type as this:
	 *	CEvent<CDelegate<ReturnType, Type1> > myevent;
	 *
	 *	This is a generic one, adapted for delegate binding function takes 6 parameters and returns not void.
	 */
	template<typename Delegate>
	class CEvent<Delegate, 6, false>
	{
	public:
		typedef Delegate EventHandler;
		typedef typename EventHandler::ReturnType ReturnType;
		typedef typename EventHandler::Arg0Type	Arg0Type;
		typedef typename EventHandler::Arg1Type	Arg1Type;
		typedef typename EventHandler::Arg2Type Arg2Type;
		typedef typename EventHandler::Arg3Type Arg3Type;
		typedef typename EventHandler::Arg4Type Arg4Type;
		typedef typename EventHandler::Arg5Type Arg5Type;

		CEvent() {}

		void operator+=(EventHandler handler) { handlers.push_front(handler); handlers.unique(); }
		void operator-=(EventHandler handler) { handlers.remove(handler); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) {
			ReturnType result;
			for (typename std::list<EventHandler>::const_iterator it = handlers.begin();
					it != handlers.end(); it++)
			{
				EventHandler handler = *it;
				result = handler.Invoke(a0, a1, a2, a3, a4, a5);
			}
			return result;
		}

	private:
		std::list<EventHandler> handlers;

	private:
		CEvent(const CEvent&);
		void operator=(const CEvent&);
	};
}

#endif /* SHARPEVENT_HPP_ */