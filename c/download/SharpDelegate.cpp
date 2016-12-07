/*
 * SharpDelegate.hpp
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

#ifndef SHARPDELEGATE_HPP_
#define SHARPDELEGATE_HPP_

#include <stdexcept>

/** 
 *	All SharpMM codes are in this namespace.
 */
namespace SharpMM
{
	/**
	 *	This namespace contains symbols which implements the SharpMM in detail.
	 *	It can be ignored when you use SharpMM.
	 */
	namespace Detail
	{
		const char* const EMPTY_DELEGATE_INVOKING_STRING = "Invoking an empty delegate!"; ///<	Constant string for the exception when a delegate invokes an empty pointer.

		/**
		 *	Type trait to check whether type T is void.
		 *	IsVoidType::VALUE return the boolean of whether T is void.
		 *
		 *	This is a generic one, adapted for non-void type.
		 */
		template<typename T>
		struct IsVoidType
		{
			static const bool VALUE = false; ///< Indicates whether type T is void.
		};

		/**
		 *	Type trait to check whether type T is void.
		 *	IsVoidType::VALUE return the boolean of whether T is void.

		 *	This is specialized one, adapted for void type.
		 */
		template<>
		struct IsVoidType<void>
		{
			static const bool VALUE = true;
		};
	}

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 6 parameters and non-void return function.
	 */
	template<typename RT = void,
		typename A0 = void,
		typename A1 = void,
		typename A2 = void,
		typename A3 = void,
		typename A4 = void,
		typename A5 = void,
		bool IsVoidFunction = Detail::IsVoidType<RT>::VALUE>
	class CDelegate
	{
	public:
		typedef RT ReturnType;	///< Return type.
		typedef A0 Arg0Type;	///< 1st parameter type.
		typedef A1 Arg1Type;	///< 2se parameter type.
		typedef A2 Arg2Type;	///< 3rd parameter type.
		typedef A3 Arg3Type;	///< 4th parameter type.
		typedef A4 Arg4Type;	///< 5th parameter type.
		typedef A5 Arg5Type;	///< 6th parameter type.
		enum { ARGC = 6 /**< Count of the function' parameters bound with the delegate. */};
		static const bool IS_VOID_DELEGATE = IsVoidFunction; ///< Indicates whether the function bound with the delegate returns void.

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const {
				return (*func)(a0, a1, a2, a3, a4, a5);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const {
				return (obj.*func)(a0, a1, a2, a3, a4, a5);
			}
		};

		holder* h;

	public:
		/**
		 *	Default constructor, binds nothing.
		 */
		CDelegate() : h(0) {}

