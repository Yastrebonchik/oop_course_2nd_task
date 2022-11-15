/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 21:29:27 by                   #+#    #+#             */
/*   Updated: 2021/06/03 12:43:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_LIST_H
# define FT_CONTAINERS_LIST_H

# include <limits>
# include "algorithm.hpp"

namespace ft {
	template<class T>
	class list {
	private:
		class node {
		public:
			T		value;
			node	*next;
			node	*prev;

			node() : next(nullptr), prev(nullptr) {};
			node(const T& val) : value(val), next(nullptr), prev(nullptr) {};
			node(node &src) : value(src.value), next(nullptr), prev(nullptr) {};
		};
		node	*_Mnode;
		size_t	_len;

	public:
		list() : _Mnode(new node()), _len(0) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
		};
		list(size_t n, const T& val = T()) : _Mnode(new node()), _len(0) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
			this->assign(n, val);
		};
		template <class InputIterator>
		list (InputIterator first, InputIterator last) : _Mnode(new node()), _len(0) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
			this->assign(first, last);
		};
		list (const list& x) : _Mnode(new node()), _len(0) {
			this->_Mnode->next = this->_Mnode;
			this->_Mnode->prev = this->_Mnode;
			this->assign(x.begin(), x.end());
		};
		~list() {
			this->clear();
			delete this->_Mnode;
		};

		list&	operator=(const list& x) {
			this->assign(x.begin(), x.end());
			return (*this);
		};

		/* Forward iterator class */
		class iterator {
		public:
			node	*_current;

			iterator() : _current(nullptr) {
			};
			iterator(node *Node) : _current(Node) {
			};
			iterator(const iterator &src) : _current(src._current) {
			};
			~iterator() {
			};

			/* Operators */
			iterator&	operator++() {
				this->_current = this->_current->next;
				return (*this);
			};
			iterator	operator++(int) {
				iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			iterator&	operator--() {
				this->_current = this->_current->prev;
				return (*this);
			};
			iterator	operator--(int) {
				iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			T&			operator*() {
				return (this->_current->value);
			};
			T*			operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			iterator&	operator=(const iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};

		};

		/* Const Forward iterator class */
		class const_iterator {
		public:
			node	*_current;

			const_iterator() : _current(nullptr) {
			};
			const_iterator(node *Node) : _current(Node) {
			};
			const_iterator(const const_iterator &src) : _current(src._current) {
			};
			~const_iterator() {
			};

			/* Operators */
			const_iterator&	operator++() {
				this->_current = this->_current->next;
				return (*this);
			};
			const_iterator	operator++(int) {
				const_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			const_iterator&	operator--() {
				this->_current = this->_current->prev;
				return (*this);
			};
			const_iterator	operator--(int) {
				const_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			const T&		operator*() {
				return (this->_current->value);
			};
			const T*		operator->() const {
				return &(operator*());
			}
			bool 		operator!=(const const_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 		operator==(const const_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			const_iterator&	operator=(const const_iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};

		};

		/* Reverse iterator class */
		class reverse_iterator {
		public:
			node	*_current;

			reverse_iterator() : _current(nullptr) {
			};
			reverse_iterator(node *Node) : _current(Node){
			};
			reverse_iterator(const reverse_iterator &src) : _current(src._current) {
			};
			~reverse_iterator() {
			};

			/* Operators */
			reverse_iterator&	operator++() {
				this->_current = this->_current->prev;
				return (*this);
			};
			reverse_iterator	operator++(int) {
				reverse_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			reverse_iterator&	operator--() {
				this->_current = this->_current->next;
				return (*this);
			};
			reverse_iterator	operator--(int) {
				reverse_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			T&					operator*() {
				return (this->_current->value);
			};
			T*					operator->() const {
				return &(operator*());
			}
			bool 				operator!=(const reverse_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 				operator==(const reverse_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			reverse_iterator&	operator=(const reverse_iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};
		};

		/* Const reverse iterator class */
		class const_reverse_iterator{
		public:
			node	*_current;

			const_reverse_iterator() : _current(nullptr) {
			};
			const_reverse_iterator(node *Node) : _current(Node){
			};
			const_reverse_iterator(const const_reverse_iterator &src) : _current(src._current) {
			};
			~const_reverse_iterator() {
			};

			/* Operators */
			const_reverse_iterator&	operator++() {
				this->_current = this->_current->prev;
				return (*this);
			};
			const_reverse_iterator	operator++(int) {
				const_reverse_iterator	result(*this);

				this->_current = this->_current->prev;
				return (result);
			};
			const_reverse_iterator&	operator--() {
				this->_current = this->_current->next;
				return (*this);
			};
			const_reverse_iterator	operator--(int) {
				const_reverse_iterator	result(*this);

				this->_current = this->_current->next;
				return (result);
			};
			const T&				operator*() {
				return (this->_current->value);
			};
			const T*				operator->() const {
				return &(operator*());
			}
			bool 					operator!=(const const_reverse_iterator &rhs) {
				if (this->_current != rhs._current)
					return (true);
				else
					return (false);
			};
			bool 					operator==(const const_reverse_iterator &rhs) {
				if (this->_current == rhs._current)
					return (true);
				else
					return (false);
			};
			const_reverse_iterator&	operator=(const reverse_iterator &rhs) {
				if (this != &rhs)
					this->_current = rhs._current;
				return (*this);
			};
		};

		/* Iterators */
		iterator 				begin(void) {
			return(iterator(this->_Mnode->next));
		};
		const_iterator			begin(void) const {
			return(const_iterator(this->_Mnode->next));
		};
		iterator				end() {
			return(iterator(this->_Mnode));
		};
		const_iterator			end() const {
			return(const_iterator(this->_Mnode));
		};
		reverse_iterator		rbegin() {
			return(reverse_iterator(this->_Mnode->prev));
		};
		const_reverse_iterator	rbegin() const {
			return(const_reverse_iterator(this->_Mnode->prev));
		};
		reverse_iterator		rend(){
			return(reverse_iterator(this->_Mnode));
		};
		const_reverse_iterator	rend() const {
			return(const_reverse_iterator(this->_Mnode));
		};

		/* Capacity */
		bool		empty() const{
			if (this->_len == 0)
				return true;
			else
				return false;
		};
		size_t		size() const {
			return (this->_len);
		};

		size_t		max_size() const {
			return (std::numeric_limits<size_t>::max() / (sizeof(node)));
		};

		/* Element access */
		T&			front() {
			return (this->_Mnode->next->value);
		};
		const T&	front() const {
			return (this->_Mnode->next->value);
		};
		T&			back() {
			return (this->_Mnode->prev->value);
		};
		const T&	back() const {
			return (this->_Mnode->prev->value);
		};

		/* Modifiers */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {
			this->clear();
			this->insert(this->begin(), first, last);
		};
		void assign (size_t n, const T& val){
			this->clear();
			this->insert(this->begin(), n ,val);
		};
		void 		push_front(const T& val) {
			node*	newNode = new node(val);

			newNode->prev = this->_Mnode;
			if (this->_len == 0)
				newNode->next = this->_Mnode;
			else{
				newNode->next = this->_Mnode->next;
				newNode->next->prev = newNode;
			}
			this->_Mnode->next = newNode;
			if (this->_len == 0)
				this->_Mnode->prev = newNode;
			this->_len++;
		};
		void 		pop_front() {
			node*	address = this->_Mnode->next;

			this->_Mnode->next = address->next;
			address->next->prev = this->_Mnode;
			delete address;
			this->_len--;
			if (this->_len == 0){
				this->_Mnode->next = this->_Mnode;
				this->_Mnode->prev = this->_Mnode;
			}
		};
		void 		push_back(const T& val) {
			node*	newNode = new node(val);

			newNode->next = this->_Mnode;
			if (this->_len == 0)
				newNode->prev = this->_Mnode;
			else {
				newNode->prev = this->_Mnode->prev;
				newNode->prev->next = newNode;
			}
			this->_Mnode->prev = newNode;
			if (this->_len == 0)
				this->_Mnode->next = newNode;
			this->_len++;
		};
		void 		pop_back() {
			node*	address = this->_Mnode->prev;

			this->_Mnode->prev = address->prev;
			address->prev->next = this->_Mnode;
			delete address;
			this->_len--;
			if (this->_len == 0){
				this->_Mnode->next = this->_Mnode;
				this->_Mnode->prev = this->_Mnode;
			}
		};
		iterator	insert(iterator position, const T& val) {
			iterator	ret;

			if (position._current != this->_Mnode) {
				node	*newNode = new node(val);

				ret._current = newNode;
				newNode->next = position._current;
				newNode->prev = position._current->prev;
				position._current->prev->next = newNode;
				position._current->prev = newNode;
				this->_len++;
			}
			else {
				this->push_back(val);
				ret._current = this->_Mnode;
			}
			return (ret);
		};
		void		insert(iterator position, size_t n, const T& val) {
			size_t	i = 0;
			while (i++ < n)
				position = this->insert(position, val);
		};
		template <class InputIterator>
		void 	insert (iterator position, InputIterator first, InputIterator last) {
			T	val;
			while (first != last) {
				val = *first;
				position = this->insert(position, val);
				first++;
			}
		};
		iterator	erase(iterator position) {
			iterator	ret;

			/* При попытке удаления конечного элемента (служебного) - Undefined Behaviour без exception'а */

			if (position._current != this->_Mnode) {
				ret._current = position._current->next;
				position._current->next->prev = position._current->prev;
				position._current->prev->next = position._current->next;
				this->_len--;
				delete position._current;
			}
			return (ret);
		};
		iterator	erase(iterator first, iterator last) {
			while (first != last)
				first = this->erase(first);
			return (first);
		};
		void swap (list& x) {
			size_t	nlen;
			node	*nNode;

			nlen = this->_len;
			this->_len = x._len;
			x._len = nlen;
			nNode = this->_Mnode;
			this->_Mnode = x._Mnode;
			x._Mnode = nNode;
		};
		void resize (size_t n, T val = T()) {
			if (n > this->size()){
				while (n > this->size())
					this->push_back(val);
			}
			else {
				while (n < this->size())
					this->pop_back();
			}
		};
		void 		clear() {
			while (!this->empty())
				this->pop_front();
		}

		/* Operations */
		void splice (iterator position, list& x) {
			this->splice(position, x, x.begin(), x.end());
		};
		void splice (iterator position, list& x, iterator i) {
			iterator	first = i;
			i++;
			this->splice(position, x, first, i);
		};
		void splice (iterator position, list& x, iterator first, iterator last) {
			list<T>::iterator	it = first;
			size_t				len = 0;

			while (it++ != last)
				len++;
			first._current->prev->next = last._current;
			last--;
			last._current->next->prev = first._current->prev;
			position._current->prev->next = first._current;
			first._current->prev = position._current->prev;
			last._current->next = position._current;
			position._current->prev = last._current;
			this->_len += len;
			x._len -= len;
		};
		void remove (const T& val) {
			list<T>::iterator it = this->begin();
			while (it != this->end()) {
				if (*it == val)
					it = this->erase(it);
				else
					it++;
			}
		};
		template <class Predicate>
		void remove_if (Predicate pred) {
			list<T>::iterator it = this->begin();
			while (it != this->end()) {
				if (pred(*it))
					it = this->erase(it);
				else
					it++;
			}
		};
		void unique() {
			list<T>::iterator it = this->begin();
			list<T>::iterator ite = this->end();
			list<T>::iterator cmp;

			cmp = it++;
			while (it != ite) {
				if (*it == *cmp)
					it = this->erase(it);
				else
					cmp = it++;;
			}
		};
		template <class BinaryPredicate>
		void unique (BinaryPredicate binary_pred) {
			list<T>::iterator it = this->begin();
			list<T>::iterator ite = this->end();
			list<T>::iterator cmp;

			cmp = it++;
			while (it != ite) {
				if (binary_pred(*cmp, *it))
					it = this->erase(it);
				else
					cmp = it++;
			}
		};
		void merge (list& x){
			list<T>::iterator it = this->begin();
			list<T>::iterator ite = this->end();

			while (it != ite) {
				if (*it > x.front() && x._len > 0)
					this->splice(it, x, x.begin());
				it++;
			}
			if (x._len > 0)
				this->splice(it, x);
		};
		template <class Compare>
		void merge (list& x, Compare comp) {
			list<T>::iterator it = this->begin();
			list<T>::iterator ite = this->end();

			while (it != ite) {
				if (comp(x.front(), *it) && x._len > 0)
					this->splice(it, x, x.begin());
				it++;
			}
			if (x._len > 0)
				this->splice(it, x);
		};
		void sort() {
			size_t		i = 0;
			iterator	it;
			iterator	ite = this->end();
			T			bubble;

			while (i < this->_len) {
				it = this->begin();
				ite--;
				while (it != ite) {
					if (it._current->value > it._current->next->value) {
						bubble = it._current->value;
						it._current->value = it._current->next->value;
						it._current->next->value = bubble;
					}
					it++;
				}
				i++;
			}
		};
		template <class Compare>
		void sort (Compare comp) {
			size_t		i = 0;
			iterator	it;
			iterator	ite = this->end();
			T			bubble;

			while (i < this->_len) {
				it = this->begin();
				ite--;
				while (it != ite) {
					if (!comp(it._current->value, it._current->next->value)) {
						bubble = it._current->value;
						it._current->value = it._current->next->value;
						it._current->next->value = bubble;
					}
					it++;
				}
				i++;
			}
		};
		void reverse() {
			list<T>::iterator	it = this->begin();
			list<T>::iterator	ite = this->end();
			node	*nNode;

			while (it != ite) {
				nNode = it._current->next;
				it._current->next = it._current->prev;
				it._current->prev = nNode;
				it._current = it._current->prev;
			}
			nNode = ite._current->next;
			ite._current->next = ite._current->prev;
			ite._current->prev = nNode;
		};

	};

	/* Non member function overloads */
	template <class T>
	void swap (list<T>& x, list<T>& y) {
		x.swap(y);
	};

	template <class T>
	bool operator==(const list<T>& lhs, const list<T>& rhs) {
	 	typename list<T>::const_iterator	itl = lhs.begin();
		typename list<T>::const_iterator	itle = lhs.end();
		typename list<T>::const_iterator	itr = rhs.begin();
		typename list<T>::const_iterator	itre = rhs.end();

		if (lhs.size() != rhs.size())
			return (false);
		while (itl != itle && itr != itre) {
			if (*itl != *itr)
				return (false);
			itl++;
			itr++;
		}
		return (true);
	};

	template <class T>
	bool operator!=(const list<T>& lhs, const list<T>& rhs) {
		return (!(lhs == rhs));
	};

	template <class T>
	bool operator<(const list<T>& lhs, const list<T>& rhs) {
		return(ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template <class T>
	bool operator>(const list<T>& lhs, const list<T>& rhs) {
		return (operator<(rhs, lhs));
	};

	template <class T>
	bool operator<=(const list<T>& lhs, const list<T>& rhs) {
		return (!(operator<(rhs, lhs)));
	};

	template <class T>
	bool operator>=(const list<T>& lhs, const list<T>& rhs) {
		return (!(operator<(lhs, rhs)));
	};
}
#endif //FT_CONTAINERS_LIST_H