		/**	
		 *	Constructor, binds a global or static function.
		 *
		 *	\param function, a global or static function pointer.
		 */
		CDelegate(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		/**
		 *	Constructor, binds a member function and an instance of the class.
		 *
		 *	\param object, a pointer of the Class.
		 *	\param function, a member function pointer of the Class.
		 */
		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		/**
		 *	Copy-constructor.
		 */
		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		/**
		 *	Destructor.
		 */
		~CDelegate() { delete h; }

		/**
		 *	Assign-function, binds a global or static function.
		 *
		 *	\param function, a global or static function pointer.
		 */
		void Assign(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		/**
		 *	Assign-function, binds a member function.
		 *
		 *	\param object, a pointer of the Class.
		 *	\param function, a member function pointer of the Class.
		 */
		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		/**
		 *	Assign-function, copy another CDelegate instance.
		 *
		 *	\param rhs, a reference of another CDelegate instance.
		 */
		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		/**
		 *	Make the delegate binds nothing.
		 */
		void Clear() { delete h; h = 0; }

		/**
		 *	Checks whether the delegate binds nothing.
		 *
		 *	\return boolean value indicats whether the delegate is empty.
		 */
		bool Empty() const { return h == 0; }

		/**
		 *	Checks whether another delegate binds the same function as this one.
		 *
		 *	\param rhs, a reference of another CDelegate instance.
		 *	\return boolean value indicates whether two delegates' functions are the same.
		 */
		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		/**
		 *	Call function bound with the delegate.
		 *
		 *	\throw std::runtime_error, if the delegate binds nothing.
		 */
		ReturnType Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const {
			if (h)
				return h->invoke(a0, a1, a2, a3, a4, a5);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		/**
		 *	Copy assign operator function.
		 *
		 *	\param rhs, a reference of another CDelegate instance.
		 *	\return reference of this delegate.
		 */
		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		/**
		 *	Checks whether two delegates are equal.
		 *
		 *	\see CDelegate::Equals
		 */
		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }

		/**
		 *	Checks whether two delegates are not equal.
		 *
		 *	\see CDelegate::Equals
		 */
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		/**
		 *	Call function bound with the delegate.
		 *
		 *	\see CDelegate::Invoke
		 */
		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const { return Invoke(a0, a1, a2, a3, a4, a5); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 6 parameters and void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2,
		typename A3,
		typename A4,
		typename A5>
	class CDelegate<RT, A0, A1, A2, A3, A4, A5, true>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		typedef A3 Arg3Type;
		typedef A4 Arg4Type;
		typedef A5 Arg5Type;
		enum { ARGC = 6 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const {
				(*func)(a0, a1, a2, a3, a4, a5);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const {
				(obj.*func)(a0, a1, a2, a3, a4, a5);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type, Arg5Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const {
			if (h)
				h->invoke(a0, a1, a2, a3, a4, a5);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4, Arg5Type a5) const { Invoke(a0, a1, a2, a3, a4, a5); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 5 parameters and non-void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2,
		typename A3,
		typename A4>
	class CDelegate<RT, A0, A1, A2, A3, A4, void, false>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		typedef A3 Arg3Type;
		typedef A4 Arg4Type;
		enum { ARGC = 5 };
		static const bool IS_VOID_DELEGATE = false;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const {
				return (*func)(a0, a1, a2, a3, a4);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const {
				return (obj.*func)(a0, a1, a2, a3, a4);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		ReturnType Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const {
			if (h)
				return h->invoke(a0, a1, a2, a3, a4);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const { return Invoke(a0, a1, a2, a3, a4); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 5 parameters and void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2,
		typename A3,
		typename A4>
	class CDelegate<RT, A0, A1, A2, A3, A4, void, true>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		typedef A3 Arg3Type;
		typedef A4 Arg4Type;
		enum { ARGC = 5 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const {
				(*func)(a0, a1, a2, a3, a4);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const {
				(obj.*func)(a0, a1, a2, a3, a4);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type, Arg4Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const {
			if (h)
				h->invoke(a0, a1, a2, a3, a4);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3, Arg4Type a4) const { Invoke(a0, a1, a2, a3, a4); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 4 parameters and non-void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2,
		typename A3>
	class CDelegate<RT, A0, A1, A2, A3, void, void, false>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		typedef A3 Arg3Type;
		enum { ARGC = 4 };
		static const bool IS_VOID_DELEGATE = false;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke(Arg0Type, Arg1Type, Arg2Type, Arg3Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const {
				return (*func)(a0, a1, a2, a3);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const {
				return (obj.*func)(a0, a1, a2, a3);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		ReturnType Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const {
			if (h)
				return h->invoke(a0, a1, a2, a3);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const { return Invoke(a0, a1, a2, a3); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 4 parameters and void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2,
		typename A3>
	class CDelegate<RT, A0, A1, A2, A3, void, void, true>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		typedef A3 Arg3Type;
		enum { ARGC = 4 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke(Arg0Type, Arg1Type, Arg2Type, Arg3Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const {
				(*func)(a0, a1, a2, a3);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const {
				(obj.*func)(a0, a1, a2, a3);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type, Arg3Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const {
			if (h)
				h->invoke(a0, a1, a2, a3);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2, Arg3Type a3) const { Invoke(a0, a1, a2, a3); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 3 parameters and non-void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2>
	class CDelegate<RT, A0, A1, A2, void, void, void, false>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		enum { ARGC = 3 };
		static const bool IS_VOID_DELEGATE = false;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke(Arg0Type, Arg1Type, Arg2Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2) const {
				return (*func)(a0, a1, a2);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)(Arg0Type, Arg1Type, Arg2Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2) const {
				return (obj.*func)(a0, a1, a2);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(ReturnType(*function)(Arg0Type, Arg1Type, Arg2Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type, Arg2Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		ReturnType Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2) const {
			if (h)
				return h->invoke(a0, a1, a2);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2) const { return Invoke(a0, a1, a2); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 3 parameters and void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1,
		typename A2>
	class CDelegate<RT, A0, A1, A2, void, void, void, true>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		typedef A2 Arg2Type;
		enum { ARGC = 3 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke(Arg0Type, Arg1Type, Arg2Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef void(*function)(Arg0Type, Arg1Type, Arg2Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2) const {
				(*func)(a0, a1, a2);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)(Arg0Type, Arg1Type, Arg2Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2) const {
				(obj.*func)(a0, a1, a2);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)(Arg0Type, Arg1Type, Arg2Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)(Arg0Type, Arg1Type, Arg2Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type, Arg2Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke(Arg0Type a0, Arg1Type a1, Arg2Type a2) const {
			if (h)
				h->invoke(a0, a1, a2);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()(Arg0Type a0, Arg1Type a1, Arg2Type a2) const { Invoke(a0, a1, a2); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 2 parameters and non-void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1>
	class CDelegate<RT, A0, A1, void, void, void, void, false>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		enum { ARGC = 2 };
		static const bool IS_VOID_DELEGATE = false;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke(Arg0Type, Arg1Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)(Arg0Type, Arg1Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1) const {
				return (*func)(a0, a1);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)(Arg0Type, Arg1Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0, Arg1Type a1) const {
				return (obj.*func)(a0, a1);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(ReturnType(*function)(Arg0Type, Arg1Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(ReturnType(*function)(Arg0Type, Arg1Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)(Arg0Type, Arg1Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		ReturnType Invoke(Arg0Type a0, Arg1Type a1) const {
			if (h)
				return h->invoke(a0, a1);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		ReturnType operator()(Arg0Type a0, Arg1Type a1) const { return Invoke(a0, a1); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 2 parameters and void return function.
	 */
	template<typename RT,
		typename A0,
		typename A1>
	class CDelegate<RT, A0, A1, void, void, void, void, true>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		typedef A1 Arg1Type;
		enum { ARGC = 2 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke(Arg0Type, Arg1Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef void(*function)(Arg0Type, Arg1Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1) const {
				(*func)(a0, a1);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)(Arg0Type, Arg1Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0, Arg1Type a1) const {
				(obj.*func)(a0, a1);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)(Arg0Type, Arg1Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)(Arg0Type, Arg1Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)(Arg0Type, Arg1Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke(Arg0Type a0, Arg1Type a1) const {
			if (h)
				h->invoke(a0, a1);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()(Arg0Type a0, Arg1Type a1) const { Invoke(a0, a1); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 1 parameter and non-void return function.
	 */
	template<typename RT,
		typename A0>
	class CDelegate<RT, A0, void, void, void, void, void, false>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		enum { ARGC = 1 };
		static const bool IS_VOID_DELEGATE = false;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke(Arg0Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)(Arg0Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0) const {
				return (*func)(a0);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)(Arg0Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke(Arg0Type a0) const {
				return (obj.*func)(a0);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(ReturnType(*function)(Arg0Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)(Arg0Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(ReturnType(*function)(Arg0Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)(Arg0Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		ReturnType Invoke(Arg0Type a0) const {
			if (h)
				return h->invoke(a0);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		ReturnType operator()(Arg0Type a0) const { return Invoke(a0); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 1 parameter and void return function.
	 */
	template<typename RT,
		typename A0>
	class CDelegate<RT, A0, void, void, void, void, void, true>
	{
	public:
		typedef RT ReturnType;
		typedef A0 Arg0Type;
		enum { ARGC = 1 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke(Arg0Type) const = 0;
		};

		struct fholder : public holder
		{
			typedef void (*function)(Arg0Type);
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0) const {
				(*func)(a0);
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)(Arg0Type);
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke(Arg0Type a0) const {
				(obj.*func)(a0);
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)(Arg0Type)) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)(Arg0Type)) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)(Arg0Type)) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)(Arg0Type)) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke(Arg0Type a0) const {
			if (h)
				h->invoke(a0);
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()(Arg0Type a0) const { Invoke(a0); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 0 parameter and non-void return function.
	 */
	template<typename RT>
	class CDelegate<RT, void, void, void, void, void, void, false>
	{
	public:
		typedef RT ReturnType;
		enum { ARGC = 0 };
		static const bool IS_VOID_DELEGATE = false;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual ReturnType invoke() const = 0;
		};

		struct fholder : public holder
		{
			typedef ReturnType(*function)();
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke() const {
				return (*func)();
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef ReturnType(concept::*function)();
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual ReturnType invoke() const {
				return (obj.*func)();
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(ReturnType(*function)()) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, ReturnType(Concept::*function)()) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(ReturnType(*function)()) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, ReturnType(Concept::*function)()) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		ReturnType Invoke() const {
			if (h)
				return h->invoke();
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		ReturnType operator()() const { return Invoke(); }
	};

	/**
	 *	Class template to immitate delegate in C#. You can bind a global (static) function or a member function
	 *	to a CDelegate as this: exmpale CDelegate<ReturnType, Type1, Type2> mydelegate, return type first, following
	 *	are parameter types in order. If the function returns nothing, just make return type 'void'.
	 *
	 *	You can call CDelegate::Invoke(<parameters>) to invoke the function stored in the delegate.
	 *
	 *	\remark	Now only functions that take 0-6 parameters supported.
	 *	
	 *	This is generic one, adapted for 0 parameter and void return function.
	 */
	template<typename RT>
	class CDelegate<RT, void, void, void, void, void, void, true>
	{
	public:
		typedef RT ReturnType;
		enum { ARGC = 0 };
		static const bool IS_VOID_DELEGATE = true;

	private:
		struct holder
		{
			virtual ~holder() {}
			virtual holder* clone() const = 0;
			virtual bool equals(const holder*) const = 0;
			virtual void invoke() const = 0;
		};

		struct fholder : public holder
		{
			typedef void(*function)();
			function func;
			fholder(function f) : func(f) {}
			virtual holder* clone() const { return new fholder(func); }
			virtual bool equals(const holder* rhs) const {
				const fholder* p = dynamic_cast<const fholder*>(rhs);
				if (p)
					return func == p->func;
				else
					return false;
			}
			virtual void invoke() const {
				(*func)();
			}
		};

		template<typename Concept>
		struct mholder : public holder
		{
			typedef Concept concept;
			typedef void(concept::*function)();
			concept& obj;
			function func;
			mholder(concept& o, function f) : obj(o), func(f) {}
			virtual holder* clone() const { return new mholder(obj, func); }
			virtual bool equals(const holder* rhs) const {
				const mholder* p = dynamic_cast<const mholder*>(rhs);
				if (p)
					return &obj == &(p->obj) && func == p->func;
				else
					return false;
			}
			virtual void invoke() const {
				(obj.*func)();
			}
		};

		holder* h;

	public:
		CDelegate() : h(0) {}

		CDelegate(void(*function)()) : h(0) {
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		CDelegate(Concept* object, void(Concept::*function)()) : h(0) {
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		CDelegate(const CDelegate& rhs) : h(0) {
			if (rhs.h)
				h = rhs.h->clone();
		}

		~CDelegate() { delete h; }

		void Assign(void(*function)()) {
			Clear();
			if (function)
				h = new fholder(function);
		}

		template<typename Concept>
		void Assign(Concept* object, void(Concept::*function)()) {
			Clear();
			if (object && function)
				h = new mholder<Concept>(*object, function);
		}

		void Assign(const CDelegate& rhs) {
			if (Equals(rhs))
				return;
			Clear();
			if (rhs.h)
				h = rhs.h->clone();
		}

		void Clear() { delete h; h = 0; }

		bool Empty() const { return h == 0; }

		bool Equals(const CDelegate& rhs) const {
			if (h && rhs.h)
				return h->equals(rhs.h);
			return false;
		}

		void Invoke() const {
			if (h)
				h->invoke();
			else
				throw std::runtime_error(Detail::EMPTY_DELEGATE_INVOKING_STRING);
		}

		CDelegate& operator=(const CDelegate& rhs) { Assign(rhs); return *this; }

		bool operator==(const CDelegate& rhs) const { return Equals(rhs); }
		bool operator!=(const CDelegate& rhs) const { return !Equals(rhs); }

		void operator()() const { Invoke(); }
	};
}

#endif /* SHARPDELEGATE_HPP_ */